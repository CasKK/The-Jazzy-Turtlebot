// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from motor_interfaces:msg/MotorCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "motor_interfaces/msg/motor_command.h"


#ifndef MOTOR_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__STRUCT_H_
#define MOTOR_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'command_type'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/MotorCommand in the package motor_interfaces.
typedef struct motor_interfaces__msg__MotorCommand
{
  uint8_t id;
  rosidl_runtime_c__String command_type;
  double value;
} motor_interfaces__msg__MotorCommand;

// Struct for a sequence of motor_interfaces__msg__MotorCommand.
typedef struct motor_interfaces__msg__MotorCommand__Sequence
{
  motor_interfaces__msg__MotorCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} motor_interfaces__msg__MotorCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOTOR_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__STRUCT_H_
