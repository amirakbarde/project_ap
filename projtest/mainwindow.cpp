#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include"signup_form.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    file=new QFile("usersInfo.txt");

    //open mizani; age nbood misazi
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_signin_button_clicked()
{

}


void MainWindow::on_signup_button_clicked()
{
    signup_Form* sup=new signup_Form();
    connect(sup,SIGNAL(sig_signup(information&)),this,SLOT(slot_signup(information&)));
    this->close();
    sup->show();
}

void MainWindow::slot_signup(information& user){
    if(!file->open(QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(file);
    out<<user.username<<":"<<user.password<<":"<<user.name<<":"<<user.phone<<":"<<user.email<<":"<<user.coins<<":"<<user.win<<":"<<user.lose<<"\n";
    file->close();
}



