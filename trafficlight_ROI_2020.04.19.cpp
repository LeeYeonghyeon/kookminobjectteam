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
		string checker = bouding_box.Class;

	if (xmin_><start x_point> &&  ymin_><start y_point> && xmax_ <<end x_point> && ymax_ <<end y_point>&& checker != None)
		ROS_INFO(xmin_," ",ymin_,\n, xmax_," ",ymax_);
	else
		return ;
	checker = None;
	Mat ROI(<input array>,Rect(xmin_, ymin_, xmax_, ymax_));
	resize(ROI,ROI,Size(1920, 1080), 0, 0, CV_INTER_NN);
		
<package name>.x_min = xmin_;
<package name>.y_min = ymin_;
<package name>.x_max = xmax_;
<package name>.y_max = ymax_;

}


int main(int argc, char **argv){
	ros::init(argc, argv, "<노드이름>");
	ros::NodeHandle nh_;
	image_transport::ImageTransport it(nh_);
	image_transport::Publisher pub_=it.advertise(/*publish topic*/,1);
	ros::Subscriber sub_;
	cv_bridge::CvImage ptr;
	ros::Rate loop_rate(60);
	VideoCapture capture(0);
	Mat frame;
	if(!capture.isOpened()){
		std::cout<<"camera is no working!!"<<std::endl;
return 0;
}
ros::Time time = ros::Time:now();

while(ros::ok()){
	/* ROI and PUB Darknet*/
/**/capture>>frame;
/**/Mat ROI_darknet(frame,Rect(20,0,300,900));
/**/ptr->encoding = "bgr8";
/**/ptr->header.stamp = time;
/**/sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(),"bgr8",frame).toImageMsg();
/**/pub_.publish(msg)
////////////////////////////////////////////////////////////////////////

	/* SUB and ROI */
sub_=nh_.subscribe("/darknet_ros/bouding_boxes",10,traffic_light_callback);


if(waitKey(25)<0)
	break;
}	
	ros::spin();

	return 0;

}
	
