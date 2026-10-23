#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "motor_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__motor_interfaces__msg__MotorCommand() -> *const std::ffi::c_void;
}

#[link(name = "motor_interfaces__rosidl_generator_c")]
extern "C" {
    fn motor_interfaces__msg__MotorCommand__init(msg: *mut MotorCommand) -> bool;
    fn motor_interfaces__msg__MotorCommand__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<MotorCommand>, size: usize) -> bool;
    fn motor_interfaces__msg__MotorCommand__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<MotorCommand>);
    fn motor_interfaces__msg__MotorCommand__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<MotorCommand>, out_seq: *mut rosidl_runtime_rs::Sequence<MotorCommand>) -> bool;
}

// Corresponds to motor_interfaces__msg__MotorCommand
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MotorCommand {

    // This member is not documented.
    #[allow(missing_docs)]
    pub id: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub command_type: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub value: f64,

}



impl Default for MotorCommand {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !motor_interfaces__msg__MotorCommand__init(&mut msg as *mut _) {
        panic!("Call to motor_interfaces__msg__MotorCommand__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for MotorCommand {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { motor_interfaces__msg__MotorCommand__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { motor_interfaces__msg__MotorCommand__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { motor_interfaces__msg__MotorCommand__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for MotorCommand {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for MotorCommand where Self: Sized {
  const TYPE_NAME: &'static str = "motor_interfaces/msg/MotorCommand";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__motor_interfaces__msg__MotorCommand() }
  }
}


