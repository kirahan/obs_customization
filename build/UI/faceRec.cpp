#include "faceRec.h"
#include "ui_faceRec.h"
#include<Qdebug>
#include<qobject.h>
#include<qdialog.h>
#include<qpushbutton.h>
#include <qlayout.h>

FaceRec::FaceRec(QDialog* parent) :QDialog(parent),
ui(new Ui::FaceRec)
{
	ui->setupUi(this);
	camera = new QCamera;//摄像头
	viewfinder = new QCameraViewfinder(this);
	imageCapture = new QCameraImageCapture(camera);//截图部件
	camera->setViewfinder(viewfinder);

	ui->cameraType->clear();
	cameras = QCameraInfo::availableCameras();
	foreach(const QCameraInfo & cameraInfo, cameras) {
		qDebug() << "CameraInfo:" << cameraInfo;
		ui->cameraType->addItem(cameraInfo.description());
	}

	ui->v_layout->addWidget(viewfinder);
	ui->v_layout->addLayout(ui->h_layout);

	QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(ShowTheCapture()));
	QObject::connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(SavePicture()));
	QObject::connect(imageCapture, SIGNAL(imageCaptured(int, QImage)), this, SLOT(displayImage(int, QImage)));
	imageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
	camera->setCaptureMode(QCamera::CaptureStillImage);
	camera->setViewfinder(viewfinder);
	camera->start(); //启动摄像头

}
FaceRec::~FaceRec()
{
	delete ui;
}

void FaceRec::ShowTheCapture()
{
	imageCapture->capture();
}
void FaceRec::displayImage(int, QImage image)
{



	//QImage image1(ui->label->x(),ui->label->y(),QImage::Format_RGB888);
       // image=new QImage(220,220,QImage::Format_RGB888);
       // image.setPixel(,Format_RGB888);
       // QColor color(QImage::Format_RGB888);
       // image.fill(color);
	//QImage image2;
	//QImage::Format format =  image1.format();
	//qDebug() << (int)format;
	image = image.convertToFormat(QImage::Format_RGB888);
	ui->label->setPixmap(QPixmap::fromImage(image));
	QImage::Format format = image.format();
	qDebug() << (int)format;
	qDebug() << "displayImage" << endl;

}



void FaceRec::SavePicture()
{
	bool isSave;
	const QPixmap* pixmap = ui->label->pixmap();
	if (pixmap)
	{
		isSave = pixmap->save("./deng.png");
		if (isSave)
		{
			qDebug() << "have saved" << endl;
		}

	}


}
void FaceRec::on_cameraType_activated(int index)
{
	
	index = ui->cameraType->currentIndex();
	qDebug() << "Index" << index << ": " << ui->cameraType->currentText();
	camera->stop();
	camera = new QCamera(cameras[index]);
	camera->setCaptureMode(QCamera::CaptureVideo);
	camera->setViewfinder(viewfinder);
	camera->start();
}
