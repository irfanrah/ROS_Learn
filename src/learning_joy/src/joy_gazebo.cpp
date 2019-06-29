#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <iostream>
#include <std_msgs/Float32.h>
#include <std_msgs/String.h>
using namespace std;



void joyTranslate(const sensor_msgs::Joy::ConstPtr& joy)
{
	std::stringstream ss;
	std_msgs::Float32 msgkiri;
	std_msgs::Float32 msgkanan;
	ros::NodeHandle nh2;
	ros::Rate rate(10);
	ros::Publisher bankiri = nh2.advertise<std_msgs::Float32>("/simple_robot/left_wheel_speed", 10);
	ros::Publisher bankanan = nh2.advertise<std_msgs::Float32>("/simple_robot/right_wheel_speed", 10);
	double start_vel = -3;

   
		
	int angka = 1;
	if (joy->buttons[0] == angka)
		{
			//ss << "segitiga" ;
			ss << "Segitiga " ;
		}
	else if(joy->buttons[1] == angka)
	{
		ss << "bulet" ;
	}
	else if(joy->buttons[2] == angka)
	{
		ss << "X" ;
	}
	else if(joy->buttons[3] == angka)
	{
		ss << "Kotak" ;
	}
	else if(joy->buttons[4] == angka)
	{
		ss << "L 1" ;
	}
	else if(joy->buttons[5] == angka)
	{
		ss << "R 1" ;
	}
	else if(joy->buttons[6] == angka)
	{
		ss << "L 2" ;
	}
	else if(joy->buttons[7] == angka)
	{
		ss << "R 2" ;
	}
	else if(joy->axes[0] == angka and joy->axes[1] == 0)
	{
		ss << "AnalogKiriKeKiri" ;
		msgkiri.data = 0; 
		msgkanan.data = start_vel; 
	}
	else if(joy->axes[0] == -angka and joy->axes[1] == 0)
	{
		ss << "AnalogKiriKeKanan" ;
		msgkiri.data = start_vel; 
		msgkanan.data = 0; 
	}
	else if(joy->axes[1] == angka and joy->axes[0] == 0)
	{
		ss << "10" ;
		msgkiri.data = start_vel; 
		msgkanan.data = start_vel; 
	}
	else if(joy->axes[1] == -angka and joy->axes[0] == 0)
	{
		ss << "-10" ;
		msgkiri.data = -start_vel; 
		msgkanan.data = -start_vel; 
	}
	else if(joy->axes[3] == angka)
	{
		ss << "AnalogKananKeKiri" ;
	}
	else if(joy->axes[3] == -angka)
	{
		ss << "AnalogKananKeKanan" ;
	}
	else if(joy->axes[2] == angka)
	{
		ss << "AnalogKananKeAtas" ;
	}
	else if(joy->axes[2] == -angka)
	{
		ss << "AnalogKananKeBawah" ;
	}
	else if(joy->axes[4] == angka)
	{
		ss << "ArahKiri" ;
	}
	else if(joy->axes[4] == -angka)
	{
		ss << "ArahKanan" ;
	}
	else if(joy->axes[5] == angka)
	{
		ss << "ArahAtas" ;
	}
	else if(joy->axes[5] == -angka)
	{
		ss << "ArahBawah" ;
	}
	else if(joy->axes[5] == -angka)
	{
		ss << "ArahBawah" ;
	}
	else if(joy->axes[0] != 0 and joy->axes[1] != 0) //mager nerusin wkwkw
	{
		if (joy->axes[0] > 0 and joy->axes[1] > 0) // serong kiri +
		{
			if (joy->axes[1] == 1) //serong kiri atas
			{
				msgkiri.data = start_vel; 
				msgkanan.data = start_vel; 
			}
			else if (joy->axes[0] == 1 ) //serong kiri bawah
			{
				msgkiri.data = start_vel-((1-joy->axes[1])/2); 
				msgkanan.data = start_vel+((1-joy->axes[1])/2); ; 
			}
		}
	}
	
	bankiri.publish(msgkiri);
	bankanan.publish(msgkanan);
	ros::spin();
	
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "joystcik_reader");
  ros::NodeHandle nh;
  ros::Subscriber joy_sub = nh.subscribe<sensor_msgs::Joy>("joy", 10, &joyTranslate);
  ros::Rate loop_rate(10);
  ros::spin();
}

