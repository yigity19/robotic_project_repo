// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_messages_pkg:msg/DroneRPM.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_messages_pkg/msg/detail/drone_rpm__rosidl_typesupport_introspection_c.h"
#include "custom_messages_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_messages_pkg/msg/detail/drone_rpm__functions.h"
#include "custom_messages_pkg/msg/detail/drone_rpm__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void DroneRPM__rosidl_typesupport_introspection_c__DroneRPM_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_messages_pkg__msg__DroneRPM__init(message_memory);
}

void DroneRPM__rosidl_typesupport_introspection_c__DroneRPM_fini_function(void * message_memory)
{
  custom_messages_pkg__msg__DroneRPM__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember DroneRPM__rosidl_typesupport_introspection_c__DroneRPM_message_member_array[1] = {
  {
    "rpm_drone",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(custom_messages_pkg__msg__DroneRPM, rpm_drone),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers DroneRPM__rosidl_typesupport_introspection_c__DroneRPM_message_members = {
  "custom_messages_pkg__msg",  // message namespace
  "DroneRPM",  // message name
  1,  // number of fields
  sizeof(custom_messages_pkg__msg__DroneRPM),
  DroneRPM__rosidl_typesupport_introspection_c__DroneRPM_message_member_array,  // message members
  DroneRPM__rosidl_typesupport_introspection_c__DroneRPM_init_function,  // function to initialize message memory (memory has to be allocated)
  DroneRPM__rosidl_typesupport_introspection_c__DroneRPM_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t DroneRPM__rosidl_typesupport_introspection_c__DroneRPM_message_type_support_handle = {
  0,
  &DroneRPM__rosidl_typesupport_introspection_c__DroneRPM_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_messages_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_messages_pkg, msg, DroneRPM)() {
  if (!DroneRPM__rosidl_typesupport_introspection_c__DroneRPM_message_type_support_handle.typesupport_identifier) {
    DroneRPM__rosidl_typesupport_introspection_c__DroneRPM_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &DroneRPM__rosidl_typesupport_introspection_c__DroneRPM_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
