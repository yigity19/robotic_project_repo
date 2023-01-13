"""Script demonstrating the joint use of simulation and control.

The simulation is run by a `CtrlAviary` or `VisionAviary` environment.
The control is given by the PID implementation in `DSLPIDControl`.

Example
-------
In a terminal, run as:

    $ python fly.py

Notes
-----
The drones move, at different altitudes, along cicular trajectories 
in the X-Y plane, around point (0, -.3).

"""
import os
import time
import argparse
from datetime import datetime
import pdb
import math
import random
import numpy as np
import pybullet as p
import matplotlib.pyplot as plt

import rclpy
from rclpy.node import Node
from std_msgs.msg import String

from gym_pybullet_drones.utils.enums import DroneModel, Physics
from gym_pybullet_drones.envs.CtrlAviary import CtrlAviary
from gym_pybullet_drones.envs.VisionAviary import VisionAviary
from gym_pybullet_drones.control.DSLPIDControl import DSLPIDControl
from gym_pybullet_drones.control.SimplePIDControl import SimplePIDControl
from gym_pybullet_drones.utils.Logger import Logger
from gym_pybullet_drones.utils.utils import sync, str2bool

DEFAULT_DRONES = DroneModel("cf2x")
DEFAULT_NUM_DRONES = 5
DEFAULT_PHYSICS = Physics("pyb")
DEFAULT_VISION = False
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

