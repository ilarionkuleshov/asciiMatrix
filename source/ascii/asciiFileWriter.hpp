#include <iostream>
#include <string>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;


class AsciiFileWriter {
public:
    string fileName;
    int width, height, codec, totalFrames, framesCounter, startTime;
    float fps, prevLoggedProgress, loggingProgressStep;
    VideoWriter writer;

    AsciiFileWriter() {};

    AsciiFileWriter(
        VideoCapture capture,
        string fileName = "data/output.mp4",
        float loggingProgressStep = 0.05
    ) {
        this->width = capture.get(3);
        this->height = capture.get(4);
        this->fps = capture.get(CAP_PROP_FPS);
        this->totalFrames = (int)(capture.get(CAP_PROP_FRAME_COUNT));

        this->fileName = fileName;
        this->loggingProgressStep = loggingProgressStep;
        this->framesCounter = 0;
        this->startTime = time(0);
        this->prevLoggedProgress = 0;
        this->codec = VideoWriter::fourcc('m', 'p', '4', 'v');

        this->writer.open(
            this->fileName,
            this->codec,
            this->fps,
            Size(this->width, this->height)
        );
        cout << "Write to " << this->fileName << endl;
    }

    void writeFrame(Mat frame) {
        this->writer.write(frame);
        this->framesCounter++;
        float progress = ((float)this->framesCounter / (float)this->totalFrames);
        if(progress - this->prevLoggedProgress >= this->loggingProgressStep) {
            int deltaTime = time(0) - this->startTime;
            float remainingTime = (deltaTime / progress) - deltaTime;
            this->prevLoggedProgress = progress;
            cout << (int)(progress * 100) << "% Remaining ~" <<
                setprecision(3) << remainingTime << " seconds" << endl;
        }
    }

    void release() {
        this->writer.release();
        cout << "Writing completed successfully" << endl;
    }
};
