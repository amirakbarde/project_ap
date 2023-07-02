#ifndef INFORMATION_H
#define INFORMATION_H
#include<QString>

class information
{
public:
    information();
    QString name;
    QString username;
    QString password;
    QString email;
    QString phone;
    qint32 coins;
    qint32 win;
    qint32 lose;
    //dor akhar hr bazi vector<int,int>
};

#endif // INFORMATION_H
