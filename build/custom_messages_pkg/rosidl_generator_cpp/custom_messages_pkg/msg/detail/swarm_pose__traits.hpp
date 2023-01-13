// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_messages_pkg:msg/SwarmPose.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MESSAGES_PKG__MSG__DETAIL__SWARM_POSE__TRAITS_HPP_
#define CUSTOM_MESSAGES_PKG__MSG__DETAIL__SWARM_POSE__TRAITS_HPP_

#include "custom_messages_pkg/msg/detail/swarm_pose__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_messages_pkg::msg::SwarmPose>()
{
  return "custom_messages_pkg::msg::SwarmPose";
}

template<>
inline const char * name<custom_messages_pkg::msg::SwarmPose>()
{
  return "custom_messages_pkg/msg/SwarmPose";
}

template<>
struct has_fixed_size<custom_messages_pkg::msg::SwarmPose>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_messages_pkg::msg::SwarmPose>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_messages_pkg::msg::SwarmPose>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MESSAGES_PKG__MSG__DETAIL__SWARM_POSE__TRAITS_HPP_
