// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_messages_pkg:msg/CustomControl.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MESSAGES_PKG__MSG__DETAIL__CUSTOM_CONTROL__TRAITS_HPP_
#define CUSTOM_MESSAGES_PKG__MSG__DETAIL__CUSTOM_CONTROL__TRAITS_HPP_

#include "custom_messages_pkg/msg/detail/custom_control__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_messages_pkg::msg::CustomControl>()
{
  return "custom_messages_pkg::msg::CustomControl";
}

template<>
inline const char * name<custom_messages_pkg::msg::CustomControl>()
{
  return "custom_messages_pkg/msg/CustomControl";
}

template<>
struct has_fixed_size<custom_messages_pkg::msg::CustomControl>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_messages_pkg::msg::CustomControl>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_messages_pkg::msg::CustomControl>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MESSAGES_PKG__MSG__DETAIL__CUSTOM_CONTROL__TRAITS_HPP_
