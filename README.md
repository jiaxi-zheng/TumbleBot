# Gazebo ROS Demos

* Author: jacky <jiaxizheng11@gmail.com>
* License: GNU General Public License, version 3 (GPL-3.0)

Example robots and code for interfacing Gazebo with ROS

## Tutorials

[ROS URDF](http://gazebosim.org/tutorials/?tut=ros_urdf)

## Quick Start

Rviz:

    roslaunch urchin_description rrbot_rviz.launch

Gazebo:

    roslaunch urchin_gazebo urchin_world.launch

ROS Control:

    roslaunch urchin_control urchin_control.launch

Example of Moving Joints:

    rostopic pub /rrbot/joint2_position_controller/command std_msgs/Float64 "data: -0.9"

## Develop and Contribute

We welcome any contributions to this repo and encourage you to fork the project then send pull requests back to this parent repo. Thanks for your help!
sudo apt install ros-noetic-navigation
sudo apt-get install ros-noetic-joint-trajectory-controller
sudo apt install ros-noetic-velocity-controllers
