#include "sign_in_sign_up.h"
#include "ui_sign_in_sign_up.h"

#include<QPushButton>
#include<QFont>
#include<QWidget>
#include<QWindow>

SIGN_IN_SIGN_UP::SIGN_IN_SIGN_UP(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SIGN_IN_SIGN_UP)
{
    ui->setupUi(this);
    this->resize(600,500);
    this->setWindowTitle("sign in & sign up");
    QPixmap skull(":/images/skull.jpg");
    skull = skull.scaled(QSize(75,75), Qt::KeepAspectRatio);
    QPalette skull_;
    skull_.setBrush(QPalette::Window, skull);
    this->setPalette(skull_);
    SIGN_IN = new QPushButton(this);
    SIGN_UP = new QPushButton(this);
    SIGN_IN->setText("Sign in");
    SIGN_IN->setFont(QFont("Curlz MT",14));
    SIGN_IN->setGeometry(0,60,300,33);
    SIGN_IN->setStyleSheet("background-color: rgb(255,219,75)");
    SIGN_UP->setText("Sign up");
    SIGN_UP->setFont(QFont("Curlz MT",14));
    SIGN_UP->setGeometry(0,120,300,33);
    SIGN_UP->setStyleSheet("background-color: rgb(255,219,75)");
}

SIGN_IN_SIGN_UP::~SIGN_IN_SIGN_UP()
{
    delete ui;
}


