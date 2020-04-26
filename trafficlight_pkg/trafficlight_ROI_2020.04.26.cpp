#include<iostream>
#include<ros/ros.h>
#include<opencv2/opencv.hpp>
#include<image_transport/image_transport.h>
#include<cv_bridge/cv_bridge.h>
#include<sensor_msg/Image.h>
#include<darknet_ros_msgs/BoudingBoxes.h>
#include<trafficlight_pkg/trafficlightfilter.h>
using namespace cv;

class Traffic_light_sys{
	protected:
		ros::NodeHandle nh_;
		image_transport::ImageTransport it(nh_);
		
		image_transport::Publisher Pub_=it.advertise(/*publish topic*/,1);
		ros::Subscriber sub_;
		Mat frame;
		cv_bridge::CvImage ptr;
		trafficlight_pkg::Trafficlightfilter traffic_light_filter_msg;
		
	public:
		Traffic_light_sys(){
			process();
		}
		~Traffic_light_sys(){ROS_INFO("END_TRAFFIC_LIGHT");}
					
		void process(){
			VideoCapture capture(0);
			if(captuer.isOpened()){
				ROS_INFO("No camera data!!");
				return ;}
			
			capture >> frame;
			Rect rect(/*default point*/);
			frame(rect);
			ros::TIme time = ros::Time::now();
			ptr->encoding = "bgr8";
			ptr->header.stamp = time;
			ptr->header.frame_id = /*pulish topic*/;

			ptr->image = frame;
			
			pub_.publish(ptr->toImageMsg());
			ros::Publisher f_pub_ = nh_.advertise<trafficlight_pkg::Trafficlightfilter>("/traffic_light/filter",1);
			sub_ = nh_.subscribe("/darknet_ros/bounding_boxes", 10, traffic_liht_Callback);		
		
			
				
		}

		void traffic_light_Callback(const darknet_ros_msgs::BoudingBoxes::ConstPtr &darknet_roi){
		darknet_ros_msgs::BoudingBox bouding_box= darknet_roi->bouding_boxes[i];
			int xmin_ = bouding_box.xmin;
			int ymin_ = bouding_box.ymin;
			int xmax_ = bouding_box.xmax;
			int ymax_ = bouding_box.ymax;

			
			string checker = bouding_box.Class;

			if (xmin_><start x_point> &&  ymin_><start y_point> && xmax_ <<end x_point> && ymax_ <<end y_point>&& checker != None)
                ROS_INFO(xmin_," ",ymin_,\n, xmax_," ",ymax_);
		else
		{ROS_INFO("index is wrong from darknet");
			return ;}
		Rect rect_(xmin_, ymin, xmax_, ymax_);
		frame(rect_);
		resize(frame, frame, Size(1920,1080), 0, 0, CV_INTER_NN);
		
		/*인식*/
		//
		//
		//
		//
		//
		//////////////////////////////////////////////////////

	

		};
		int main(int argc, char **argv){
			ros::init(argc, argv,"node_name");

			Traffic_light_sys tls;
			
			ros::spin()

			return 0;

			}
		
