#include "signup_form.h"
#include "ui_signup_form.h"
#include<QMessageBox>
#include"mainwindow.h"
#include<QFile>

signup_Form::signup_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup_Form)
{
    ui->setupUi(this);
}

signup_Form::~signup_Form()
{
    delete ui;
}

void signup_Form::on_buttonBox_accepted()
{
    QFile file("usersInfo.txt");
    if(ui->userLE->text().isEmpty()||ui->passLE->text().isEmpty()||
               ui->nameLE->text().isEmpty()||ui->emailLE->text().isEmpty()||
               ui->phoneLE->text().isEmpty()){
          QMessageBox::information(this,tr("Sign up"),tr("Please fill the form!"));
        }
     //check bra user tekrari
    else{
        information newuser;
        newuser.name=ui->nameLE->text();
        newuser.password=ui->passLE->text();
        newuser.username=ui->userLE->text();
        newuser.email=ui->emailLE->text();
        newuser.phone=ui->phoneLE->text();
        newuser.coins=1000; newuser.lose=0; newuser.win=0;

        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        QTextStream in(&file);
        bool flag=false;
        while(!in.atEnd()){
            QString line=in.readLine();
            QStringList data=line.split(':');
            if(data[0]==newuser.username){
                flag=true;
            }
        }
        file.close();
        if(flag){
            QMessageBox::information(this,tr("Sign up"),tr("This username already exist"));
        }
        else{
        emit sig_signup(newuser);
        QMessageBox::information(this,tr("Sign up"),tr("Done!"));
        MainWindow* w=new MainWindow;
        w->show();
        this->close();
        // ya bre safhe bazi
        }
    }
}


void signup_Form::on_buttonBox_rejected()
{
    MainWindow* w=new MainWindow;
    w->show();
    this->close();
}

