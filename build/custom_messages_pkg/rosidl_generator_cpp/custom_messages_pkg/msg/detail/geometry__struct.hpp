// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_messages_pkg:msg/Geometry.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MESSAGES_PKG__MSG__DETAIL__GEOMETRY__STRUCT_HPP_
#define CUSTOM_MESSAGES_PKG__MSG__DETAIL__GEOMETRY__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'center'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_messages_pkg__msg__Geometry __attribute__((deprecated))
#else
# define DEPRECATED__custom_messages_pkg__msg__Geometry __declspec(deprecated)
#endif

namespace custom_messages_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Geometry_
{
  using Type = Geometry_<ContainerAllocator>;

  explicit Geometry_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : center(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->radius = 0.0;
    }
  }

  explicit Geometry_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : center(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->radius = 0.0;
    }
  }

  // field types and members
  using _center_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _center_type center;
  using _radius_type =
    double;
  _radius_type radius;

  // setters for named parameter idiom
  Type & set__center(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->center = _arg;
    return *this;
  }
  Type & set__radius(
    const double & _arg)
  {
    this->radius = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_messages_pkg::msg::Geometry_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_messages_pkg::msg::Geometry_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_messages_pkg::msg::Geometry_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_messages_pkg::msg::Geometry_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_messages_pkg::msg::Geometry_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_messages_pkg::msg::Geometry_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_messages_pkg::msg::Geometry_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_messages_pkg::msg::Geometry_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_messages_pkg::msg::Geometry_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_messages_pkg::msg::Geometry_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_messages_pkg__msg__Geometry
    std::shared_ptr<custom_messages_pkg::msg::Geometry_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_messages_pkg__msg__Geometry
    std::shared_ptr<custom_messages_pkg::msg::Geometry_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Geometry_ & other) const
  {
    if (this->center != other.center) {
      return false;
    }
    if (this->radius != other.radius) {
      return false;
    }
    return true;
  }
  bool operator!=(const Geometry_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Geometry_

// alias to use template instance with default allocator
using Geometry =
  custom_messages_pkg::msg::Geometry_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_messages_pkg

#endif  // CUSTOM_MESSAGES_PKG__MSG__DETAIL__GEOMETRY__STRUCT_HPP_
