#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/tracking.hpp"
#include "KCFTracker.hpp"

using namespace cv;  
using namespace std;  

static const char* keys =
{ 
    "{@video_name  | | video name            }"
};

int main(int argc, char** argv)  
{  
    CommandLineParser parser( argc, argv, keys );
    String video_name = parser.get<String>( 0 );
    if (video_name.empty())
    {
        cout << "video_name is empty" << endl;
        return -1;
    }

    VideoCapture cap;  
    cap.open(video_name);  
    //cap.open("test_02.wmv"); 
  
    if( !cap.isOpened() )
    {
        cout << "video didn't open!" << endl;
        return -1;  
    }
    
    Mat frame;
    KCFTracker tracker1;
    KCFTracker tracker2;
    KCFTracker tracker3;
    KCFTracker tracker4;
    KCFTracker tracker5;
    KCFTracker tracker6;
    KCFTracker tracker7;
    KCFTracker tracker8;

    printf("Start the tracking process, press ESC to quit.\n");

    for(;;)  
    {  
        double t = (double)getTickCount();  
  
        cap >> frame;  
        if(frame.empty())
        {
            cout << "end of video" << endl;
            break;
        }
        // update the tracking result
        tracker1.update(frame);
        tracker2.update(frame);
        tracker3.update(frame);
        tracker4.update(frame);
        tracker5.update(frame);
        tracker6.update(frame);
        tracker7.update(frame);
        tracker8.update(frame);

        tracker1.draw(frame);
        tracker2.draw(frame);
        tracker3.draw(frame);
        tracker4.draw(frame);
        tracker5.draw(frame);
        tracker6.draw(frame);
        tracker7.draw(frame);
        tracker8.draw(frame);

        imshow("tracker", frame);

        switch(waitKey(1))
        {
            case 27:    // press "ESC"
                cout << "exit" << endl;
                return 0;
            case 'p':
                cout << "pause" << endl;
                waitKey();
                break;
            case 'c':
                cout << "capture ROI" << endl;
                tracker1.resetTracker(frame);
                break;
            case 'x':
                cout << "capture ROI2" << endl;
                tracker2.resetTracker(frame);
                break;
            case 'z':
                cout << "capture ROI3" << endl;
                tracker3.resetTracker(frame);
                break;
            case 'v':
                cout << "capture ROI4" << endl;
                tracker4.resetTracker(frame);
                break;
            case 'b':
                cout << "capture ROI5" << endl;
                tracker5.resetTracker(frame);
                break;
            case 'n':
                cout << "capture ROI6" << endl;
                tracker6.resetTracker(frame);
                break;
            case 'm':
                cout << "capture ROI7" << endl;
                tracker7.resetTracker(frame);
                break;
            case 'a':
                cout << "capture ROI8" << endl;
                tracker8.resetTracker(frame);
                break;

        }
        t = (double)getTickCount() - t;
        double costTime = t / (double)getTickFrequency() * 1000;
        cout << "cost time: " << costTime << endl;

    }  
    return 0;  
}  
