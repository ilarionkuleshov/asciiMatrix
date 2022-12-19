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

    ui->progressBar->setValue(0);
    ui->progressBar->setEnabled(false);
    ui->pushButton_4->setEnabled(false);

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
            cv::resize(frame, frame, Size(600, 329));
            QImage cvImage((uchar*)frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
            ui->cvLabel->setPixmap(QPixmap::fromImage(cvImage));
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
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_4->setEnabled(false);
    ui->progressBar->setValue(0);
    ui->progressBar->setEnabled(false);
    ui->cvLabel->autoFillBackground();
    QMessageBox::warning(this, "Success", "Process completed!");
}

void MainWindow::on_pushButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open file", QDir::homePath());
    ui->openFileInput->setText(filePath);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString openFile = ui->openFileInput->text();
    QString saveFile = ui->saveAsInput->text();
    if(QFileInfo::exists(openFile) && saveFile != "" && saveFile.contains(".mp4")) {
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_4->setEnabled(true);
        ui->progressBar->setEnabled(true);

        capture = VideoCapture(openFile.toStdString());
        converter = AsciiConverter(
            capture,
            ui->rInput->text().toFloat(),
            ui->gInput->text().toFloat(),
            ui->bInput->text().toFloat(),
            ui->charWInput->text().toInt(),
            ui->charHInput->text().toInt()
        );
        writer = AsciiFileWriter(capture, ui->saveAsInput->text().toStdString());

        isStartConverting = true;
    }
    else {
        QMessageBox::warning(this, "Error", "Fields are filled incorrectly!");
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save as", QDir::homePath());
    ui->saveAsInput->setText(filePath);
}


void MainWindow::on_pushButton_4_clicked()
{
    stopConverting();
}

