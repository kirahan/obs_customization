/********************************************************************************
** Form generated from reading UI file 'AutoConfigVideoPage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOCONFIGVIDEOPAGE_H
#define UI_AUTOCONFIGVIDEOPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AutoConfigVideoPage
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout_2;
    QLabel *label;
    QComboBox *canvasRes;
    QLabel *label_3;
    QComboBox *fps;
    QSpacerItem *horizontalSpacer;
    QLabel *warningLabel;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *AutoConfigVideoPage)
    {
        if (AutoConfigVideoPage->objectName().isEmpty())
            AutoConfigVideoPage->setObjectName(QString::fromUtf8("AutoConfigVideoPage"));
        AutoConfigVideoPage->resize(470, 300);
        AutoConfigVideoPage->setWindowTitle(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(AutoConfigVideoPage);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout_2->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(AutoConfigVideoPage);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        canvasRes = new QComboBox(AutoConfigVideoPage);
        canvasRes->setObjectName(QString::fromUtf8("canvasRes"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, canvasRes);

        label_3 = new QLabel(AutoConfigVideoPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_3);

        fps = new QComboBox(AutoConfigVideoPage);
        fps->setObjectName(QString::fromUtf8("fps"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, fps);

        horizontalSpacer = new QSpacerItem(87, 17, QSizePolicy::Fixed, QSizePolicy::Minimum);

        formLayout_2->setItem(3, QFormLayout::LabelRole, horizontalSpacer);


        verticalLayout->addLayout(formLayout_2);

        warningLabel = new QLabel(AutoConfigVideoPage);
        warningLabel->setObjectName(QString::fromUtf8("warningLabel"));
        warningLabel->setWordWrap(true);

        verticalLayout->addWidget(warningLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(canvasRes);
        label_3->setBuddy(fps);
#endif // QT_NO_SHORTCUT

        retranslateUi(AutoConfigVideoPage);

        QMetaObject::connectSlotsByName(AutoConfigVideoPage);
    } // setupUi

    void retranslateUi(QWidget *AutoConfigVideoPage)
    {
        label->setText(QApplication::translate("AutoConfigVideoPage", "Basic.Settings.Video.BaseResolution", nullptr));
        label_3->setText(QApplication::translate("AutoConfigVideoPage", "Basic.Settings.Video.FPS", nullptr));
        warningLabel->setText(QApplication::translate("AutoConfigVideoPage", "Basic.AutoConfig.VideoPage.CanvasExplanation", nullptr));
        Q_UNUSED(AutoConfigVideoPage);
    } // retranslateUi

};

namespace Ui {
    class AutoConfigVideoPage: public Ui_AutoConfigVideoPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOCONFIGVIDEOPAGE_H
