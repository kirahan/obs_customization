#pragma once
#pragma once

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>


class GetCourses:public QObject
{
	Q_OBJECT

public:
	void login();
	void updateCourses(QString token);
private:
	QNetworkAccessManager manager;   //manager  相关注意点见后文
	QNetworkRequest request;    //request 


private slots:
	void finishLogin(QNetworkReply*);

signals:
	

};
