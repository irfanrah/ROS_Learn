…or create a new repository on the command line

git init
git add --all
git commit -m "first commit"
git push -u origin master --force

…or push an existing repository from the command line

git remote add origin https://github.com/irfanrah/Test.git
git push -u origin master

ea

For Launch

1. Turtlesim with joystick
roslaunch learning_joy turtle_joy.launch

2.listener dari topic 
roslaunch learning_joy listener.launch

3. Reading Joystick Data to terminal
roslaunch ros_joystick_reading_data joystick_reading_data.launch
(optional) listener roslaunch learning_joy listener.launch

4.Gazebo without joystick 
roslaunch mobilku start.launch
  (if mobilku model not appear killall gzclient and killall gzserver)

rostopic pub /simple_robot/right_wheel_speed std_msgs/Float32 "data: 1" (from package set_speed_joint)
rostopic pub /simple_robot/left_wheel_speed std_msgs/Float32 "data: 1" (from package set_speed_joint)

5.Gazebo withjoystick 
roslaunch mobilku start.launch
  (if mobilku model not appear killall gzclient and killall gzserver)
roslaunch learning_joy joygazeb.launch




