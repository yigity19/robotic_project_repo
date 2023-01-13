// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from custom_messages_pkg:msg/DroneRPM.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MESSAGES_PKG__MSG__DETAIL__DRONE_RPM__FUNCTIONS_H_
#define CUSTOM_MESSAGES_PKG__MSG__DETAIL__DRONE_RPM__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "custom_messages_pkg/msg/rosidl_generator_c__visibility_control.h"

#include "custom_messages_pkg/msg/detail/drone_rpm__struct.h"

/// Initialize msg/DroneRPM message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * custom_messages_pkg__msg__DroneRPM
 * )) before or use
 * custom_messages_pkg__msg__DroneRPM__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_messages_pkg
bool
custom_messages_pkg__msg__DroneRPM__init(custom_messages_pkg__msg__DroneRPM * msg);

/// Finalize msg/DroneRPM message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_messages_pkg
void
custom_messages_pkg__msg__DroneRPM__fini(custom_messages_pkg__msg__DroneRPM * msg);

/// Create msg/DroneRPM message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * custom_messages_pkg__msg__DroneRPM__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_messages_pkg
custom_messages_pkg__msg__DroneRPM *
custom_messages_pkg__msg__DroneRPM__create();

/// Destroy msg/DroneRPM message.
/**
 * It calls
 * custom_messages_pkg__msg__DroneRPM__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_messages_pkg
void
custom_messages_pkg__msg__DroneRPM__destroy(custom_messages_pkg__msg__DroneRPM * msg);

/// Check for msg/DroneRPM message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_messages_pkg
bool
custom_messages_pkg__msg__DroneRPM__are_equal(const custom_messages_pkg__msg__DroneRPM * lhs, const custom_messages_pkg__msg__DroneRPM * rhs);

/// Copy a msg/DroneRPM message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_messages_pkg
bool
custom_messages_pkg__msg__DroneRPM__copy(
  const custom_messages_pkg__msg__DroneRPM * input,
  custom_messages_pkg__msg__DroneRPM * output);

/// Initialize array of msg/DroneRPM messages.
/**
 * It allocates the memory for the number of elements and calls
 * custom_messages_pkg__msg__DroneRPM__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_messages_pkg
bool
custom_messages_pkg__msg__DroneRPM__Sequence__init(custom_messages_pkg__msg__DroneRPM__Sequence * array, size_t size);

/// Finalize array of msg/DroneRPM messages.
/**
 * It calls
 * custom_messages_pkg__msg__DroneRPM__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_messages_pkg
void
custom_messages_pkg__msg__DroneRPM__Sequence__fini(custom_messages_pkg__msg__DroneRPM__Sequence * array);

/// Create array of msg/DroneRPM messages.
/**
 * It allocates the memory for the array and calls
 * custom_messages_pkg__msg__DroneRPM__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_messages_pkg
custom_messages_pkg__msg__DroneRPM__Sequence *
custom_messages_pkg__msg__DroneRPM__Sequence__create(size_t size);

/// Destroy array of msg/DroneRPM messages.
/**
 * It calls
 * custom_messages_pkg__msg__DroneRPM__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_messages_pkg
void
custom_messages_pkg__msg__DroneRPM__Sequence__destroy(custom_messages_pkg__msg__DroneRPM__Sequence * array);

/// Check for msg/DroneRPM message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_messages_pkg
bool
custom_messages_pkg__msg__DroneRPM__Sequence__are_equal(const custom_messages_pkg__msg__DroneRPM__Sequence * lhs, const custom_messages_pkg__msg__DroneRPM__Sequence * rhs);

/// Copy an array of msg/DroneRPM messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_custom_messages_pkg
bool
custom_messages_pkg__msg__DroneRPM__Sequence__copy(
  const custom_messages_pkg__msg__DroneRPM__Sequence * input,
  custom_messages_pkg__msg__DroneRPM__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MESSAGES_PKG__MSG__DETAIL__DRONE_RPM__FUNCTIONS_H_
