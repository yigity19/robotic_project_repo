## EB
## waypoint_follower.py
## 
## BLG456E Assignment 2 Skeleton
## 
## Notes to consier: Few helper functions and code snippets are already given to you. Examine the code carefully beforehand.
##
## If you want to make use of the map, use occupancy_grid variable.
##
## 
## STUDENT_ID:<150190107>
import rclpy
from rclpy.node import Node
import sys
from sensor_msgs.msg import LaserScan
from nav_msgs.msg import OccupancyGrid
from nav_msgs.msg import Odometry
from nav_msgs.srv import GetMap
from geometry_msgs.msg import Twist, PoseArray, PoseStamped, Pose
from tf2_ros.transform_listener import TransformListener
from tf2_ros.buffer import Buffer
from tf2_ros import TransformException
#######################################################################
from math import degrees, radians, sqrt, atan2, asin 
from enum import Enum
"""
HELPER FUNCTIONS
"""

ROT_THRESHOLD = 5
EULER_THRESHOLD = 0.20
DISTANCE_TO_LINE_THRESHOLD = 0.8
DISTANCE_TO_WALL_THRESHOLD = 0.4

class ROBOT_STATE_MACHINE(Enum):
    WAYPOINT_FOLLOWING = 1
    WALL_FOLLOWING = 2    
    ON_LINE = 3
    
class ROBOT_WALL_FOLLOWING_STATE_MACHINE(Enum):
    ROTATE_RIGHT = 1
    KEEP_WALL_ON_LEFT = 2
    KEEP_WALL_ON_LEFT_TURN_LEFT = 3
    WALL_FRONT = 4

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
        roll_x = atan2(t0, t1)
     
        t2 = +2.0 * (w * y - z * x)
        t2 = +1.0 if t2 > +1.0 else t2
        t2 = -1.0 if t2 < -1.0 else t2
        pitch_y = asin(t2)
     
        t3 = +2.0 * (w * z + x * y)
        t4 = +1.0 - 2.0 * (y * y + z * z)
        yaw_z = atan2(t3, t4)
     
        return roll_x, pitch_y, yaw_z # in radians
        
def convert_to_d(angle_r):
    return degrees(angle_r) + 180

