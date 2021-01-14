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
QJsonArray courseListData = { "abc" };
QJsonArray courseStream = { "abc" };
int clicked_row = 1;

LoginClass::LoginClass(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

LoginClass::~LoginClass()
{

}
void LoginClass::on_loginBtn_clicked() {

	QString loginName = ui.loginLineEdit->text();
	QString password = ui.pwdLineEdit->text();
	if (loginName.isEmpty() || password.isEmpty())
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("账号密码不能为空!"), QMessageBox::Yes);
		ui.loginLineEdit->clear();
		ui.pwdLineEdit->clear();
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
		request.setUrl(QUrl("https://ycary.cn:1083/zhiBoApi/v2/login"));

		manager.post(request, data);
		connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishRequest(QNetworkReply*)));
		ui.loginBtn->setDisabled(true);

	}
}

void LoginClass::finishRequest(QNetworkReply* reply)
{
	ui.loginBtn->setDisabled(false);
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
							QString token = token_value.toString();
							if (token != "") {
								getCourses(token);
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
								coursesList.append("课程:");
								coursesList.append(curriculumName);
								coursesList.append("  ");
								coursesList.append("直播日期:");
								coursesList.append(beginDate);
								coursesList.append("  ");
								coursesList.append("开始时间:");
								coursesList.append(beginTime);
								coursesList.append("  ");

								coursesList.append("结束时间:");
								coursesList.append(endTime);
								coursesList.append("  ");

								coursesList.append("直播状态:");

								QJsonValue playStatus_json = data_obj.take("playStatus");
								int playStatus = playStatus_json.toInt();
								
								if (playStatus == 0)
								{
									coursesList.append("未开始 ");
								}
								else if (playStatus == 1)
								{
									coursesList.append("直播中 ");
								}
								else if (playStatus == 2)
								{
									coursesList.append("直播中断 ");
								}
								else if (playStatus == 3)
								{
									coursesList.append("未开始 ");
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

void LoginClass::getCourses(QString token) {
	qDebug() << "token:" << token;
	QByteArray token_bytes = token.toLocal8Bit();
	
	QJsonObject date_json;

	QString currentDate = QDateTime::currentDateTime().toString("yyyy-MM-dd");
	qDebug() << "aaa:currentDate_login"<<currentDate;  //输出：QJsonValue(string, "登录成功")
	date_json.insert("beginDate", "2020-12-30");
	QJsonDocument courses_document;
	courses_document.setObject(date_json);

	QByteArray byte_array = courses_document.toJson(QJsonDocument::Compact);
	QByteArray courses_data;
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application / x - www - form - urlencoded");
	request.setRawHeader("user-Agent", "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/75.0.3770.100 Safari/537.36");
	request.setRawHeader("content-type", "application/json");
	request.setRawHeader("token", token_bytes);

	request.setUrl(QUrl("https://ycary.cn:1083/zhiBoApi/curriculum/getNotLiveCurriculumList"));
	courses_data.append(byte_array);
	manager.post(request, courses_data);
	QTime _Timer = QTime::currentTime().addMSecs(5000);

	while (QTime::currentTime() < _Timer)
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
	connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishGetCourses(QNetworkReply*)));
	//可能是接口太慢，等返回的时候，取数据的时候，数据是空的，过一会才会有数据

}
