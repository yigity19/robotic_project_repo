// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_messages_pkg:msg/SwarmRPM.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MESSAGES_PKG__MSG__DETAIL__SWARM_RPM__STRUCT_H_
#define CUSTOM_MESSAGES_PKG__MSG__DETAIL__SWARM_RPM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'rpm_swarm'
#include "custom_messages_pkg/msg/detail/drone_rpm__struct.h"

// Struct defined in msg/SwarmRPM in the package custom_messages_pkg.
typedef struct custom_messages_pkg__msg__SwarmRPM
{
  custom_messages_pkg__msg__DroneRPM__Sequence rpm_swarm;
} custom_messages_pkg__msg__SwarmRPM;

// Struct for a sequence of custom_messages_pkg__msg__SwarmRPM.
typedef struct custom_messages_pkg__msg__SwarmRPM__Sequence
{
  custom_messages_pkg__msg__SwarmRPM * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_messages_pkg__msg__SwarmRPM__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MESSAGES_PKG__MSG__DETAIL__SWARM_RPM__STRUCT_H_
