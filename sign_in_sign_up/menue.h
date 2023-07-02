#ifndef MENUE_H
#define MENUE_H

#include <QMainWindow>
#include<QLabel>

namespace Ui {
class menue;
}

class menue : public QMainWindow
{
    Q_OBJECT

public:
    explicit menue(QWidget *parent = nullptr);
    ~menue();
    void getting(QString, QString);

public slots:
    void end();
    void his();
    void changing();
    void change2(int, QString);
private:
    Ui::menue *ui;
    QMainWindow *change_;
    QString username;
    QString path;
    QLabel *history_l;
    int flag;

};

#endif // MENUE_H
