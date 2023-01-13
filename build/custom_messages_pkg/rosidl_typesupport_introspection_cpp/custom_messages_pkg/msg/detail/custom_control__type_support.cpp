// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from custom_messages_pkg:msg/CustomControl.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "custom_messages_pkg/msg/detail/custom_control__struct.hpp"
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

void CustomControl_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) custom_messages_pkg::msg::CustomControl(_init);
}

void CustomControl_fini_function(void * message_memory)
{
  auto typed_message = static_cast<custom_messages_pkg::msg::CustomControl *>(message_memory);
  typed_message->~CustomControl();
}

size_t size_function__CustomControl__rpm_drone(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__CustomControl__rpm_drone(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__CustomControl__rpm_drone(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 4> *>(untyped_member);
  return &member[index];
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember CustomControl_message_member_array[1] = {
  {
    "rpm_drone",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(custom_messages_pkg::msg::CustomControl, rpm_drone),  // bytes offset in struct
    nullptr,  // default value
    size_function__CustomControl__rpm_drone,  // size() function pointer
    get_const_function__CustomControl__rpm_drone,  // get_const(index) function pointer
    get_function__CustomControl__rpm_drone,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers CustomControl_message_members = {
  "custom_messages_pkg::msg",  // message namespace
  "CustomControl",  // message name
  1,  // number of fields
  sizeof(custom_messages_pkg::msg::CustomControl),
  CustomControl_message_member_array,  // message members
  CustomControl_init_function,  // function to initialize message memory (memory has to be allocated)
  CustomControl_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t CustomControl_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &CustomControl_message_members,
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
get_message_type_support_handle<custom_messages_pkg::msg::CustomControl>()
{
  return &::custom_messages_pkg::msg::rosidl_typesupport_introspection_cpp::CustomControl_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_messages_pkg, msg, CustomControl)() {
  return &::custom_messages_pkg::msg::rosidl_typesupport_introspection_cpp::CustomControl_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
