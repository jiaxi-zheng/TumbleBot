cmake_minimum_required(VERSION 3.0.2)
project(urchin_control)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  tf
  turtlesim
  urchin_msg
)

catkin_package()

add_executable(Fixed_motion src/Fixed_motion.cpp)
target_link_libraries(Fixed_motion ${catkin_LIBRARIES})

add_executable(tele_pub src/tele_pub.cpp)
target_link_libraries(tele_pub ${catkin_LIBRARIES})

include_directories(include ${catkin_INCLUDE_DIRS} )

install(DIRECTORY config
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
