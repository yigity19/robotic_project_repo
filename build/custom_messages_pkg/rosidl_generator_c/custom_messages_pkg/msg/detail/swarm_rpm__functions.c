// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_messages_pkg:msg/SwarmRPM.idl
// generated code does not contain a copyright notice
#include "custom_messages_pkg/msg/detail/swarm_rpm__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `rpm_swarm`
#include "custom_messages_pkg/msg/detail/drone_rpm__functions.h"

bool
custom_messages_pkg__msg__SwarmRPM__init(custom_messages_pkg__msg__SwarmRPM * msg)
{
  if (!msg) {
    return false;
  }
  // rpm_swarm
  if (!custom_messages_pkg__msg__DroneRPM__Sequence__init(&msg->rpm_swarm, 0)) {
    custom_messages_pkg__msg__SwarmRPM__fini(msg);
    return false;
  }
  return true;
}

void
custom_messages_pkg__msg__SwarmRPM__fini(custom_messages_pkg__msg__SwarmRPM * msg)
{
  if (!msg) {
    return;
  }
  // rpm_swarm
  custom_messages_pkg__msg__DroneRPM__Sequence__fini(&msg->rpm_swarm);
}

bool
custom_messages_pkg__msg__SwarmRPM__are_equal(const custom_messages_pkg__msg__SwarmRPM * lhs, const custom_messages_pkg__msg__SwarmRPM * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // rpm_swarm
  if (!custom_messages_pkg__msg__DroneRPM__Sequence__are_equal(
      &(lhs->rpm_swarm), &(rhs->rpm_swarm)))
  {
    return false;
  }
  return true;
}

bool
custom_messages_pkg__msg__SwarmRPM__copy(
  const custom_messages_pkg__msg__SwarmRPM * input,
  custom_messages_pkg__msg__SwarmRPM * output)
{
  if (!input || !output) {
    return false;
  }
  // rpm_swarm
  if (!custom_messages_pkg__msg__DroneRPM__Sequence__copy(
      &(input->rpm_swarm), &(output->rpm_swarm)))
  {
    return false;
  }
  return true;
}

custom_messages_pkg__msg__SwarmRPM *
custom_messages_pkg__msg__SwarmRPM__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_messages_pkg__msg__SwarmRPM * msg = (custom_messages_pkg__msg__SwarmRPM *)allocator.allocate(sizeof(custom_messages_pkg__msg__SwarmRPM), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_messages_pkg__msg__SwarmRPM));
  bool success = custom_messages_pkg__msg__SwarmRPM__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_messages_pkg__msg__SwarmRPM__destroy(custom_messages_pkg__msg__SwarmRPM * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_messages_pkg__msg__SwarmRPM__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_messages_pkg__msg__SwarmRPM__Sequence__init(custom_messages_pkg__msg__SwarmRPM__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_messages_pkg__msg__SwarmRPM * data = NULL;

  if (size) {
    data = (custom_messages_pkg__msg__SwarmRPM *)allocator.zero_allocate(size, sizeof(custom_messages_pkg__msg__SwarmRPM), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_messages_pkg__msg__SwarmRPM__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_messages_pkg__msg__SwarmRPM__fini(&data[i - 1]);
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
custom_messages_pkg__msg__SwarmRPM__Sequence__fini(custom_messages_pkg__msg__SwarmRPM__Sequence * array)
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
      custom_messages_pkg__msg__SwarmRPM__fini(&array->data[i]);
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

custom_messages_pkg__msg__SwarmRPM__Sequence *
custom_messages_pkg__msg__SwarmRPM__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_messages_pkg__msg__SwarmRPM__Sequence * array = (custom_messages_pkg__msg__SwarmRPM__Sequence *)allocator.allocate(sizeof(custom_messages_pkg__msg__SwarmRPM__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_messages_pkg__msg__SwarmRPM__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_messages_pkg__msg__SwarmRPM__Sequence__destroy(custom_messages_pkg__msg__SwarmRPM__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_messages_pkg__msg__SwarmRPM__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_messages_pkg__msg__SwarmRPM__Sequence__are_equal(const custom_messages_pkg__msg__SwarmRPM__Sequence * lhs, const custom_messages_pkg__msg__SwarmRPM__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_messages_pkg__msg__SwarmRPM__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_messages_pkg__msg__SwarmRPM__Sequence__copy(
  const custom_messages_pkg__msg__SwarmRPM__Sequence * input,
  custom_messages_pkg__msg__SwarmRPM__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_messages_pkg__msg__SwarmRPM);
    custom_messages_pkg__msg__SwarmRPM * data =
      (custom_messages_pkg__msg__SwarmRPM *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_messages_pkg__msg__SwarmRPM__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          custom_messages_pkg__msg__SwarmRPM__fini(&data[i]);
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
    if (!custom_messages_pkg__msg__SwarmRPM__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