class SimulationExecuter(Node):
    def __init__(self):
        super().__init__("simulation_executer")
        self.subscription = self.create_subscription(String,'topic',self.listener_callback,10)
        
    def listener_callback(self, msg):
        print("fly çalışıyor")

    def run(
            drone=DEFAULT_DRONES,
            num_drones=DEFAULT_NUM_DRONES,
            physics=DEFAULT_PHYSICS,
            vision=DEFAULT_VISION,
            gui=DEFAULT_GUI,
            record_video=DEFAULT_RECORD_VISION,
            plot=DEFAULT_PLOT,
            user_debug_gui=DEFAULT_USER_DEBUG_GUI,
            aggregate=DEFAULT_AGGREGATE,
            obstacles=DEFAULT_OBSTACLES,
            simulation_freq_hz=DEFAULT_SIMULATION_FREQ_HZ,
            control_freq_hz=DEFAULT_CONTROL_FREQ_HZ,
            duration_sec=DEFAULT_DURATION_SEC,
            output_folder=DEFAULT_OUTPUT_FOLDER,
            colab=DEFAULT_COLAB
            ):
        #### Initialize the simulation #############################
        H = .1
        H_STEP = .05
        R = .3
        INIT_XYZS = np.array([[R*np.cos((i/6)*2*np.pi+np.pi/2), R*np.sin((i/6)*2*np.pi+np.pi/2)-R, H+i*H_STEP] for i in range(num_drones)])
        INIT_RPYS = np.array([[0, 0,  i * (np.pi/2)/num_drones] for i in range(num_drones)])
        AGGR_PHY_STEPS = int(simulation_freq_hz/control_freq_hz) if aggregate else 1

        #### Initialize a circular trajectory ######################
        PERIOD = 10
        NUM_WP = control_freq_hz*PERIOD
        TARGET_POS = np.zeros((NUM_WP,3))
        for i in range(NUM_WP):
            TARGET_POS[i, :] = R*np.cos((i/NUM_WP)*(2*np.pi)+np.pi/2)+INIT_XYZS[0, 0], R*np.sin((i/NUM_WP)*(2*np.pi)+np.pi/2)-R+INIT_XYZS[0, 1], 0
        wp_counters = np.array([int((i*NUM_WP/6)%NUM_WP) for i in range(num_drones)])

        #### Debug trajectory ######################################
        #### Uncomment alt. target_pos in .computeControlFromState()
        #INIT_XYZS = np.array([[.3 * i, 0, .1] for i in range(num_drones)])
        #INIT_RPYS = np.array([[0, 0,  i * (np.pi/3)/num_drones] for i in range(num_drones)])
        #NUM_WP = control_freq_hz*15
        #TARGET_POS = np.zeros((NUM_WP,3))
        #for i in range(NUM_WP):
        #    if i < NUM_WP/6:
        #        TARGET_POS[i, :] = (i*6)/NUM_WP, 0, 0.5*(i*6)/NUM_WP
        #    elif i < 2 * NUM_WP/6:
        #        TARGET_POS[i, :] = 1 - ((i-NUM_WP/6)*6)/NUM_WP, 0, 0.5 - 0.5*((i-NUM_WP/6)*6)/NUM_WP
        #    elif i < 3 * NUM_WP/6:
        #        TARGET_POS[i, :] = 0, ((i-2*NUM_WP/6)*6)/NUM_WP, 0.5*((i-2*NUM_WP/6)*6)/NUM_WP
        #    elif i < 4 * NUM_WP/6:
        #        TARGET_POS[i, :] = 0, 1 - ((i-3*NUM_WP/6)*6)/NUM_WP, 0.5 - 0.5*((i-3*NUM_WP/6)*6)/NUM_WP
        #    elif i < 5 * NUM_WP/6:
        #        TARGET_POS[i, :] = ((i-4*NUM_WP/6)*6)/NUM_WP, ((i-4*NUM_WP/6)*6)/NUM_WP, 0.5*((i-4*NUM_WP/6)*6)/NUM_WP
        #    elif i < 6 * NUM_WP/6:
        #        TARGET_POS[i, :] = 1 - ((i-5*NUM_WP/6)*6)/NUM_WP, 1 - ((i-5*NUM_WP/6)*6)/NUM_WP, 0.5 - 0.5*((i-5*NUM_WP/6)*6)/NUM_WP
        #wp_counters = np.array([0 for i in range(num_drones)])
        #### Create the environment with or without video capture ##
        if vision: 
            env = VisionAviary(drone_model=drone,
                            num_drones=num_drones,
                            initial_xyzs=INIT_XYZS,
                            initial_rpys=INIT_RPYS,
                            physics=physics,
                            neighbourhood_radius=10,
                            freq=simulation_freq_hz,
                            aggregate_phy_steps=AGGR_PHY_STEPS,
                            gui=gui,
                            record=record_video,
                            obstacles=obstacles
                            )
        else: 
            env = CtrlAviary(drone_model=drone,
                            num_drones=num_drones,
                            initial_xyzs=INIT_XYZS,
                            initial_rpys=INIT_RPYS,
                            physics=physics,
                            neighbourhood_radius=10,
                            freq=simulation_freq_hz,
                            aggregate_phy_steps=AGGR_PHY_STEPS,
                            gui=gui,
                            record=record_video,
                            obstacles=obstacles,
                            user_debug_gui=user_debug_gui
                            )

        #### Obtain the PyBullet Client ID from the environment ####
        PYB_CLIENT = env.getPyBulletClient()
        

        #### Initialize the controllers ############################
        if drone in [DroneModel.CF2X, DroneModel.CF2P]:
            ctrl = [DSLPIDControl(drone_model=drone) for i in range(num_drones)]
        elif drone in [DroneModel.HB]:
            ctrl = [SimplePIDControl(drone_model=drone) for i in range(num_drones)]

        #### Run the simulation ####################################
        CTRL_EVERY_N_STEPS = int(np.floor(env.SIM_FREQ/control_freq_hz))
        action = {str(i): np.array([0,0,0,0]) for i in range(num_drones)}
        START = time.time()
        i = 0
        #for i in range(0, int(duration_sec*env.SIM_FREQ), AGGR_PHY_STEPS):
        while True:
            
            #### Make it rain rubber ducks #############################
            #if i/env.SIM_FREQ>5 and i%10==0 and i/env.SIM_FREQ<10: p.loadURDF("duck_vhacd.urdf", [0+random.gauss(0, 0.3),-0.5+random.gauss(0, 0.3),3], p.getQuaternionFromEuler([random.randint(0,360),random.randint(0,360),random.randint(0,360)]), physicsClientId=PYB_CLIENT)

            #### Step the simulation ###################################
            
            obs, reward, done, info = env.step(action)

            #### Compute control at the desired frequency ##############
            if i%CTRL_EVERY_N_STEPS == 0:

                #### Compute control for the current way point #############
                ### burada hazır kontrolcü kullanılıyor 
                ### action bir tane sözlük aslında, burada döndürdüğü şey tam 
                for j in range(num_drones):
                    action[str(j)], _, _ = ctrl[j].computeControlFromState(control_timestep=CTRL_EVERY_N_STEPS*env.TIMESTEP,
                                                                        state=obs[str(j)]["state"],
                                                                        target_pos=np.hstack([TARGET_POS[wp_counters[j], 0:2], INIT_XYZS[j, 2]]),
                                                                        #target_pos=INIT_XYZS[j, :] + TARGET_POS[wp_counters[j], :],
                                                                        target_rpy=INIT_RPYS[j, :]
                                                                        )

                #### Go to the next way point and loop #####################
                for j in range(num_drones): 
                    wp_counters[j] = wp_counters[j] + 1 if wp_counters[j] < (NUM_WP-1) else 0

            #### her bir drone için istenebilecek değerler aşağıda yer almakta 
            #for j in range(num_drones):
            #    print("drone x,y,z",j, env.pos[j, :])
            #    print("drone vel",i, env.vel[j, :])
            #    print("drone angular vel", i, env.vel[j, :])
            #    print("drone ", i, env.ang_v[j, :])
            #    print("drone ", j, env.rpy[j, :])

            #### 
            #if gui:
            #    sync(i, START, env.TIMESTEP)
            i += AGGR_PHY_STEPS

        #### Close the environment #################################
        env.close()


def main(args=None):
    rclpy.init(args=args)

    simulation = SimulationExecuter()

    rclpy.spin(simulation)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    simulation.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()