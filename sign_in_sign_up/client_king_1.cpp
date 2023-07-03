#include "client_king_1.h"
#include "ui_client_king_1.h"
#include<QTime>
#include <synchapi.h>
#include"menue.h"
#include<QFile>
client_king_1::client_king_1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::client_king_1)
{
    ip = new QLineEdit(this);
    ipp = new QPushButton(this);
    ipp->setText("ok");
    ipp->setGeometry(0,50,100,30);
    ipp->show();
    ip->show();

    connect(ipp,SIGNAL(clicked()),this,SLOT(conn()));
}

client_king_1::~client_king_1()
{
    delete ui;
}

void client_king_1::getting(QString u,QString p){
    username =u;
    path=p;
}

void client_king_1::conn(){
    ipp->hide();
    ip->hide();
    my_socket = new QTcpSocket();
    my_socket->connectToHost(ip->text(),8080);
    connect(my_socket,SIGNAL(connected()),this,SLOT(rounds()));
}

void client_king_1::dealing_cards(int round){
    int which = round * 2;
    int shomare;
    for(int i=0;i<round*2;i++){
        shomare = (rand()%(42-(which)));
        deck_push.push_back(deck[shomare]);
        deck_push_copy.push_back(deck[shomare]);
        deck.erase(deck.begin() + shomare);
        which++;
    }
}

void client_king_1::making_deck(int round){
    cards tmp("0", "0");
    for(int i=0;i<42-(round*2);i++){
        my_socket->waitForReadyRead(-1);
        tmp.name = my_socket->readAll();
        my_socket->write("0");
        my_socket->waitForReadyRead(-1);
        tmp.numb = my_socket->readAll();
        my_socket->write("0");
        deck.push_back(tmp);
    }

}

void client_king_1::how_many(){
    how_many_hands = new QLineEdit(this);
    taeed = new QPushButton(this);
    how_many_hands->setGeometry(600,0,200,30);
    taeed->setGeometry(700,40,50,30);
    taeed->setText("ok");
    how_many_hands->show();
    taeed->show();
    connect(taeed,SIGNAL(clicked()),this,SLOT(dast()));
}


void client_king_1::connect_push(int round, int which_card){
    if(deck_enemy[which_card].name == "queen" || deck_enemy[which_card].name == "king" || deck_enemy[which_card].name == "pirate"){
        for(int i=0;i<(round*2);i++){
            QObject::connect(buttons[i], &QPushButton::clicked, [this](){loop.quit();});
            connect(buttons[i], &QPushButton::clicked, [this, round, i]() { recive_send(i,(round*2)-1); });
        }
    }
    else{
        int flag =0;
        for(int i=0;i<deck_push_copy.size();i++){
            if(deck_push_copy[i].name == deck_enemy[which_card].name){
                flag++;
                //qDebug()<<flag<<"f";
                break;
            }
        }
        if(flag==1){
            for(int i=0;i<deck_push.size();i++){
                if(deck_push[i].name==deck_enemy[which_card].name){
                    QObject::connect(buttons[i], &QPushButton::clicked, [this](){loop.quit();});
                    connect(buttons[i], &QPushButton::clicked, [this, round, i]() { recive_send(i,(round*2)-1); });
                }
            }
        }
        else{
            for(int i=0;i<(round*2);i++){
                QObject::connect(buttons[i], &QPushButton::clicked, [this](){loop.quit();});
                connect(buttons[i], &QPushButton::clicked, [this, round, i]() { recive_send(i,(round*2)-1); });
            }
        }
    }
}

