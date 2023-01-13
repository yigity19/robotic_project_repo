// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_messages_pkg:msg/SwarmRPM.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_messages_pkg/msg/detail/swarm_rpm__rosidl_typesupport_introspection_c.h"
#include "custom_messages_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_messages_pkg/msg/detail/swarm_rpm__functions.h"
#include "custom_messages_pkg/msg/detail/swarm_rpm__struct.h"


// Include directives for member types
// Member `rpm_swarm`
#include "custom_messages_pkg/msg/drone_rpm.h"
// Member `rpm_swarm`
#include "custom_messages_pkg/msg/detail/drone_rpm__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void SwarmRPM__rosidl_typesupport_introspection_c__SwarmRPM_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_messages_pkg__msg__SwarmRPM__init(message_memory);
}

void SwarmRPM__rosidl_typesupport_introspection_c__SwarmRPM_fini_function(void * message_memory)
{
  custom_messages_pkg__msg__SwarmRPM__fini(message_memory);
}

size_t SwarmRPM__rosidl_typesupport_introspection_c__size_function__DroneRPM__rpm_swarm(
  const void * untyped_member)
{
  const custom_messages_pkg__msg__DroneRPM__Sequence * member =
    (const custom_messages_pkg__msg__DroneRPM__Sequence *)(untyped_member);
  return member->size;
}

const void * SwarmRPM__rosidl_typesupport_introspection_c__get_const_function__DroneRPM__rpm_swarm(
  const void * untyped_member, size_t index)
{
  const custom_messages_pkg__msg__DroneRPM__Sequence * member =
    (const custom_messages_pkg__msg__DroneRPM__Sequence *)(untyped_member);
  return &member->data[index];
}

void * SwarmRPM__rosidl_typesupport_introspection_c__get_function__DroneRPM__rpm_swarm(
  void * untyped_member, size_t index)
{
  custom_messages_pkg__msg__DroneRPM__Sequence * member =
    (custom_messages_pkg__msg__DroneRPM__Sequence *)(untyped_member);
  return &member->data[index];
}

bool SwarmRPM__rosidl_typesupport_introspection_c__resize_function__DroneRPM__rpm_swarm(
  void * untyped_member, size_t size)
{
  custom_messages_pkg__msg__DroneRPM__Sequence * member =
    (custom_messages_pkg__msg__DroneRPM__Sequence *)(untyped_member);
  custom_messages_pkg__msg__DroneRPM__Sequence__fini(member);
  return custom_messages_pkg__msg__DroneRPM__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember SwarmRPM__rosidl_typesupport_introspection_c__SwarmRPM_message_member_array[1] = {
  {
    "rpm_swarm",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_messages_pkg__msg__SwarmRPM, rpm_swarm),  // bytes offset in struct
    NULL,  // default value
    SwarmRPM__rosidl_typesupport_introspection_c__size_function__DroneRPM__rpm_swarm,  // size() function pointer
    SwarmRPM__rosidl_typesupport_introspection_c__get_const_function__DroneRPM__rpm_swarm,  // get_const(index) function pointer
    SwarmRPM__rosidl_typesupport_introspection_c__get_function__DroneRPM__rpm_swarm,  // get(index) function pointer
    SwarmRPM__rosidl_typesupport_introspection_c__resize_function__DroneRPM__rpm_swarm  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers SwarmRPM__rosidl_typesupport_introspection_c__SwarmRPM_message_members = {
  "custom_messages_pkg__msg",  // message namespace
  "SwarmRPM",  // message name
  1,  // number of fields
  sizeof(custom_messages_pkg__msg__SwarmRPM),
  SwarmRPM__rosidl_typesupport_introspection_c__SwarmRPM_message_member_array,  // message members
  SwarmRPM__rosidl_typesupport_introspection_c__SwarmRPM_init_function,  // function to initialize message memory (memory has to be allocated)
  SwarmRPM__rosidl_typesupport_introspection_c__SwarmRPM_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t SwarmRPM__rosidl_typesupport_introspection_c__SwarmRPM_message_type_support_handle = {
  0,
  &SwarmRPM__rosidl_typesupport_introspection_c__SwarmRPM_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_messages_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_messages_pkg, msg, SwarmRPM)() {
  SwarmRPM__rosidl_typesupport_introspection_c__SwarmRPM_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_messages_pkg, msg, DroneRPM)();
  if (!SwarmRPM__rosidl_typesupport_introspection_c__SwarmRPM_message_type_support_handle.typesupport_identifier) {
    SwarmRPM__rosidl_typesupport_introspection_c__SwarmRPM_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &SwarmRPM__rosidl_typesupport_introspection_c__SwarmRPM_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
