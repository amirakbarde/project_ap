#include "sign_in_sign_up.h"
#include "ui_sign_in_sign_up.h"
#include<QPushButton>
#include<QFont>
#include<QWidget>
#include<QWindow>
#include "sign_in_class_header.h"
#include"sign_up.h"

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
    QPushButton *SIGN_IN = new QPushButton(this);
    QPushButton *SIGN_UP = new QPushButton(this);
    SIGN_IN->setText("Sign in");
    SIGN_IN->setFont(QFont("Curlz MT",14));
    SIGN_IN->setGeometry(0,60,300,33);
    SIGN_IN->setStyleSheet("background-color: rgb(255,219,75)");
    SIGN_UP->setText("Sign up");
    SIGN_UP->setFont(QFont("Curlz MT",14));
    SIGN_UP->setGeometry(0,120,300,33);
    SIGN_UP->setStyleSheet("background-color: rgb(255,219,75)");
    connect(SIGN_UP, SIGNAL(clicked()),this, SLOT(sign_up__()));
    connect(SIGN_IN, SIGNAL(clicked()),this, SLOT(going_to_sign_in()));
}

SIGN_IN_SIGN_UP::~SIGN_IN_SIGN_UP()
{
    delete ui;
}
void SIGN_IN_SIGN_UP::going_to_sign_in(){
    this->hide();
    sign_in_class_header* object_sign_in=new sign_in_class_header();
    object_sign_in->show();
}
void SIGN_IN_SIGN_UP::sign_up__(){
    this->hide();
    sign_up *obj_sign_up = new sign_up();
    obj_sign_up->show();

}