void client_king_1::rounds(){
    pause =  new QPushButton(this);
    pause->setText("pause");
    pause->setGeometry(800,60,50,50);
    pause->show();
    connect(pause,SIGNAL(clicked()),this,SLOT(pause_f()));
    resume =  new QPushButton(this);
    resume->setText("resume");
    resume->setGeometry(800,120,50,50);
    resume->show();
    connect(resume,SIGNAL(clicked()),this,SLOT(pause_f()));
    score=0;
    deck.clear();
    deck_push.clear();
    deck_push_copy.clear();
    deck_enemy.clear();
    buttons.clear();
    e_b=0;
    exit = new QPushButton(this);
    exit->setText("exit");
    exit->setGeometry(800,0,50,50);
    exit->show();
    connect(exit,SIGNAL(clicked()),this,SLOT(dis()));
    connect(my_socket, &QTcpSocket::disconnected, this, [this]() {dis_e();});
    rounds_befor = new QPushButton(this);
    rounds_befor->setGeometry(300,300,100,20);
    rounds_befor->setText("rounds_befor");
    eve_befor = new QTextEdit(this);
    eve_befor->setGeometry(0,500,70,100);
    connect(rounds_befor,SIGNAL(clicked(bool)),this,SLOT(event_befor()));
    rounds_befor->show();
    for(int i=1;i<8;i++){
        making_deck(i);
        dealing_cards(i);
        event = new QTextEdit(this);
        event->setGeometry(50,30,70,100);
        if(i==1){
            score__ = new QLineEdit(this);
            score__->setGeometry(250,30,200,100);
            score__->show();
        }
        for(int j=0;j<i*2;j++){
            buttons.push_back(new QPushButton(this));
        }
        for(int j=0;j<i*2;j++){
            buttons[j]->setText(deck_push[j].name + deck_push[j].numb);
            buttons[j]->setGeometry(j * 100,200,75,75);
            buttons[j]->show();
        }
        how_many();
        for(int j=0;j<i*2;j++){
            my_socket->waitForReadyRead();
            QString data = my_socket->readAll();
            my_socket->write("0");
            if(data == "0"){
                if(j==0){
                    hand=0;
                }
                for(int k=0;k<(i*2);k++){
                    QObject::connect(buttons[k], &QPushButton::clicked, [this](){loop.quit();});
                    connect(buttons[k], &QPushButton::clicked, [this,i,k]() { send_recive(k,(i*2)-1); });
                }
                loop.exec();
                //qDebug()<<deck_enemy[j].name + deck_enemy[j].numb<<"enemy";
            }
            else{
                if(j==0){
                    hand=0;
                }
                cards tmp("0","0");
                my_socket->waitForReadyRead(-1);
                tmp.name = my_socket->readAll();
                my_socket->write("0");
                my_socket->waitForReadyRead(-1);
                tmp.numb = my_socket->readAll();
                event->append(tmp.name+tmp.numb);
                deck_enemy.push_back(tmp);
                eve_befor->append(tmp.name+tmp.numb);
                connect_push(i,j);
                loop.exec();
                //qDebug()<<deck_enemy[j].name + deck_enemy[j].numb<<"enemy";
            }
            my_socket->waitForReadyRead(-1);
            QString dd = my_socket->readAll();
            my_socket->write("l") ;
            if(dd=="0"){
                hand++;
                if(deck_enemy[j].name=="queen"){
                    score+=20;
                }
                if(deck_enemy[j].name=="king"){
                    score+=15;
                }
                if(deck_enemy[j].name=="pirate"){
                    score+=10;
                }
                if(deck_push[card_me].name=="queen"){
                    score+=20;
                }
                if(deck_push[card_me].name=="king"){
                    score+=15;
                }
                if(deck_push[card_me].name=="pirate"){
                    score+=10;
                }
            }
        }
        qDebug()<<hand;
        qDebug()<<e_hand;
        if(e_hand==0 && e_hand!=hand){
            score-=i*10;
        }
        else if(e_hand>hand){
            score+=(hand-e_hand)*10;
        }
        else if(e_hand<hand){
            score+=(e_hand-hand)*10;
        }
        else{
            if(e_hand==0){
                score += i*10;
            }
            else{
                score+=e_hand*10;
            }
        }
        qDebug()<<score;
        score__->insert(QString::number(score)+">>");
        deck.clear();
        deck_push.clear();
        deck_push_copy.clear();
        deck_enemy.clear();
        buttons.clear();
    }
    my_socket->waitForReadyRead(-1);
    my_socket->readAll();
    my_socket->write((QString::number(score)).toStdString().c_str());
    my_socket->waitForReadyRead(-1);
    my_socket->readAll();
    my_socket->write(username.toStdString().c_str());
    my_socket->waitForReadyRead(-1);
    my_socket->readAll();
    my_socket->write(path.toStdString().c_str());
    this->hide();
    menue *obj = new menue();
    obj->getting(username,path);
    obj->show();
}

