#ifndef SERVER_KING1_H
#define SERVER_KING1_H

#include"cards.h"
#include <QMainWindow>
#include<QTcpsocket>
#include<QTcpServer>
#include<time.h>
#include<vector>
#include<QVector>
#include<QPushButton>
#include<QLineEdit>
#include<QEventLoop>
#include<QTextEdit>

using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class server_king1; }
QT_END_NAMESPACE

class server_king1 : public QMainWindow
{
    Q_OBJECT

public:
    server_king1(QWidget *parent = nullptr);
    void dealing_cards(int);
    void making_deck();
    void handing_deck(int);
    void rounds();
    void how_many();
    void connect_push(int, int);
    void the_winner(cards, int);
    void the_winner1(cards, int);
    void pause2();
    ~server_king1();
private slots:
    void dast();
    void dis();
    void dis_e();
    void connect_to_cli();
    void recive_send(int push, int where, int j);
    void send_recive(int push, int where);
    void event_befor();
    void pause_f();

private:
    Ui::server_king1 *ui;
    QPushButton* pause;
    QPushButton* resume;
    QPushButton *ip;
    QPushButton *exit;
    QTcpSocket *my_socket;
    QTextEdit *eve_befor;
    QPushButton *rounds_befor;
    QLineEdit *score__;
    QTextEdit *event;
    QLineEdit *how_many_hands;
    QTcpServer *my_server;
    vector<cards> deck;
    vector<cards> deck_push;
    vector<cards> deck_push_copy;
    vector<cards> deck_enemy;
    QVector <QPushButton*> buttons;
    QPushButton *taeed;
    QEventLoop loop;
    QEventLoop loop2;
    int card_me;
    int flag__;
    int e_b;
    int turn;
    int score;
    int e_hand;
    int hand;

};
#endif // SERVER_KING1_H
