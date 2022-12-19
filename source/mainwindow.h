#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "opencv2/opencv.hpp"
#include "ascii/asciiConverter.hpp"
#include "ascii/asciiFileWriter.hpp"

using namespace cv;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void displayImage();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void stopConverting();

    QImage cvImage;
    QTimer* timer;

    VideoCapture capture;
    Mat frame;
    AsciiConverter converter;
    AsciiFileWriter writer;

    bool isStartConverting;

private slots:
    void on_openFileButton_clicked();

    void on_saveAsButton_clicked();

    void on_convertButton_clicked();

    void on_stopButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
