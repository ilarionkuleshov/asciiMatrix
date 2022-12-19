#include <QTimer>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

#include <iostream>

#include "mainwindow.h"
#include "./ui_mainwindow.h"

using namespace cv;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(displayImage()));
    timer->start();

    isStartConverting = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayImage() {
    if(isStartConverting) {
        capture >> frame;
        if(!frame.empty()) {
            frame = converter.getAsciiFrame(frame);
            int progress = writer.writeFrame(frame);
            cvtColor(frame, frame, COLOR_BGR2RGB);
            cv::resize(frame, frame, Size(ui->opencvLabel->width()-10, ui->opencvLabel->height()-10));
            QImage cvImage((uchar*)frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
            ui->opencvLabel->setPixmap(QPixmap::fromImage(cvImage));
            if(progress != 0) {
                ui->progressBar->setValue(progress);
            }
        }
        else {
            stopConverting();
        }
    }
}

void MainWindow::stopConverting() {
    isStartConverting = false;
    capture.release();
    writer.release();
    ui->convertButton->setEnabled(true);
    ui->stopButton->setEnabled(false);
    ui->progressBar->setValue(0);
    ui->progressBar->setEnabled(false);
    ui->opencvLabel->autoFillBackground();
    QMessageBox::warning(this, "Success", "Process completed!");
}


void MainWindow::on_openFileButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open file", QDir::homePath());
    ui->openFileLineEdit->setText(filePath);
}


void MainWindow::on_saveAsButton_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save as", QDir::homePath());
    ui->saveAsLineEdit->setText(filePath);
}


void MainWindow::on_convertButton_clicked()
{
    QString openFile = ui->openFileLineEdit->text();
    QString saveFile = ui->saveAsLineEdit->text();
    if(QFileInfo::exists(openFile) && saveFile != "" && saveFile.contains(".mp4")) {
        ui->convertButton->setEnabled(false);
        ui->stopButton->setEnabled(true);
        ui->progressBar->setEnabled(true);

        capture = VideoCapture(openFile.toStdString());
        converter = AsciiConverter(
            capture,
            ui->redLineEdit->text().toFloat(),
            ui->greenLineEdit->text().toFloat(),
            ui->blueLineEdit->text().toFloat(),
            ui->charWidthLineEdit->text().toInt(),
            ui->charHeightLineEdit->text().toInt()
        );
        writer = AsciiFileWriter(capture, saveFile.toStdString());

        isStartConverting = true;
    }
    else {
        QMessageBox::warning(this, "Error", "Fields are filled incorrectly!");
    }
}


void MainWindow::on_stopButton_clicked()
{
    stopConverting();
}

