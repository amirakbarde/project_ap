#include "menue.h"
#include "ui_menue.h"
#include "sign_in_sign_up.h"
#include<QPushButton>
#include<QFile>
#include<QLineEdit>
#include <QTextStream>
menue::menue(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menue)
{
    ui->setupUi(this);
    flag=0;
    this->resize(600,500);
    this->setWindowTitle("menue");
    QPixmap skull(":/images/skull.jpg");
    skull = skull.scaled(QSize(75,75), Qt::KeepAspectRatio);
    QPalette skull_;
    skull_.setBrush(QPalette::Window, skull);
    this->setPalette(skull_);
    history_l = new QLabel(this);
    history_l->setFont(QFont("Curlz MT",14));
    history_l->setGeometry(100,300,400,33);
    history_l->setStyleSheet("background-color: rgb(255,219,75)");
    QPushButton *start = new QPushButton(this);
    start->setText("start");
    start->setFont(QFont("Curlz MT",14));
    start->setGeometry(0,60,220,33);
    start->setStyleSheet("background-color: rgb(255,219,75)");
    QPushButton *change = new QPushButton(this);
    change->setText("change");
    change->setFont(QFont("Curlz MT",14));
    change->setGeometry(0,120,220,33);
    change->setStyleSheet("background-color: rgb(255,219,75)");
    connect(change,SIGNAL(clicked()),this,SLOT(changing()));
    QPushButton *history = new QPushButton(this);
    history->setText("history");
    history->setFont(QFont("Curlz MT",14));
    history->setGeometry(0,180,220,33);
    history->setStyleSheet("background-color: rgb(255,219,75)");
    connect(history,SIGNAL(clicked()),this,SLOT(his()));
    QPushButton *exit = new QPushButton(this);
    exit->setText("exit");
    exit->setFont(QFont("Curlz MT",14));
    exit->setGeometry(0,240,220,33);
    exit->setStyleSheet("background-color: rgb(255,219,75)");
    connect(exit,SIGNAL(clicked()),this,SLOT(end()));

}

menue::~menue()
{
    delete ui;
}

void menue::getting(QString u, QString p){
    username=u;
    path=p;
    qDebug()<<username<<path;
    this->show();

}

void menue::end(){
    this->hide();
    SIGN_IN_SIGN_UP *obj = new SIGN_IN_SIGN_UP();
    obj->show();
}

void menue::his(){
    QFile file(path+username+".txt");
    QString tmp,tmp1,tmp2;
    QTextStream stream(&file);
    if(flag==0){
        if (!file.open(QIODevice::ReadOnly)){

        }
        else{
    for(int i=0;i<9;i++){
        if(i==6){
           tmp = stream.readLine();
        }
        else if(i==7){
           tmp1 = stream.readLine();
        }
        else if(i==8){
           tmp2 = stream.readLine();
        }
        else{
            stream.readLine();
        }
        history_l->setText("win: "+ tmp +"     lose: "+tmp1+"     score: " + tmp2);
        history_l->show();
    }
    file.close();
        }
    flag=1;
    }
    else{
    history_l->hide();
    flag=0;
    }
}

