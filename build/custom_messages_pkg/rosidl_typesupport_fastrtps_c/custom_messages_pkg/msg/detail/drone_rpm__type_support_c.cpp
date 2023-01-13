// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from custom_messages_pkg:msg/DroneRPM.idl
// generated code does not contain a copyright notice
#include "custom_messages_pkg/msg/detail/drone_rpm__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "custom_messages_pkg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "custom_messages_pkg/msg/detail/drone_rpm__struct.h"
#include "custom_messages_pkg/msg/detail/drone_rpm__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _DroneRPM__ros_msg_type = custom_messages_pkg__msg__DroneRPM;

static bool _DroneRPM__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _DroneRPM__ros_msg_type * ros_message = static_cast<const _DroneRPM__ros_msg_type *>(untyped_ros_message);
  // Field name: rpm_drone
  {
    size_t size = 4;
    auto array_ptr = ros_message->rpm_drone;
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _DroneRPM__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _DroneRPM__ros_msg_type * ros_message = static_cast<_DroneRPM__ros_msg_type *>(untyped_ros_message);
  // Field name: rpm_drone
  {
    size_t size = 4;
    auto array_ptr = ros_message->rpm_drone;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_messages_pkg
size_t get_serialized_size_custom_messages_pkg__msg__DroneRPM(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _DroneRPM__ros_msg_type * ros_message = static_cast<const _DroneRPM__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name rpm_drone
  {
    size_t array_size = 4;
    auto array_ptr = ros_message->rpm_drone;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _DroneRPM__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_messages_pkg__msg__DroneRPM(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_messages_pkg
size_t max_serialized_size_custom_messages_pkg__msg__DroneRPM(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: rpm_drone
  {
    size_t array_size = 4;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _DroneRPM__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_custom_messages_pkg__msg__DroneRPM(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_DroneRPM = {
  "custom_messages_pkg::msg",
  "DroneRPM",
  _DroneRPM__cdr_serialize,
  _DroneRPM__cdr_deserialize,
  _DroneRPM__get_serialized_size,
  _DroneRPM__max_serialized_size
};

static rosidl_message_type_support_t _DroneRPM__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_DroneRPM,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_messages_pkg, msg, DroneRPM)() {
  return &_DroneRPM__type_support;
}

#if defined(__cplusplus)
}
#endif
