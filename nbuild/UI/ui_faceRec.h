/********************************************************************************
** Form generated from reading UI file 'faceRec.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACEREC_H
#define UI_FACEREC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaceRec
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *v_layout;
    QLabel *label;
    QLabel *label_2;
    QPushButton *ExitButton;
    QPushButton *pushButton;
    QComboBox *cameraType;

    void setupUi(QDialog *FaceRec)
    {
        if (FaceRec->objectName().isEmpty())
            FaceRec->setObjectName(QString::fromUtf8("FaceRec"));
        FaceRec->resize(430, 498);
        verticalLayoutWidget = new QWidget(FaceRec);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 70, 411, 301));
        v_layout = new QVBoxLayout(verticalLayoutWidget);
        v_layout->setObjectName(QString::fromUtf8("v_layout"));
        v_layout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        v_layout->addWidget(label);

        label_2 = new QLabel(FaceRec);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 10, 181, 61));
        label_2->setStyleSheet(QString::fromUtf8("color:rgb(48, 132, 235);\n"
"font: 75 28pt \347\255\211\347\272\277;"));
        ExitButton = new QPushButton(FaceRec);
        ExitButton->setObjectName(QString::fromUtf8("ExitButton"));
        ExitButton->setGeometry(QRect(10, 460, 409, 32));
        ExitButton->setStyleSheet(QString::fromUtf8("font:12pt;"));
        pushButton = new QPushButton(FaceRec);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 420, 409, 32));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setStyleSheet(QString::fromUtf8("font:12pt;"));
        cameraType = new QComboBox(FaceRec);
        cameraType->setObjectName(QString::fromUtf8("cameraType"));
        cameraType->setGeometry(QRect(10, 380, 409, 32));

        retranslateUi(FaceRec);
        QObject::connect(ExitButton, SIGNAL(clicked()), FaceRec, SLOT(close()));

        QMetaObject::connectSlotsByName(FaceRec);
    } // setupUi

    void retranslateUi(QDialog *FaceRec)
    {
        FaceRec->setWindowTitle(QCoreApplication::translate("FaceRec", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("FaceRec", "\345\256\236\345\220\215\350\256\244\350\257\201", nullptr));
        ExitButton->setText(QCoreApplication::translate("FaceRec", "\351\200\200\345\207\272", nullptr));
        pushButton->setText(QCoreApplication::translate("FaceRec", "\350\256\244\350\257\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FaceRec: public Ui_FaceRec {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACEREC_H
