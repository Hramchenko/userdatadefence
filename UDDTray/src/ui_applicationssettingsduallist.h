/********************************************************************************
** Form generated from reading UI file 'applicationssettingsduallist.ui'
**
** Created: 
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLICATIONSSETTINGSDUALLIST_H
#define UI_APPLICATIONSSETTINGSDUALLIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "ApplicationsSettingsList.h"

QT_BEGIN_NAMESPACE

class Ui_ApplicationsSettingsDualList
{
public:
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_12;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_9;
    ApplicationsSettingsList *groupsListWgt;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout_17;
    ApplicationsSettingsList *itemsListWgt;
    QVBoxLayout *verticalLayout_6;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ApplicationsSettingsDualList)
    {
        if (ApplicationsSettingsDualList->objectName().isEmpty())
            ApplicationsSettingsDualList->setObjectName(QString::fromUtf8("ApplicationsSettingsDualList"));
        ApplicationsSettingsDualList->resize(400, 300);
        horizontalLayout = new QHBoxLayout(ApplicationsSettingsDualList);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        groupBox_6 = new QGroupBox(ApplicationsSettingsDualList);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setFlat(true);
        verticalLayout_9 = new QVBoxLayout(groupBox_6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        groupsListWgt = new ApplicationsSettingsList(groupBox_6);
        groupsListWgt->setObjectName(QString::fromUtf8("groupsListWgt"));

        verticalLayout_9->addWidget(groupsListWgt);


        horizontalLayout_12->addWidget(groupBox_6);

        groupBox_7 = new QGroupBox(ApplicationsSettingsDualList);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setFlat(true);
        horizontalLayout_17 = new QHBoxLayout(groupBox_7);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        itemsListWgt = new ApplicationsSettingsList(groupBox_7);
        itemsListWgt->setObjectName(QString::fromUtf8("itemsListWgt"));

        horizontalLayout_17->addWidget(itemsListWgt);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        toolButton_3 = new QToolButton(groupBox_7);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/list-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon);

        verticalLayout_6->addWidget(toolButton_3);

        toolButton_4 = new QToolButton(groupBox_7);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/list-remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon1);

        verticalLayout_6->addWidget(toolButton_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);


        horizontalLayout_17->addLayout(verticalLayout_6);


        horizontalLayout_12->addWidget(groupBox_7);


        horizontalLayout->addLayout(horizontalLayout_12);


        retranslateUi(ApplicationsSettingsDualList);

        QMetaObject::connectSlotsByName(ApplicationsSettingsDualList);
    } // setupUi

    void retranslateUi(QWidget *ApplicationsSettingsDualList)
    {
        ApplicationsSettingsDualList->setWindowTitle(QApplication::translate("ApplicationsSettingsDualList", "Form", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("ApplicationsSettingsDualList", "Application groups", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("ApplicationsSettingsDualList", "Modes", 0, QApplication::UnicodeUTF8));
        toolButton_3->setText(QApplication::translate("ApplicationsSettingsDualList", "...", 0, QApplication::UnicodeUTF8));
        toolButton_4->setText(QApplication::translate("ApplicationsSettingsDualList", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ApplicationsSettingsDualList: public Ui_ApplicationsSettingsDualList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICATIONSSETTINGSDUALLIST_H
