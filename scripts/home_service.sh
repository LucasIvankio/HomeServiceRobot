#!/bin/sh

xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/robond/Desktop/ROS/Project5/catkin_ws/src/turtlebot_simulator/turtlebot_gazebo/worlds/house.world" &
sleep 5
xterm -e " roslaunch turtlebot_gazebo amcl_demo.launch map_file:=/home/robond/Desktop/ROS/Project5/catkin_ws/src/turtlebot_simulator/turtlebot_gazebo/maps/map.yaml" &
sleep 5
xterm -e " roslaunch turtlebot_rviz_launchers view_navigation.launch config_file:=/home/robond/Desktop/ROS/Project5/catkin_ws/src/add_markers/rviz/navigation.rviz" &
sleep 5
xterm -e " roslaunch add_markers add_markers.launch" &
sleep 5
xterm -e " roslaunch pick_objects pick_objects.launch" &
