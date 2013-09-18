#include "highgui.h"
#include <cv.h>
#include <iostream>
int main (int argc, char** argv) {
    cvNamedWindow("Example2", CV_WINDOW_AUTOSIZE) ;
    CvCapture* capture;
    IplImage* frame;
    while(1) {
        frame = cvQueryFrame(capture);
        if (!frame) break;
        cvShowImage ("Example2", frame);
        char c;
        c = cvWaitKey(33);
        if (c == 27) break;
    }
    cvReleaseCapture( &capture );
    cvDestroyWindow("Example2");

}
