#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/tracking.hpp"
  
using namespace cv;  
using namespace std;

class KCFTracker
{
private:
	Rect2d roi;
	Ptr<TrackerKCF> Tracker;
	TrackerKCF::Params param;
	
	bool fromCenter; 
	bool showCrosshair; 

	Scalar color;

	RNG rng;

public:
	KCFTracker();
	void update(Mat frame);
	void draw(Mat frame);
	bool resetTracker(Mat frame);

};