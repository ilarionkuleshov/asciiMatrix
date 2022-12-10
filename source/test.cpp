#include <iostream>
#include "opencv2/opencv.hpp"

#include "ascii/asciiConverter.hpp"

using namespace std;
using namespace cv;


int main(int argc, char** argv) {
    VideoCapture *source;
    if(argc == 1) source = new VideoCapture(0);
    else source = new VideoCapture(argv[1]);

    VideoCapture capture(*source);
    if(!capture.isOpened()) {
        cout << "ERROR: Cannot open VideoCapture" << endl;
        return 0;
    }

    Mat frame;
    AsciiConverter converter(capture);

    while(true) {
        capture >> frame;
        frame = converter.getAsciiFrame(frame);
        imshow("ASCII Matrix", frame);
        waitKey(1);
    }
    return 0;
}
