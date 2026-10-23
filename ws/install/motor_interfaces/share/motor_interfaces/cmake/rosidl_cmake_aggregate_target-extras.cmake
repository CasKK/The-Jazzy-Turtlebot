# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target motor_interfaces::motor_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${motor_interfaces_TARGETS}.
if(motor_interfaces_TARGETS AND NOT TARGET motor_interfaces::motor_interfaces)
  add_library(motor_interfaces::motor_interfaces INTERFACE IMPORTED)
  set_target_properties(motor_interfaces::motor_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${motor_interfaces_TARGETS}")
endif()
