// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_messages_pkg:msg/DroneRPM.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MESSAGES_PKG__MSG__DETAIL__DRONE_RPM__STRUCT_H_
#define CUSTOM_MESSAGES_PKG__MSG__DETAIL__DRONE_RPM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/DroneRPM in the package custom_messages_pkg.
typedef struct custom_messages_pkg__msg__DroneRPM
{
  double rpm_drone[4];
} custom_messages_pkg__msg__DroneRPM;

// Struct for a sequence of custom_messages_pkg__msg__DroneRPM.
typedef struct custom_messages_pkg__msg__DroneRPM__Sequence
{
  custom_messages_pkg__msg__DroneRPM * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_messages_pkg__msg__DroneRPM__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MESSAGES_PKG__MSG__DETAIL__DRONE_RPM__STRUCT_H_
