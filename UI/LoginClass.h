#pragma once

#include <QDialog>
#include "ui_LoginClass.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

class LoginClass : public QDialog
{
	Q_OBJECT

public:
	LoginClass(QWidget *parent = Q_NULLPTR);
	~LoginClass();

private:
	Ui::LoginClass ui;
	QNetworkAccessManager manager;   //manager  相关注意点见后文
	QNetworkRequest request;    //request 

public slots:
	void finishRequest(QNetworkReply*);
	void on_loginBtn_clicked();

	
};
