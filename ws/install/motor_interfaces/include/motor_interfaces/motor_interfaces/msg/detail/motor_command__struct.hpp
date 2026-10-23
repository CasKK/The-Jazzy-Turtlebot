// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from motor_interfaces:msg/MotorCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "motor_interfaces/msg/motor_command.hpp"


#ifndef MOTOR_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__STRUCT_HPP_
#define MOTOR_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__motor_interfaces__msg__MotorCommand __attribute__((deprecated))
#else
# define DEPRECATED__motor_interfaces__msg__MotorCommand __declspec(deprecated)
#endif

namespace motor_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorCommand_
{
  using Type = MotorCommand_<ContainerAllocator>;

  explicit MotorCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0;
      this->command_type = "";
      this->value = 0.0;
    }
  }

  explicit MotorCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : command_type(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0;
      this->command_type = "";
      this->value = 0.0;
    }
  }

  // field types and members
  using _id_type =
    uint8_t;
  _id_type id;
  using _command_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _command_type_type command_type;
  using _value_type =
    double;
  _value_type value;

  // setters for named parameter idiom
  Type & set__id(
    const uint8_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__command_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->command_type = _arg;
    return *this;
  }
  Type & set__value(
    const double & _arg)
  {
    this->value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    motor_interfaces::msg::MotorCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const motor_interfaces::msg::MotorCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<motor_interfaces::msg::MotorCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<motor_interfaces::msg::MotorCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      motor_interfaces::msg::MotorCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<motor_interfaces::msg::MotorCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      motor_interfaces::msg::MotorCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<motor_interfaces::msg::MotorCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<motor_interfaces::msg::MotorCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<motor_interfaces::msg::MotorCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__motor_interfaces__msg__MotorCommand
    std::shared_ptr<motor_interfaces::msg::MotorCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__motor_interfaces__msg__MotorCommand
    std::shared_ptr<motor_interfaces::msg::MotorCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorCommand_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->command_type != other.command_type) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorCommand_

// alias to use template instance with default allocator
using MotorCommand =
  motor_interfaces::msg::MotorCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace motor_interfaces

#endif  // MOTOR_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__STRUCT_HPP_