void menue::changing(){
    this->hide();
    change_ = new QMainWindow();
    change_->resize(600,500);
    QPixmap skull(":/images/skull.jpg");
    skull = skull.scaled(QSize(75,75), Qt::KeepAspectRatio);
    QPalette skull_;
    skull_.setBrush(QPalette::Window, skull);
    change_->setPalette(skull_);
    QPushButton *user_ = new QPushButton(change_);
    user_->setText("user");
    user_->setFont(QFont("Curlz MT",14));
    user_->setGeometry(0,60,80,33);
    user_->setStyleSheet("background-color: rgb(255,219,75)");
    user_->show();
    QPushButton *pass_ = new QPushButton(change_);
    pass_->setText("pass");
    pass_->setFont(QFont("Curlz MT",14));
    pass_->setGeometry(0,120,80,33);
    pass_->setStyleSheet("background-color: rgb(255,219,75)");
    pass_->show();
    QPushButton *name_ = new QPushButton(change_);
    name_->setText("name");
    name_->setFont(QFont("Curlz MT",14));
    name_->setGeometry(0,180,80,33);
    name_->setStyleSheet("background-color: rgb(255,219,75)");
    name_->show();
    QPushButton *phone_ = new QPushButton(change_);
    phone_->setText("phone");
    phone_->setFont(QFont("Curlz MT",14));
    phone_->setGeometry(0,240,80,33);
    phone_->setStyleSheet("background-color: rgb(255,219,75)");
    phone_->show();
    QPushButton *gmail_ = new QPushButton(change_);
    gmail_->setText("email");
    gmail_->setFont(QFont("Curlz MT",14));
    gmail_->setGeometry(0,300,80,33);
    gmail_->show();
    gmail_->setStyleSheet("background-color: rgb(255,219,75)");
    QLineEdit *user_e= new QLineEdit(change_);
    user_e->setFont(QFont("Curlz MT",14));
    user_e->setGeometry(81,60,220,33);
    user_e->setStyleSheet("background-color: rgb(255,219,75)");
    user_e->show();
    QLineEdit *pass_e= new QLineEdit(change_);
    pass_e->setFont(QFont("Curlz MT",14));
    pass_e->setGeometry(81,120,220,33);
    pass_e->setStyleSheet("background-color: rgb(255,219,75)");
    pass_e->show();
    QLineEdit *name_e= new QLineEdit(change_);
    name_e->setFont(QFont("Curlz MT",14));
    name_e->setGeometry(81,180,220,33);
    name_e->setStyleSheet("background-color: rgb(255,219,75)");
    name_e->show();
    QLineEdit *number_e= new QLineEdit(change_);
    number_e->setFont(QFont("Curlz MT",14));
    number_e->setGeometry(81,240,220,33);
    number_e->setStyleSheet("background-color: rgb(255,219,75)");
    number_e->show();
    QLineEdit *gmail_e= new QLineEdit(change_);
    gmail_e->setFont(QFont("Curlz MT",14));
    gmail_e->setGeometry(81,300,220,33);
    gmail_e->setStyleSheet("background-color: rgb(255,219,75)");
    gmail_e->show();
    QPushButton *back = new QPushButton(change_);
    back->setText("back");
    back->setFont(QFont("Curlz MT",14));
    back->setGeometry(300,340,80,33);
    back->show();
    back->setStyleSheet("background-color: rgb(255,219,75)");
    connect(pass_, &QPushButton::clicked, this, [this,pass_e]() {
        change2(1, pass_e->text());
    });
    connect(phone_, &QPushButton::clicked, this, [this,number_e]() {
        change2(3, number_e->text());
    });
    connect(name_, &QPushButton::clicked, this, [this,name_e]() {
        change2(2, name_e->text());
    });
    connect(user_, &QPushButton::clicked, this, [this,user_e]() {
        change2(0, user_e->text());
    });
    connect(gmail_, &QPushButton::clicked, this, [this,gmail_e]() {
        change2(4, gmail_e->text());
    });
    change_->show();
    connect(back, &QPushButton::clicked, this, [this]() {
        change_->hide();
        this->getting(username, path);
    });
}

void menue::change2(int round, QString nn){
    QFile file(path+username+".txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
    }
    else{
    QStringList fileContents;
    QTextStream inStream(&file);
    while (!inStream.atEnd()){
    QString line = inStream.readLine();
    fileContents.append(line);
    }
    fileContents[round] =nn;
    file.resize(0);
    QTextStream outStream(&file);
    for (const QString& line : fileContents)
    {
    outStream << line <<"\n";
    }
    }
    file.close();
    if(round==0){
    if (QFile::rename(path+username+".txt",path+nn+".txt"));
    {
    username=nn;
    }
}
}
