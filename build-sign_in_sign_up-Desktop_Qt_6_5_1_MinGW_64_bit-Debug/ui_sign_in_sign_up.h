/********************************************************************************
** Form generated from reading UI file 'sign_in_sign_up.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGN_IN_SIGN_UP_H
#define UI_SIGN_IN_SIGN_UP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SIGN_IN_SIGN_UP
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SIGN_IN_SIGN_UP)
    {
        if (SIGN_IN_SIGN_UP->objectName().isEmpty())
            SIGN_IN_SIGN_UP->setObjectName("SIGN_IN_SIGN_UP");
        SIGN_IN_SIGN_UP->resize(800, 600);
        centralwidget = new QWidget(SIGN_IN_SIGN_UP);
        centralwidget->setObjectName("centralwidget");
        SIGN_IN_SIGN_UP->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SIGN_IN_SIGN_UP);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        SIGN_IN_SIGN_UP->setMenuBar(menubar);
        statusbar = new QStatusBar(SIGN_IN_SIGN_UP);
        statusbar->setObjectName("statusbar");
        SIGN_IN_SIGN_UP->setStatusBar(statusbar);

        retranslateUi(SIGN_IN_SIGN_UP);

        QMetaObject::connectSlotsByName(SIGN_IN_SIGN_UP);
    } // setupUi

    void retranslateUi(QMainWindow *SIGN_IN_SIGN_UP)
    {
        SIGN_IN_SIGN_UP->setWindowTitle(QCoreApplication::translate("SIGN_IN_SIGN_UP", "SIGN_IN_SIGN_UP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SIGN_IN_SIGN_UP: public Ui_SIGN_IN_SIGN_UP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGN_IN_SIGN_UP_H
