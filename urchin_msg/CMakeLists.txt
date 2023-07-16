cmake_minimum_required(VERSION 3.0.2)
project(urchin_msg)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  message_generation
  roscpp
  rospy
  std_msgs
)

 add_message_files(
    FILES
    spins.msg
 )

 generate_messages(
   DEPENDENCIES
   geometry_msgs
   std_msgs
 )

catkin_package(
  CATKIN_DEPENDS 
  geometry_msgs message_runtime roscpp rospy std_msgs
)

include_directories(
 include
 ${catkin_INCLUDE_DIRS}
)
