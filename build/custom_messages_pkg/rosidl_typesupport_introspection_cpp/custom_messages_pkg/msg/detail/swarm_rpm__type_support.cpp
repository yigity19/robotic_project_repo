// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from custom_messages_pkg:msg/SwarmRPM.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "custom_messages_pkg/msg/detail/swarm_rpm__struct.hpp"
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

void SwarmRPM_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) custom_messages_pkg::msg::SwarmRPM(_init);
}

void SwarmRPM_fini_function(void * message_memory)
{
  auto typed_message = static_cast<custom_messages_pkg::msg::SwarmRPM *>(message_memory);
  typed_message->~SwarmRPM();
}

size_t size_function__SwarmRPM__rpm_swarm(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<custom_messages_pkg::msg::DroneRPM> *>(untyped_member);
  return member->size();
}

const void * get_const_function__SwarmRPM__rpm_swarm(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<custom_messages_pkg::msg::DroneRPM> *>(untyped_member);
  return &member[index];
}

void * get_function__SwarmRPM__rpm_swarm(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<custom_messages_pkg::msg::DroneRPM> *>(untyped_member);
  return &member[index];
}

void resize_function__SwarmRPM__rpm_swarm(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<custom_messages_pkg::msg::DroneRPM> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SwarmRPM_message_member_array[1] = {
  {
    "rpm_swarm",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<custom_messages_pkg::msg::DroneRPM>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_messages_pkg::msg::SwarmRPM, rpm_swarm),  // bytes offset in struct
    nullptr,  // default value
    size_function__SwarmRPM__rpm_swarm,  // size() function pointer
    get_const_function__SwarmRPM__rpm_swarm,  // get_const(index) function pointer
    get_function__SwarmRPM__rpm_swarm,  // get(index) function pointer
    resize_function__SwarmRPM__rpm_swarm  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SwarmRPM_message_members = {
  "custom_messages_pkg::msg",  // message namespace
  "SwarmRPM",  // message name
  1,  // number of fields
  sizeof(custom_messages_pkg::msg::SwarmRPM),
  SwarmRPM_message_member_array,  // message members
  SwarmRPM_init_function,  // function to initialize message memory (memory has to be allocated)
  SwarmRPM_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SwarmRPM_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SwarmRPM_message_members,
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
get_message_type_support_handle<custom_messages_pkg::msg::SwarmRPM>()
{
  return &::custom_messages_pkg::msg::rosidl_typesupport_introspection_cpp::SwarmRPM_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_messages_pkg, msg, SwarmRPM)() {
  return &::custom_messages_pkg::msg::rosidl_typesupport_introspection_cpp::SwarmRPM_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
