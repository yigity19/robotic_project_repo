// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_messages_pkg:msg/Geometry.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MESSAGES_PKG__MSG__DETAIL__GEOMETRY__BUILDER_HPP_
#define CUSTOM_MESSAGES_PKG__MSG__DETAIL__GEOMETRY__BUILDER_HPP_

#include "custom_messages_pkg/msg/detail/geometry__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace custom_messages_pkg
{

namespace msg
{

namespace builder
{

class Init_Geometry_radius
{
public:
  explicit Init_Geometry_radius(::custom_messages_pkg::msg::Geometry & msg)
  : msg_(msg)
  {}
  ::custom_messages_pkg::msg::Geometry radius(::custom_messages_pkg::msg::Geometry::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_messages_pkg::msg::Geometry msg_;
};

class Init_Geometry_center
{
public:
  Init_Geometry_center()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Geometry_radius center(::custom_messages_pkg::msg::Geometry::_center_type arg)
  {
    msg_.center = std::move(arg);
    return Init_Geometry_radius(msg_);
  }

private:
  ::custom_messages_pkg::msg::Geometry msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_messages_pkg::msg::Geometry>()
{
  return custom_messages_pkg::msg::builder::Init_Geometry_center();
}

}  // namespace custom_messages_pkg

#endif  // CUSTOM_MESSAGES_PKG__MSG__DETAIL__GEOMETRY__BUILDER_HPP_
