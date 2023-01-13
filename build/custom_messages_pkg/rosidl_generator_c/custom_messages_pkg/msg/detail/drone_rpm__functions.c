// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_messages_pkg:msg/DroneRPM.idl
// generated code does not contain a copyright notice
#include "custom_messages_pkg/msg/detail/drone_rpm__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
custom_messages_pkg__msg__DroneRPM__init(custom_messages_pkg__msg__DroneRPM * msg)
{
  if (!msg) {
    return false;
  }
  // rpm_drone
  return true;
}

void
custom_messages_pkg__msg__DroneRPM__fini(custom_messages_pkg__msg__DroneRPM * msg)
{
  if (!msg) {
    return;
  }
  // rpm_drone
}

bool
custom_messages_pkg__msg__DroneRPM__are_equal(const custom_messages_pkg__msg__DroneRPM * lhs, const custom_messages_pkg__msg__DroneRPM * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // rpm_drone
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->rpm_drone[i] != rhs->rpm_drone[i]) {
      return false;
    }
  }
  return true;
}

bool
custom_messages_pkg__msg__DroneRPM__copy(
  const custom_messages_pkg__msg__DroneRPM * input,
  custom_messages_pkg__msg__DroneRPM * output)
{
  if (!input || !output) {
    return false;
  }
  // rpm_drone
  for (size_t i = 0; i < 4; ++i) {
    output->rpm_drone[i] = input->rpm_drone[i];
  }
  return true;
}

custom_messages_pkg__msg__DroneRPM *
custom_messages_pkg__msg__DroneRPM__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_messages_pkg__msg__DroneRPM * msg = (custom_messages_pkg__msg__DroneRPM *)allocator.allocate(sizeof(custom_messages_pkg__msg__DroneRPM), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_messages_pkg__msg__DroneRPM));
  bool success = custom_messages_pkg__msg__DroneRPM__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_messages_pkg__msg__DroneRPM__destroy(custom_messages_pkg__msg__DroneRPM * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_messages_pkg__msg__DroneRPM__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_messages_pkg__msg__DroneRPM__Sequence__init(custom_messages_pkg__msg__DroneRPM__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_messages_pkg__msg__DroneRPM * data = NULL;

  if (size) {
    data = (custom_messages_pkg__msg__DroneRPM *)allocator.zero_allocate(size, sizeof(custom_messages_pkg__msg__DroneRPM), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_messages_pkg__msg__DroneRPM__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_messages_pkg__msg__DroneRPM__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_messages_pkg__msg__DroneRPM__Sequence__fini(custom_messages_pkg__msg__DroneRPM__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_messages_pkg__msg__DroneRPM__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_messages_pkg__msg__DroneRPM__Sequence *
custom_messages_pkg__msg__DroneRPM__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_messages_pkg__msg__DroneRPM__Sequence * array = (custom_messages_pkg__msg__DroneRPM__Sequence *)allocator.allocate(sizeof(custom_messages_pkg__msg__DroneRPM__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_messages_pkg__msg__DroneRPM__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_messages_pkg__msg__DroneRPM__Sequence__destroy(custom_messages_pkg__msg__DroneRPM__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_messages_pkg__msg__DroneRPM__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_messages_pkg__msg__DroneRPM__Sequence__are_equal(const custom_messages_pkg__msg__DroneRPM__Sequence * lhs, const custom_messages_pkg__msg__DroneRPM__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_messages_pkg__msg__DroneRPM__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_messages_pkg__msg__DroneRPM__Sequence__copy(
  const custom_messages_pkg__msg__DroneRPM__Sequence * input,
  custom_messages_pkg__msg__DroneRPM__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_messages_pkg__msg__DroneRPM);
    custom_messages_pkg__msg__DroneRPM * data =
      (custom_messages_pkg__msg__DroneRPM *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_messages_pkg__msg__DroneRPM__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          custom_messages_pkg__msg__DroneRPM__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_messages_pkg__msg__DroneRPM__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
