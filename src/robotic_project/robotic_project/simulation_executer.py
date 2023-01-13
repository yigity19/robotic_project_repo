import time
from datetime import datetime

import numpy as np
import pybullet as p

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist, Pose

from gym_pybullet_drones.utils.enums import DroneModel, Physics
from gym_pybullet_drones.envs.CtrlAviary import CtrlAviary
from gym_pybullet_drones.control.DSLPIDControl import DSLPIDControl
from gym_pybullet_drones.control.SimplePIDControl import SimplePIDControl
from gym_pybullet_drones.utils.Logger import Logger

from custom_messages_pkg.msg import SwarmPose, DroneRPM, SwarmRPM

DEFAULT_DRONES = DroneModel("cf2x")
DEFAULT_NUM_DRONES = 2
DEFAULT_PHYSICS = Physics("pyb")
DEFAULT_GUI = True
DEFAULT_RECORD_VISION = False
DEFAULT_PLOT = True
DEFAULT_USER_DEBUG_GUI = False
DEFAULT_AGGREGATE = True
DEFAULT_OBSTACLES = False
DEFAULT_SIMULATION_FREQ_HZ = 240
DEFAULT_CONTROL_FREQ_HZ = 48
DEFAULT_DURATION_SEC = 12
DEFAULT_OUTPUT_FOLDER = 'results'
DEFAULT_COLAB = False
DEFAULT_SIMULATION_FREQ_PERIOD = 1 / DEFAULT_SIMULATION_FREQ_HZ


class SimulationExecuter(Node):
    def __init__(self):
        super().__init__("simulation_executer")
        self.simulation_start()
        self.publisher = self.create_publisher(SwarmPose, 'swarm_pose', 10)
        self.subscription = self.create_subscription(SwarmRPM,'swarm_commands',self.controller_callback,10)
        self.num_drones = DEFAULT_NUM_DRONES
        self.timer = self.create_timer(DEFAULT_SIMULATION_FREQ_PERIOD, self.timer_callback)
        self.obs = None
    #def timer_callback2(self):
           
    
    def timer_callback(self):
        msg = SwarmPose()
        pose_msg_arr = []
        twist_msg_arr = []
        for j in range(self.num_drones):
            drone_pose = Pose()
            drone_pose.position.x = self.env.pos[j, 0]
            drone_pose.position.y = self.env.pos[j, 1]
            drone_pose.position.z = self.env.pos[j, 2]
            drone_pose.orientation.x = self.env.quat[j, 0]
            drone_pose.orientation.y = self.env.quat[j, 1]
            drone_pose.orientation.z = self.env.quat[j, 2]
            drone_pose.orientation.w = self.env.quat[j, 3]
            pose_msg_arr.append(drone_pose)

            drone_twist = Twist()
            drone_twist.linear.x =  self.env.vel[j, 0]
            drone_twist.linear.y =  self.env.vel[j, 1]
            drone_twist.linear.z =  self.env.vel[j, 2]
            drone_twist.angular.x = self.env.ang_v[j, 0]
            drone_twist.angular.y = self.env.ang_v[j, 1]
            drone_twist.angular.z = self.env.ang_v[j, 2]
            twist_msg_arr.append(drone_twist)
            #if self.obs is not None:
            #    print("pos", self.obs[str(j)]["state"][0:3] == self.env.pos[j,:])
            #    print("quat", self.obs[str(j)]["state"][3:7] == self.env.quat[j,:])
            #    print("quat", self.obs[str(j)]["state"][4:7] , self.env.quat[j,:])
            #    print("ang", self.obs[str(j)]["state"][13:16] == self.env.ang_v[j,:])
            #    print("vel", self.obs[str(j)]["state"][10:13] == self.env.vel[j,:])
            #    print()
        msg.pose = pose_msg_arr
        msg.twist = twist_msg_arr
        self.publisher.publish(msg)
        self.simulation_loop()
        
    def controller_callback(self, msg):
        for i in range(self.num_drones):
            self.action[str(i)] = msg.rpm_swarm[i].rpm_drone
            print(i, msg.rpm_swarm[i].rpm_drone)

    def simulation_start(self,
            drone=DEFAULT_DRONES,
            physics=DEFAULT_PHYSICS,
            gui=DEFAULT_GUI,
            record_video=DEFAULT_RECORD_VISION,
            user_debug_gui=DEFAULT_USER_DEBUG_GUI,
            aggregate=DEFAULT_AGGREGATE,
            obstacles=DEFAULT_OBSTACLES,
            simulation_freq_hz=DEFAULT_SIMULATION_FREQ_HZ,
            control_freq_hz=DEFAULT_CONTROL_FREQ_HZ):
        #### Initialize the simulation #############################
        self.num_drones=DEFAULT_NUM_DRONES
        H = .1
        H_STEP = .05
        R = .3
        #self.INIT_XYZS = np.array([[R*np.cos((i/6)*2*np.pi+np.pi/2), R*np.sin((i/6)*2*np.pi+np.pi/2)-R, H+i*H_STEP] for i in range(self.num_drones)])
        #self.INIT_XYZS = np.zeros(self.num_drones * 3).reshape(self.num_drones, 3)
        self.INIT_RPYS = np.array([[0, 0,  i * (np.pi/2)/self.num_drones] for i in range(self.num_drones)])
        self.INIT_XYZS = np.array([[R*np.cos((i/6)*2*np.pi+np.pi/2), R*np.sin((i/6)*2*np.pi+np.pi/2)-R, 0] for i in range(self.num_drones)])
  
        #self.INIT_RPYS = np.array([[0, 0,  i * (np.pi/2)/self.num_drones] for i in range(self.num_drones)])

        #### Initialize a circular trajectory ######################
        PERIOD = 10
        self.NUM_WP = control_freq_hz*PERIOD

        self.env = CtrlAviary(drone_model=drone,
                        num_drones=self.num_drones,
                        initial_xyzs=self.INIT_XYZS,
                        initial_rpys=self.INIT_RPYS,
                        physics=physics,
                        neighbourhood_radius=10,
                        freq=simulation_freq_hz,
                        gui=gui,
                        record=record_video,
                        obstacles=obstacles,
                        user_debug_gui=user_debug_gui
                        )

        #### Obtain the PyBullet Client ID from the environment ####
        PYB_CLIENT = self.env.getPyBulletClient()
        

        #### Initialize the controllers ############################
        self.ctrl = [DSLPIDControl(drone_model=drone) for i in range(self.num_drones)]


        #### Run the simulation ####################################
        self.CTRL_EVERY_N_STEPS = int(np.floor(self.env.SIM_FREQ/control_freq_hz))
        self.action = {str(i): np.array([0,0,0,0]) for i in range(self.num_drones)}
        START = time.time()
        self.i = 0

        #for i in range(0, int(duration_sec*env.SIM_FREQ), AGGR_PHY_STEPS):
        
        
    def simulation_loop(self):
        self.obs, reward, done, info = self.env.step(self.action)

        #self.env.close()


def main(args=None):
    rclpy.init(args=args)

    simulation = SimulationExecuter()

    rclpy.spin(simulation)

    simulation.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()