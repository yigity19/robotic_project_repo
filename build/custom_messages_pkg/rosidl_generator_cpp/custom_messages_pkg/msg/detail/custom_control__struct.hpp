// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_messages_pkg:msg/CustomControl.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MESSAGES_PKG__MSG__DETAIL__CUSTOM_CONTROL__STRUCT_HPP_
#define CUSTOM_MESSAGES_PKG__MSG__DETAIL__CUSTOM_CONTROL__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__custom_messages_pkg__msg__CustomControl __attribute__((deprecated))
#else
# define DEPRECATED__custom_messages_pkg__msg__CustomControl __declspec(deprecated)
#endif

namespace custom_messages_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CustomControl_
{
  using Type = CustomControl_<ContainerAllocator>;

  explicit CustomControl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 4>::iterator, double>(this->rpm_drone.begin(), this->rpm_drone.end(), 0.0);
    }
  }

  explicit CustomControl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : rpm_drone(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 4>::iterator, double>(this->rpm_drone.begin(), this->rpm_drone.end(), 0.0);
    }
  }

  // field types and members
  using _rpm_drone_type =
    std::array<double, 4>;
  _rpm_drone_type rpm_drone;

  // setters for named parameter idiom
  Type & set__rpm_drone(
    const std::array<double, 4> & _arg)
  {
    this->rpm_drone = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_messages_pkg::msg::CustomControl_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_messages_pkg::msg::CustomControl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_messages_pkg::msg::CustomControl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_messages_pkg::msg::CustomControl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_messages_pkg::msg::CustomControl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_messages_pkg::msg::CustomControl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_messages_pkg::msg::CustomControl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_messages_pkg::msg::CustomControl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_messages_pkg::msg::CustomControl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_messages_pkg::msg::CustomControl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_messages_pkg__msg__CustomControl
    std::shared_ptr<custom_messages_pkg::msg::CustomControl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_messages_pkg__msg__CustomControl
    std::shared_ptr<custom_messages_pkg::msg::CustomControl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CustomControl_ & other) const
  {
    if (this->rpm_drone != other.rpm_drone) {
      return false;
    }
    return true;
  }
  bool operator!=(const CustomControl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CustomControl_

// alias to use template instance with default allocator
using CustomControl =
  custom_messages_pkg::msg::CustomControl_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_messages_pkg

#endif  // CUSTOM_MESSAGES_PKG__MSG__DETAIL__CUSTOM_CONTROL__STRUCT_HPP_
