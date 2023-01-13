// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_messages_pkg:msg/Geometry.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MESSAGES_PKG__MSG__DETAIL__GEOMETRY__TRAITS_HPP_
#define CUSTOM_MESSAGES_PKG__MSG__DETAIL__GEOMETRY__TRAITS_HPP_

#include "custom_messages_pkg/msg/detail/geometry__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'center'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_messages_pkg::msg::Geometry>()
{
  return "custom_messages_pkg::msg::Geometry";
}

template<>
inline const char * name<custom_messages_pkg::msg::Geometry>()
{
  return "custom_messages_pkg/msg/Geometry";
}

template<>
struct has_fixed_size<custom_messages_pkg::msg::Geometry>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value> {};

template<>
struct has_bounded_size<custom_messages_pkg::msg::Geometry>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value> {};

template<>
struct is_message<custom_messages_pkg::msg::Geometry>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MESSAGES_PKG__MSG__DETAIL__GEOMETRY__TRAITS_HPP_
