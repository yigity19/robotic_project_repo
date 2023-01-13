// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_messages_pkg:msg/SwarmRPM.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MESSAGES_PKG__MSG__DETAIL__SWARM_RPM__BUILDER_HPP_
#define CUSTOM_MESSAGES_PKG__MSG__DETAIL__SWARM_RPM__BUILDER_HPP_

#include "custom_messages_pkg/msg/detail/swarm_rpm__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace custom_messages_pkg
{

namespace msg
{

namespace builder
{

class Init_SwarmRPM_rpm_swarm
{
public:
  Init_SwarmRPM_rpm_swarm()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_messages_pkg::msg::SwarmRPM rpm_swarm(::custom_messages_pkg::msg::SwarmRPM::_rpm_swarm_type arg)
  {
    msg_.rpm_swarm = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_messages_pkg::msg::SwarmRPM msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_messages_pkg::msg::SwarmRPM>()
{
  return custom_messages_pkg::msg::builder::Init_SwarmRPM_rpm_swarm();
}

}  // namespace custom_messages_pkg

#endif  // CUSTOM_MESSAGES_PKG__MSG__DETAIL__SWARM_RPM__BUILDER_HPP_
