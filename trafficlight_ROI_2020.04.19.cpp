#include<iotream>
#include<ros/ros.h>
#include<opencv2/opencv.hpp>
#include<image_transport/image_transport.h>
#include<cv_bridge/cv_bridge.h>
#include<sensor_msg/Image.h>
using namespace cv;


void traffic_light_Callback(const darknet_ros_msgs::BoundingBoxes::ConstPtr &darknet_roi){
	int size = darknet_msg->bouding_boxes.size();
	darknet_ros_msgs::BoundingBox bounding_box = darknet_msg_roi->bouding_boxes[i];
		int xmin_ = bouding_box.xmin;
		int ymin_ = bouding_box.ymin;
		int xmax_ = bouding_box.xmax;
		int ymax_ = bouding_box.ymax;
		
<package name>.x_min = xmin_;
<package name>.y_min = ymin_;
<package name>.x_max = xmax_;
<package name>.y_max = ymax_;


int main(int argc, char **argv){
	ros::init(argc, argv, "<노드이름>");

	
