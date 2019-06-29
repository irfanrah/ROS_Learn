cmake_minimum_required(VERSION 2.8.3)
project(mobilku)
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  gazebo_ros
  roscpp
)

#include_directories(
## include
  #${catkin_INCLUDE_DIRS}
#)

##joy
#add_executable(joygazeb src/joy_control.cpp)
#target_link_libraries(joygazeb ${catkin_LIBRARIES} )

#Depend on system install of Gazebo
find_package(gazebo REQUIRED)

link_directories(${GAZEBO_LIBRARY_DIRS})
include_directories(${Boost_INCLUDE_DIR} ${catkin_INCLUDE_DIRS} ${GAZEBO_INCLUDE_DIRS})

# For set_speed_joint_plugin plugin
add_library(plugin_jalan src/set_speed_joint_plugin.cpp)
target_link_libraries(plugin_jalan ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})



catkin_package(
  DEPENDS 
    roscpp 
    gazebo_ros 
)

# controlernya jadinya buat pkg baru bos wkwkwk

