#ifndef SIGN_IN_SIGN_UP_H
#define SIGN_IN_SIGN_UP_H

#include <QMainWindow>
#include<QPushButton>
#include "sign_in_class_header.h"


QT_BEGIN_NAMESPACE
namespace Ui { class SIGN_IN_SIGN_UP; }
QT_END_NAMESPACE

class SIGN_IN_SIGN_UP : public QMainWindow
{
    Q_OBJECT

public:
    SIGN_IN_SIGN_UP(QWidget *parent = nullptr);
    ~SIGN_IN_SIGN_UP();

private slots:
    void going_to_sign_in();
    //void going_to_sign_up();
private:
    Ui::SIGN_IN_SIGN_UP *ui;

};
#endif // SIGN_IN_SIGN_UP_H
