// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_messages_pkg:msg/SwarmRPM.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MESSAGES_PKG__MSG__DETAIL__SWARM_RPM__STRUCT_HPP_
#define CUSTOM_MESSAGES_PKG__MSG__DETAIL__SWARM_RPM__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'rpm_swarm'
#include "custom_messages_pkg/msg/detail/drone_rpm__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_messages_pkg__msg__SwarmRPM __attribute__((deprecated))
#else
# define DEPRECATED__custom_messages_pkg__msg__SwarmRPM __declspec(deprecated)
#endif

namespace custom_messages_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SwarmRPM_
{
  using Type = SwarmRPM_<ContainerAllocator>;

  explicit SwarmRPM_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit SwarmRPM_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _rpm_swarm_type =
    std::vector<custom_messages_pkg::msg::DroneRPM_<ContainerAllocator>, typename ContainerAllocator::template rebind<custom_messages_pkg::msg::DroneRPM_<ContainerAllocator>>::other>;
  _rpm_swarm_type rpm_swarm;

  // setters for named parameter idiom
  Type & set__rpm_swarm(
    const std::vector<custom_messages_pkg::msg::DroneRPM_<ContainerAllocator>, typename ContainerAllocator::template rebind<custom_messages_pkg::msg::DroneRPM_<ContainerAllocator>>::other> & _arg)
  {
    this->rpm_swarm = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_messages_pkg::msg::SwarmRPM_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_messages_pkg::msg::SwarmRPM_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_messages_pkg::msg::SwarmRPM_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_messages_pkg::msg::SwarmRPM_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_messages_pkg::msg::SwarmRPM_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_messages_pkg::msg::SwarmRPM_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_messages_pkg::msg::SwarmRPM_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_messages_pkg::msg::SwarmRPM_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_messages_pkg::msg::SwarmRPM_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_messages_pkg::msg::SwarmRPM_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_messages_pkg__msg__SwarmRPM
    std::shared_ptr<custom_messages_pkg::msg::SwarmRPM_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_messages_pkg__msg__SwarmRPM
    std::shared_ptr<custom_messages_pkg::msg::SwarmRPM_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SwarmRPM_ & other) const
  {
    if (this->rpm_swarm != other.rpm_swarm) {
      return false;
    }
    return true;
  }
  bool operator!=(const SwarmRPM_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SwarmRPM_

// alias to use template instance with default allocator
using SwarmRPM =
  custom_messages_pkg::msg::SwarmRPM_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_messages_pkg

#endif  // CUSTOM_MESSAGES_PKG__MSG__DETAIL__SWARM_RPM__STRUCT_HPP_
