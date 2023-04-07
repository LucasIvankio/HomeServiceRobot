#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>

visualization_msgs::Marker marker;
ros::Publisher marker_pub;

uint32_t shape = visualization_msgs::Marker::CYLINDER;

void odom_callback(const nav_msgs::Odometry::ConstPtr& msg)
{
	double error = 0.15;
	geometry_msgs::Point current_pos = msg->pose.pose.position;
	geometry_msgs::Quaternion current_ori = msg->pose.pose.orientation;
	ROS_WARN_ONCE("Odom Callback!");
	if(current_pos.x < 3.0+error && current_pos.x > 3.0-error && current_pos.y > -2.8-error && current_pos.y < -2.8+error)
	{
		ROS_WARN_ONCE("Robot at PICKUP location!");
		marker.action = visualization_msgs::Marker::DELETE;
		marker_pub.publish(marker);
		ros::Duration(5.0).sleep();

	}
	if(current_pos.x < 0.8+error && current_pos.x > 0.8-error && current_pos.y > -0.8-error && current_pos.y < -0.8+error)
	{
		ROS_WARN_ONCE("Robot at DROPOFF location!");
	    marker.action = visualization_msgs::Marker::ADD;
    	marker.pose.position.x = 0.8;
    	marker.pose.position.y = -0.8;
    	marker.pose.position.z = 0.5;
    	marker_pub.publish(marker);
	}

}

int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  
  bool marker_flag = false;
  
  ros::Subscriber sub = n.subscribe("/odom", 1000, odom_callback);

  if (ros::ok())
  {

    marker.header.frame_id = "/map";
    marker.header.stamp = ros::Time::now();

    marker.ns = "basic_shapes";
    marker.id = 0;

    marker.type = shape;

    marker.scale.x = 0.15;
    marker.scale.y = 0.15;
    marker.scale.z = 0.1;
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;
    marker.lifetime = ros::Duration();

    // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }
    ROS_WARN_ONCE("Subscriber created");
    sleep(1);
    
    if (!marker_flag)
    {
    	marker.action = visualization_msgs::Marker::ADD;
    	marker.pose.position.x = 3.0;
		marker.pose.position.y = -2.8;
		marker.pose.position.z = 0.5;
		marker.pose.orientation.x = 0.0;
		marker.pose.orientation.y = 0.0;
		marker.pose.orientation.z = 0.0;
		marker.pose.orientation.w = 1.0;
    	marker_pub.publish(marker);
    	marker_flag=true;
    }
	
  }
  ros::spin();
  return 0;
}
