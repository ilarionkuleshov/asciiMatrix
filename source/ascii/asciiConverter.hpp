#include <iostream>
#include <string>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;


class AsciiConverter {
public:
    int width, height, charWidth, charHeight, matrixWidth, matrixHeight;
    float fps, norm, redK, greenK, blueK, fontSize;
    string chars;
    HersheyFonts font;

    AsciiConverter() {};

    AsciiConverter(
        VideoCapture capture,
        float redK = 0.5, float greenK = 1, float blueK = 0.5,
        int charWidth = 10, int charHeight = 15,
        string chars = "Æ@#W$9876543210?!abc;:+=-,._  ",
        float fontSize = 0.4
    ) {
        this->width = capture.get(3);
        this->height = capture.get(4);
        this->fps = capture.get(CAP_PROP_FPS);

        this->charWidth = charWidth;
        this->charHeight = charHeight;
        this->matrixWidth = (int)(this->width / this->charWidth);
        this->matrixHeight = (int)(this->height / this->charHeight);

        this->chars = chars;
        this->norm = 255 / chars.length();

        this->redK = redK;
        this->greenK = greenK;
        this->blueK = blueK;

        this->font = FONT_HERSHEY_DUPLEX;
        this->fontSize = fontSize;

        cout << this->width << "x" << this->height << ", " << this->fps << "fps" << endl;
    }

    ~AsciiConverter() {};

    Mat getAsciiFrame(Mat frame) {
        Mat asciiFrame(this->height, this->width, CV_8UC3, Scalar(0, 0, 0));
        Mat resizedFrame, grayFrame;
        resize(frame, resizedFrame, Size(this->matrixWidth, this->matrixHeight), INTER_NEAREST);
        cvtColor(resizedFrame, grayFrame, COLOR_BGR2GRAY);

        for(int y = 0; y < grayFrame.rows; y++) {
            for(int x = 0; x < grayFrame.cols; x++) {
                int intensity = (int)grayFrame.at<uchar>(y, x);
                int charIndex = (int)(intensity / norm);
                string targetChar(1, this->chars[charIndex]);

                Vec3b colorPixel = resizedFrame.at<Vec3b>(y, x);
                int blue = (int)(this->blueK * colorPixel.val[0]);
                int green = (int)(this->greenK * colorPixel.val[1]);
                int red = (int)(this->redK * colorPixel.val[2]);

                putText(
                    asciiFrame,
                    targetChar,
                    Point(x * this->charWidth, y * this->charHeight),
                    this->font,
                    this->fontSize,
                    CV_RGB(red, green, blue),
                    1
                );
            }
        }
        return asciiFrame;
    }
};
