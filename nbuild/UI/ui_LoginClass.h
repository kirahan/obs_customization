/********************************************************************************
** Form generated from reading UI file 'LoginClass.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINCLASS_H
#define UI_LOGINCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginClass
{
public:
    QWidget *widget;
    QLineEdit *loginLineEdit;
    QLineEdit *pwdLineEdit;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *loginBtn;
    QPushButton *exitBtn;

    void setupUi(QDialog *LoginClass)
    {
        if (LoginClass->objectName().isEmpty())
            LoginClass->setObjectName(QString::fromUtf8("LoginClass"));
        LoginClass->resize(1920, 1080);
        LoginClass->setStyleSheet(QString::fromUtf8("#LoginClass{background-image:url(:/res/images/login.png);}"));
        widget = new QWidget(LoginClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(1160, 330, 360, 440));
        widget->setAcceptDrops(false);
        widget->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255);\n"
"border-radius:10px;"));
        loginLineEdit = new QLineEdit(widget);
        loginLineEdit->setObjectName(QString::fromUtf8("loginLineEdit"));
        loginLineEdit->setGeometry(QRect(40, 100, 280, 45));
        loginLineEdit->setStyleSheet(QString::fromUtf8("border:2px solid rgb(113, 113, 113);\n"
"color:rgb(0,0,0);\n"
""));
        loginLineEdit->setFrame(true);
        loginLineEdit->setCursorPosition(0);
        loginLineEdit->setDragEnabled(false);
        pwdLineEdit = new QLineEdit(widget);
        pwdLineEdit->setObjectName(QString::fromUtf8("pwdLineEdit"));
        pwdLineEdit->setGeometry(QRect(40, 180, 280, 45));
        pwdLineEdit->setStyleSheet(QString::fromUtf8("border:2px solid rgb(113, 113, 113);\n"
"color:rgb(0,0,0);\n"
""));
        pwdLineEdit->setEchoMode(QLineEdit::Password);
        pwdLineEdit->setClearButtonEnabled(false);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(64, 35, 231, 41));
        label_3->setStyleSheet(QString::fromUtf8("color:rgb(48, 132, 235);\n"
"font: 75 18pt \"\347\255\211\347\272\277\";"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 360, 241, 31));
        label_4->setStyleSheet(QString::fromUtf8("color:black"));
        loginBtn = new QPushButton(widget);
        loginBtn->setObjectName(QString::fromUtf8("loginBtn"));
        loginBtn->setGeometry(QRect(40, 250, 280, 30));
        loginBtn->setStyleSheet(QString::fromUtf8("background-color:rgb(86, 106, 223);\n"
"color:white;\n"
"background-image:none"));
        loginBtn->setAutoExclusive(true);
        loginBtn->setAutoRepeatInterval(1000);
        loginBtn->setAutoDefault(false);
        exitBtn = new QPushButton(widget);
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));
        exitBtn->setGeometry(QRect(40, 300, 280, 30));
        exitBtn->setStyleSheet(QString::fromUtf8("background-color:rgb(240, 54, 57);\n"
"color:white;"));
        exitBtn->setAutoExclusive(true);
        exitBtn->setAutoRepeatInterval(1000);
        exitBtn->setAutoDefault(false);

        retranslateUi(LoginClass);
        QObject::connect(exitBtn, SIGNAL(clicked()), LoginClass, SLOT(close()));

        QMetaObject::connectSlotsByName(LoginClass);
    } // setupUi

    void retranslateUi(QDialog *LoginClass)
    {
        LoginClass->setWindowTitle(QCoreApplication::translate("LoginClass", "LoginClass", nullptr));
        widget->setProperty("themeID", QVariant(QCoreApplication::translate("LoginClass", "loginPannel", nullptr)));
        loginLineEdit->setText(QString());
        loginLineEdit->setPlaceholderText(QCoreApplication::translate("LoginClass", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        pwdLineEdit->setPlaceholderText(QCoreApplication::translate("LoginClass", "\345\257\206\347\240\201\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("LoginClass", "\347\224\250\346\210\267\347\231\273\345\275\225/UserLogin", nullptr));
        label_4->setText(QCoreApplication::translate("LoginClass", "\346\263\250\357\274\232\347\224\250\346\210\267\345\220\215\344\270\272\346\225\231\345\270\210\350\272\253\344\273\275\350\257\201\345\217\267\357\274\214\345\257\206\347\240\201\344\270\272123456", nullptr));
        loginBtn->setText(QCoreApplication::translate("LoginClass", "\347\231\273\345\275\225", nullptr));
        exitBtn->setText(QCoreApplication::translate("LoginClass", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginClass: public Ui_LoginClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINCLASS_H
