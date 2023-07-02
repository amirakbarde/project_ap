#include "sign_up.h"
#include "ui_sign_up.h"
#include<QFile>
#include <QIODevice>
#include <QDebug>
#include "menue.h"
sign_up::sign_up(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sign_up)
{
    ui->setupUi(this);
    this->resize(600,500);
    this->setWindowTitle("sign in & sign up");
    QPixmap skull(":/images/skull.jpg");
    skull = skull.scaled(QSize(75,75), Qt::KeepAspectRatio);
    QPalette skull_;
    skull_.setBrush(QPalette::Window, skull);
    this->setPalette(skull_);
    QLabel *user_l= new QLabel(this);
    user_l->setText("username:");
    user_l->setFont(QFont("Curlz MT",14));
    user_l->setGeometry(0,60,80,33);
    user_l->setStyleSheet("background-color: rgb(255,219,75)");
    QLabel *pass_l= new QLabel(this);
    pass_l->setText("password:");
    pass_l->setFont(QFont("Curlz MT",14));
    pass_l->setGeometry(0,120,80,33);
    pass_l->setStyleSheet("background-color: rgb(255,219,75)");
    QLabel *name_l= new QLabel(this);
    name_l->setText("name:");
    name_l->setFont(QFont("Curlz MT",14));
    name_l->setGeometry(0,180,80,33);
    name_l->setStyleSheet("background-color: rgb(255,219,75)");
    QLabel *number_l= new QLabel(this);
    number_l->setText("phone:");
    number_l->setFont(QFont("Curlz MT",14));
    number_l->setGeometry(0,240,80,33);
    number_l->setStyleSheet("background-color: rgb(255,219,75)");
    QLabel *gmail_l= new QLabel(this);
    gmail_l->setText("email:");
    gmail_l->setFont(QFont("Curlz MT",14));
    gmail_l->setGeometry(0,300,80,33);
    gmail_l->setStyleSheet("background-color: rgb(255,219,75)");
    QLabel *path_l= new QLabel(this);
    path_l->setText("path:");
    path_l->setFont(QFont("Curlz MT",14));
    path_l->setGeometry(0,360,80,33);
    path_l->setStyleSheet("background-color: rgb(255,219,75)");
    ok = new QPushButton(this);
    ok->setText("ok");
    ok->setFont(QFont("Curlz MT",14));
    ok->setGeometry(300,400,40,20);
    ok->setStyleSheet("background-color: rgb(255,219,75)");
    connect(ok,SIGNAL(clicked()),this,SLOT(checking_sign_up()));
    user_e= new QLineEdit(this);
    user_e->setFont(QFont("Curlz MT",14));
    user_e->setGeometry(81,60,220,33);
    user_e->setStyleSheet("background-color: rgb(255,219,75)");
    pass_e= new QLineEdit(this);
    pass_e->setFont(QFont("Curlz MT",14));
    pass_e->setGeometry(81,120,220,33);
    pass_e->setStyleSheet("background-color: rgb(255,219,75)");
    name_e= new QLineEdit(this);
    name_e->setFont(QFont("Curlz MT",14));
    name_e->setGeometry(81,180,220,33);
    name_e->setStyleSheet("background-color: rgb(255,219,75)");
    number_e= new QLineEdit(this);
    number_e->setFont(QFont("Curlz MT",14));
    number_e->setGeometry(81,240,220,33);
    number_e->setStyleSheet("background-color: rgb(255,219,75)");
    gmail_e= new QLineEdit(this);
    gmail_e->setFont(QFont("Curlz MT",14));
    gmail_e->setGeometry(81,300,220,33);
    gmail_e->setStyleSheet("background-color: rgb(255,219,75)");
    path_e= new QLineEdit(this);
    path_e->setFont(QFont("Curlz MT",14));
    path_e->setGeometry(81,360,220,33);
    path_e->setStyleSheet("background-color: rgb(255,219,75)");
}

sign_up::~sign_up()
{
    delete ui;
}

void sign_up::checking_sign_up(){
    int flag=0;
    QString username = user_e->text();
    QFile file(path_e->text() + "users.txt");
    if (!file.open(QIODevice::ReadOnly)){
        if (!file.open(QIODevice::WriteOnly)){

        }
        else{
            creating();
        }
    }
    else{
        QTextStream stream(&file);
        while (!stream.atEnd()){
            if(stream.readLine()==username){
                flag=1;
                break;
            }
        }
        if(flag==0){
            creating();
        }
    }

    file.close();
}

void sign_up::creating(){
    QFile file(path_e->text()+"users.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text)){

    }
    else{
        QTextStream outStream(&file);
        file.seek(file.size());
        outStream <<user_e->text()<< "\n";
        file.close();
    }
    file.close();
    QFile file2(path_e->text() + user_e->text() +".txt");
    if (!file2.open(QIODevice::WriteOnly)){

    }
    else{
        QTextStream outStream(&file2);
        outStream <<user_e->text()<< "\n";
        outStream <<pass_e->text()<< "\n";
        outStream <<name_e->text()<< "\n";
        outStream <<number_e->text()<< "\n";
        outStream <<gmail_e->text()<< "\n";
        outStream <<"1000\n";
        outStream <<"0\n";
        outStream <<"0\n";
        outStream <<"0\n";
    }
    file2.close();
    this->hide();
    menue *obj = new menue();
    obj->getting(user_e->text(),path_e->text());
}
