/********************************************************************************
** Form generated from reading UI file 'scripts.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCRIPTS_H
#define UI_SCRIPTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScriptsTool
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *scriptsTab;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QListWidget *scripts;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addScripts;
    QPushButton *removeScripts;
    QPushButton *reloadScripts;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *defaults;
    QPushButton *scriptLog;
    QVBoxLayout *propertiesLayout;
    QLabel *label_3;
    QLabel *description;
    QWidget *pythonSettingsTab;
    QVBoxLayout *verticalLayout_2;
    QLabel *pythonPathLabel;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *pythonPath;
    QPushButton *pythonPathBrowse;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *close;

    void setupUi(QWidget *ScriptsTool)
    {
        if (ScriptsTool->objectName().isEmpty())
            ScriptsTool->setObjectName(QString::fromUtf8("ScriptsTool"));
        ScriptsTool->resize(775, 492);
        verticalLayout = new QVBoxLayout(ScriptsTool);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(ScriptsTool);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabBarAutoHide(true);
        scriptsTab = new QWidget();
        scriptsTab->setObjectName(QString::fromUtf8("scriptsTab"));
        horizontalLayout_4 = new QHBoxLayout(scriptsTab);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(scriptsTab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        scripts = new QListWidget(scriptsTab);
        scripts->setObjectName(QString::fromUtf8("scripts"));
        scripts->setContextMenuPolicy(Qt::CustomContextMenu);
        scripts->setSortingEnabled(true);

        verticalLayout_3->addWidget(scripts);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        addScripts = new QPushButton(scriptsTab);
        addScripts->setObjectName(QString::fromUtf8("addScripts"));
        addScripts->setMaximumSize(QSize(22, 22));
        addScripts->setText(QString::fromUtf8(""));
        addScripts->setFlat(true);
        addScripts->setProperty("themeID", QVariant(QString::fromUtf8("addIconSmall")));

        horizontalLayout_2->addWidget(addScripts);

        removeScripts = new QPushButton(scriptsTab);
        removeScripts->setObjectName(QString::fromUtf8("removeScripts"));
        removeScripts->setMaximumSize(QSize(22, 22));
        removeScripts->setText(QString::fromUtf8(""));
        removeScripts->setFlat(true);
        removeScripts->setProperty("themeID", QVariant(QString::fromUtf8("removeIconSmall")));

        horizontalLayout_2->addWidget(removeScripts);

        reloadScripts = new QPushButton(scriptsTab);
        reloadScripts->setObjectName(QString::fromUtf8("reloadScripts"));
        reloadScripts->setMaximumSize(QSize(22, 22));
        reloadScripts->setText(QString::fromUtf8(""));
        reloadScripts->setFlat(true);
        reloadScripts->setProperty("themeID", QVariant(QString::fromUtf8("refreshIconSmall")));

        horizontalLayout_2->addWidget(reloadScripts);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        defaults = new QPushButton(scriptsTab);
        defaults->setObjectName(QString::fromUtf8("defaults"));

        horizontalLayout_2->addWidget(defaults);

        scriptLog = new QPushButton(scriptsTab);
        scriptLog->setObjectName(QString::fromUtf8("scriptLog"));

        horizontalLayout_2->addWidget(scriptLog);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout_3);

        propertiesLayout = new QVBoxLayout();
        propertiesLayout->setObjectName(QString::fromUtf8("propertiesLayout"));
        label_3 = new QLabel(scriptsTab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        propertiesLayout->addWidget(label_3);

        description = new QLabel(scriptsTab);
        description->setObjectName(QString::fromUtf8("description"));
        description->setText(QString::fromUtf8(""));
        description->setOpenExternalLinks(false);
        description->setWordWrap(true);
        description->setMargin(12);

        propertiesLayout->addWidget(description);


        horizontalLayout_4->addLayout(propertiesLayout);

        tabWidget->addTab(scriptsTab, QString());
        pythonSettingsTab = new QWidget();
        pythonSettingsTab->setObjectName(QString::fromUtf8("pythonSettingsTab"));
        verticalLayout_2 = new QVBoxLayout(pythonSettingsTab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pythonPathLabel = new QLabel(pythonSettingsTab);
        pythonPathLabel->setObjectName(QString::fromUtf8("pythonPathLabel"));
        pythonPathLabel->setText(QString::fromUtf8(""));

        verticalLayout_2->addWidget(pythonPathLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pythonPath = new QLineEdit(pythonSettingsTab);
        pythonPath->setObjectName(QString::fromUtf8("pythonPath"));
        pythonPath->setReadOnly(true);

        horizontalLayout_3->addWidget(pythonPath);

        pythonPathBrowse = new QPushButton(pythonSettingsTab);
        pythonPathBrowse->setObjectName(QString::fromUtf8("pythonPathBrowse"));

        horizontalLayout_3->addWidget(pythonPathBrowse);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(510, 306, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        tabWidget->addTab(pythonSettingsTab, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        close = new QPushButton(ScriptsTool);
        close->setObjectName(QString::fromUtf8("close"));

        horizontalLayout->addWidget(close);


        verticalLayout->addLayout(horizontalLayout);

#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(scripts);
        pythonPathLabel->setBuddy(pythonPath);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(tabWidget, close);
        QWidget::setTabOrder(close, pythonPath);
        QWidget::setTabOrder(pythonPath, pythonPathBrowse);

        retranslateUi(ScriptsTool);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ScriptsTool);
    } // setupUi

    void retranslateUi(QWidget *ScriptsTool)
    {
        ScriptsTool->setWindowTitle(QApplication::translate("ScriptsTool", "Scripts", nullptr));
        label_2->setText(QApplication::translate("ScriptsTool", "LoadedScripts", nullptr));
#ifndef QT_NO_TOOLTIP
        addScripts->setToolTip(QApplication::translate("ScriptsTool", "AddScripts", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_ACCESSIBILITY
        addScripts->setAccessibleName(QApplication::translate("ScriptsTool", "AddScripts", nullptr));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_TOOLTIP
        removeScripts->setToolTip(QApplication::translate("ScriptsTool", "RemoveScripts", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_ACCESSIBILITY
        removeScripts->setAccessibleName(QApplication::translate("ScriptsTool", "RemoveScripts", nullptr));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_TOOLTIP
        reloadScripts->setToolTip(QApplication::translate("ScriptsTool", "ReloadScripts", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_ACCESSIBILITY
        reloadScripts->setAccessibleName(QApplication::translate("ScriptsTool", "ReloadScripts", nullptr));
#endif // QT_NO_ACCESSIBILITY
        defaults->setText(QApplication::translate("ScriptsTool", "Defaults", nullptr));
        scriptLog->setText(QApplication::translate("ScriptsTool", "ScriptLogWindow", nullptr));
        label_3->setText(QApplication::translate("ScriptsTool", "Description", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(scriptsTab), QApplication::translate("ScriptsTool", "Scripts", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        pythonPathBrowse->setAccessibleName(QApplication::translate("ScriptsTool", "PythonSettings.BrowsePythonPath", nullptr));
#endif // QT_NO_ACCESSIBILITY
        pythonPathBrowse->setText(QApplication::translate("ScriptsTool", "Browse", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pythonSettingsTab), QApplication::translate("ScriptsTool", "PythonSettings", nullptr));
        close->setText(QApplication::translate("ScriptsTool", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScriptsTool: public Ui_ScriptsTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCRIPTS_H
