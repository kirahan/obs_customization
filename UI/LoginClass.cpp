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

LoginClass::LoginClass(QWidget *parent)
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
		QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("账号和密码不能为空"), QMessageBox::Yes);
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
		data.append( byte_array);

		request.setHeader(QNetworkRequest::ContentTypeHeader,"application / x - www - form - urlencoded"); 
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
						/*
						QJsonValue message_value = obj.take("message");
						QString message_value_string = message_value.toString();
						qDebug() << "message string"<< message_value_string;  //输出：QJsonValue(string, "登录成功")
						if (message_value_string == "成功")
						{
							
							//取data的数据，获取教师的相关信息
							QJsonValue data_value = obj.take("data");
							QJsonObject data_obj = data_value.toObject();
							QJsonValue name_value = data_obj.take("name");
							QString name = name_value.toString();
							QJsonValue message_value = obj.take("message");
							qDebug() << message_value << endl;  //输出：QJsonValue(string, "登录成功")
						}
						else {
							QMessageBox::warning(this, "提示",message_value_string, QMessageBox::Yes);
							qDebug() << message_value << endl;  //输出：QJsonValue(string, "登录失败")
						}	
						*/
						
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
					QMessageBox::warning(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("系统错误！"), QMessageBox::Yes);
				}
			}
		}
	}
	reply->deleteLater();
}
