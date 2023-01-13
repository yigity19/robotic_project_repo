## EB
## a1_answer.py
## 
## BLG456E Assignment 1 Skeleton
##
## Instructions: Change the scan_callback and odom_callback function to make the robot navigate to the goal
## using desired motion planning algorithm (Bug1 or Bug2). You may add helper functions to make code seem more clean, it would also
## help me to easily examine :))
## 
## Notes to consider: Few helper functions and code snippets are already given to you. Examine the code carefully beforehand.
##
## Extra: If you want to make use of the robot's mapping subsystem then you can
## make use of the map in the mapping_callback function.
##
## 
## STUDENT_ID:<150190107>
import rclpy
from rclpy.node import Node
import sys
from sensor_msgs.msg import LaserScan
from nav_msgs.msg import OccupancyGrid
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist
from tf2_ros.transform_listener import TransformListener
from tf2_ros.buffer import Buffer
from tf2_ros import TransformException
import math
from math import radians, degrees
from enum import Enum 
"""
HELPER FUNCTIONS
"""

ROT_THRESHOLD = 5
EULER_THRESHOLD = 0.20
DISTANCE_TO_LINE_THRESHOLD = 0.8
DISTANCE_TO_WALL_THRESHOLD = 0.8


def euler_from_quaternion(x, y, z, w):
        """
        Convert a quaternion into euler angles (roll, pitch, yaw)
        roll is rotation around x in radians (counterclockwise)
        pitch is rotation around y in radians (counterclockwise)
        yaw is rotation around z in radians (counterclockwise)
        """
        # DO NOT CHANGE HERE
        # DO NOT CHANGE HERE
        # DO NOT CHANGE HERE
        # DO NOT CHANGE HERE
        t0 = +2.0 * (w * x + y * z)
        t1 = +1.0 - 2.0 * (x * x + y * y)
        roll_x = math.atan2(t0, t1)
     
        t2 = +2.0 * (w * y - z * x)
        t2 = +1.0 if t2 > +1.0 else t2
        t2 = -1.0 if t2 < -1.0 else t2
        pitch_y = math.asin(t2)
     
        t3 = +2.0 * (w * z + x * y)
        t4 = +1.0 - 2.0 * (y * y + z * z)
        yaw_z = math.atan2(t3, t4)
     
        return roll_x, pitch_y, yaw_z # in radians
        
def convert_to_d(angle_r):
    return degrees(angle_r) + 180


class ROBOT_STATE_MACHINE(Enum):
    ON_LINE = 1
    WALL_FOLLOWING = 2    
    
class ROBOT_WALL_FOLLOWING_STATE_MACHINE(Enum):
    ROTATE_LEFT = 1
    KEEP_WALL_ON_RIGHT = 2
    KEEP_WALL_ON_RIGHT_TURN_RIGHT = 3
    WALL_FRONT = 4


class Navigator(Node):
    """
    Navigator node to make robot go from location A to B. 
    [IMPORTANT]
    IMPLEMENT YOUR CODES WITHIN THIS CLASS (You can define helper functions outside the class if you want)
    [IMPORTANT]
    """
    def __init__(self):
        super().__init__('a1_answer')
        self.subscription_scan = self.create_subscription(
            LaserScan,
            '/scan',
            self.scan_callback,
            10)
        self.subscription_map = self.create_subscription(
            OccupancyGrid,
            '/map',
            self.map_callback,
            10)
        self.subscription_odom = self.create_subscription(
            Odometry,
            '/odom',
            self.odom_callback,
            10)
        self.publish_twist = self.create_publisher(
            Twist,
            '/cmd_vel',
            10
        )
        self.tf_buffer = Buffer() # for transformation
        self.tf_listener = TransformListener(self.tf_buffer, self) # for transformation
        # DO NOT CHANGE self.goal!
        self.goal = {'x': -1,'y':-2} # DO NOT CHANGE! REFEREE EXECUTABLE WILL CHECK THIS GOAL!
        # DO NOT CHANGE self.goal!
        self.goal_dist_thld = 0.2 # max acceptable distance between robot and the goal
        
        ###################################
        self.f_dist = float('inf')
        self.r_dist = float('inf')
        self.l_dist = float('inf')
        self.b_dist = float('inf')
        
        self.x      = float('inf')
        self.y      = float('inf')
        self.yaw_d  = float('inf')
        ####################################
        self.line_equation_calculated = False
        self.eq_parameters = {}
        
        timer_period = 0.5 
        #self.timer = self.create_timer(timer_period, self.check_robot_environment)
        self.robot_state = ROBOT_STATE_MACHINE.ON_LINE
        self.wall_following_state = ROBOT_WALL_FOLLOWING_STATE_MACHINE.ROTATE_LEFT
        
        self.wall_tracking_target_angle = None
        self.wall_tracking_keep_angle = None
        
        self.turned_right_b = False
        self.turned_left_b = False
        self.left_turn_angle = float('inf')
        self.goal_x, self.goal_y = 0,0
        self.crosssed_the_wall_b = False
        
    def find_angle_of_right_dir(self, angle_d):
        if angle_d < 0:
            angle_d = 360 + angle_d
        if angle_d< 90 and angle_d >= 0:
            return 0
        elif angle_d < 180 and angle_d >= 90: 
            return 90
        elif angle_d < 270 and angle_d >= 180:
            return 180
        elif angle_d < 360 and angle_d >= 270:
            return 270
        
    def find_angle(self, angle_d):
        if angle_d< 45 and angle_d >= 0:
            return 0
        elif angle_d < 360 and angle_d >= 315:
            return 0
        elif angle_d < 135 and angle_d >= 45: 
            return 90
        elif angle_d < 225 and angle_d >= 135:
            return 180
        elif angle_d < 315 and angle_d >= 225:
            return 270
        
    def find_angle_of_left_dir(self, angle_d):
        if angle_d > 360:
            angle_d = angle_d - 360
        if angle_d< 90 and angle_d >= 0:
            return 90
        elif angle_d < 180 and angle_d >= 90: 
            return 180
        elif angle_d < 270 and angle_d >= 180:
            return 270
        elif angle_d < 360 and angle_d >= 270:
            return 0
        
    def assign_waypoint(self):
        angle_ = self.find_angle(self.yaw_d)
        MUCH = 1
        LESS = 0.4
        if angle_ == 90:
            print("///////////first case//////////////")
            print(self.x - MUCH, self.y - LESS)
            return self.x - MUCH, self.y - LESS
        elif angle_ == 0:
            print("///////////second case//////////////")
            print(self.x - LESS, self.y + MUCH)
            return self.x - LESS, self.y + MUCH
        elif angle_ == 180:
            print("///////////third case//////////////")
            print(self.x + LESS, self.y - MUCH)
            return self.x + LESS, self.y - MUCH
        elif angle_ == 270:
            print("///////////fourth case//////////////")
            print(self.x + MUCH, self.y + LESS)
            return self.x + MUCH, self.y + LESS
        #else:
        #    print("**********other conditions***************")
        #    pass
        #return 0, 0
                
    #def check_robot_environment(self):
    #    #print("checking robot environment")
    #    if self.check_wall():
    #        self.robot_state = ROBOT_STATE_MACHINE.WALL_FOLLOWING
    #    elif self.check_robot_on_line():
    #        self.robot_state = ROBOT_STATE_MACHINE.ON_LINE

    def find_angle_d(self, goal_x, goal_y):
        return convert_to_d(math.atan2(goal_y - self.y, goal_x - self.x))
    
    ### checks whether there is an wall ahead
    def check_wall_front(self):
        if self.f_dist < DISTANCE_TO_WALL_THRESHOLD:
            return True
        return False
    
    def check_wall_right(self):
        print("sağa uzaklık", self.r_dist)
        if self.r_dist < 1.3:
            return True
        return False

    def line_equation(self):
        self.eq_parameters['m'] = (self.goal['y'] - self.y) / (self.goal['x'] - self.x)
        self.eq_parameters['c'] = self.y - self.eq_parameters['m'] * self.x
        
    def check_robot_on_line(self):
        if 'm' in self.eq_parameters.keys():
            m = self.eq_parameters['m']  
            c = self.eq_parameters['c']
            #print(m,c)
            distance = abs(m * self.x - 1 * self.y + c) / math.sqrt(m**2 + 1)
            print("distance to line", distance )
            if distance < DISTANCE_TO_LINE_THRESHOLD:
                return True
            return False
        return True
    
    def scan_callback(self, msg):

        
        ###### CONSIDER THE POSSIBILITY OF RECEIVED ANGLES OF NOT BEING 360        
        self.f_dist = msg.ranges[0]
        self.r_dist = msg.ranges[269]
        self.l_dist = msg.ranges[89]
        self.b_dist = msg.ranges[179]
        ###################################################################
        
        if self.x != float('inf'):
            msg = self.state_machine()
            self.publish_twist.publish(msg) 
            
    def state_machine(self):
        msg = Twist()
        
        ### if robot is on the line which lies between the starting point and the goal point 
        if self.robot_state == ROBOT_STATE_MACHINE.ON_LINE:
            print("state 1")
            print("------------------------------------------------------------") 
            self.crosssed_the_wall_b = False
            if self.check_wall_front():
                self.robot_state = ROBOT_STATE_MACHINE.WALL_FOLLOWING
                    
            else:
                goal_x, goal_y = (self.goal['x'], self.goal['y'])
                angle_d = self.find_angle_d(goal_x = goal_x, goal_y = goal_y)
                msg = self.rotate(msg, angle_d)
                if msg.angular.z == float(0):
                    msg, _ = self.move(msg, goal_x, goal_y)
            return msg 
        
        ### if robot is encountered with an obstacle, follow the wall 
        elif self.robot_state == ROBOT_STATE_MACHINE.WALL_FOLLOWING:

            ### perform rotation to the right
            if self.wall_following_state == ROBOT_WALL_FOLLOWING_STATE_MACHINE.ROTATE_LEFT:
                ### 91 derece ile karşıya geldiği vakit hata oluyor yine 90 derece ile girmeye çalışıyor !!!!!!!!!!!!
                
                if self.turned_left_b == False:    ### if degree to the left is not calculated, calculate it 
                    self.wall_tracking_target_angle = self.find_angle_of_left_dir(self.yaw_d + 45)
                    print("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")
                    self.turned_left_b = True
                
                msg = self.rotate(msg, self.wall_tracking_target_angle) # rotate to the left 
                print("case 2.1 rotating left...")
                ### if yaw is close to the wall tracking target angle, change state of the robot to the keep wall on the left
                if msg.angular.z == float(0):#abs(self.yaw_d - self.wall_tracking_target_angle) < ROT_THRESHOLD: #type:ignore 
                    self.wall_following_state = ROBOT_WALL_FOLLOWING_STATE_MACHINE.KEEP_WALL_ON_RIGHT
                    
            
            elif self.wall_following_state == ROBOT_WALL_FOLLOWING_STATE_MACHINE.KEEP_WALL_ON_RIGHT:
                ### while wall in on the left, go on 
                if self.check_wall_right():
                    
                    msg = self.rotate(msg, self.find_angle(self.yaw_d))
                    
                    if msg.angular.z == float(0):
                        msg.linear.x = 0.8
                        
                    print("case 2.2 following the wall")
                    
                    if self.check_wall_front():
                        self.robot_state = ROBOT_STATE_MACHINE.ON_LINE
                        self.wall_following_state = ROBOT_WALL_FOLLOWING_STATE_MACHINE.ROTATE_LEFT
                        print("ooooooooooooooooooooooooooooooooooooooooooooooooooooooo")
                        self.turned_left_b = False
                        #msg = self.rotate(msg, self.find_angle_of_left_dir(self.yaw_d + 45))
                ### if wall is passed, turn left and go on slowly 
                else:
                    if self.check_robot_on_line():
                        self.robot_state = ROBOT_STATE_MACHINE.ON_LINE
                        self.wall_following_state = ROBOT_WALL_FOLLOWING_STATE_MACHINE.ROTATE_LEFT
                        self.turned_right_b = False
                        self.turned_left_b = False
                    else:
                        self.wall_following_state = ROBOT_WALL_FOLLOWING_STATE_MACHINE.KEEP_WALL_ON_RIGHT_TURN_RIGHT
                    
                    
            if self.wall_following_state == ROBOT_WALL_FOLLOWING_STATE_MACHINE.KEEP_WALL_ON_RIGHT_TURN_RIGHT:
                
                distance_to_wall = self.l_dist
                if self.turned_right_b == False:
                   self.left_turn_angle = self.find_angle_of_right_dir(self.yaw_d - 45) 
                   self.goal_x, self.goal_y = self.assign_waypoint()
                   msg.linear.x = float(0)
                   msg.angular.z = float(0)
                   #input()"
                   self.turned_right_b = True
                print("case 2.3 no wall, turn right")
                #self.wall_tracking_target_angle = self.left_turn_angle
                #if msg.angular.z == float(0) and abs(self.yaw_d - self.left_turn_angle) < 15:
                #   msg.linear.x = 0.2
                #   print("go slowly ")

                
                left_dir = self.find_angle_d(self.goal_x, self.goal_y)
                msg = self.rotate(msg, left_dir)
                print("rotating",self.goal_x, self.goal_y, self.yaw_d, left_dir)
                target_reached = False
                if msg.angular.z == float(0):
                    msg, target_reached = self.move(msg, self.goal_x, self.goal_y)
                    print("moving ", self.goal_x, self.goal_y) 
                    print("2.3.1, moving to the target point")

                if target_reached:
                    if self.check_wall_right:
                        self.wall_following_state = ROBOT_WALL_FOLLOWING_STATE_MACHINE.KEEP_WALL_ON_RIGHT
                    else:
                        print("sağda duvar yok, indetermined case-----------------------------------------------")

                    self.crosssed_the_wall_b = True
                    self.turned_right_b = False
                    
            if self.check_robot_on_line() and self.crosssed_the_wall_b:
                self.robot_state = ROBOT_STATE_MACHINE.ON_LINE
                self.wall_following_state = ROBOT_WALL_FOLLOWING_STATE_MACHINE.ROTATE_LEFT
                print("ıııııııııııııııııııııııııııııııııııııııı")
                self.turned_left_b = False
            print("******************************************************")
            return msg

    def rotate(self, msg, angle_d):
        angle_diff = abs(angle_d - self.yaw_d)
        if 360 - angle_diff < angle_diff:
            angle_diff = 360 - angle_diff
            
        if angle_diff < ROT_THRESHOLD:
            msg.angular.z = float(0)
            return msg
        K = 0.01
        MAX_ANGULAR_SPEED = 0.5
        if self.yaw_d > angle_d:
            if  abs(angle_d - self.yaw_d) < 180:
                msg.angular.z = -min(angle_diff* K, MAX_ANGULAR_SPEED) # negative speed 
            else:
                msg.angular.z = min(angle_diff* K, MAX_ANGULAR_SPEED) # positive speed 
        else:
            if abs(angle_d - self.yaw_d) < 180:
                msg.angular.z = min(angle_diff * K, MAX_ANGULAR_SPEED) # positive speed 
            else:
                msg.angular.z = -min(angle_diff * K, MAX_ANGULAR_SPEED) # negative speed 
        
        return msg
    
    ## Function to move robot to a desired point 
    def move(self, msg, goal_x, goal_y):
        distance_to_goal = math.sqrt((self.x - goal_x)**2 + (self.y - goal_y)**2)
        K = 0.25
        MAX_LINEAR_SPEED = float(0.7)
        if distance_to_goal > EULER_THRESHOLD:
            print("moving the robot distance: ", distance_to_goal)
            msg.linear.x = min(distance_to_goal * K, MAX_LINEAR_SPEED)
            return msg, False
        else:
            print("stopped", distance_to_goal)
            msg.linear.x = float(0)
            return msg, True            

    ######################################################################################################################
    ######################################################################################################################
    ######################################################################################################################
    def map_callback(self, msg):

        chatty_map = False # change to true if you want to examine the map in a compressed way (shrinked to fit into terminal)
        if chatty_map:
            print ("-------MAP---------")
            ## Here x and y has been incremented with five to make it fit in the terminal
            ## Note that we have lost some map information by shrinking the data
            for x in range(0,msg.info.width-1,5):
                for y in range(0,msg.info.height-1,5):
                    index = x+y*msg.info.width
                    if msg.data[index] > 50:
                        ## This square is occupied
                        sys.stdout.write('X')
                    elif msg.data[index] >= 0:
                        ## This square is unoccupied
                        sys.stdout.write(' ')
                    else:
                        sys.stdout.write('?')
                sys.stdout.write('\n')
            sys.stdout.flush()
            print ("-------------------")
        pass
   
    def odom_callback(self, msg):
        global robotX # global keyword makes the variable accessable even outside the function!
        global robotY # global keyword makes the variable accessable even outside the function!
        global robotX_tf # global keyword makes the variable accessable even outside the function!
        global robotY_tf # global keyword makes the variable accessable even outside the function!
        global robot_yaw # global keyword makes the variable accessable even outside the function!

        
        robotX = msg.pose.pose.position.x
        robotY = msg.pose.pose.position.y
        
        to_frame_rel = "odom"
        from_frame_rel = "base_footprint"
        try:
            # grab the latest available transform from the odometry frame 
            # (robot's original location - usually the same as the map unless the odometry becomes inaccurate) to the robot's base.
            t = self.tf_buffer.lookup_transform(
                to_frame_rel,
                from_frame_rel,
                rclpy.time.Time())
        except TransformException as ex:
            self.get_logger().info(
                f'Could not transform {to_frame_rel} to {from_frame_rel}: {ex}')
            return

        # Convert the quaternion-based orientation of the latest message to Euler representation in order to get z axis rotation
        _,_,robot_orient_z = euler_from_quaternion(t.transform.rotation.x,t.transform.rotation.y,t.transform.rotation.z,t.transform.rotation.w)
        robotX_tf = self.x = t.transform.translation.x
        robotY_tf = self.y = t.transform.translation.y
        robot_yaw = robot_orient_z # # only need the z axis, degree of orientation, between pi and -pi
        self.yaw_d = convert_to_d(robot_yaw)

        if self.line_equation_calculated == False:
            self.line_equation()
            self.line_equation_calculated = True
            
        #self.get_logger().info('X:'+str(robotX_tf),throttle_duration_sec=0.5) # once at a half of a second
        #self.get_logger().info('Y:'+str(robotY_tf),throttle_duration_sec=0.5) # once at a half of a second
        #self.get_logger().info('Yaw:'+str(robot_yaw),throttle_duration_sec=0.5) # once at a half of a second

def main(args=None):
    # DO NOT CHANGE HERE
    # DO NOT CHANGE HERE
    # DO NOT CHANGE HERE
    # DO NOT CHANGE HERE
    rclpy.init(args=args)

    navigator_node = Navigator()
    rclpy.spin(navigator_node) 

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
   
    
    navigator_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
