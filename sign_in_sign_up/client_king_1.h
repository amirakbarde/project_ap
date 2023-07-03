#ifndef CLIENT_KING_1_H
#define CLIENT_KING_1_H

#include"cards.h"
#include <QMainWindow>
#include<QTcpSocket>
#include<vector>
#include<QPushButton>
#include<QLineEdit>
#include<QEventLoop>
#include<QTextEdit>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class client_king_1; }
QT_END_NAMESPACE

class client_king_1 : public QMainWindow
{
    Q_OBJECT

public:
    client_king_1(QWidget *parent = nullptr);
    void dealing_cards(int);
    void making_deck(int);
    void how_many();
    void connect_push(int, int);
    void getting(QString,QString);
    ~client_king_1();
public slots:
    void conn();
    void dis_e();
    void dis();
    void event_befor();
    void rounds();
    void dast();
    void send_recive(int push, int where);
    void recive_send(int push, int where);
    void pause_f();
private:
    Ui::client_king_1 *ui;

    QPushButton *pause;
    QPushButton *resume;
    QPushButton *exit;
    QPushButton *rounds_befor;
    QPushButton *ipp;
    QLineEdit *ip;
    vector<cards> deck;
    vector<cards> deck_push;
    vector<cards> deck_push_copy;
    vector<cards> deck_enemy;
    QTcpSocket *my_socket;
    QLineEdit *score__;
    QTextEdit *event;
    QTextEdit *eve_befor;
    QLineEdit *how_many_hands;
    QVector <QPushButton*> buttons;
    QPushButton *taeed;
    int score;
    int card_me;
    int e_b;
    int flag__;
    QEventLoop loop;
    int e_hand;
    int hand;
    QString username;
    QString path;

};
#endif // CLIENT_KING_1_H
