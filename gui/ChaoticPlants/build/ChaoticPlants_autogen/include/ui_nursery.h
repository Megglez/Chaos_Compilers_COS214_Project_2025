/********************************************************************************
** Form generated from reading UI file 'nursery.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NURSERY_H
#define UI_NURSERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Nursery
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Nursery)
    {
        if (Nursery->objectName().isEmpty())
            Nursery->setObjectName(QString::fromUtf8("Nursery"));
        Nursery->resize(800, 600);
        centralwidget = new QWidget(Nursery);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Nursery->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Nursery);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        Nursery->setMenuBar(menubar);
        statusbar = new QStatusBar(Nursery);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Nursery->setStatusBar(statusbar);

        retranslateUi(Nursery);

        QMetaObject::connectSlotsByName(Nursery);
    } // setupUi

    void retranslateUi(QMainWindow *Nursery)
    {
        Nursery->setWindowTitle(QCoreApplication::translate("Nursery", "Nursery", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Nursery: public Ui_Nursery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NURSERY_H
