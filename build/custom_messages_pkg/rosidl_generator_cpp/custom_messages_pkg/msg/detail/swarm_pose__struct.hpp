// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_messages_pkg:msg/SwarmPose.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MESSAGES_PKG__MSG__DETAIL__SWARM_POSE__STRUCT_HPP_
#define CUSTOM_MESSAGES_PKG__MSG__DETAIL__SWARM_POSE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"
// Member 'twist'
#include "geometry_msgs/msg/detail/twist__struct.hpp"
// Member 'accel'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_messages_pkg__msg__SwarmPose __attribute__((deprecated))
#else
# define DEPRECATED__custom_messages_pkg__msg__SwarmPose __declspec(deprecated)
#endif

namespace custom_messages_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SwarmPose_
{
  using Type = SwarmPose_<ContainerAllocator>;

  explicit SwarmPose_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit SwarmPose_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _pose_type =
    std::vector<geometry_msgs::msg::Pose_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Pose_<ContainerAllocator>>::other>;
  _pose_type pose;
  using _twist_type =
    std::vector<geometry_msgs::msg::Twist_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Twist_<ContainerAllocator>>::other>;
  _twist_type twist;
  using _accel_type =
    std::vector<geometry_msgs::msg::Vector3_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Vector3_<ContainerAllocator>>::other>;
  _accel_type accel;

  // setters for named parameter idiom
  Type & set__pose(
    const std::vector<geometry_msgs::msg::Pose_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Pose_<ContainerAllocator>>::other> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__twist(
    const std::vector<geometry_msgs::msg::Twist_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Twist_<ContainerAllocator>>::other> & _arg)
  {
    this->twist = _arg;
    return *this;
  }
  Type & set__accel(
    const std::vector<geometry_msgs::msg::Vector3_<ContainerAllocator>, typename ContainerAllocator::template rebind<geometry_msgs::msg::Vector3_<ContainerAllocator>>::other> & _arg)
  {
    this->accel = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_messages_pkg::msg::SwarmPose_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_messages_pkg::msg::SwarmPose_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_messages_pkg::msg::SwarmPose_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_messages_pkg::msg::SwarmPose_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_messages_pkg::msg::SwarmPose_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_messages_pkg::msg::SwarmPose_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_messages_pkg::msg::SwarmPose_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_messages_pkg::msg::SwarmPose_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_messages_pkg::msg::SwarmPose_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_messages_pkg::msg::SwarmPose_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_messages_pkg__msg__SwarmPose
    std::shared_ptr<custom_messages_pkg::msg::SwarmPose_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_messages_pkg__msg__SwarmPose
    std::shared_ptr<custom_messages_pkg::msg::SwarmPose_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SwarmPose_ & other) const
  {
    if (this->pose != other.pose) {
      return false;
    }
    if (this->twist != other.twist) {
      return false;
    }
    if (this->accel != other.accel) {
      return false;
    }
    return true;
  }
  bool operator!=(const SwarmPose_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SwarmPose_

// alias to use template instance with default allocator
using SwarmPose =
  custom_messages_pkg::msg::SwarmPose_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_messages_pkg

#endif  // CUSTOM_MESSAGES_PKG__MSG__DETAIL__SWARM_POSE__STRUCT_HPP_
