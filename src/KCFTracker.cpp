#include "KCFTracker.hpp"

KCFTracker::KCFTracker()
{
    param.desc_pca = TrackerKCF::CN;   //TrackerKCF::GRAY | 
    // param.desc_npca = 0;
    param.compress_feature = true;
    param.compressed_size = 3;
    param.pca_learning_rate=0.03;

    Tracker = TrackerKCF::createTracker(param);
    color = Scalar(rand() % 255, rand() % 255, rand() % 255);
    showCrosshair = false; 
    fromCenter = false; 
    
}

void KCFTracker::update(Mat frame)
{
    if(roi.width > 0 || roi.height >0)
    {
        Tracker->update(frame, roi);
    }
}

void KCFTracker::draw(Mat frame)
{
    if(roi.width > 0 || roi.height >0)
    {
        rectangle( frame, roi, color, 2, 1 );
    }
}

bool KCFTracker::resetTracker(Mat frame)
{
    roi = selectROI("tracker", frame, fromCenter, showCrosshair);
    if(roi.width > 0 || roi.height >0)
    {
        Tracker.release();
        Tracker = TrackerKCF::createTracker(param);
        Tracker->init(frame, roi);
        return true;
    }
    return false;
}
