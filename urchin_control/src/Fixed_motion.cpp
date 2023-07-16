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

#include"ros/ros.h"
#include"string"
#include"stdio.h"
#include"std_msgs/Float64.h"
#include"unistd.h"
#include"sys/types.h"
#include"sys/signal.h"
#include"sys/stat.h"
#include"fcntl.h"
#include"termios.h"
#include"errno.h"
#include"limits.h"
#include"stdint.h"
#include"iostream"
#include"vector"
#include"geometry_msgs/TransformStamped.h"
#include"geometry_msgs/Twist.h"

using namespace std;
/***********1************/
float spin_vel_1_set = 0.01;//0.009
float spin_vel_1_set_left = 0.01;//0.017
float spin_vel_1_set_right = 0.01;//0.013

/***********2************/
float spin_vel_2_set = 0.01;
float spin_vel_2_set_left = 0.01;
float spin_vel_2_set_right = 0.011;

/***********3************/
float spin_vel_3_set = 0.01;//0.009
float spin_vel_3_set_left = 0.01;//0.017
float spin_vel_3_set_right = 0.01;//0.013

/***********4************/
float spin_vel_4_set = 0.01;
float spin_vel_4_set_left = 0.01;
float spin_vel_4_set_right = 0.01;

double LEN_111;
double LEN_222;
double LEN_555;
double LEN_666;

class command_comb
{
private:

    ros::NodeHandle nh; 
    std_msgs::Float64 output_netLoad;

    ros::Subscriber TF_sub;
	ros::Subscriber joy_depth_sub;
    ros::Subscriber joy_x_sub;
    ros::Subscriber joy_y_sub;
    ros::Subscriber joy_yaw_sub;

    ros::Subscriber LINK_1_LEN_SUB;
    ros::Subscriber LINK_2_LEN_SUB;
    ros::Subscriber LINK_5_LEN_SUB;
    ros::Subscriber LINK_6_LEN_SUB;

    ros::Publisher val_pub_111;ros::Publisher val_pub_11;ros::Publisher val_pub_1;ros::Publisher val_pub_222;ros::Publisher val_pub_22;ros::Publisher val_pub_2;ros::Publisher val_pub_333;ros::Publisher val_pub_33;
    ros::Publisher val_pub_3;ros::Publisher val_pub_444;ros::Publisher val_pub_44;ros::Publisher val_pub_4;ros::Publisher val_pub_555;ros::Publisher val_pub_55;ros::Publisher val_pub_5;ros::Publisher val_pub_666;
    ros::Publisher val_pub_66;ros::Publisher val_pub_6;ros::Publisher val_pub_777;ros::Publisher val_pub_77;ros::Publisher val_pub_7;ros::Publisher val_pub_888;ros::Publisher val_pub_88;ros::Publisher val_pub_8;
    ros::Publisher val_pub_999;ros::Publisher val_pub_99;ros::Publisher val_pub_9;ros::Publisher val_pub_101010;ros::Publisher val_pub_1010;ros::Publisher val_pub_10;ros::Publisher val_pub_111111;ros::Publisher val_pub_1111;
    ros::Publisher val_pub__11;ros::Publisher val_pub_121212;ros::Publisher val_pub_1212;ros::Publisher val_pub_12;ros::Publisher val_pub_131313;ros::Publisher val_pub_1313;ros::Publisher val_pub_13;ros::Publisher val_pub_141414;
    ros::Publisher val_pub_1414;ros::Publisher val_pub_14;

public:

    command_comb()       
    {
        val_pub_111 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_111/command",1);val_pub_11 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_11/command",1);val_pub_1 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_1/command",1);
        val_pub_222 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_222/command",1);val_pub_22 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_22/command",1);val_pub_2= nh.advertise<std_msgs::Float64>("/urchin_bot/joint_2/command",1);
        val_pub_333 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_333/command",1);val_pub_33 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_33/command",1);val_pub_3 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_3/command",1);
        val_pub_444 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_444/command",1);val_pub_44 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_44/command",1);val_pub_4= nh.advertise<std_msgs::Float64>("/urchin_bot/joint_4/command",1);
        val_pub_555 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_555/command",1);val_pub_55 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_55/command",1);val_pub_5 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_5/command",1);
        val_pub_666 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_666/command",1);val_pub_66 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_66/command",1);val_pub_6 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_6/command",1);
        val_pub_777 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_777/command",1);val_pub_77 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_77/command",1);val_pub_7 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_7/command",1);
        val_pub_888 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_888/command",1);val_pub_88 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_88/command",1);val_pub_8 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_8/command",1);
        val_pub_999 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_999/command",1);val_pub_99 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_99/command",1);val_pub_9= nh.advertise<std_msgs::Float64>("/urchin_bot/joint_9/command",1);
        val_pub_101010 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_101010/command",1);val_pub_1010 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_1010/command",1);val_pub_10 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_10/command",1);
        val_pub_111111 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_111111/command",1);val_pub_1111 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_1111/command",1);val_pub__11= nh.advertise<std_msgs::Float64>("/urchin_bot/joint__11/command",1);
        val_pub_121212 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_121212/command",1);val_pub_1212 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_1212/command",1);val_pub_12 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_12/command",1);
        val_pub_131313 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_131313/command",1);val_pub_1313 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_1313/command",1);val_pub_13 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_13/command",1);
        val_pub_141414 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_141414/command",1);val_pub_1414 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_1414/command",1);val_pub_14 = nh.advertise<std_msgs::Float64>("/urchin_bot/joint_14/command",1);

        // joy_depth_sub = nh.subscribe("/command/depth",1,&command_comb::Depth_callback,this);
        // joy_x_sub = nh.subscribe("/command/x",1,&command_comb::X_callback,this);
        // joy_y_sub = nh.subscribe("/command/y",1,&command_comb::Y_callback,this);
        // joy_yaw_sub = nh.subscribe("/command/yaw",1,&command_comb::Yaw_callback,this);

        LINK_1_LEN_SUB = nh.subscribe("/urchin/length_111",1,&command_comb::L111_callback,this);
        LINK_2_LEN_SUB = nh.subscribe("/urchin/length_222",1,&command_comb::L222_callback,this);
        LINK_5_LEN_SUB = nh.subscribe("/urchin/length_555",1,&command_comb::L555_callback,this);
        LINK_6_LEN_SUB = nh.subscribe("/urchin/length_666",1,&command_comb::L666_callback,this);

        TF_sub = nh.subscribe("/tf",1,&command_comb::TF_CB,this);
    }

    ~command_comb() 
    {
         //cv::destroyAllWindows();
         //cv::destroyWindow(OUTPUT);
    }

    string lin_2 = "2_link";

    void TF_CB(const geometry_msgs::TransformStamped& msg) 
    {
        if(msg.child_frame_id == lin_2 )
        {
            cout<<"hh"<<endl;
            cout<<"pasehere"<<endl;
        }
    }

    // void Depth_callback(const urchin_msg::DepthCommand &msg)	{output_netLoad.data  = 0.0003*msg.depth;val_pub_111.publish(output_netLoad);val_pub_11.publish(output_netLoad);val_pub_1.publish(output_netLoad);}
    // void X_callback(const urchin_msg::LinearCommand &msg)	{output_netLoad.data  = 0.0003*msg.value;val_pub_222.publish(output_netLoad);val_pub_22.publish(output_netLoad);val_pub_2.publish(output_netLoad); }
    // void Y_callback(const urchin_msg::LinearCommand &msg)	{output_netLoad.data  = 0.0003*msg.value;val_pub_555.publish(output_netLoad);val_pub_55.publish(output_netLoad);val_pub_5.publish(output_netLoad); }
    // void Yaw_callback(const urchin_msg::AttitudeCommand &msg)	{output_netLoad.data  = 0.0003*msg.value;val_pub_666.publish(output_netLoad);val_pub_66.publish(output_netLoad);val_pub_6.publish(output_netLoad); }

    void L111_callback(const geometry_msgs::Twist &msg)	{output_netLoad.data  = -2*(0.04-msg.linear.x);val_pub_111.publish(output_netLoad);val_pub_11.publish(output_netLoad);val_pub_1.publish(output_netLoad); }
    void L222_callback(const geometry_msgs::Twist &msg)	{output_netLoad.data  = -2*(0.04-msg.linear.x);val_pub_222.publish(output_netLoad);val_pub_22.publish(output_netLoad);val_pub_2.publish(output_netLoad); }
    void L555_callback(const geometry_msgs::Twist &msg)	{output_netLoad.data  = -2*(0.04-msg.linear.x);val_pub_555.publish(output_netLoad);val_pub_55.publish(output_netLoad);val_pub_5.publish(output_netLoad); }
    void L666_callback(const geometry_msgs::Twist &msg)	{output_netLoad.data  = -2*(0.04-msg.linear.x);val_pub_666.publish(output_netLoad);val_pub_66.publish(output_netLoad);val_pub_6.publish(output_netLoad); }

    void spin1_push(float spin_vel){output_netLoad.data = -spin_vel;val_pub_111.publish(output_netLoad);val_pub_11.publish(output_netLoad);val_pub_1.publish(output_netLoad);}
    void spin1_retract(float spin_vel){output_netLoad.data = spin_vel;val_pub_111.publish(output_netLoad);val_pub_11.publish(output_netLoad);val_pub_1.publish(output_netLoad);}

    void spin2_push(float spin_vel){output_netLoad.data = -spin_vel;val_pub_222.publish(output_netLoad);val_pub_22.publish(output_netLoad);val_pub_2.publish(output_netLoad); }
    void spin2_retract(float spin_vel){output_netLoad.data = spin_vel;val_pub_222.publish(output_netLoad);val_pub_22.publish(output_netLoad);val_pub_2.publish(output_netLoad);}

    void spin3_push(float spin_vel){output_netLoad.data = -spin_vel;val_pub_333.publish(output_netLoad);val_pub_33.publish(output_netLoad);val_pub_3.publish(output_netLoad);}
    void spin3_retract(float spin_vel){output_netLoad.data = spin_vel;val_pub_333.publish(output_netLoad);val_pub_33.publish(output_netLoad);val_pub_3.publish(output_netLoad);}

    void spin4_push(float spin_vel){output_netLoad.data = -spin_vel;val_pub_444.publish(output_netLoad);val_pub_44.publish(output_netLoad);val_pub_4.publish(output_netLoad); }
    void spin4_retract(float spin_vel){output_netLoad.data = spin_vel;val_pub_444.publish(output_netLoad);val_pub_44.publish(output_netLoad);val_pub_4.publish(output_netLoad);}

    void spin5_push(float spin_vel){output_netLoad.data = -spin_vel;val_pub_555.publish(output_netLoad);val_pub_55.publish(output_netLoad);val_pub_5.publish(output_netLoad);}
    void spin5_retract(float spin_vel){output_netLoad.data = spin_vel;val_pub_555.publish(output_netLoad);val_pub_55.publish(output_netLoad);val_pub_5.publish(output_netLoad);}

    void spin6_push(float spin_vel){output_netLoad.data = -spin_vel;val_pub_666.publish(output_netLoad);val_pub_66.publish(output_netLoad);val_pub_6.publish(output_netLoad); }
    void spin6_retract(float spin_vel){output_netLoad.data = spin_vel;val_pub_666.publish(output_netLoad);val_pub_66.publish(output_netLoad);val_pub_6.publish(output_netLoad);}

    void spin7_push(float spin_vel){output_netLoad.data = -spin_vel;val_pub_777.publish(output_netLoad);val_pub_77.publish(output_netLoad);val_pub_7.publish(output_netLoad);}
    void spin7_retract(float spin_vel){output_netLoad.data = spin_vel;val_pub_777.publish(output_netLoad);val_pub_77.publish(output_netLoad);val_pub_7.publish(output_netLoad);}

    void spin8_push(float spin_vel){output_netLoad.data = -spin_vel;val_pub_888.publish(output_netLoad);val_pub_88.publish(output_netLoad);val_pub_8.publish(output_netLoad); }
    void spin8_retract(float spin_vel){output_netLoad.data = spin_vel;val_pub_888.publish(output_netLoad);val_pub_88.publish(output_netLoad);val_pub_8.publish(output_netLoad);}

    void spin9_push(float spin_vel){output_netLoad.data = -spin_vel;val_pub_999.publish(output_netLoad);val_pub_99.publish(output_netLoad);val_pub_9.publish(output_netLoad);}
    void spin9_retract(float spin_vel){output_netLoad.data = spin_vel;val_pub_999.publish(output_netLoad);val_pub_99.publish(output_netLoad);val_pub_9.publish(output_netLoad);}

    void spin10_push(float spin_vel){output_netLoad.data = -spin_vel;val_pub_101010.publish(output_netLoad);val_pub_1010.publish(output_netLoad);val_pub_10.publish(output_netLoad); }
    void spin10_retract(float spin_vel){output_netLoad.data = spin_vel;val_pub_101010.publish(output_netLoad);val_pub_1010.publish(output_netLoad);val_pub_10.publish(output_netLoad);}

    void spin11_push(float spin_vel){output_netLoad.data = -spin_vel;val_pub_111111.publish(output_netLoad);val_pub_1111.publish(output_netLoad);val_pub__11.publish(output_netLoad);}
    void spin11_retract(float spin_vel){output_netLoad.data = spin_vel;val_pub_111111.publish(output_netLoad);val_pub_1111.publish(output_netLoad);val_pub__11.publish(output_netLoad);}

    void spin12_push(float spin_vel){output_netLoad.data = -spin_vel;val_pub_121212.publish(output_netLoad);val_pub_1212.publish(output_netLoad);val_pub_12.publish(output_netLoad); }
    void spin12_retract(float spin_vel){output_netLoad.data = spin_vel;val_pub_121212.publish(output_netLoad);val_pub_1212.publish(output_netLoad);val_pub_12.publish(output_netLoad);}

    void spin13_push(float spin_vel){output_netLoad.data = -spin_vel;val_pub_131313.publish(output_netLoad);val_pub_1313.publish(output_netLoad);val_pub_13.publish(output_netLoad);}
    void spin13_retract(float spin_vel){output_netLoad.data = spin_vel;val_pub_131313.publish(output_netLoad);val_pub_1313.publish(output_netLoad);val_pub_13.publish(output_netLoad);}

    void spin14_push(float spin_vel){output_netLoad.data = -spin_vel;val_pub_141414.publish(output_netLoad);val_pub_1414.publish(output_netLoad);val_pub_14.publish(output_netLoad); }
    void spin14_retract(float spin_vel){output_netLoad.data = spin_vel;val_pub_141414.publish(output_netLoad);val_pub_1414.publish(output_netLoad);val_pub_14.publish(output_netLoad);}

    void stop()
    {
        spin1_retract(0);
        spin2_retract(0);
        spin3_retract(0);
        spin4_retract(0);
        spin5_retract(0);
        spin6_retract(0);
        spin7_retract(0);
        spin8_retract(0);
        spin9_retract(0);
        spin10_retract(0);
        spin11_retract(0);
        spin12_retract(0);
        spin13_retract(0);
        spin14_retract(0);
        sleep(10);
    }
    /*****************************************************************************/
    /*****************************************************************************/
    void run_init()
    {
        sleep(2);
        spin1_push(0.05);
        spin2_push(0.05);
        spin5_push(0.05);
        spin6_push(0.05);
        sleep(5);
        spin3_retract(0.05);
        spin4_retract(0.05);
        spin7_retract(0.05);
        spin8_retract(0.05);
        spin9_retract(0.05);
        spin10_retract(0.05);
        spin11_retract(0.05);
        spin12_retract(0.05);
        spin13_retract(0.05);
        spin14_retract(0.05);

        sleep(4.5);

        spin2_retract(spin_vel_1_set_left);
        spin1_retract(spin_vel_1_set_right);
    
        ros::Duration(1).sleep(); 
    }

    void run()
    {
        /********************************************************/
        ros::Duration(2).sleep(); 

        spin2_retract(spin_vel_1_set_left);
        spin1_retract(spin_vel_1_set_right);

        ros::Duration(1).sleep(); 

        spin10_push(3*spin_vel_1_set);
        spin13_push(2*spin_vel_1_set);

        //  spin2_retract(0);
        //  spin1_retract(0);

        spin6_retract(2*spin_vel_1_set_left);
        spin5_retract(2*spin_vel_1_set_right);

        ros::Duration(1.4).sleep(); 

        spin13_retract(spin_vel_1_set);

        spin3_push(1.2*spin_vel_1_set_left);
        spin4_push(1.2*spin_vel_1_set_right);
        spin2_push(spin_vel_1_set_left);
        spin1_push(spin_vel_1_set_right);

        ros::Duration(1.2).sleep(); 

        spin13_retract(0);
    
        spin10_retract(3*spin_vel_1_set);
    /********************************************************/
        ros::Duration(2).sleep(); 

        spin3_retract(spin_vel_1_set_left);//retract-2s
        spin4_retract(spin_vel_1_set_right);//retract-2s

        ros::Duration(1).sleep(); 

        spin13_push(3*spin_vel_1_set);
        spin12_push(2*spin_vel_1_set);

        //  spin3_retract(0);
        //  spin4_retract(0);

        spin1_retract(2*spin_vel_1_set_right);//to_end
        spin2_retract(2*spin_vel_1_set_left);//to_end

        ros::Duration(1.4).sleep(); 

        spin12_retract(spin_vel_1_set);

        spin7_push(1.2*spin_vel_1_set_left);
        spin8_push(1.2*spin_vel_1_set_right);
        spin3_push(spin_vel_1_set_left);
        spin4_push(spin_vel_1_set_right);

        ros::Duration(1.2).sleep(); 

        spin12_retract(0);
    
        spin13_retract(3*spin_vel_1_set);
    /********************************************************/
        ros::Duration(2).sleep(); 

        spin7_retract(spin_vel_1_set_left);
        spin8_retract(spin_vel_1_set_right);

        ros::Duration(1).sleep(); 

        spin12_push(3*spin_vel_1_set);
        spin14_push(2*spin_vel_1_set);

        //  spin7_retract(0);
        //  spin8_retract(0);

        spin4_retract(2*spin_vel_1_set_right);
        spin3_retract(2*spin_vel_1_set_left);

        //ros::Duration(0.2).sleep(); 

        ros::Duration(1.4).sleep(); 

        spin14_retract(spin_vel_1_set);

        spin6_push(1.2*spin_vel_1_set_left);
        spin5_push(1.2*spin_vel_1_set_right);
        spin7_push(spin_vel_1_set_left);
        spin8_push(spin_vel_1_set_right);

        ros::Duration(1.2).sleep(); 

        spin14_retract(0);
    
        spin12_retract(3*spin_vel_1_set);
    /********************************************************/
        ros::Duration(2).sleep(); 

        spin6_retract(spin_vel_1_set_left);
        spin5_retract(spin_vel_1_set_right);

        ros::Duration(1).sleep(); 

        spin14_push(3*spin_vel_1_set);
        spin10_push(2*spin_vel_1_set);

        //  spin6_retract(0);
        //  spin5_retract(0);

        spin7_retract(2*spin_vel_1_set_left);
        spin8_retract(2*spin_vel_1_set_right);

        //ros::Duration(0.2).sleep(); 

        ros::Duration(1.4).sleep(); 

        spin10_retract(spin_vel_1_set);

        spin2_push(1.2*spin_vel_1_set_left);
        spin1_push(1.2*spin_vel_1_set_right);
        spin6_push(spin_vel_1_set_left);
        spin5_push(spin_vel_1_set_right);

        ros::Duration(1.2).sleep(); 

        spin10_retract(0);

        spin14_retract(3*spin_vel_1_set);

    }
    /*****************************************************************************/
    /*****************************************************************************/
    void turn_left_init()
    {
        spin2_push(0.05);
        spin1_push(0.05);
        spin6_push(0.05);
        spin5_push(0.05);
        ros::Duration(2).sleep(); 

        spin1_retract(spin_vel_2_set_left);
        spin5_retract(spin_vel_2_set_right);

        ros::Duration(1).sleep(); 
    }
    void turn_left()
    {
        /********************************************************/
        ros::Duration(2).sleep(); 

        spin5_retract(spin_vel_2_set_right);
        spin1_retract(spin_vel_2_set_left);

        ros::Duration(1).sleep(); 

        spin10_push(0.03);
        spin9_push(0.02);

        //  spin2_retract(0);
        //  spin1_retract(0);

        spin6_retract(2*spin_vel_2_set_right);
        spin2_retract(2*spin_vel_2_set_left);

        //ros::Duration(0.2).sleep(); 

        ros::Duration(1.4).sleep(); 

        spin9_retract(0.01);

        spin8_push(1.2*spin_vel_2_set_right);
        spin4_push(1.2*spin_vel_2_set_left);
        spin5_push(spin_vel_2_set_right);
        spin1_push(spin_vel_2_set_left);

        ros::Duration(1.2).sleep(); 

        spin9_retract(0);
    
        spin10_retract(0.03);
        /********************************************************/
        ros::Duration(2).sleep(); 

        spin4_retract(spin_vel_2_set_left);
        spin8_retract(spin_vel_2_set_right);

        ros::Duration(1).sleep(); 

        spin9_push(0.03);
        spin12_push(0.02);

        //  spin2_retract(0);
        //  spin1_retract(0);

        spin1_retract(2*spin_vel_2_set_left);
        spin5_retract(2*spin_vel_2_set_right);

        //ros::Duration(0.2).sleep(); 

        ros::Duration(1.4).sleep(); 

        spin12_retract(0.01);

        spin3_push(1.2*spin_vel_2_set_left);
        spin7_push(1.2*spin_vel_2_set_right);
        spin4_push(spin_vel_2_set_left);
        spin8_push(spin_vel_2_set_right);

        ros::Duration(1.2).sleep(); 

        spin12_retract(0);
    
        spin9_retract(0.03);
        /********************************************************/
        ros::Duration(2).sleep(); 

        spin3_retract(spin_vel_2_set_left);
        spin7_retract(spin_vel_2_set_right);

        ros::Duration(1).sleep(); 

        spin12_push(0.03);
        spin11_push(0.02);

        //  spin2_retract(0);
        //  spin1_retract(0);

        spin4_retract(2*spin_vel_2_set_left);
        spin8_retract(2*spin_vel_2_set_right);

        //ros::Duration(0.2).sleep(); 

        ros::Duration(1.4).sleep(); 

        spin11_retract(0.01);

        spin2_push(1.2*spin_vel_2_set_left);
        spin6_push(1.2*spin_vel_2_set_right);
        spin3_push(spin_vel_2_set_left);
        spin7_push(spin_vel_2_set_right);

        ros::Duration(1.2).sleep(); 

        spin11_retract(0);
    
        spin12_retract(0.03);
    /********************************************************/
        ros::Duration(2).sleep(); 

        spin2_retract(spin_vel_2_set_left);
        spin6_retract(spin_vel_2_set_right);

        ros::Duration(1).sleep(); 

        spin11_push(0.03);
        spin10_push(0.02);

        //  spin2_retract(0);
        //  spin1_retract(0);

        spin3_retract(2*spin_vel_2_set_left);
        spin7_retract(2*spin_vel_2_set_right);

        //ros::Duration(0.2).sleep(); 

        ros::Duration(1.4).sleep(); 

        spin10_retract(0.01);

        spin1_push(1.2*spin_vel_2_set_left);
        spin5_push(1.2*spin_vel_2_set_right);
        spin2_push(spin_vel_2_set_left);
        spin6_push(spin_vel_2_set_right);

        ros::Duration(1.2).sleep(); 

        spin10_retract(0);
    
        spin11_retract(0.03);
    }
    /*****************************************************************************/
    /*****************************************************************************/
    void run_3_init()
    {
        spin2_push(0.05);
        spin1_push(0.05);
        spin6_push(0.05);
        spin5_push(0.05);
        ros::Duration(2).sleep(); 

        spin5_retract(spin_vel_3_set_left);
        spin6_retract(spin_vel_3_set_right);

        ros::Duration(1).sleep(); 
    }
    void run_3()
    {
        /********************************************************/
        ros::Duration(2).sleep(); 

        spin5_retract(spin_vel_3_set_left);
        spin6_retract(spin_vel_3_set_right);

        ros::Duration(1).sleep(); 

        spin10_push(3*spin_vel_3_set);
        spin14_push(2*spin_vel_3_set);

        //  spin2_retract(0);
        //  spin1_retract(0);

        spin1_retract(2*spin_vel_3_set_left);
        spin2_retract(2*spin_vel_3_set_right);

        //ros::Duration(0.2).sleep(); 

        ros::Duration(1.4).sleep(); 

        spin14_retract(spin_vel_3_set);

        spin5_push(1.2*spin_vel_3_set_left);
        spin6_push(1.2*spin_vel_3_set_right);
        spin8_push(spin_vel_3_set_left);
        spin7_push(spin_vel_3_set_right);

        ros::Duration(1.2).sleep(); 

        spin14_retract(0);
    
        spin10_retract(3*spin_vel_3_set);
        /********************************************************/
        ros::Duration(2).sleep(); 

        spin8_retract(spin_vel_3_set_left);
        spin7_retract(spin_vel_3_set_right);

        ros::Duration(1).sleep(); 

        spin14_push(3*spin_vel_3_set);
        spin12_push(2*spin_vel_3_set);

        //  spin2_retract(0);
        //  spin1_retract(0);

        spin5_retract(2*spin_vel_3_set_left);
        spin6_retract(2*spin_vel_3_set_right);

        //ros::Duration(0.2).sleep(); 

        ros::Duration(1.4).sleep(); 

        spin12_retract(spin_vel_3_set);

        spin8_push(1.2*spin_vel_3_set_left);
        spin7_push(1.2*spin_vel_3_set_right);
        spin4_push(spin_vel_3_set_left);
        spin3_push(spin_vel_3_set_right);

        ros::Duration(1.2).sleep(); 

        spin12_retract(0);
    
        spin14_retract(3*spin_vel_3_set);
        /********************************************************/
        ros::Duration(2).sleep(); 

        spin4_retract(spin_vel_3_set_left);
        spin3_retract(spin_vel_3_set_right);

        ros::Duration(1).sleep(); 

        spin12_push(3*spin_vel_3_set);
        spin13_push(2*spin_vel_3_set);

        //  spin2_retract(0);
        //  spin1_retract(0);

        spin8_retract(2*spin_vel_3_set_left);
        spin7_retract(2*spin_vel_3_set_right);

        //ros::Duration(0.2).sleep(); 

        ros::Duration(1.4).sleep(); 

        spin13_retract(spin_vel_3_set);

        spin4_push(1.2*spin_vel_3_set_left);
        spin3_push(1.2*spin_vel_3_set_right);
        spin1_push(spin_vel_3_set_left);
        spin2_push(spin_vel_3_set_right);

        ros::Duration(1.2).sleep(); 

        spin13_retract(0);
    
        spin12_retract(3*spin_vel_3_set);
    /********************************************************/
        ros::Duration(2).sleep(); 

        spin1_retract(spin_vel_3_set_left);
        spin2_retract(spin_vel_3_set_right);

        ros::Duration(1).sleep(); 

        spin13_push(3*spin_vel_3_set);
        spin10_push(2*spin_vel_3_set);

        //  spin2_retract(0);
        //  spin1_retract(0);

        spin4_retract(2*spin_vel_3_set_left);
        spin3_retract(2*spin_vel_3_set_right);

        //ros::Duration(0.2).sleep(); 

        ros::Duration(1.4).sleep(); 

        spin10_retract(spin_vel_3_set);

        spin1_push(1.2*spin_vel_3_set_left);
        spin2_push(1.2*spin_vel_3_set_right);
        spin5_push(spin_vel_3_set_left);
        spin6_push(spin_vel_3_set_right);

        ros::Duration(1.2).sleep(); 

        spin10_retract(0);
    
        spin13_retract(3*spin_vel_3_set);
    }
    /*****************************************************************************/
    /*****************************************************************************/
    void run_4_init()
    {
        spin2_push(0.05);
        spin1_push(0.05);
        spin6_push(0.05);
        spin5_push(0.05);
        ros::Duration(2).sleep(); 

        spin6_retract(spin_vel_4_set_left);
        spin2_retract(spin_vel_4_set_right);

        ros::Duration(1).sleep(); 
    }
    void run_4()
    {
        /********************************************************/
        ros::Duration(2).sleep(); 

        spin6_retract(spin_vel_4_set_left);
        spin2_retract(spin_vel_4_set_right);

        ros::Duration(1).sleep(); 

        spin10_push(3*spin_vel_4_set);
        spin11_push(2*spin_vel_4_set);

        //  spin2_retract(0);
        //  spin1_retract(0);

        spin5_retract(2*spin_vel_4_set_left);
        spin1_retract(2*spin_vel_4_set_right);

        //ros::Duration(0.2).sleep(); 

        ros::Duration(1.4).sleep(); 

        spin11_retract(spin_vel_4_set);

        spin6_push(1.2*spin_vel_4_set_left);
        spin2_push(1.2*spin_vel_4_set_right);
        spin7_push(spin_vel_4_set_left);
        spin3_push(spin_vel_4_set_right);

        ros::Duration(1.2).sleep(); 

        spin11_retract(0);
    
        spin10_retract(3*spin_vel_4_set);
        /********************************************************/
        ros::Duration(2).sleep(); 

        spin7_retract(spin_vel_4_set_left);
        spin3_retract(spin_vel_4_set_right);

        ros::Duration(1).sleep(); 

        spin11_push(3*spin_vel_4_set);
        spin12_push(2*spin_vel_4_set);

        //  spin2_retract(0);
        //  spin1_retract(0);

        spin6_retract(2*spin_vel_4_set_left);
        spin2_retract(2*spin_vel_4_set_right);

        //ros::Duration(0.2).sleep(); 

        ros::Duration(1.4).sleep(); 

        spin12_retract(spin_vel_4_set);

        spin7_push(1.2*spin_vel_4_set_left);
        spin3_push(1.2*spin_vel_4_set_right);
        spin8_push(spin_vel_4_set_left);
        spin4_push(spin_vel_4_set_right);

        ros::Duration(1.2).sleep(); 

        spin12_retract(0);
    
        spin11_retract(3*spin_vel_4_set);
        /********************************************************/
        ros::Duration(2).sleep(); 

        spin8_retract(spin_vel_4_set_left);
        spin4_retract(spin_vel_4_set_right);

        ros::Duration(1).sleep(); 

        spin12_push(3*spin_vel_4_set);
        spin9_push(2*spin_vel_4_set);

        //  spin2_retract(0);
        //  spin1_retract(0);

        spin7_retract(2*spin_vel_4_set_left);
        spin3_retract(2*spin_vel_4_set_right);

        //ros::Duration(0.2).sleep(); 

        ros::Duration(1.4).sleep(); 

        spin9_retract(spin_vel_4_set);

        spin8_push(1.2*spin_vel_4_set_left);
        spin4_push(1.2*spin_vel_4_set_right);
        spin5_push(spin_vel_4_set_left);
        spin1_push(spin_vel_4_set_right);

        ros::Duration(1.2).sleep(); 

        spin9_retract(0);
    
        spin12_retract(3*spin_vel_4_set);
    /********************************************************/
        ros::Duration(2).sleep(); 

        spin5_retract(spin_vel_4_set_left);
        spin1_retract(spin_vel_4_set_right);

        ros::Duration(1).sleep(); 

        spin9_push(3*spin_vel_4_set);
        spin10_push(2*spin_vel_4_set);

        //  spin2_retract(0);
        //  spin1_retract(0);

        spin8_retract(2*spin_vel_4_set_left);
        spin4_retract(2*spin_vel_4_set_right);

        //ros::Duration(0.2).sleep(); 

        ros::Duration(1.4).sleep(); 

        spin10_retract(spin_vel_4_set);

        spin5_push(1.2*spin_vel_4_set_left);
        spin1_push(1.2*spin_vel_4_set_right);
        spin6_push(spin_vel_4_set_left);
        spin2_push(spin_vel_4_set_right);

        ros::Duration(1.2).sleep(); 

        spin10_retract(0);
    
        spin9_retract(3*spin_vel_4_set);
    }
};

int main (int argc, char** argv)
{
    ros::init(argc, argv, "Fixed_motion");
    ros::Time::init();
    ros::Rate loop_rate(100);

    command_comb command_Comb;
    command_Comb.run_init();

    while(ros::ok())  
    {
        command_Comb.turn_left_init();
        command_Comb.turn_left();
    }
    ros::spinOnce();
    loop_rate.sleep();
}