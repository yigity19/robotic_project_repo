// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_messages_pkg:msg/SwarmPose.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MESSAGES_PKG__MSG__DETAIL__SWARM_POSE__BUILDER_HPP_
#define CUSTOM_MESSAGES_PKG__MSG__DETAIL__SWARM_POSE__BUILDER_HPP_

#include "custom_messages_pkg/msg/detail/swarm_pose__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace custom_messages_pkg
{

namespace msg
{

namespace builder
{

class Init_SwarmPose_accel
{
public:
  explicit Init_SwarmPose_accel(::custom_messages_pkg::msg::SwarmPose & msg)
  : msg_(msg)
  {}
  ::custom_messages_pkg::msg::SwarmPose accel(::custom_messages_pkg::msg::SwarmPose::_accel_type arg)
  {
    msg_.accel = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_messages_pkg::msg::SwarmPose msg_;
};

class Init_SwarmPose_twist
{
public:
  explicit Init_SwarmPose_twist(::custom_messages_pkg::msg::SwarmPose & msg)
  : msg_(msg)
  {}
  Init_SwarmPose_accel twist(::custom_messages_pkg::msg::SwarmPose::_twist_type arg)
  {
    msg_.twist = std::move(arg);
    return Init_SwarmPose_accel(msg_);
  }

private:
  ::custom_messages_pkg::msg::SwarmPose msg_;
};

class Init_SwarmPose_pose
{
public:
  Init_SwarmPose_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SwarmPose_twist pose(::custom_messages_pkg::msg::SwarmPose::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_SwarmPose_twist(msg_);
  }

private:
  ::custom_messages_pkg::msg::SwarmPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_messages_pkg::msg::SwarmPose>()
{
  return custom_messages_pkg::msg::builder::Init_SwarmPose_pose();
}

}  // namespace custom_messages_pkg

#endif  // CUSTOM_MESSAGES_PKG__MSG__DETAIL__SWARM_POSE__BUILDER_HPP_
