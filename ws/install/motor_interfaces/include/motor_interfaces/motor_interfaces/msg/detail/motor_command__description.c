// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from motor_interfaces:msg/MotorCommand.idl
// generated code does not contain a copyright notice

#include "motor_interfaces/msg/detail/motor_command__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_motor_interfaces
const rosidl_type_hash_t *
motor_interfaces__msg__MotorCommand__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf5, 0x5a, 0xc6, 0xb2, 0x89, 0x4f, 0xd9, 0xf1,
      0x36, 0x0a, 0x52, 0x6b, 0xc5, 0x25, 0x3b, 0x92,
      0x9e, 0xff, 0x89, 0x97, 0xd3, 0xc8, 0x36, 0xbd,
      0xae, 0x32, 0x47, 0x48, 0xf8, 0x8b, 0xc8, 0x4e,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char motor_interfaces__msg__MotorCommand__TYPE_NAME[] = "motor_interfaces/msg/MotorCommand";

// Define type names, field names, and default values
static char motor_interfaces__msg__MotorCommand__FIELD_NAME__id[] = "id";
static char motor_interfaces__msg__MotorCommand__FIELD_NAME__command_type[] = "command_type";
static char motor_interfaces__msg__MotorCommand__FIELD_NAME__value[] = "value";

static rosidl_runtime_c__type_description__Field motor_interfaces__msg__MotorCommand__FIELDS[] = {
  {
    {motor_interfaces__msg__MotorCommand__FIELD_NAME__id, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {motor_interfaces__msg__MotorCommand__FIELD_NAME__command_type, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {motor_interfaces__msg__MotorCommand__FIELD_NAME__value, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
motor_interfaces__msg__MotorCommand__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {motor_interfaces__msg__MotorCommand__TYPE_NAME, 33, 33},
      {motor_interfaces__msg__MotorCommand__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint8 id\n"
  "string command_type\n"
  "float64 value";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
motor_interfaces__msg__MotorCommand__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {motor_interfaces__msg__MotorCommand__TYPE_NAME, 33, 33},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 42, 42},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
motor_interfaces__msg__MotorCommand__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *motor_interfaces__msg__MotorCommand__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
