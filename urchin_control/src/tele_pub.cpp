 /**
  ********************************************************************************************************
  * <one line to give the program's name and a brief idea of what it does.>
  * Copyright (C) <2022>  <jacky>
  * 
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  * 
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  * 
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <https://www.gnu.org/licenses/>.
  ********************************************************************************************************
  */

#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Spawn.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "tele_pub");

  ros::NodeHandle node;

  ros::service::waitForService("spawn");
  ros::ServiceClient add_turtle =
    node.serviceClient<turtlesim::Spawn>("spawn");
  turtlesim::Spawn srv;
  add_turtle.call(srv);

  ros::Publisher urchin_ft111_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_111", 1);ros::Publisher urchin_ft11_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_11", 1);
  ros::Publisher urchin_ft222_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_222", 1);ros::Publisher urchin_ft22_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_22", 1);
  ros::Publisher urchin_ft333_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_333", 1);ros::Publisher urchin_ft33_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_33", 1);
  ros::Publisher urchin_ft444_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_444", 1);ros::Publisher urchin_ft44_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_44", 1);
  ros::Publisher urchin_ft555_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_555", 1);ros::Publisher urchin_ft55_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_55", 1);
  ros::Publisher urchin_ft666_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_666", 1);ros::Publisher urchin_ft66_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_66", 1);
  ros::Publisher urchin_ft777_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_777", 1);ros::Publisher urchin_ft77_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_77", 1);
  ros::Publisher urchin_ft888_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_888", 1);ros::Publisher urchin_ft88_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_88", 1);
  ros::Publisher urchin_ft999_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_999", 1);ros::Publisher urchin_ft99_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_99", 1);
  ros::Publisher urchin_ft101010_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_101010", 1);ros::Publisher urchin_ft1010_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_1010", 1);
  ros::Publisher urchin_ft111111_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_111111", 1);ros::Publisher urchin_ft1111_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_1111", 1);
  ros::Publisher urchin_ft121212_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_121212", 1);ros::Publisher urchin_ft1212_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_1212", 1);
  ros::Publisher urchin_ft131313_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_131313", 1);ros::Publisher urchin_ft1313_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_1313", 1);
  ros::Publisher urchin_ft141414_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_141414", 1);ros::Publisher urchin_ft1414_pub = node.advertise<geometry_msgs::Twist>("/urchin/length_1414", 1);
  // ros::Publisher urchin_base_pub = node.advertise<geometry_msgs::Twist>("/urchin/tf_base", 1);

  tf::TransformListener listener111;tf::TransformListener listener11;
  tf::TransformListener listener222;tf::TransformListener listener22;
  tf::TransformListener listener333;tf::TransformListener listener33;
  tf::TransformListener listener444;tf::TransformListener listener44;
  tf::TransformListener listener555;tf::TransformListener listener55;
  tf::TransformListener listener666;tf::TransformListener listener66;
  tf::TransformListener listener777;tf::TransformListener listener77;
  tf::TransformListener listener888;tf::TransformListener listener88;
  tf::TransformListener listener999;tf::TransformListener listener99;
  tf::TransformListener listener101010;tf::TransformListener listener1010;
  tf::TransformListener listener111111;tf::TransformListener listener1111;
  tf::TransformListener listener121212;tf::TransformListener listener1212;
  tf::TransformListener listener131313;tf::TransformListener listener1313;
  tf::TransformListener listener141414;tf::TransformListener listener1414;
  // tf::TransformListener listenerbase;

  ros::Rate rate(50.0);
  
  while (node.ok()){

    tf::StampedTransform transform111;tf::StampedTransform transform11;
    tf::StampedTransform transform222;tf::StampedTransform transform22;
    tf::StampedTransform transform333;tf::StampedTransform transform33;
    tf::StampedTransform transform444;tf::StampedTransform transform44;
    tf::StampedTransform transform555;tf::StampedTransform transform55;
    tf::StampedTransform transform666;tf::StampedTransform transform66;
    tf::StampedTransform transform777;tf::StampedTransform transform77;
    tf::StampedTransform transform888;tf::StampedTransform transform88;
    tf::StampedTransform transform999;tf::StampedTransform transform99;
    tf::StampedTransform transform101010;tf::StampedTransform transform1010;
    tf::StampedTransform transform111111;tf::StampedTransform transform1111;
    tf::StampedTransform transform121212;tf::StampedTransform transform1212;
    tf::StampedTransform transform131313;tf::StampedTransform transform1313;
    tf::StampedTransform transform141414;tf::StampedTransform transform1414;
    // tf::StampedTransform transformbase;
    try{
      listener111.lookupTransform("111_Link", "11_Link", ros::Time(0), transform111);listener11.lookupTransform("11_Link", "1_Link", ros::Time(0), transform11);
      listener222.lookupTransform("222_Link", "22_Link", ros::Time(0), transform222);listener22.lookupTransform("22_Link", "2_Link", ros::Time(0), transform22);
      listener333.lookupTransform("333_Link", "33_Link", ros::Time(0), transform333);listener33.lookupTransform("33_Link", "3_Link", ros::Time(0), transform33);
      listener444.lookupTransform("444_Link", "44_Link", ros::Time(0), transform444);listener44.lookupTransform("44_Link", "4_Link", ros::Time(0), transform44);
      listener555.lookupTransform("555_Link", "55_Link", ros::Time(0), transform555);listener55.lookupTransform("55_Link", "5_Link", ros::Time(0), transform55);
      listener666.lookupTransform("666_Link", "66_Link", ros::Time(0), transform666);listener66.lookupTransform("66_Link", "6_Link", ros::Time(0), transform66);
      listener777.lookupTransform("777_Link", "77_Link", ros::Time(0), transform777);listener77.lookupTransform("77_Link", "7_Link", ros::Time(0), transform77);
      listener888.lookupTransform("888_Link", "88_Link", ros::Time(0), transform888);listener88.lookupTransform("88_Link", "8_Link", ros::Time(0), transform88);
      listener999.lookupTransform("999_Link", "99_Link", ros::Time(0), transform999);listener99.lookupTransform("99_Link", "9_Link", ros::Time(0), transform99);
      listener101010.lookupTransform("101010_Link", "1010_Link", ros::Time(0), transform101010);listener1010.lookupTransform("1010_Link", "10_Link", ros::Time(0), transform1010);
      listener111111.lookupTransform("111111_Link", "1111_Link", ros::Time(0), transform111111);listener1111.lookupTransform("1111_Link", "11_Link", ros::Time(0), transform1111);
      listener121212.lookupTransform("121212_Link", "1212_Link", ros::Time(0), transform121212);listener1212.lookupTransform("1212_Link", "12_Link", ros::Time(0), transform1212);
      listener131313.lookupTransform("131313_Link", "1313_Link", ros::Time(0), transform131313);listener1313.lookupTransform("1313_Link", "13_Link", ros::Time(0), transform1313);
      listener141414.lookupTransform("141414_Link", "1414_Link", ros::Time(0), transform141414);listener1414.lookupTransform("1414_Link", "14_Link", ros::Time(0), transform1414);
      // listenerbase.lookupTransform("map", "base_Link", ros::Time(0), transformbase);
    }
    catch (tf::TransformException &ex) {
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
      continue;
    }

    geometry_msgs::Twist tele111_msg;geometry_msgs::Twist tele11_msg;
    geometry_msgs::Twist tele222_msg;geometry_msgs::Twist tele22_msg;
    geometry_msgs::Twist tele333_msg;geometry_msgs::Twist tele33_msg;
    geometry_msgs::Twist tele444_msg;geometry_msgs::Twist tele44_msg;
    geometry_msgs::Twist tele555_msg;geometry_msgs::Twist tele55_msg;
    geometry_msgs::Twist tele666_msg;geometry_msgs::Twist tele66_msg;
    geometry_msgs::Twist tele777_msg;geometry_msgs::Twist tele77_msg;
    geometry_msgs::Twist tele888_msg;geometry_msgs::Twist tele88_msg;
    geometry_msgs::Twist tele999_msg;geometry_msgs::Twist tele99_msg;
    geometry_msgs::Twist tele101010_msg;geometry_msgs::Twist tele1010_msg;
    geometry_msgs::Twist tele111111_msg;geometry_msgs::Twist tele1111_msg;
    geometry_msgs::Twist tele121212_msg;geometry_msgs::Twist tele1212_msg;
    geometry_msgs::Twist tele131313_msg;geometry_msgs::Twist tele1313_msg;
    geometry_msgs::Twist tele141414_msg;geometry_msgs::Twist tele1414_msg;
    // geometry_msgs::Twist base_msg;

    tele111_msg.angular.z = transform111.getOrigin().y(); tele111_msg.linear.x = transform111.getOrigin().x();tele11_msg.angular.z = transform11.getOrigin().y(); tele11_msg.linear.x = transform11.getOrigin().x();
    tele222_msg.angular.z = transform222.getOrigin().y(); tele222_msg.linear.x = transform222.getOrigin().x();tele22_msg.angular.z = transform22.getOrigin().y(); tele22_msg.linear.x = transform22.getOrigin().x();
    tele333_msg.angular.z = transform333.getOrigin().y(); tele333_msg.linear.x = transform333.getOrigin().x();tele33_msg.angular.z = transform33.getOrigin().y(); tele33_msg.linear.x = transform33.getOrigin().x();
    tele444_msg.angular.z = transform444.getOrigin().y(); tele444_msg.linear.x = transform444.getOrigin().x();tele44_msg.angular.z = transform44.getOrigin().y(); tele44_msg.linear.x = transform44.getOrigin().x();
    tele555_msg.angular.z = transform555.getOrigin().y(); tele555_msg.linear.x = transform555.getOrigin().x();tele55_msg.angular.z = transform55.getOrigin().y(); tele55_msg.linear.x = transform55.getOrigin().x();
    tele666_msg.angular.z = transform666.getOrigin().y(); tele666_msg.linear.x = transform666.getOrigin().x();tele66_msg.angular.z = transform66.getOrigin().y(); tele66_msg.linear.x = transform66.getOrigin().x();
    tele777_msg.angular.z = transform777.getOrigin().y(); tele777_msg.linear.x = transform777.getOrigin().x();tele77_msg.angular.z = transform77.getOrigin().y(); tele77_msg.linear.x = transform77.getOrigin().x();
    tele888_msg.angular.z = transform888.getOrigin().y(); tele888_msg.linear.x = transform888.getOrigin().x();tele88_msg.angular.z = transform88.getOrigin().y(); tele88_msg.linear.x = transform88.getOrigin().x();
    tele999_msg.angular.z = transform999.getOrigin().y(); tele999_msg.linear.x = transform999.getOrigin().x();tele99_msg.angular.z = transform99.getOrigin().y(); tele99_msg.linear.x = transform99.getOrigin().x();
    tele101010_msg.angular.z = transform101010.getOrigin().y(); tele101010_msg.linear.x = transform101010.getOrigin().x();tele1010_msg.angular.z = transform1010.getOrigin().y(); tele1010_msg.linear.x = transform1010.getOrigin().x();
    tele111111_msg.angular.z = transform111111.getOrigin().y(); tele111111_msg.linear.x = transform111111.getOrigin().x();tele1111_msg.angular.z = transform1111.getOrigin().y(); tele1111_msg.linear.x = transform1111.getOrigin().x();
    tele121212_msg.angular.z = transform121212.getOrigin().y(); tele121212_msg.linear.x = transform121212.getOrigin().x();tele1212_msg.angular.z = transform1212.getOrigin().y(); tele1212_msg.linear.x = transform1212.getOrigin().x();
    tele131313_msg.angular.z = transform131313.getOrigin().y(); tele131313_msg.linear.x = transform131313.getOrigin().x();tele1313_msg.angular.z = transform1313.getOrigin().y(); tele1313_msg.linear.x = transform1313.getOrigin().x();
    tele141414_msg.angular.z = transform141414.getOrigin().y(); tele141414_msg.linear.x = transform141414.getOrigin().x();tele1414_msg.angular.z = transform1414.getOrigin().y(); tele1414_msg.linear.x = transform1414.getOrigin().x();
    // base_msg.linear.x = transformbase.getOrigin().x(); base_msg.linear.y = transformbase.getOrigin().y();base_msg.linear.z = transformbase.getOrigin().z(); 

    urchin_ft111_pub.publish(tele111_msg); urchin_ft11_pub.publish(tele11_msg);
    urchin_ft222_pub.publish(tele222_msg); urchin_ft22_pub.publish(tele22_msg);
    urchin_ft333_pub.publish(tele333_msg); urchin_ft33_pub.publish(tele33_msg);
    urchin_ft444_pub.publish(tele444_msg); urchin_ft44_pub.publish(tele44_msg);
    urchin_ft555_pub.publish(tele555_msg); urchin_ft55_pub.publish(tele55_msg);
    urchin_ft666_pub.publish(tele666_msg); urchin_ft66_pub.publish(tele66_msg);
    urchin_ft777_pub.publish(tele777_msg);urchin_ft77_pub.publish(tele77_msg);
    urchin_ft888_pub.publish(tele888_msg);urchin_ft88_pub.publish(tele88_msg);
    urchin_ft999_pub.publish(tele999_msg);urchin_ft99_pub.publish(tele99_msg);
    urchin_ft101010_pub.publish(tele101010_msg);urchin_ft1010_pub.publish(tele1010_msg);
    urchin_ft111111_pub.publish(tele111111_msg);urchin_ft1111_pub.publish(tele1111_msg);
    urchin_ft121212_pub.publish(tele121212_msg);urchin_ft1212_pub.publish(tele1212_msg);
    urchin_ft131313_pub.publish(tele131313_msg);urchin_ft1313_pub.publish(tele1313_msg);
    urchin_ft141414_pub.publish(tele141414_msg);urchin_ft1414_pub.publish(tele1414_msg);
    // urchin_base_pub.publish(base_msg);

    rate.sleep();
  }
  return 0;
};