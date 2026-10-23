#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to motor_interfaces__msg__MotorCommand

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct MotorCommand {

    // This member is not documented.
    #[allow(missing_docs)]
    pub id: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub command_type: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub value: f64,

}



impl Default for MotorCommand {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::MotorCommand::default())
  }
}

impl rosidl_runtime_rs::Message for MotorCommand {
  type RmwMsg = super::msg::rmw::MotorCommand;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
        command_type: msg.command_type.as_str().into(),
        value: msg.value,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
        command_type: msg.command_type.as_str().into(),
      value: msg.value,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
      command_type: msg.command_type.to_string(),
      value: msg.value,
    }
  }
}


