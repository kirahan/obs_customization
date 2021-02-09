#include "LoginClass.h"
#include <QMessageBox>
#include <QByteArray>
#include <QString>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonParseError>
#include <QJsonValue>
#include <QJsonObject>
#include <QDebug>
#include <iostream>
#include "window-basic-main.hpp"
QString str = "aaa";
QString token = "";
QJsonArray courseListData = { "abc" };
QJsonArray courseStream = { "abc" };
int clicked_row = 1;

LoginClass::LoginClass(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	//this->showMaximized();
	//this->resize(1920, 1080);
	this->setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
	//this->setStyleSheet("background-image:url(:/res/images/login.png)");
	QWidget* widget =  this->findChild<QWidget*>("widget");
	

}

LoginClass::~LoginClass()
{

}
void LoginClass::on_loginBtn_clicked() {
	qDebug() << "loginbtn clicked";
	ui.loginBtn->setDisabled(true);
	ui.loginBtn->setStyleSheet("background-color:grey;color:white");
	QString loginName = ui.loginLineEdit->text();
	QString password = ui.pwdLineEdit->text();
	if (loginName.isEmpty() || password.isEmpty())
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("账号密码不能为空!"), QMessageBox::Yes);
		ui.loginBtn->setDisabled(false);
		ui.loginBtn->setStyleSheet("background-color:rgb(86, 106, 223);color:white");
	}
	else {
		QJsonObject json;
		json.insert("loginName", loginName);
		json.insert("password", password);
		json.insert("moduleType", "YUN_ZHI_BO");
		json.insert("accountType", "LECTURER");
		QJsonDocument document;
		document.setObject(json);

		QByteArray byte_array = document.toJson(QJsonDocument::Compact);
		QByteArray data;
		data.append(byte_array);

		request.setHeader(QNetworkRequest::ContentTypeHeader, "application / x - www - form - urlencoded");
		request.setRawHeader("user-Agent", "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/75.0.3770.100 Safari/537.36");
		request.setRawHeader("content-type", "application/json");
		request.setUrl(QUrl("https://hbzjsp.com/zhiBoApi/v2/login"));

		manager.post(request, data);
		connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishRequest(QNetworkReply*)));
		ui.loginBtn->setDisabled(true);

	}
}

void LoginClass::finishRequest(QNetworkReply* reply)
{
	ui.loginBtn->setDisabled(false);
	ui.loginBtn->setStyleSheet("background-color:rgb(86, 106, 223);color:white");
	if (reply->error()) {
		QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("系统错误!"), QMessageBox::Yes);
	}
	else {

		QByteArray byte_array = reply->readAll();  //Json ducument
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
						QJsonValue data_value = obj.take("data");
						QJsonObject data_obj = data_value.toObject();
						if (data_obj.contains("token"))
						{
							QJsonValue token_value = data_obj.take("token");
							//QString token = token_value.toString();
							token = token_value.toString();
							
							if (token != "") {
								qDebug() << "token = " << token;
								getCourses();
								QTimer* _loop = new QTimer(this);
								connect(_loop, SIGNAL(timeout()), this, SLOT(getCourses()));
								_loop->start(2000);
								
							}

						}
						else {
							//QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("获取课程列表成功"), QMessageBox::Yes);
							QJsonArray data_arr = data_value.toArray();
							for (int i = 0; i < data_arr.count(); i++)
							{

								QJsonObject data_obj = data_arr[i].toObject();
								courseStream.append(data_obj);
								QString coursesList = "";
								QString curriculumName = data_obj.take("curriculumName").toString();
								QString beginDate = data_obj.take("beginDate").toString();
								QString beginTime = data_obj.take("beginTime").toString();
								QString endTime = data_obj.take("endTime").toString();
								
								coursesList.append(QString::fromLocal8Bit("课程："));
								coursesList.append(curriculumName);
								coursesList.append("  ");
								coursesList.append(QString::fromLocal8Bit("直播日期："));
								coursesList.append(beginDate);
								coursesList.append("  ");
								coursesList.append(QString::fromLocal8Bit("开始时间"));
								coursesList.append(beginTime);
								coursesList.append("  ");

								coursesList.append(QString::fromLocal8Bit("结束时间："));
								coursesList.append(endTime);
								coursesList.append("  ");

								coursesList.append(QString::fromLocal8Bit("直播状态："));

								QJsonValue playStatus_json = data_obj.take("playStatus");
								int playStatus = playStatus_json.toInt();
								
								if (playStatus == 0)
								{
									coursesList.append(QString::fromLocal8Bit("未开始"));
								}
								else if (playStatus == 1)
								{
									coursesList.append(QString::fromLocal8Bit("直播中"));
								}
								else if (playStatus == 2)
								{
									coursesList.append(QString::fromLocal8Bit("直播中断"));
								}
								else if (playStatus == 3)
								{
									coursesList.append(QString::fromLocal8Bit("未开始"));
								}
								courseListData.append(coursesList);
								

							}
							
						}

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
					QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("系统错误"), QMessageBox::Yes);
				}
			}
		}
	}
	reply->deleteLater();
}

void LoginClass::getCourses() {
	qDebug() << "token:" << token;
	QByteArray token_bytes = token.toLocal8Bit();
	
	QJsonObject date_json;

	QString currentDate = QDateTime::currentDateTime().toString("yyyy-MM-dd");
	qDebug() << "aaa:currentDate_login"<<currentDate;  //输出：QJsonValue(string, "登录成功")
	date_json.insert("beginDate", currentDate);
	QJsonDocument courses_document;
	courses_document.setObject(date_json);

	QByteArray byte_array = courses_document.toJson(QJsonDocument::Compact);
	QByteArray courses_data;
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application / x - www - form - urlencoded");
	request.setRawHeader("user-Agent", "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/75.0.3770.100 Safari/537.36");
	request.setRawHeader("content-type", "application/json");
	request.setRawHeader("token", token_bytes);

	request.setUrl(QUrl("https://hbzjsp.com/zhiBoApi/curriculum/getNotLiveCurriculumList"));
	courses_data.append(byte_array);
	manager.post(request, courses_data);
	QTime _Timer = QTime::currentTime().addMSecs(1000);

	while (QTime::currentTime() < _Timer)
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
	connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishRequest(QNetworkReply*)));
	//可能是接口太慢，等返回的时候，取数据的时候，数据是空的，过一会才会有数据
}


