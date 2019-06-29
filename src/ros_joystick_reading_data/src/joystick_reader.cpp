#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <iostream>
#include "std_msgs/String.h"

using namespace std;

void joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
    cout<<"axes: ["<< joy->axes[0] <<","<<joy->axes[1] <<","<<joy->axes[2] <<","<<joy->axes[3]<<","<< joy->axes[4]<<","<< joy->axes[5] <<","<<joy->axes[6]<<","<< joy->axes[7]   <<"]"<<endl;
    cout<<"buttons: ["<<  joy->buttons[0]  <<","<< joy->buttons[1] <<","<<joy->buttons[2] <<","<<joy->buttons[3]<<","<< joy->buttons[4] <<","<<joy->buttons[5] <<","<<joy->buttons[6] <<","<<joy->buttons[7] <<","<<joy->buttons[8] <<","<<joy->buttons[9]<<","<<joy->buttons[10]   <<"]"<<endl;
}

void joyTranslate(const sensor_msgs::Joy::ConstPtr& joy)
{
	std::stringstream ss;
	int angka = 1;
	if (joy->buttons[0] == angka)
	{
		cout<<"segitiga" <<endl;
	}
	else if(joy->buttons[1] == angka)
	{
		cout<<"bulet" <<endl;
	}
	else if(joy->buttons[2] == angka)
	{
		cout<<"X" <<endl;
	}
	else if(joy->buttons[3] == angka)
	{
		cout<<"Kotak" <<endl;
	}
	else if(joy->buttons[4] == angka)
	{
		cout<<"L 1" <<endl;
	}
	else if(joy->buttons[5] == angka)
	{
		cout<<"R 1" <<endl;
	}
	else if(joy->buttons[6] == angka)
	{
		cout<<"L 2" <<endl;
	}
	else if(joy->buttons[7] == angka)
	{
		cout<<"R 2" <<endl;
	}
	else if(joy->axes[0] == angka)
	{
		cout<<"AnalogKiriKeKiri" <<endl;
	}
	else if(joy->axes[0] == -angka)
	{
		cout<<"AnalogKiriKeKanan" <<endl;
	}
	else if(joy->axes[1] == angka)
	{
		cout<<"AnalogKiriKeAtas" <<endl;
	}
	else if(joy->axes[1] == -angka)
	{
		cout<<"AnalogKiriKeBawah" <<endl;
	}
	else if(joy->axes[3] == angka)
	{
		cout<<"AnalogKananKeKiri" <<endl;
	}
	else if(joy->axes[3] == -angka)
	{
		cout<<"AnalogKananKeKanan" <<endl;
	}
	else if(joy->axes[2] == angka)
	{
		cout<<"AnalogKananKeAtas" <<endl;
	}
	else if(joy->axes[2] == -angka)
	{
		cout<<"AnalogKananKeBawah" <<endl;
	}
	else if(joy->axes[4] == angka)
	{
		cout<<"ArahKiri" <<endl;
	}
	else if(joy->axes[4] == -angka)
	{
		cout<<"ArahKanan" <<endl;
	}
	else if(joy->axes[5] == angka)
	{
		cout<<"ArahAtas" <<endl;
	}
	else if(joy->axes[5] == -angka)
	{
		cout<<"ArahBawah" <<endl;
	}
	
	
	

}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "joystcik_reader");
  ros::NodeHandle nh;
  ros::Subscriber joy_sub = nh.subscribe<sensor_msgs::Joy>("joy", 10, &joyCallback);
  //ros::Publisher chat_joy = nh.advertise<std_msgs::String>("chatter", 10);
  ros::Rate loop_rate(10);
  int time = 0;
  while(ros::ok) {
	/* //Code 1
    ROS_INFO_STREAM("detik" << time);
	ros::Duration(1).sleep();
	++time ;
	ros::spinOnce(); // berguna untuk is used to call the subscriber and publisher functions of a certain node at a certain rate.
	
	*/  

	
	
	ros::spinOnce();
	}
  ros::spin();
}

