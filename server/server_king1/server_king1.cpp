#include "server_king1.h"
#include "ui_server_king1.h"
#include<QList>
#include <QNetworkInterface>
#include<QTime>
#include <synchapi.h>
server_king1::server_king1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::server_king1)
{
    ui->setupUi(this);
    ip = new QPushButton(this);
    QList<QHostAddress> ipAddresses = QNetworkInterface::allAddresses();
    srand(time(NULL));
    foreach (const QHostAddress& ipAddress, ipAddresses) {
        if (ipAddress != QHostAddress::LocalHost && ipAddress.toIPv4Address()) {
            ip->setText(ipAddress.toString());
            ip->show();
        }
    }
    my_server = new QTcpServer();
    my_server->listen(QHostAddress::Any,8080);
    connect(my_server,SIGNAL(newConnection()),this,SLOT(connect_to_cli()));
}

server_king1::~server_king1()
{
    delete ui;
}

void server_king1::dealing_cards(int round){
    int which = 0;
    int shomare;
    for(int i=0;i<round*2;i++){
        shomare = (rand()%(42-(which)));
        deck_push.push_back(deck[shomare]);
        deck_push_copy.push_back(deck[shomare]);
        deck.erase(deck.begin() + shomare);
        which++;
    }

}

void server_king1::making_deck(){
    cards tmp("0", "0");
    for(int i=0;i<8;i++){
        tmp.name = "ganj";
        tmp.numb = QString::number(i+1);
        deck.push_back(tmp);
    }
    for(int i=0;i<8;i++){
        tmp.name = "tooti";
        tmp.numb = QString::number(i+1);
        deck.push_back(tmp);
    }
    for(int i=0;i<8;i++){
        tmp.name = "naghshe";
        tmp.numb = QString::number(i+1);
        deck.push_back(tmp);
    }
    for(int i=0;i<8;i++){
        tmp.name = "parcham";
        tmp.numb = QString::number(i+1);
        deck.push_back(tmp);
    }
    for(int i=0;i<4;i++){
        tmp.name = "pirate";
        tmp.numb = QString::number(i+1);
        deck.push_back(tmp);
    }
    for(int i=0;i<3;i++){
        tmp.name = "king";
        tmp.numb = QString::number(i+1);
        deck.push_back(tmp);
    }
    for(int i=0;i<3;i++){
        tmp.name = "queen";
        tmp.numb = QString::number(i+1);
        deck.push_back(tmp);
    }
}

void server_king1::handing_deck(int round){
    for(int i=0;i<42-(round*2);i++){
        my_socket->write((deck[i].name).toStdString().c_str());
        my_socket->waitForReadyRead(-1);
        my_socket->readAll();
        my_socket->write((deck[i].numb).toStdString().c_str());
        my_socket->waitForReadyRead(-1);
        my_socket->readAll();
    }

}

void server_king1::connect_to_cli(){
    my_socket = my_server->nextPendingConnection();
    ip->hide();
    rounds();
}

void server_king1::how_many(){
    how_many_hands = new QLineEdit(this);
    taeed = new QPushButton(this);
    how_many_hands->setGeometry(600,0,200,30);
    taeed->setGeometry(700,40,50,30);
    taeed->setText("ok");
    how_many_hands->show();
    taeed->show();
    connect(taeed,SIGNAL(clicked()),this,SLOT(dast()));
}