class Navigator(Node):
    """
    Navigator node to make robot go from location A to B. 
    [IMPORTANT]
    IMPLEMENT YOUR CODES WITHIN THIS CLASS (You can define helper functions outside the class if you want)
    [IMPORTANT]
    """
    def __init__(self):
        super().__init__('waypoint_follower')
        self.subscription_scan = self.create_subscription(
            LaserScan,
            '/scan',
            self.scan_callback,
            10)
        self.subscription_odom = self.create_subscription(
            Odometry,
            '/odom',
            self.odom_callback,
            10)
        self.sub_route1 = self.create_subscription(
            PoseArray,
            '/route1',
            self.set_route1,
            10,
        )# subscribe first route
        self.sub_route2 = self.create_subscription(
            PoseArray,
            '/route2',
            self.set_route2,
            10
        ) # subscribe second route
        self.subscription_waypoint = self.create_subscription(
            PoseStamped,
            '/waypoint',
            self.waypoint_callback,
            10) # subscribe next waypoint
        self.publish_twist = self.create_publisher(
            Twist,
            '/cmd_vel',
            10
        )
        self.cli = self.create_client(GetMap, '/map_server/map')
        #/map_server/map
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = GetMap.Request()
        
        ### MAP ###
        self.occupancy_grid = [] # OCCUPANCY GRID MESSAGE VARIABLE. You can also use this knowledge
                                # to handle obstacle.
        self.map_origin = Pose() # origin as a Pose type.
        self.map_width = 0 # width
        self.map_height = 0 # height
        self.map_resolution = 0 # size of each grid cell
        ###     ###
        self.tf_buffer = Buffer() # for transformation
        self.tf_listener = TransformListener(self.tf_buffer, self) # for transformation
        self.goal_dist_thld = 0.2 # max acceptable distance between robot and the goal
        self.is_route1_set= 0 # 0 or 1, if 1 route1 is acquired by the topic
        self.is_route2_set = 0 # 0 or 1, if 1 route2 is acquired by the topic
        self.route1 = PoseArray() # route1
        self.route2 = PoseArray() # route2
        self.waypoint = PoseStamped() # next wayoint
        self.prev_distance = 0
        self.chatty_map = False # you may set chatty_map to true if you want to see map on the terminal
        ###############################################################################################
        self.f_dist = float('inf')
        self.r_dist = float('inf')
        self.l_dist = float('inf')
        self.b_dist = float('inf')
        
        self.x      = float('inf')
        self.y      = float('inf')
        self.yaw_d  = float('inf')
        
        self.route1_wp_index = 0
        self.route1_completed = False

        self.route2_wp_index = 0
        self.route2_completed = False
        
        self.robot_state = ROBOT_STATE_MACHINE.WAYPOINT_FOLLOWING
        self.wall_following_state = ROBOT_WALL_FOLLOWING_STATE_MACHINE.ROTATE_RIGHT
        
        self.crosssed_the_wall_b = False
        self.turned_right_b = False
        
    def send_request(self):
        
        self.future = self.cli.call_async(self.req)
    def set_route1(self, msg):
        if (self.is_route1_set == 0):
            self.route1 = msg
            self.is_route1_set = 1
        else:
            pass
        print("target 1: ", msg.poses[0].position.x)
        print("\n")

    def set_route2(self, msg):
        if (self.is_route2_set == 0):
            self.route2 = msg
            self.is_route2_set = 1
        else:
            pass
    def waypoint_callback(self,msg):
        self.waypoint = msg
    def scan_callback(self, msg):
        self.f_dist = msg.ranges[0]
        self.r_dist = msg.ranges[269]
        self.l_dist = msg.ranges[89]
        self.b_dist = msg.ranges[179]

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
        #############################################################################################
        robotX_tf = self.x = t.transform.translation.x
        robotY_tf = self.y = t.transform.translation.y
        robot_yaw = robot_orient_z # # only need the z axis, degree of orientation, between pi and -pi
        ##############################################################################################
        self.yaw_d = convert_to_d(robot_yaw)
        
        #self.get_logger().info('X:'+str(robotX_tf),throttle_duration_sec=0.5) # once at a half of a second
        #self.get_logger().info('Y:'+str(robotY_tf),throttle_duration_sec=0.5) # once at a half of a second
        #self.get_logger().info('Yaw:'+str(robot_yaw),throttle_duration_sec=0.5) # once at a half of a second

        # TURTLEBOT: I HAVE NO CLUE, WHICH INFORMATION SHOULD I DEPEND FOR INTELLIGENT WAYPOINT FOLLOWING? HELP ME MY FELLOW ENGINEER! 
        # TURTLEBOT: I HAVE NO CLUE, WHICH INFORMATION SHOULD I DEPEND FOR INTELLIGENT WAYPOINT FOLLOWING? HELP ME MY FELLOW ENGINEER! 
        # Twist is a type of ROS Message that enables us to send velocity commands to the robot
        velocity_vec = Twist()
        ################################################################################
        ### ROBOT FOLLOWING ROUTE 1 and WAYPOINTS ARE NOT  CORRUPTED
        if self.is_route1_set and self.route1_completed == False:
            target_x = self.route1.poses[self.route1_wp_index].position.x
            target_y = self.route1.poses[self.route1_wp_index].position.y
            target_angle = self.find_angle_d(target_x, target_y)
            velocity_vec = self.rotate(velocity_vec, target_angle)
            velocity_vec, reached = self.move(velocity_vec, target_x, target_y)
            if reached:
                self.route1_wp_index += 1
            if self.route1_wp_index == len(self.route1.poses):
                self.route1_completed = True
            self.publish_twist.publish(velocity_vec) # publish twist message through cmd_vel topic
        
        ### ROBOT FOLLOWING ROUTE2 and WAYPOINT ARE CORRUPTED DUE TO THE MAP CHANGE
        if self.route1_completed == True and self.is_route2_set:
            if self.check_wall_front():
                print("oh there is an obstacle in front of me, where are you my fellow engineer???")
                velocity_vec.angular.z = float(0)
                velocity_vec.linear.x = float(0)
                self.publish_twist.publish(velocity_vec)
                self.robot_state = ROBOT_STATE_MACHINE.WALL_FOLLOWING
                
                
            if self.robot_state == ROBOT_STATE_MACHINE.WAYPOINT_FOLLOWING:
                
                target_x = self.route2.poses[self.route2_wp_index].position.x
                target_y = self.route2.poses[self.route2_wp_index].position.y
                target_angle = self.find_angle_d(target_x, target_y)
                velocity_vec = self.rotate(velocity_vec, target_angle)
                velocity_vec, reached = self.move(velocity_vec, target_x, target_y)
                if reached:
                    self.route2_wp_index += 1
                if self.route2_wp_index == len(self.route2.poses):
                    self.route2_completed = True
                self.publish_twist.publish(velocity_vec) # publish twist message through cmd_vel topic
            
            elif self.robot_state == ROBOT_STATE_MACHINE.WALL_FOLLOWING:
                target_x = self.route2.poses[self.route2_wp_index].position.x
                target_y = self.route2.poses[self.route2_wp_index].position.y
                msg_twist = self.state_machine(target_x, target_y)
                print("here I am", msg_twist)
                self.publish_twist.publish(msg_twist)
        
        if (self.chatty_map):
            # you may set chatty_map to true if you want to see map on the terminal
            # map is only acquired for once and does not change since then.
            self.get_logger().info(str(self.occupancy_grid))
            self.get_logger().info("Length of the map array:" + str(len(self.occupancy_grid)))
            self.get_logger().info("Height:" + str(self.map_height) + " Width:"+ str(self.map_height))
            self.get_logger().info("Origin of the map (Cell 0,0):" + str(self.map_origin))
            self.get_logger().info("Resolution (Size of each grid cell):" + str(self.map_resolution))

            self.chatty_map = False # avoid repetitive printing.
            
    def state_machine(self, target_x, target_y):
        msg = Twist()
        ### if robot is encountered with an obstacle, follow the wall 
        #if self.robot_state == ROBOT_STATE_MACHINE.WALL_FOLLOWING:
        ### perform rotation to the right
        if self.wall_following_state == ROBOT_WALL_FOLLOWING_STATE_MACHINE.ROTATE_RIGHT:
            if self.turned_right_b == False:    ### if degree to the left is not calculated, calculate it 
                self.wall_tracking_target_angle = self.find_angle_of_right_dir(self.yaw_d - 45)
                self.turned_right_b = True
                print("turning right ++++++++++++++++++++++++++++++++++++")
            
            msg = self.rotate(msg, self.wall_tracking_target_angle) # rotate to the left 
            print("case 2.1 rotating right...")
            ### if yaw is close to the wall tracking target angle, change state of the robot to the keep wall on the left
            if msg.angular.z == float(0):#abs(self.yaw_d - self.wall_tracking_target_angle) < ROT_THRESHOLD: #type:ignore 
                self.wall_following_state = ROBOT_WALL_FOLLOWING_STATE_MACHINE.KEEP_WALL_ON_LEFT
                
        
        elif self.wall_following_state == ROBOT_WALL_FOLLOWING_STATE_MACHINE.KEEP_WALL_ON_LEFT:
            ### while wall in on the left, go on 
            if self.check_wall_left():
                
                msg = self.rotate(msg, self.find_angle(self.yaw_d))
                
                if msg.angular.z == float(0):
                    msg.linear.x = 0.8
                    
                print("case 2.2 following the wall")
                
                if self.check_wall_front():
                    self.robot_state = ROBOT_STATE_MACHINE.ON_LINE
                    self.wall_following_state = ROBOT_WALL_FOLLOWING_STATE_MACHINE.ROTATE_RIGHT
                    print("ooooooooooooooooooooooooooooooooooooooooooooooooooooooo")
                    self.turned_right_b = False
                    #msg = self.rotate(msg, self.find_angle_of_left_dir(self.yaw_d + 45))
            ### if wall is passed, turn left and go on slowly 
            else:
                #if self.check_robot_on_line():
                #    self.robot_state = ROBOT_STATE_MACHINE.ON_LINE
                #    self.wall_following_state = ROBOT_WALL_FOLLOWING_STATE_MACHINE.ROTATE_RIGHT
                #    self.turned_right_b = False
                #else:
                self.wall_following_state = ROBOT_WALL_FOLLOWING_STATE_MACHINE.KEEP_WALL_ON_LEFT_TURN_LEFT
                ### emin değilim 
                self.turned_right_b = False
                    
                
        if self.wall_following_state == ROBOT_WALL_FOLLOWING_STATE_MACHINE.KEEP_WALL_ON_LEFT_TURN_LEFT:
            
            distance_to_wall = self.l_dist
            print("burada ama -------------------------------------------------------")
            if self.turned_right_b == False:
                self.left_turn_angle = self.find_angle_of_left_dir(self.yaw_d + 45) 
                self.goal_x, self.goal_y = self.assign_waypoint()
                print("acaba, burada mı +++++++++++++++++++++++++++++++", self.goal_x, self.goal_y)
                msg.linear.x = float(0)
                msg.angular.z = float(0)
                #input()"
                self.turned_right_b = True
            print("case 2.3 no wall, turn right")
            
            right_dir = self.find_angle_d(self.goal_x, self.goal_y)
            msg = self.rotate(msg, right_dir)
            print("rotating",self.goal_x, self.goal_y, self.yaw_d, right_dir)
            target_reached = False
            if msg.angular.z == float(0):
                msg, target_reached = self.move(msg, self.goal_x, self.goal_y)
                print("moving ", self.goal_x, self.goal_y) 
                print("2.3.1, moving to the target point")

            if target_reached:
                if self.check_wall_left:
                    self.wall_following_state = ROBOT_WALL_FOLLOWING_STATE_MACHINE.KEEP_WALL_ON_LEFT
                else:
                    print("solda duvar yok, indetermined case-----------------------------------------------")
                    target_angle = self.find_angle_d(target_x, target_y)
                    msg = self.rotate(msg, target_angle)
                    msg, reached = self.move(msg, target_x, target_y)                    
                    
                self.crosssed_the_wall_b = True
                self.turned_right_b = False
                
        ###if self.check_robot_on_line() and self.crosssed_the_wall_b:
        ###    self.robot_state = ROBOT_STATE_MACHINE.ON_LINE
        ###    self.wall_following_state = ROBOT_WALL_FOLLOWING_STATE_MACHINE.ROTATE_RIGHT
        ###    print("ıııııııııııııııııııııııııııııııııııııııı")
        ###    self.turned_right_b = False
        ###print("******************************************************")
        return msg

    def check_wall_left(self):
        print("sola uzaklık", self.l_dist)
        if self.l_dist < 1.3:
            return True
        return False
            
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
            print(self.x + MUCH, self.y + LESS)
            return self.x + MUCH, self.y + LESS
        elif angle_ == 0:
            print("///////////second case//////////////")
            print(self.x - LESS, self.y + MUCH)
            return self.x + LESS, self.y - MUCH
        elif angle_ == 180:
            print("///////////third case//////////////")
            print(self.x + LESS, self.y - MUCH)
            return self.x - LESS, self.y + MUCH
        elif angle_ == 270:
            print("///////////fourth case//////////////")
            print(self.x + MUCH, self.y + LESS)
            return self.x - MUCH, self.y - LESS
            
    def find_angle_d(self, goal_x, goal_y):
        return convert_to_d(atan2(goal_y - self.y, goal_x - self.x))
    
    def check_wall_front(self):
        if self.f_dist < DISTANCE_TO_WALL_THRESHOLD:
            return True
        return False
        
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
        distance_to_goal = sqrt((self.x - goal_x)**2 + (self.y - goal_y)**2)
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
        
def main(args=None):
    # DO NOT CHANGE HERE
    # DO NOT CHANGE HERE
    # DO NOT CHANGE HERE
    # DO NOT CHANGE HERE
    rclpy.init(args=args)

    navigator_node = Navigator()
    navigator_node.send_request() # send request to map server
    get_response=False
    while rclpy.ok():
        rclpy.spin_once(navigator_node) 
        if (navigator_node.future.done() & (not get_response)):
            # if future job is accomplished (GetMap) and not accomplished before
            navigator_node.get_logger().info("map is acquired")
            try:
                response = navigator_node.future.result() # get map response
                get_response = True # raise the response flag
                navigator_node.occupancy_grid= response.map.data # get the occupancy grid array
                navigator_node.map_height= response.map.info.height # get the occupancy grid array
                navigator_node.map_width= response.map.info.width # get the occupancy grid array
                navigator_node.map_origin= response.map.info.origin # get the occupancy grid array
                navigator_node.map_resolution= response.map.info.resolution # get the occupancy grid array
                
            except Exception as e:
                navigator_node.get_logger().info(e) # raise an error if response could not be acquired.
                get_response = False # lower the flag


    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    navigator_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()