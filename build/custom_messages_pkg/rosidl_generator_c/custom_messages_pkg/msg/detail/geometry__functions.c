// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_messages_pkg:msg/Geometry.idl
// generated code does not contain a copyright notice
#include "custom_messages_pkg/msg/detail/geometry__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `center`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
custom_messages_pkg__msg__Geometry__init(custom_messages_pkg__msg__Geometry * msg)
{
  if (!msg) {
    return false;
  }
  // center
  if (!geometry_msgs__msg__Point__init(&msg->center)) {
    custom_messages_pkg__msg__Geometry__fini(msg);
    return false;
  }
  // radius
  return true;
}

void
custom_messages_pkg__msg__Geometry__fini(custom_messages_pkg__msg__Geometry * msg)
{
  if (!msg) {
    return;
  }
  // center
  geometry_msgs__msg__Point__fini(&msg->center);
  // radius
}

bool
custom_messages_pkg__msg__Geometry__are_equal(const custom_messages_pkg__msg__Geometry * lhs, const custom_messages_pkg__msg__Geometry * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // center
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->center), &(rhs->center)))
  {
    return false;
  }
  // radius
  if (lhs->radius != rhs->radius) {
    return false;
  }
  return true;
}

bool
custom_messages_pkg__msg__Geometry__copy(
  const custom_messages_pkg__msg__Geometry * input,
  custom_messages_pkg__msg__Geometry * output)
{
  if (!input || !output) {
    return false;
  }
  // center
  if (!geometry_msgs__msg__Point__copy(
      &(input->center), &(output->center)))
  {
    return false;
  }
  // radius
  output->radius = input->radius;
  return true;
}

custom_messages_pkg__msg__Geometry *
custom_messages_pkg__msg__Geometry__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_messages_pkg__msg__Geometry * msg = (custom_messages_pkg__msg__Geometry *)allocator.allocate(sizeof(custom_messages_pkg__msg__Geometry), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_messages_pkg__msg__Geometry));
  bool success = custom_messages_pkg__msg__Geometry__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_messages_pkg__msg__Geometry__destroy(custom_messages_pkg__msg__Geometry * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_messages_pkg__msg__Geometry__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_messages_pkg__msg__Geometry__Sequence__init(custom_messages_pkg__msg__Geometry__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_messages_pkg__msg__Geometry * data = NULL;

  if (size) {
    data = (custom_messages_pkg__msg__Geometry *)allocator.zero_allocate(size, sizeof(custom_messages_pkg__msg__Geometry), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_messages_pkg__msg__Geometry__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_messages_pkg__msg__Geometry__fini(&data[i - 1]);
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
custom_messages_pkg__msg__Geometry__Sequence__fini(custom_messages_pkg__msg__Geometry__Sequence * array)
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
      custom_messages_pkg__msg__Geometry__fini(&array->data[i]);
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

custom_messages_pkg__msg__Geometry__Sequence *
custom_messages_pkg__msg__Geometry__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_messages_pkg__msg__Geometry__Sequence * array = (custom_messages_pkg__msg__Geometry__Sequence *)allocator.allocate(sizeof(custom_messages_pkg__msg__Geometry__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_messages_pkg__msg__Geometry__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_messages_pkg__msg__Geometry__Sequence__destroy(custom_messages_pkg__msg__Geometry__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_messages_pkg__msg__Geometry__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_messages_pkg__msg__Geometry__Sequence__are_equal(const custom_messages_pkg__msg__Geometry__Sequence * lhs, const custom_messages_pkg__msg__Geometry__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_messages_pkg__msg__Geometry__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_messages_pkg__msg__Geometry__Sequence__copy(
  const custom_messages_pkg__msg__Geometry__Sequence * input,
  custom_messages_pkg__msg__Geometry__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_messages_pkg__msg__Geometry);
    custom_messages_pkg__msg__Geometry * data =
      (custom_messages_pkg__msg__Geometry *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_messages_pkg__msg__Geometry__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          custom_messages_pkg__msg__Geometry__fini(&data[i]);
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
    if (!custom_messages_pkg__msg__Geometry__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
