// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from motor_interfaces:msg/MotorCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "motor_interfaces/msg/motor_command.hpp"


#ifndef MOTOR_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__BUILDER_HPP_
#define MOTOR_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "motor_interfaces/msg/detail/motor_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace motor_interfaces
{

namespace msg
{

namespace builder
{

class Init_MotorCommand_value
{
public:
  explicit Init_MotorCommand_value(::motor_interfaces::msg::MotorCommand & msg)
  : msg_(msg)
  {}
  ::motor_interfaces::msg::MotorCommand value(::motor_interfaces::msg::MotorCommand::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::motor_interfaces::msg::MotorCommand msg_;
};

class Init_MotorCommand_command_type
{
public:
  explicit Init_MotorCommand_command_type(::motor_interfaces::msg::MotorCommand & msg)
  : msg_(msg)
  {}
  Init_MotorCommand_value command_type(::motor_interfaces::msg::MotorCommand::_command_type_type arg)
  {
    msg_.command_type = std::move(arg);
    return Init_MotorCommand_value(msg_);
  }

private:
  ::motor_interfaces::msg::MotorCommand msg_;
};

class Init_MotorCommand_id
{
public:
  Init_MotorCommand_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorCommand_command_type id(::motor_interfaces::msg::MotorCommand::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_MotorCommand_command_type(msg_);
  }

private:
  ::motor_interfaces::msg::MotorCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::motor_interfaces::msg::MotorCommand>()
{
  return motor_interfaces::msg::builder::Init_MotorCommand_id();
}

}  // namespace motor_interfaces

#endif  // MOTOR_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__BUILDER_HPP_
