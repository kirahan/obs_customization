#pragma once

#include <QDialog>
#include "ui_LoginClass.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
extern QString str;
extern QJsonArray courseListData;

class LoginClass : public QDialog
{
	Q_OBJECT

public:
	LoginClass(QWidget *parent = Q_NULLPTR);
	~LoginClass();
	void LoginClass::getCourses(QString token);

private:
	Ui::LoginClass ui;
	QNetworkAccessManager manager;   //manager  ���ע��������
	QNetworkRequest request;    //request 

public slots:
	void finishRequest(QNetworkReply*);
	void on_loginBtn_clicked();

signals:
	void sendCourses(QString data);
	
};
