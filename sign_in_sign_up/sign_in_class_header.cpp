#include "sign_in_class_header.h"
#include "ui_sign_in_class_header.h"
#include<QMainWindow>
#include<QPushButton>
#include<QString>
#include<QFile>

sign_in_class_header::sign_in_class_header(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sign_in_class_header)
{
    ui->setupUi(this);
    this->resize(600,500);
    this->setWindowTitle("sign in");
    QPixmap skull(":/images/skull.jpg");
    skull = skull.scaled(QSize(75,75), Qt::KeepAspectRatio);
    QPalette skull_;
    skull_.setBrush(QPalette::Window, skull);
    this->setPalette(skull_);
    QPushButton *f_password = new QPushButton(this);
    f_password->setText("forgot passwordr");
    f_password->setFont(QFont("Curlz MT",14));
    f_password->setGeometry(0,180,300,33);
    f_password->setStyleSheet("background-color: rgb(255,219,75)");
    QLabel *username = new QLabel(this);
    QLabel *password = new QLabel(this);
    QPushButton *taeed = new QPushButton(this);
    taeed->setText("ok");
    taeed->setFont(QFont("Curlz MT",14));
    taeed->setGeometry(260,240,80,33);
    taeed->setStyleSheet("background-color: rgb(255,219,75)");
    userna = new QLineEdit(this);
    passwo = new QLineEdit(this);
    username->setText("username");
    username->setFont(QFont("Curlz MT",14));
    username->setGeometry(0,60,80,33);
    username->setStyleSheet("background-color: rgb(255,219,75)");
    password->setText("password");
    password->setFont(QFont("Curlz MT",14));
    password->setGeometry(0,120,80,33);
    password->setStyleSheet("background-color: rgb(255,219,75)");
    userna->setFont(QFont("Curlz MT",14));
    userna->setGeometry(81,60,220,33);
    userna->setStyleSheet("background-color: rgb(255,219,75)");
    passwo->setFont(QFont("Curlz MT",14));
    passwo->setGeometry(81,120,220,33);
    passwo->setStyleSheet("background-color: rgb(255,219,75)");
    connect(f_password,SIGNAL(clicked()),this ,SLOT(forgot_password()));
    connect(taeed,SIGNAL(clicked()),this ,SLOT(line_getting_username_password()));
}

sign_in_class_header::~sign_in_class_header()
{
    delete ui;
}

void sign_in_class_header::forgot_password(){
    this->hide();
    window_forgot_password = new QMainWindow();
    window_forgot_password->resize(600,500);
    window_forgot_password->setWindowTitle("forgot password");
    QPixmap skull(":/images/skull.jpg");
    skull = skull.scaled(QSize(75,75), Qt::KeepAspectRatio);
    QPalette skull_;
    skull_.setBrush(QPalette::Window, skull);
    window_forgot_password->setPalette(skull_);
    QLabel *phone_num = new QLabel(window_forgot_password);
    telephone = new QLineEdit(window_forgot_password);
    QPushButton *taeed = new QPushButton(window_forgot_password);
    telepho_username = new QLineEdit(window_forgot_password);
    QLabel *username = new QLabel(window_forgot_password);
    username->setFont(QFont("Curlz MT",14));
    username->setText("username : ");
    username->setGeometry(0,60,80,33);
    username->setStyleSheet("background-color: rgb(255,219,75)");
    telephone->setFont(QFont("Curlz MT",14));
    telephone->setGeometry(81,120,220,33);
    telephone->setStyleSheet("background-color: rgb(255,219,75)");
    telepho_username->setFont(QFont("Curlz MT",14));
    telepho_username->setGeometry(81,60,220,33);
    telepho_username->setStyleSheet("background-color: rgb(255,219,75)");
    taeed->setText("ok");
    taeed->setFont(QFont("Curlz MT",14));
    taeed->setGeometry(260,200,100,33);
    taeed->setStyleSheet("background-color: rgb(255,219,75)");
    phone_num->setFont(QFont("Curlz MT",14));
    phone_num->setText("telephone : ");
    phone_num->setGeometry(0,120,80,33);
    phone_num->setStyleSheet("background-color: rgb(255,219,75)");
    window_forgot_password->show();
    connect(taeed,SIGNAL(clicked()),SLOT(line_getting_telephone()));

}
 void sign_in_class_header::line_getting_username_password(){
    QString user = userna->text();
    QString pass = passwo->text();
    QString f_pass;
    QString path = "C:/sign_in_sign_up/" + user + ".txt";
    QFile file(path);
    if(!file.exists()){

    }
    else{
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream stream(&file);
            for(int i=0;i<2;i++){
                f_pass = stream.readLine();
            }
            if(f_pass == pass )
                this->hide();
        }
    }
    file.close();
}
 void sign_in_class_header::line_getting_telephone(){
    QString telep = telephone->text();
    QString usernn = telepho_username->text();
    QString f_telep;
    QString path = "C:/sign_in_sign_up/" + usernn + ".txt";
    //qDebug()<<path;
    QFile file(path);
    if(!file.exists()){

    }
    else{
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream stream(&file);
            for(int i=0;i<4;i++){
                f_telep = stream.readLine();
            }
            if(f_telep == telep )
                window_forgot_password->hide();
        }
    }
    file.close();
 }


