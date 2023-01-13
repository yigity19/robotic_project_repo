// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_messages_pkg:msg/SwarmPose.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MESSAGES_PKG__MSG__DETAIL__SWARM_POSE__STRUCT_H_
#define CUSTOM_MESSAGES_PKG__MSG__DETAIL__SWARM_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'twist'
#include "geometry_msgs/msg/detail/twist__struct.h"
// Member 'accel'
#include "geometry_msgs/msg/detail/vector3__struct.h"

// Struct defined in msg/SwarmPose in the package custom_messages_pkg.
typedef struct custom_messages_pkg__msg__SwarmPose
{
  geometry_msgs__msg__Pose__Sequence pose;
  geometry_msgs__msg__Twist__Sequence twist;
  geometry_msgs__msg__Vector3__Sequence accel;
} custom_messages_pkg__msg__SwarmPose;

// Struct for a sequence of custom_messages_pkg__msg__SwarmPose.
typedef struct custom_messages_pkg__msg__SwarmPose__Sequence
{
  custom_messages_pkg__msg__SwarmPose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_messages_pkg__msg__SwarmPose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MESSAGES_PKG__MSG__DETAIL__SWARM_POSE__STRUCT_H_
