#include <iostream>
#include "opencv2/opencv.hpp"

#include "ascii/asciiConverter.hpp"
#include "ascii/asciiFileWriter.hpp"

using namespace std;
using namespace cv;


int main(int argc, char** argv) {
    VideoCapture *source;
    bool isVideoFile = true;
    if(argc == 1) {
        source = new VideoCapture(0);
        isVideoFile = false;
    }
    else source = new VideoCapture(argv[1]);

    VideoCapture capture(*source);
    if(!capture.isOpened()) {
        cout << "ERROR: Cannot open VideoCapture" << endl;
        return 0;
    }

    Mat frame;
    AsciiConverter converter(capture);

    AsciiFileWriter writer;
    if(isVideoFile) writer = AsciiFileWriter(capture);

    while(true) {
        capture >> frame;
        if(frame.empty()) break;
        frame = converter.getAsciiFrame(frame);
        imshow("ASCII Matrix", frame);
        if(isVideoFile) writer.writeFrame(frame);
        waitKey(1);
    }

    capture.release();
    if(isVideoFile) writer.release();
    destroyAllWindows();

    return 0;
}
