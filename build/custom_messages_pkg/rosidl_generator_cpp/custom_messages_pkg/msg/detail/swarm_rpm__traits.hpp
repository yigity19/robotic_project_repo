// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_messages_pkg:msg/SwarmRPM.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MESSAGES_PKG__MSG__DETAIL__SWARM_RPM__TRAITS_HPP_
#define CUSTOM_MESSAGES_PKG__MSG__DETAIL__SWARM_RPM__TRAITS_HPP_

#include "custom_messages_pkg/msg/detail/swarm_rpm__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_messages_pkg::msg::SwarmRPM>()
{
  return "custom_messages_pkg::msg::SwarmRPM";
}

template<>
inline const char * name<custom_messages_pkg::msg::SwarmRPM>()
{
  return "custom_messages_pkg/msg/SwarmRPM";
}

template<>
struct has_fixed_size<custom_messages_pkg::msg::SwarmRPM>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_messages_pkg::msg::SwarmRPM>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_messages_pkg::msg::SwarmRPM>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MESSAGES_PKG__MSG__DETAIL__SWARM_RPM__TRAITS_HPP_
