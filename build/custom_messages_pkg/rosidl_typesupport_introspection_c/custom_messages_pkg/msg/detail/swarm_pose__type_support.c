// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_messages_pkg:msg/SwarmPose.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_messages_pkg/msg/detail/swarm_pose__rosidl_typesupport_introspection_c.h"
#include "custom_messages_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_messages_pkg/msg/detail/swarm_pose__functions.h"
#include "custom_messages_pkg/msg/detail/swarm_pose__struct.h"


// Include directives for member types
// Member `pose`
#include "geometry_msgs/msg/pose.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"
// Member `twist`
#include "geometry_msgs/msg/twist.h"
// Member `twist`
#include "geometry_msgs/msg/detail/twist__rosidl_typesupport_introspection_c.h"
// Member `accel`
#include "geometry_msgs/msg/vector3.h"
// Member `accel`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void SwarmPose__rosidl_typesupport_introspection_c__SwarmPose_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_messages_pkg__msg__SwarmPose__init(message_memory);
}

void SwarmPose__rosidl_typesupport_introspection_c__SwarmPose_fini_function(void * message_memory)
{
  custom_messages_pkg__msg__SwarmPose__fini(message_memory);
}

size_t SwarmPose__rosidl_typesupport_introspection_c__size_function__Pose__pose(
  const void * untyped_member)
{
  const geometry_msgs__msg__Pose__Sequence * member =
    (const geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  return member->size;
}

const void * SwarmPose__rosidl_typesupport_introspection_c__get_const_function__Pose__pose(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Pose__Sequence * member =
    (const geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  return &member->data[index];
}

void * SwarmPose__rosidl_typesupport_introspection_c__get_function__Pose__pose(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Pose__Sequence * member =
    (geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  return &member->data[index];
}

bool SwarmPose__rosidl_typesupport_introspection_c__resize_function__Pose__pose(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Pose__Sequence * member =
    (geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  geometry_msgs__msg__Pose__Sequence__fini(member);
  return geometry_msgs__msg__Pose__Sequence__init(member, size);
}

size_t SwarmPose__rosidl_typesupport_introspection_c__size_function__Twist__twist(
  const void * untyped_member)
{
  const geometry_msgs__msg__Twist__Sequence * member =
    (const geometry_msgs__msg__Twist__Sequence *)(untyped_member);
  return member->size;
}

const void * SwarmPose__rosidl_typesupport_introspection_c__get_const_function__Twist__twist(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Twist__Sequence * member =
    (const geometry_msgs__msg__Twist__Sequence *)(untyped_member);
  return &member->data[index];
}

void * SwarmPose__rosidl_typesupport_introspection_c__get_function__Twist__twist(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Twist__Sequence * member =
    (geometry_msgs__msg__Twist__Sequence *)(untyped_member);
  return &member->data[index];
}

bool SwarmPose__rosidl_typesupport_introspection_c__resize_function__Twist__twist(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Twist__Sequence * member =
    (geometry_msgs__msg__Twist__Sequence *)(untyped_member);
  geometry_msgs__msg__Twist__Sequence__fini(member);
  return geometry_msgs__msg__Twist__Sequence__init(member, size);
}

size_t SwarmPose__rosidl_typesupport_introspection_c__size_function__Vector3__accel(
  const void * untyped_member)
{
  const geometry_msgs__msg__Vector3__Sequence * member =
    (const geometry_msgs__msg__Vector3__Sequence *)(untyped_member);
  return member->size;
}

const void * SwarmPose__rosidl_typesupport_introspection_c__get_const_function__Vector3__accel(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Vector3__Sequence * member =
    (const geometry_msgs__msg__Vector3__Sequence *)(untyped_member);
  return &member->data[index];
}

void * SwarmPose__rosidl_typesupport_introspection_c__get_function__Vector3__accel(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Vector3__Sequence * member =
    (geometry_msgs__msg__Vector3__Sequence *)(untyped_member);
  return &member->data[index];
}

bool SwarmPose__rosidl_typesupport_introspection_c__resize_function__Vector3__accel(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Vector3__Sequence * member =
    (geometry_msgs__msg__Vector3__Sequence *)(untyped_member);
  geometry_msgs__msg__Vector3__Sequence__fini(member);
  return geometry_msgs__msg__Vector3__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember SwarmPose__rosidl_typesupport_introspection_c__SwarmPose_message_member_array[3] = {
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_messages_pkg__msg__SwarmPose, pose),  // bytes offset in struct
    NULL,  // default value
    SwarmPose__rosidl_typesupport_introspection_c__size_function__Pose__pose,  // size() function pointer
    SwarmPose__rosidl_typesupport_introspection_c__get_const_function__Pose__pose,  // get_const(index) function pointer
    SwarmPose__rosidl_typesupport_introspection_c__get_function__Pose__pose,  // get(index) function pointer
    SwarmPose__rosidl_typesupport_introspection_c__resize_function__Pose__pose  // resize(index) function pointer
  },
  {
    "twist",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_messages_pkg__msg__SwarmPose, twist),  // bytes offset in struct
    NULL,  // default value
    SwarmPose__rosidl_typesupport_introspection_c__size_function__Twist__twist,  // size() function pointer
    SwarmPose__rosidl_typesupport_introspection_c__get_const_function__Twist__twist,  // get_const(index) function pointer
    SwarmPose__rosidl_typesupport_introspection_c__get_function__Twist__twist,  // get(index) function pointer
    SwarmPose__rosidl_typesupport_introspection_c__resize_function__Twist__twist  // resize(index) function pointer
  },
  {
    "accel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_messages_pkg__msg__SwarmPose, accel),  // bytes offset in struct
    NULL,  // default value
    SwarmPose__rosidl_typesupport_introspection_c__size_function__Vector3__accel,  // size() function pointer
    SwarmPose__rosidl_typesupport_introspection_c__get_const_function__Vector3__accel,  // get_const(index) function pointer
    SwarmPose__rosidl_typesupport_introspection_c__get_function__Vector3__accel,  // get(index) function pointer
    SwarmPose__rosidl_typesupport_introspection_c__resize_function__Vector3__accel  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers SwarmPose__rosidl_typesupport_introspection_c__SwarmPose_message_members = {
  "custom_messages_pkg__msg",  // message namespace
  "SwarmPose",  // message name
  3,  // number of fields
  sizeof(custom_messages_pkg__msg__SwarmPose),
  SwarmPose__rosidl_typesupport_introspection_c__SwarmPose_message_member_array,  // message members
  SwarmPose__rosidl_typesupport_introspection_c__SwarmPose_init_function,  // function to initialize message memory (memory has to be allocated)
  SwarmPose__rosidl_typesupport_introspection_c__SwarmPose_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t SwarmPose__rosidl_typesupport_introspection_c__SwarmPose_message_type_support_handle = {
  0,
  &SwarmPose__rosidl_typesupport_introspection_c__SwarmPose_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_messages_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_messages_pkg, msg, SwarmPose)() {
  SwarmPose__rosidl_typesupport_introspection_c__SwarmPose_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  SwarmPose__rosidl_typesupport_introspection_c__SwarmPose_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Twist)();
  SwarmPose__rosidl_typesupport_introspection_c__SwarmPose_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  if (!SwarmPose__rosidl_typesupport_introspection_c__SwarmPose_message_type_support_handle.typesupport_identifier) {
    SwarmPose__rosidl_typesupport_introspection_c__SwarmPose_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &SwarmPose__rosidl_typesupport_introspection_c__SwarmPose_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