void client_king_1::recive_send(int push, int where){
    for(int i=0;i<where+1;i++){
        disconnect(buttons[i], &QPushButton::clicked, nullptr, nullptr);
    }
    card_me=push;
    event->append(deck_push[push].name+deck_push[push].numb);
    eve_befor->append(deck_push[push].name+deck_push[push].numb);
    my_socket->write((deck_push[push].name).toStdString().c_str());
    my_socket->waitForReadyRead(-1);
    my_socket->readAll();
    my_socket->write((deck_push[push].numb).toStdString().c_str());
    deck_push_copy.erase(deck_push_copy.begin() + push);
    buttons[push]->hide();
}

void client_king_1::send_recive(int push, int where){
    for(int i=0;i<where+1;i++){
        disconnect(buttons[i], &QPushButton::clicked, nullptr, nullptr);
    }
    card_me=push;
    cards tmp("0","0");
    event->append(deck_push[push].name+deck_push[push].numb);
    eve_befor->append(deck_push[push].name+deck_push[push].numb);
    my_socket->write((deck_push[push].name).toStdString().c_str());
    my_socket->waitForReadyRead(-1);
    my_socket->readAll();
    my_socket->write((deck_push[push].numb).toStdString().c_str());
    buttons[push]->hide();
    my_socket->waitForReadyRead(-1);
    tmp.name = my_socket->readAll();
    my_socket->write("0");
    my_socket->waitForReadyRead(-1);
    tmp.numb = my_socket->readAll();
    event->append(tmp.name+tmp.numb);
    eve_befor->append(tmp.name+tmp.numb);
    deck_push_copy.erase(deck_push_copy.begin() + push);
    my_socket->write("0");
    deck_enemy.push_back(tmp);
}

void client_king_1::dast(){
    e_hand = (how_many_hands->text()).toInt();
    taeed->hide();
    how_many_hands->hide();
    event->show();
}

void client_king_1::event_befor(){
    if(e_b%2==0){
        eve_befor->show();
    }
    else{
        eve_befor->hide();
    }
    e_b++;
}

void client_king_1::dis_e(){
    if(flag__==0){
        QFile file(path+username+".txt");
        if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        {
        }
        else{
            int coin;
            QStringList fileContents;
            QTextStream inStream(&file);
            while (!inStream.atEnd()){
                QString line = inStream.readLine();
                fileContents.append(line);
            }
            coin = fileContents[5].toInt();
            coin+=50;
            fileContents[5]=QString::number(coin);
            coin = fileContents[6].toInt();
            coin++;
            fileContents[6]=QString::number(coin);
            file.resize(0);
            QTextStream outStream(&file);
            for (const QString& line : fileContents)
            {
                outStream << line <<"\n";
            }
        }
        file.close();
        qDebug()<<"coin 50+";
        this->hide();
    }
}

void client_king_1::dis(){
    qDebug()<<"nothing";
    flag__=1;
    my_socket->disconnectFromHost();
        QFile file(path+username+".txt");
        if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        {
        }
        else{
            int coin;
            QStringList fileContents;
            QTextStream inStream(&file);
            while (!inStream.atEnd()){
                QString line = inStream.readLine();
                fileContents.append(line);
            }
            coin = fileContents[5].toInt();
            coin-=50;
            fileContents[5]=QString::number(coin);
            coin = fileContents[7].toInt();
            coin++;
            fileContents[7]=QString::number(coin);
            file.resize(0);
            QTextStream outStream(&file);
            for (const QString& line : fileContents)
            {
                outStream << line <<"\n";
            }
        }
        file.close();
    this->hide();
}

void client_king_1::pause_f(){
    Sleep(3000);
    this->setEnabled(false);
    Sleep(5000);
    // After the freezeButton is clicked, enable the main window again
    this->setEnabled(true);
    //resume->hide();
}