void server_king1::connect_push(int round, int which_card){
    if(deck_enemy[which_card].name == "queen" || deck_enemy[which_card].name == "king" || deck_enemy[which_card].name == "pirate"){
        for(int i=0;i<(round*2);i++){
            QObject::connect(buttons[i], &QPushButton::clicked, [this](){loop.quit();});
            connect(buttons[i], &QPushButton::clicked, [this, round, i, which_card]() { recive_send(i,(round*2)-1, which_card); });
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
        if(flag!=0){
            for(int i=0;i<deck_push.size();i++){
                if(deck_push[i].name==deck_enemy[which_card].name){
                    QObject::connect(buttons[i], &QPushButton::clicked, [this](){loop.quit();});
                    connect(buttons[i], &QPushButton::clicked, [this, round, i, which_card]() { recive_send(i,(round*2)-1, which_card); });
                }
            }
        }
        else{
            for(int i=0;i<(round*2);i++){
                QObject::connect(buttons[i], &QPushButton::clicked, [this](){loop.quit();});
                connect(buttons[i], &QPushButton::clicked, [this, round, i, which_card]() { recive_send(i,(round*2)-1, which_card); });
            }
        }
    }
}

void server_king1::the_winner(cards enemy, int hero){
    if(enemy.name == "queen"){
        if(enemy.name == deck_push[hero].name){
            turn = 1;
        }
        else if(deck_push[hero].name == "pirate"){
            turn = 0;
        }
        else if(deck_push[hero].name == "king"){
            turn = 1;
        }
    }
    else if(enemy.name == "king"){
        if(enemy.name == deck_push[hero].name){
            turn = 1;
        }
        else if(deck_push[hero].name == "queen"){
            turn = 0;
        }
        else if(deck_push[hero].name == "pirate"){
            turn = 1;
        }
    }
    else if(enemy.name == "pirate"){
        if(enemy.name == deck_push[hero].name){
            turn = 1;
        }
        else if(deck_push[hero].name == "king"){
            turn = 0;
        }
        else if(deck_push[hero].name == "queen"){
            turn = 1;
        }
    }
    else if(enemy.name == "naghshe" || enemy.name == "tooti" || enemy.name == "ganj"){
        if(enemy.name == deck_push[hero].name){
            if(enemy.numb.toInt()>deck_push[hero].numb.toInt()){
                turn = 1;
            }
            else{
                turn = 0;
            }
        }
        else if(deck_push[hero].name == "parcham" || deck_push[hero].name == "queen" || deck_push[hero].name == "king"
            || deck_push[hero].name == "pirate"){
            turn =0;
        }
        else{
            turn =1;
        }
    }
    else{
        if(enemy.name == deck_push[hero].name){
            if(enemy.numb.toInt()>deck_push[hero].numb.toInt()){
                turn = 1;
            }
            else{
                turn = 0;
            }
        }
        else if(deck_push[hero].name == "queen" || deck_push[hero].name == "king" || deck_push[hero].name == "pirate"){
            turn =0;
        }
        else{
            turn =1;
        }
    }
}

void server_king1::the_winner1(cards enemy, int hero){
    if(deck_push[hero].name == "queen"){
        if(enemy.name == deck_push[hero].name){
            turn = 0;
        }
        else if(enemy.name == "pirate"){
            turn = 1;
        }
        else if(enemy.name == "king"){
            turn = 0;
        }
    }
    else if(deck_push[hero].name == "king"){
        if(enemy.name == deck_push[hero].name){
            turn = 0;
        }
        else if(enemy.name == "queen"){
            turn = 1;
        }
        else if(enemy.name == "pirate"){
            turn = 0;
        }
    }
    else if(deck_push[hero].name == "pirate"){
        if(enemy.name == deck_push[hero].name){
            turn = 0;
        }
        else if(enemy.name == "king"){
            turn = 1;
        }
        else if(enemy.name == "queen"){
            turn = 0;
        }
    }
    else if(deck_push[hero].name == "naghshe" || deck_push[hero].name == "tooti" || deck_push[hero].name == "ganj"){
        if(enemy.name == deck_push[hero].name){
            if(enemy.numb.toInt()>deck_push[hero].numb.toInt()){
                turn = 1;
            }
            else{
                turn = 0;
            }
        }
        else if(enemy.name == "parcham" || enemy.name == "queen" || enemy.name == "king"
                 || enemy.name == "pirate"){
            turn =1;
        }
        else{
            turn =0;
        }
    }
    else{
        if(enemy.name == deck_push[hero].name){
            if(enemy.numb.toInt()>deck_push[hero].numb.toInt()){
                turn = 1;
            }
            else{
                turn = 0;
            }
        }
        else if(enemy.name == "queen" || enemy.name == "king" || enemy.name == "pirate"){
            turn =1;
        }
        else{
            turn =0;
        }
    }
}

void server_king1::rounds(){
    flag__=0;
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
    deck.clear();
    deck_push.clear();
    deck_push_copy.clear();
    deck_enemy.clear();
    buttons.clear();
    score =0;
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
        making_deck();
        dealing_cards(i);
        handing_deck(i);
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
            if(j==0){
                hand=0;
            }
            if(j==0 && i==1){
                turn = rand()%2;
            }
            if(turn == 0){
                my_socket->write("1");
                my_socket->waitForReadyRead();
                my_socket->readAll();
                for(int k=0;k<(i*2);k++){
                QObject::connect(buttons[k], &QPushButton::clicked, [this](){loop.quit();});
                connect(buttons[k], &QPushButton::clicked, [this,i, k]() { send_recive(k,(i*2)-1); });
                }
                loop.exec();
            }
            else{
                my_socket->write("0");
                my_socket->waitForReadyRead();
                my_socket->readAll();
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
            }
            if(turn ==0){
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
                hand++;
                my_socket->write("1");
                my_socket->waitForReadyRead(-1);
                my_socket->readAll();
            }
            if(turn ==1){
                //hand++;
                my_socket->write("0");
                my_socket->waitForReadyRead(-1);
                my_socket->readAll();
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
        else if(e_hand==0 && hand==0){
            score += i*10;
        }
        else{
            score+=e_hand*10;
        }
        qDebug()<<score;
        score__->insert(QString::number(score)+ " >>");
        deck.clear();
        deck_push.clear();
        deck_push_copy.clear();
        deck_enemy.clear();
        buttons.clear();
    }
    my_socket->write("0");
    my_socket->waitForReadyRead(-1);
    QString enemy_score = my_socket->readAll();
    if(enemy_score.toInt()>score){
        my_socket->write("w");
        qDebug()<<"l";
    }
    else if(enemy_score.toInt()<score){
        my_socket->write("l");
        qDebug()<<"w";
    }
    else{
        my_socket->write("d");
        qDebug()<<"d";
    }
}


void server_king1::send_recive(int push, int where){
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
    deck_push_copy.erase(deck_push_copy.begin() + push);
    buttons[push]->hide();
    my_socket->waitForReadyRead(-1);
    tmp.name = my_socket->readAll();
    my_socket->write("0");
    my_socket->waitForReadyRead(-1);
    tmp.numb = my_socket->readAll();
    event->append(tmp.name+tmp.numb);
    eve_befor->append(tmp.name+tmp.numb);
    deck_enemy.push_back(tmp);
    the_winner1(tmp,push);
}

void server_king1::recive_send(int push, int where, int j){
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
    my_socket->waitForReadyRead(-1);
    my_socket->readAll();
    buttons[push]->hide();
    the_winner(deck_enemy[j],push);
}

void server_king1::dast(){
    e_hand = (how_many_hands->text()).toInt();
    taeed->hide();
    how_many_hands->hide();
    event->show();
    //qDebug()<<e_hand;
}

void server_king1::event_befor(){
    if(e_b%2==0){
    eve_befor->show();
    }
    else{
    eve_befor->hide();
    }
    e_b++;
}

void server_king1::dis(){
    qDebug()<<"nothing";
    flag__=1;
    my_socket->disconnectFromHost();
    this->hide();
}

void server_king1::dis_e(){
    if(flag__==0){
    qDebug()<<"50+";
    this->hide();
    }
}

void server_king1::pause_f(){
    Sleep(3000);
    this->setEnabled(false);
    Sleep(5000);
    // After the freezeButton is clicked, enable the main window again
    this->setEnabled(true);
    //resume->hide();
}
