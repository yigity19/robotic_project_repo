// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_messages_pkg:msg/Geometry.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MESSAGES_PKG__MSG__DETAIL__GEOMETRY__STRUCT_H_
#define CUSTOM_MESSAGES_PKG__MSG__DETAIL__GEOMETRY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'center'
#include "geometry_msgs/msg/detail/point__struct.h"

// Struct defined in msg/Geometry in the package custom_messages_pkg.
typedef struct custom_messages_pkg__msg__Geometry
{
  geometry_msgs__msg__Point center;
  double radius;
} custom_messages_pkg__msg__Geometry;

// Struct for a sequence of custom_messages_pkg__msg__Geometry.
typedef struct custom_messages_pkg__msg__Geometry__Sequence
{
  custom_messages_pkg__msg__Geometry * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_messages_pkg__msg__Geometry__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MESSAGES_PKG__MSG__DETAIL__GEOMETRY__STRUCT_H_
