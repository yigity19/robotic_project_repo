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
from geometry_msgs.msg import Twist, PoseArray, Pose, PoseStamped

from gym_pybullet_drones.utils.enums import DroneModel, Physics
from gym_pybullet_drones.envs.CtrlAviary import CtrlAviary
from gym_pybullet_drones.envs.VisionAviary import VisionAviary
from gym_pybullet_drones.control.DSLPIDControl import DSLPIDControl
from gym_pybullet_drones.control.SimplePIDControl import SimplePIDControl
from gym_pybullet_drones.utils.Logger import Logger
from gym_pybullet_drones.utils.utils import sync, str2bool

from custom_messages_pkg.mgs import CustomCommand

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
        self.simulation_start()
        self.subscription = self.create_subscription(Twist,'topic',self.simulation_loop,10)
        print("çalıştı")
        exit()
    def listener_callback(self, msg):
        print("fly çalışıyor", msg)

    def simulation_start(self,
            drone=DEFAULT_DRONES,
            
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
        self.num_drones=DEFAULT_NUM_DRONES
        H = .1
        H_STEP = .05
        R = .3
        self.INIT_XYZS = np.array([[R*np.cos((i/6)*2*np.pi+np.pi/2), R*np.sin((i/6)*2*np.pi+np.pi/2)-R, H+i*H_STEP] for i in range(self.num_drones)])
        self.INIT_RPYS = np.array([[0, 0,  i * (np.pi/2)/self.num_drones] for i in range(self.num_drones)])
        self.AGGR_PHY_STEPS = int(simulation_freq_hz/control_freq_hz) if aggregate else 1

        #### Initialize a circular trajectory ######################
        PERIOD = 10
        self.NUM_WP = control_freq_hz*PERIOD
        self.TARGET_POS = np.zeros((self.NUM_WP,3))
        for i in range(self.NUM_WP):
            self.TARGET_POS[i, :] = R*np.cos((i/self.NUM_WP)*(2*np.pi)+np.pi/2)+self.INIT_XYZS[0, 0], R*np.sin((i/self.NUM_WP)*(2*np.pi)+np.pi/2)-R+self.INIT_XYZS[0, 1], 0
        self.wp_counters = np.array([int((i*self.NUM_WP/6)%self.NUM_WP) for i in range(self.num_drones)])


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
        if drone in [DroneModel.CF2X, DroneModel.CF2P]:
            self.ctrl = [DSLPIDControl(drone_model=drone) for i in range(self.num_drones)]
        elif drone in [DroneModel.HB]:
            self.ctrl = [SimplePIDControl(drone_model=drone) for i in range(self.num_drones)]

        #### Run the simulation ####################################
        self.CTRL_EVERY_N_STEPS = int(np.floor(self.env.SIM_FREQ/control_freq_hz))
        self.action = {str(i): np.array([0,0,0,0]) for i in range(self.num_drones)}
        START = time.time()
        self.i = 0
        #for i in range(0, int(duration_sec*env.SIM_FREQ), AGGR_PHY_STEPS):
        
        
    def simulation_loop(self, msg):
        obs, reward, done, info = self.env.step(self.action)
        
        #### Compute control at the desired frequency ##############
        if self.i%self.CTRL_EVERY_N_STEPS == 0:

            #### Compute control for the current way point #############
            ### burada hazır kontrolcü kullanılıyor 
            ### action bir tane sözlük aslında, burada döndürdüğü şey tam 
            for j in range(self.num_drones):
                pass
                #self.action[str(j)], _, _ = #self.ctrl[j].computeControlFromState(control_timestep=self.CTRL_EVERY_N_STEPS*self.env.TIMESTEP,
                                            #                state=obs[str(j)]["state"],
                                            #                target_pos=np.hstack([self.TARGET_POS[self.wp_counters[j], 0:2], self.INIT_XYZS[j, 2]]),
                                            #                #target_pos=INIT_XYZS[j, :] + TARGET_POS[wp_counters[j], :],
                                            #                target_rpy=self.INIT_RPYS[j, :]
                                            #                )

            for j in range(self.num_drones): 
                self.wp_counters[j] = self.wp_counters[j] + 1 if self.wp_counters[j] < (self.NUM_WP-1) else 0

        self.i += self.AGGR_PHY_STEPS

        #self.env.close()


def main(args=None):
    rclpy.init(args=args)

    simulation = SimulationExecuter()

    rclpy.spin(simulation)

    simulation.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()