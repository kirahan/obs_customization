#pragma once
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QCameraInfo>
#include <QList>
#include <QDebug>
#include <QImage>
#include <qdialog.h>

namespace Ui {
    class FaceRec;
}

class FaceRec : public QDialog
{
    Q_OBJECT

    public:
        explicit FaceRec(QDialog *parent = 0);
        ~FaceRec();

    private slots:
        void ShowTheCapture();
        void SavePicture();
        void displayImage(int, QImage image);
	void on_cameraType_activated(int index);

    private:
        Ui::FaceRec *ui;
	QList<QCameraInfo> cameras;
    public:
        QCamera *camera;//摄像头
        QCameraViewfinder* viewfinder;//摄像头取景器部件
        QCameraImageCapture* imageCapture;//截图部件

};

#endif // WIDGET_H
