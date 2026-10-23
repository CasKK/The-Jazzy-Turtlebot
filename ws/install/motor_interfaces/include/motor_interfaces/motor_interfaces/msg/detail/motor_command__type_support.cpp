// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from motor_interfaces:msg/MotorCommand.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "motor_interfaces/msg/detail/motor_command__functions.h"
#include "motor_interfaces/msg/detail/motor_command__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace motor_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MotorCommand_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) motor_interfaces::msg::MotorCommand(_init);
}

void MotorCommand_fini_function(void * message_memory)
{
  auto typed_message = static_cast<motor_interfaces::msg::MotorCommand *>(message_memory);
  typed_message->~MotorCommand();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MotorCommand_message_member_array[3] = {
  {
    "id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motor_interfaces::msg::MotorCommand, id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "command_type",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motor_interfaces::msg::MotorCommand, command_type),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "value",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(motor_interfaces::msg::MotorCommand, value),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MotorCommand_message_members = {
  "motor_interfaces::msg",  // message namespace
  "MotorCommand",  // message name
  3,  // number of fields
  sizeof(motor_interfaces::msg::MotorCommand),
  false,  // has_any_key_member_
  MotorCommand_message_member_array,  // message members
  MotorCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  MotorCommand_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MotorCommand_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MotorCommand_message_members,
  get_message_typesupport_handle_function,
  &motor_interfaces__msg__MotorCommand__get_type_hash,
  &motor_interfaces__msg__MotorCommand__get_type_description,
  &motor_interfaces__msg__MotorCommand__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace motor_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<motor_interfaces::msg::MotorCommand>()
{
  return &::motor_interfaces::msg::rosidl_typesupport_introspection_cpp::MotorCommand_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, motor_interfaces, msg, MotorCommand)() {
  return &::motor_interfaces::msg::rosidl_typesupport_introspection_cpp::MotorCommand_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
