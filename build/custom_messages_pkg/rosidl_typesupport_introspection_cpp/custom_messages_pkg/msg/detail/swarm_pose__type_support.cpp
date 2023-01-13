// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from custom_messages_pkg:msg/SwarmPose.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "custom_messages_pkg/msg/detail/swarm_pose__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace custom_messages_pkg
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void SwarmPose_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) custom_messages_pkg::msg::SwarmPose(_init);
}

void SwarmPose_fini_function(void * message_memory)
{
  auto typed_message = static_cast<custom_messages_pkg::msg::SwarmPose *>(message_memory);
  typed_message->~SwarmPose();
}

size_t size_function__SwarmPose__pose(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Pose> *>(untyped_member);
  return member->size();
}

const void * get_const_function__SwarmPose__pose(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Pose> *>(untyped_member);
  return &member[index];
}

void * get_function__SwarmPose__pose(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Pose> *>(untyped_member);
  return &member[index];
}

void resize_function__SwarmPose__pose(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Pose> *>(untyped_member);
  member->resize(size);
}

size_t size_function__SwarmPose__twist(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Twist> *>(untyped_member);
  return member->size();
}

const void * get_const_function__SwarmPose__twist(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Twist> *>(untyped_member);
  return &member[index];
}

void * get_function__SwarmPose__twist(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Twist> *>(untyped_member);
  return &member[index];
}

void resize_function__SwarmPose__twist(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Twist> *>(untyped_member);
  member->resize(size);
}

size_t size_function__SwarmPose__accel(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Vector3> *>(untyped_member);
  return member->size();
}

const void * get_const_function__SwarmPose__accel(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Vector3> *>(untyped_member);
  return &member[index];
}

void * get_function__SwarmPose__accel(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Vector3> *>(untyped_member);
  return &member[index];
}

void resize_function__SwarmPose__accel(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Vector3> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SwarmPose_message_member_array[3] = {
  {
    "pose",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Pose>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_messages_pkg::msg::SwarmPose, pose),  // bytes offset in struct
    nullptr,  // default value
    size_function__SwarmPose__pose,  // size() function pointer
    get_const_function__SwarmPose__pose,  // get_const(index) function pointer
    get_function__SwarmPose__pose,  // get(index) function pointer
    resize_function__SwarmPose__pose  // resize(index) function pointer
  },
  {
    "twist",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Twist>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_messages_pkg::msg::SwarmPose, twist),  // bytes offset in struct
    nullptr,  // default value
    size_function__SwarmPose__twist,  // size() function pointer
    get_const_function__SwarmPose__twist,  // get_const(index) function pointer
    get_function__SwarmPose__twist,  // get(index) function pointer
    resize_function__SwarmPose__twist  // resize(index) function pointer
  },
  {
    "accel",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Vector3>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_messages_pkg::msg::SwarmPose, accel),  // bytes offset in struct
    nullptr,  // default value
    size_function__SwarmPose__accel,  // size() function pointer
    get_const_function__SwarmPose__accel,  // get_const(index) function pointer
    get_function__SwarmPose__accel,  // get(index) function pointer
    resize_function__SwarmPose__accel  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SwarmPose_message_members = {
  "custom_messages_pkg::msg",  // message namespace
  "SwarmPose",  // message name
  3,  // number of fields
  sizeof(custom_messages_pkg::msg::SwarmPose),
  SwarmPose_message_member_array,  // message members
  SwarmPose_init_function,  // function to initialize message memory (memory has to be allocated)
  SwarmPose_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SwarmPose_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SwarmPose_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace custom_messages_pkg


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_messages_pkg::msg::SwarmPose>()
{
  return &::custom_messages_pkg::msg::rosidl_typesupport_introspection_cpp::SwarmPose_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_messages_pkg, msg, SwarmPose)() {
  return &::custom_messages_pkg::msg::rosidl_typesupport_introspection_cpp::SwarmPose_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
