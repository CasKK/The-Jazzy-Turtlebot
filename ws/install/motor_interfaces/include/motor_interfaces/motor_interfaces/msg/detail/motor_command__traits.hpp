// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from motor_interfaces:msg/MotorCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "motor_interfaces/msg/motor_command.hpp"


#ifndef MOTOR_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__TRAITS_HPP_
#define MOTOR_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "motor_interfaces/msg/detail/motor_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace motor_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: command_type
  {
    out << "command_type: ";
    rosidl_generator_traits::value_to_yaml(msg.command_type, out);
    out << ", ";
  }

  // member: value
  {
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: command_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command_type: ";
    rosidl_generator_traits::value_to_yaml(msg.command_type, out);
    out << "\n";
  }

  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorCommand & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace motor_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use motor_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const motor_interfaces::msg::MotorCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  motor_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use motor_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const motor_interfaces::msg::MotorCommand & msg)
{
  return motor_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<motor_interfaces::msg::MotorCommand>()
{
  return "motor_interfaces::msg::MotorCommand";
}

template<>
inline const char * name<motor_interfaces::msg::MotorCommand>()
{
  return "motor_interfaces/msg/MotorCommand";
}

template<>
struct has_fixed_size<motor_interfaces::msg::MotorCommand>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<motor_interfaces::msg::MotorCommand>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<motor_interfaces::msg::MotorCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOTOR_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__TRAITS_HPP_
