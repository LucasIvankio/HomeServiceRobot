# HomeServiceRobot

The Home Service Robot project in the Robotics Software Engineer Nanodegree uses a number of packages for localization, mapping, and navigation. As well as some custom packages designed specifically for the project, such as add_markers and pickup_objects.

### Localization

For localization, the project uses the Adaptive Monte Carlo Localization (AMCL) package. AMCL is a probabilistic algorithm that uses a particle filter to estimate the robot's position and orientation in the environment. It does this by comparing sensor data from the robot's laser range finder to a map of the environment.

### Mapping

For mapping, the project uses the gmapping package. Gmapping is a SLAM (Simultaneous Localization and Mapping) algorithm that creates a 2D occupancy grid map of the environment using data from the robot's laser range finder and odometry data.

### Navigation

For navigation, the project uses the ROS Navigation Stack. The Navigation Stack is a collection of packages that provide a complete solution for autonomous navigation. It includes packages for path planning, obstacle avoidance, and control. The Navigation Stack uses the map created by gmapping and the robot's position estimate from AMCL to plan and execute a path to a goal location.

### Add_Markers

The add_markers package is used to simulate the object that the robot needs to pick up and deliver. It creates a virtual marker that represents the object and adds it to the robot's environment. The marker is initially displayed at the pickup location, and then it disappears when the robot picks up the object. Afterward, the marker reappears at the drop-off location to indicate where the robot should deliver the object. The package subscribes to the /odom topic to read the position of the Robot, and decide when to display or remote the virtual marker.

### Pickup_Objects

The pickup_objects package simulates the robot's ability to pick up and deliver objects. It uses a combination of ROS nodes and services to simulate the robot's actions. The package includes a node that simulates the object's location and a service that simulates the pickup and delivery of the object. When the robot reaches the pickup location, it sends a request to the pickup_objects service to simulate the pickup of the object. Afterward, the robot navigates to the drop-off location and sends a request to the service to simulate the delivery of the object.
