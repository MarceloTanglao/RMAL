// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from open_manipulator_msgs:srv/SetJointPosition.idl
// generated code does not contain a copyright notice

#ifndef OPEN_MANIPULATOR_MSGS__SRV__DETAIL__SET_JOINT_POSITION__TRAITS_HPP_
#define OPEN_MANIPULATOR_MSGS__SRV__DETAIL__SET_JOINT_POSITION__TRAITS_HPP_

#include "open_manipulator_msgs/srv/detail/set_joint_position__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'joint_position'
#include "open_manipulator_msgs/msg/detail/joint_position__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<open_manipulator_msgs::srv::SetJointPosition_Request>()
{
  return "open_manipulator_msgs::srv::SetJointPosition_Request";
}

template<>
inline const char * name<open_manipulator_msgs::srv::SetJointPosition_Request>()
{
  return "open_manipulator_msgs/srv/SetJointPosition_Request";
}

template<>
struct has_fixed_size<open_manipulator_msgs::srv::SetJointPosition_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<open_manipulator_msgs::srv::SetJointPosition_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<open_manipulator_msgs::srv::SetJointPosition_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<open_manipulator_msgs::srv::SetJointPosition_Response>()
{
  return "open_manipulator_msgs::srv::SetJointPosition_Response";
}

template<>
inline const char * name<open_manipulator_msgs::srv::SetJointPosition_Response>()
{
  return "open_manipulator_msgs/srv/SetJointPosition_Response";
}

template<>
struct has_fixed_size<open_manipulator_msgs::srv::SetJointPosition_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<open_manipulator_msgs::srv::SetJointPosition_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<open_manipulator_msgs::srv::SetJointPosition_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<open_manipulator_msgs::srv::SetJointPosition>()
{
  return "open_manipulator_msgs::srv::SetJointPosition";
}

template<>
inline const char * name<open_manipulator_msgs::srv::SetJointPosition>()
{
  return "open_manipulator_msgs/srv/SetJointPosition";
}

template<>
struct has_fixed_size<open_manipulator_msgs::srv::SetJointPosition>
  : std::integral_constant<
    bool,
    has_fixed_size<open_manipulator_msgs::srv::SetJointPosition_Request>::value &&
    has_fixed_size<open_manipulator_msgs::srv::SetJointPosition_Response>::value
  >
{
};

template<>
struct has_bounded_size<open_manipulator_msgs::srv::SetJointPosition>
  : std::integral_constant<
    bool,
    has_bounded_size<open_manipulator_msgs::srv::SetJointPosition_Request>::value &&
    has_bounded_size<open_manipulator_msgs::srv::SetJointPosition_Response>::value
  >
{
};

template<>
struct is_service<open_manipulator_msgs::srv::SetJointPosition>
  : std::true_type
{
};

template<>
struct is_service_request<open_manipulator_msgs::srv::SetJointPosition_Request>
  : std::true_type
{
};

template<>
struct is_service_response<open_manipulator_msgs::srv::SetJointPosition_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // OPEN_MANIPULATOR_MSGS__SRV__DETAIL__SET_JOINT_POSITION__TRAITS_HPP_
