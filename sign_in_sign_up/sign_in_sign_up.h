#ifndef SIGN_IN_SIGN_UP_H
#define SIGN_IN_SIGN_UP_H

#include <QMainWindow>
#include<QPushButton>
#include<QWidget>
#include<QWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SIGN_IN_SIGN_UP; }
QT_END_NAMESPACE

class SIGN_IN_SIGN_UP : public QMainWindow
{
    Q_OBJECT

public:
    SIGN_IN_SIGN_UP(QWidget *parent = nullptr);
    ~SIGN_IN_SIGN_UP();
private:
    Ui::SIGN_IN_SIGN_UP *ui;
    QPushButton *SIGN_IN;
    QPushButton *SIGN_UP;

};
#endif // SIGN_IN_SIGN_UP_H
