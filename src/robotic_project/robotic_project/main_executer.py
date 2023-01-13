import rclpy
import numpy as np
from rclpy.node import Node
from gym_pybullet_drones.utils.enums import DroneModel, Physics
from gym_pybullet_drones.control.DSLPIDControl import DSLPIDControl
from custom_messages_pkg.msg import SwarmPose, DroneRPM, SwarmRPM

DEFAULT_DRONES = DroneModel("cf2x")
DEFAULT_NUM_DRONES = 2
DEFAULT_PHYSICS = Physics("pyb")
DEFAULT_SIMULATION_FREQ_HZ = 240
DEFAULT_CONTROL_FREQ_HZ = 48
DEFAULT_CONTROL_PERIOD = 1 / DEFAULT_CONTROL_FREQ_HZ
DEFAULT_SIMULATION_PERIOD = 1 / DEFAULT_SIMULATION_FREQ_HZ


class MainExecuter(Node):
    def __init__(self):
        super().__init__("main_executer")
        self.drone_positions = []
        self.main_start()
        self.subscription = self.create_subscription(SwarmPose,'swarm_pose',self.swarm_pose_sub, 10)
        self.publisher = self.create_publisher(SwarmRPM, 'swarm_commands', 10) # CHANGE
        self.timer = self.create_timer(DEFAULT_CONTROL_PERIOD, self.timer_callback)
        self.state = None
        
    def generate_waypoint(self, target, current):
        waypoint_count = DEFAULT_SIMULATION_FREQ_HZ * 15
        diff = (target - current) / waypoint_count
        
    def calculate_error(self, target_pose):
        drone_pose = np.array(self.drone_position)
        error = np.average(np.square(drone_pose - target_pose))
        return error 
    
    def timer_callback(self):
        msg = self.main_loop()
        if msg is not None:
            self.publisher.publish(msg)
        else:
            print("mesaj is none")
    
    
    def swarm_pose_sub(self, msg):
        whole_msg = []
        # her bir drone için hesaplanacak şeyler burada çalışabilir aslında 
        for i in range(len(msg.pose)):    
            full_msg = []
            full_msg.append(msg.pose[i].position.x)
            full_msg.append(msg.pose[i].position.y)
            full_msg.append(msg.pose[i].position.z)
            full_msg.append(msg.pose[i].orientation.x)
            full_msg.append(msg.pose[i].orientation.y)
            full_msg.append(msg.pose[i].orientation.z)
            full_msg.append(msg.pose[i].orientation.w)
            full_msg.append(0)
            full_msg.append(0)
            full_msg.append(0)
            full_msg.append(msg.twist[i].linear.x)
            full_msg.append(msg.twist[i].linear.y)
            full_msg.append(msg.twist[i].linear.z)
            full_msg.append(msg.twist[i].angular.x)
            full_msg.append(msg.twist[i].angular.y)
            full_msg.append(msg.twist[i].angular.z)
            whole_msg.append(full_msg)
        self.state = whole_msg
    
    def main_start(self,):
        #### Initialize the simulation #############################
        self.num_drones=DEFAULT_NUM_DRONES
        H = .1
        H_STEP = .05
        R = .3
        self.INIT_RPYS = np.array([[0, 0,  i * (np.pi/2)/self.num_drones] for i in range(self.num_drones)])
        self.INIT_XYZS = np.array([[R*np.cos((i/6)*2*np.pi+np.pi/2), R*np.sin((i/6)*2*np.pi+np.pi/2)-R, 0] for i in range(self.num_drones)])
  
        #### Initialize a circular trajectory ######################
        control_freq_hz = DEFAULT_CONTROL_FREQ_HZ
        PERIOD = 10
        self.NUM_WP = control_freq_hz*PERIOD
        self.target_positions = {}
        for j in range(self.num_drones):
            TARGET_POS = np.zeros((self.NUM_WP,3))
            for i in range(self.NUM_WP):
                #self.TARGET_POS[i, :] = R*np.cos((i/self.NUM_WP)*(2*np.pi)+np.pi/2)+self.INIT_XYZS[0, 0], R*np.sin((i/self.NUM_WP)*(2*np.pi)+np.pi/2)-R+self.INIT_XYZS[0, 1],  i / self.NUM_WP
                TARGET_POS[i, :] = self.INIT_XYZS[j, 0], self.INIT_XYZS[j, 1], i / self.NUM_WP
            self.target_positions[str(j)] = TARGET_POS

            
        self.wp_counters = np.array([int((i*self.NUM_WP/6)%self.NUM_WP) for i in range(self.num_drones)])

        ##self.INIT_XYZS = np.zeros(self.num_drones * 3).reshape(self.num_drones++, 3)
        ##
        ##sqrt_num_drones = int(np.sqrt(self.num_drones))
        ##for i in range(sqrt_num_drones):
        ##    for j in range(sqrt_num_drones):
        ##        self.INIT_XYZS[i * sqrt_num_drones + j] = i,j,0.1"
        ##self.INIT_XYZS[:,0:2] -= sqrt_num_drones / 2
        
        #### Initialize the controllers ############################
        self.ctrl = [DSLPIDControl(drone_model=DEFAULT_DRONES) for i in range(self.num_drones)]

        #### Run the simulation ####################################
        self.CTRL_EVERY_N_STEPS = int(np.floor(DEFAULT_SIMULATION_FREQ_HZ/control_freq_hz))
        
    def main_loop(self):
        if self.state is not None:
            swarm_rpm = SwarmRPM()
            swarm_rpm_list = []
            for j in range(self.num_drones):
                rpm_msg = DroneRPM()
                rpm_msg.rpm_drone, _, _ = self.ctrl[j].computeControlFromState(control_timestep=self.CTRL_EVERY_N_STEPS*DEFAULT_SIMULATION_PERIOD,
                                                            state= self.state[j],
                                                            target_pos= self.target_positions[str(j)][self.wp_counters[j]],#np.hstack([self.TARGET_POS[self.wp_counters[j], 0:2], self.INIT_XYZS[j, 2]]),
                                                            #target_pos= self.INIT_XYZS[j, :] + self.TARGET_POS[self.wp_counters[j], :],
                                                            target_rpy=self.INIT_RPYS[j, :]
                                                            )
                swarm_rpm_list.append(rpm_msg)
            swarm_rpm.rpm_swarm = swarm_rpm_list 
            for j in range(self.num_drones): 
                self.wp_counters[j] = self.wp_counters[j] + 1 if self.wp_counters[j] < (self.NUM_WP-1) else 0
            return swarm_rpm
        else:
            return None 
        #self.env.close()


def main(args=None):
    rclpy.init(args=args)

    main_executer = MainExecuter()

    rclpy.spin(main_executer)

    rclpy.shutdown()

if __name__ == "__main__":
    main()