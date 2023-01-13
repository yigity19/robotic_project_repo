// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_messages_pkg:msg/CustomControl.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MESSAGES_PKG__MSG__DETAIL__CUSTOM_CONTROL__BUILDER_HPP_
#define CUSTOM_MESSAGES_PKG__MSG__DETAIL__CUSTOM_CONTROL__BUILDER_HPP_

#include "custom_messages_pkg/msg/detail/custom_control__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace custom_messages_pkg
{

namespace msg
{

namespace builder
{

class Init_CustomControl_rpm_drone
{
public:
  Init_CustomControl_rpm_drone()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_messages_pkg::msg::CustomControl rpm_drone(::custom_messages_pkg::msg::CustomControl::_rpm_drone_type arg)
  {
    msg_.rpm_drone = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_messages_pkg::msg::CustomControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_messages_pkg::msg::CustomControl>()
{
  return custom_messages_pkg::msg::builder::Init_CustomControl_rpm_drone();
}

}  // namespace custom_messages_pkg

#endif  // CUSTOM_MESSAGES_PKG__MSG__DETAIL__CUSTOM_CONTROL__BUILDER_HPP_
