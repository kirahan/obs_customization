#pragma once

#include <QDialog>
#include "ui_LoginClass.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
extern QString str;
extern QJsonArray courseListData;
extern QJsonArray courseStream;
extern int clicked_row;
extern QString extern_token;
extern QString extern_loginName;
extern QString extern_password;

class LoginClass : public QDialog
{
	Q_OBJECT

public:
	LoginClass(QWidget *parent = Q_NULLPTR);
	~LoginClass();
	void LoginClass::getCourses(QString token);

private:
	Ui::LoginClass ui;
	QNetworkAccessManager manager;   //manager  相关注意点见后文
	QNetworkRequest request;    //request 

public slots:
	void finishRequest(QNetworkReply*);
	void on_loginBtn_clicked();

signals:
	void sendCourses(QString data);
	
};
