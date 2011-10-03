/********************************************************************************
** Form generated from reading UI file 'groupslist.ui'
**
** Created: 
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPSLIST_H
#define UI_GROUPSLIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GroupsList
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton;
    QToolButton *toolButton_2;

    void setupUi(QGroupBox *GroupsList)
    {
        if (GroupsList->objectName().isEmpty())
            GroupsList->setObjectName(QString::fromUtf8("GroupsList"));
        GroupsList->resize(400, 300);
        verticalLayout = new QVBoxLayout(GroupsList);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(GroupsList);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton = new QToolButton(GroupsList);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/list-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton);

        toolButton_2 = new QToolButton(GroupsList);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/list-remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GroupsList);

        QMetaObject::connectSlotsByName(GroupsList);
    } // setupUi

    void retranslateUi(QGroupBox *GroupsList)
    {
        GroupsList->setWindowTitle(QApplication::translate("GroupsList", "GroupBox", 0, QApplication::UnicodeUTF8));
        GroupsList->setTitle(QApplication::translate("GroupsList", "GroupBox", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("GroupsList", "...", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QApplication::translate("GroupsList", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GroupsList: public Ui_GroupsList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPSLIST_H
