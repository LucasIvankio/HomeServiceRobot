# HomeServiceRobot

The Home Service Robot project in the Robotics Software Engineer Nanodegree uses a number of packages for localization, mapping, and navigation.

### Localization

For localization, the project uses the Adaptive Monte Carlo Localization (AMCL) package. AMCL is a probabilistic algorithm that uses a particle filter to estimate the robot's position and orientation in the environment. It does this by comparing sensor data from the robot's laser range finder to a map of the environment.

### Mapping

For mapping, the project uses the gmapping package. Gmapping is a SLAM (Simultaneous Localization and Mapping) algorithm that creates a 2D occupancy grid map of the environment using data from the robot's laser range finder and odometry data.

### Navigation

For navigation, the project uses the ROS Navigation Stack. The Navigation Stack is a collection of packages that provide a complete solution for autonomous navigation. It includes packages for path planning, obstacle avoidance, and control. The Navigation Stack uses the map created by gmapping and the robot's position estimate from AMCL to plan and execute a path to a goal location.
