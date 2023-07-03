/********************************************************************************
** Form generated from reading UI file 'sign_in.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGN_IN_H
#define UI_SIGN_IN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sign_in
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *sign_in)
    {
        if (sign_in->objectName().isEmpty())
            sign_in->setObjectName("sign_in");
        sign_in->resize(800, 600);
        menubar = new QMenuBar(sign_in);
        menubar->setObjectName("menubar");
        sign_in->setMenuBar(menubar);
        centralwidget = new QWidget(sign_in);
        centralwidget->setObjectName("centralwidget");
        sign_in->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(sign_in);
        statusbar->setObjectName("statusbar");
        sign_in->setStatusBar(statusbar);

        retranslateUi(sign_in);

        QMetaObject::connectSlotsByName(sign_in);
    } // setupUi

    void retranslateUi(QMainWindow *sign_in)
    {
        sign_in->setWindowTitle(QCoreApplication::translate("sign_in", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sign_in: public Ui_sign_in {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGN_IN_H
