#include "faceRec.h"
#include "ui_faceRec.h"
#include<Qdebug>
#include<qobject.h>
#include<qdialog.h>
#include<qpushbutton.h>
#include <qlayout.h>
#include <QCameraInfo>
#include <QLabel>
#include <LoginClass.h>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonParseError>
#include <QJsonValue>
#include <QJsonObject>
#include <QHttpMultiPart>
#include <qdir.h>
 
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
    image = image.convertToFormat(QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(image));
    QImage::Format format = image.format();

     
}   

void FaceRec::SavePicture()
{
    bool isSave;
    const QPixmap* pixmap = ui->label->pixmap();
    QDir dir("../picture");//删除log文件夹下后缀为xml的文件

    QDir* folder = new QDir;
    //判断创建文件夹是否存在
    bool exist = folder->exists("../pictures");
    if (exist)
    {
	    foreach(QFileInfo mfi, dir.entryInfoList()) {
		    if (mfi.isFile() && mfi.suffix() == "png") {//判断后缀是否为xml
			    dir.remove(mfi.fileName());
		    }
	    }
    }
    else //如果不存在，创建文件夹
    {
	    //创建文件夹
	    bool ok = folder->mkdir("../pictures");
	    //判断是否成功
	    if (!ok)
	    {
		    QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("无法存储图片，请关闭软件后重试"));
	    }
    }
    if (pixmap)
    {
        isSave = pixmap->save("../pictures/faceImage.png");
        if (isSave)
        {
	    recognise();
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

void FaceRec::recognise()
{ 
	QByteArray token_bytes = extern_token.toLocal8Bit();
	phone = "18120416052";
	qDebug() << "loginbtn clicked";
	//ui.loginBtn->setDisabled(true);
	//ui.loginBtn->setStyleSheet("background-color:grey;color:white");
	if (phone == "a")
	{
		phone = "";
	}
	if (tec_name == "a"|| idCode == "a")
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("账户信息错误，请重新登录!"), QMessageBox::Yes);
	}
	else {
		QJsonObject json;
		json.insert("idCode", idCode);
		json.insert("name", tec_name);
		json.insert("phoneNumber", phone);
		QJsonDocument document;
		document.setObject(json);

		QByteArray byte_array = document.toJson(QJsonDocument::Compact);
		QByteArray data;
		data.append(byte_array);

		QHttpMultiPart* multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

		/*添加文本到request*/
		QHttpPart image_part;
		QHttpPart text_part;
		text_part.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"idCode\""));
		text_part.setBody(idCode.toLatin1());
		multiPart->append(text_part);


		text_part.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"name\""));
		text_part.setBody(tec_name.toLatin1());
		multiPart->append(text_part);

		text_part.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"phoneNumber\""));
		text_part.setBody(phone.toLatin1());
		multiPart->append(text_part);

		/*添加图片到request*/
		
		image_part.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/png"));//如果是png图片填image/png
		image_part.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"file\";filename=\"faceImage.png\""));
		QFile* file = new QFile("../pictures/faceImage.png");
		file->open(QIODevice::ReadOnly);
		image_part.setBodyDevice(file);
		file->setParent(multiPart); // we cannot delete the file now, so delete it with the multiPart

		//multiPart->append(text_part);
		multiPart->append(image_part);

		//request.setHeader(QNetworkRequest::ContentTypeHeader, "multipart/form-data");
		request.setRawHeader("user-Agent", "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/75.0.3770.100 Safari/537.36");
		request.setRawHeader("enctype", "multipart/form-data");
		
		request.setRawHeader("token", token_bytes);
		request.setUrl(QUrl("https://ycary.cn:1083/zhiBoApi/Certification/authentication_file"));

		manager.post(request, multiPart);
		connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishRequest(QNetworkReply*)));
		//ui.loginBtn->setDisabled(true);

	}
	
}

void FaceRec::finishRequest(QNetworkReply* reply)
{
	
	//ui.loginBtn->setDisabled(false);
	//ui.loginBtn->setStyleSheet("background-color:rgb(86, 106, 223);color:white");
	if (reply->error()) {
		QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("系统错误!"), QMessageBox::Yes);
	}
	else {

		QByteArray byte_array = reply->readAll();  //Json ducument
		qDebug() << "aaa:byte_array" << byte_array;  //输出：QJsonValue(string, "登录成功")
		QJsonParseError json_error;
		QJsonDocument parse_document = QJsonDocument::fromJson(byte_array, &json_error);


		if (json_error.error == QJsonParseError::NoError)
		{
			QJsonObject obj = parse_document.object();
			if (parse_document.isObject())
			{
				QJsonObject obj = parse_document.object(); //将返回的json转换成对象obj
				if (obj.contains("code"))
				{
					QJsonValue code_value = obj.take("code");
					QString code_value_string = code_value.toString();
					if (code_value_string == "200")
					{
						accept();//登录成功，跳转到主页面
						//QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("登录成功"), QMessageBox::Yes);
						qDebug() << "login_succeed";  //输出：QJsonValue(string, "登录成功")
						
					}
					else
					{
						QJsonValue message_value = obj.take("message");
						qDebug() << message_value << endl;
						QString error_message = message_value.toString();
						QMessageBox::warning(this, QString::fromLocal8Bit("提示"), error_message, QMessageBox::Yes);
					}
				}
				else {
					QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("系统错误,请重新登录"), QMessageBox::Yes);
				}
			}
		}
	}
	reply->deleteLater();
	
}
