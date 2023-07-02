#ifndef SIGNUP_FORM_H
#define SIGNUP_FORM_H

#include <QWidget>

#include"information.h"

namespace Ui {
class signup_Form;
}

class signup_Form : public QWidget
{
    Q_OBJECT

public:
    explicit signup_Form(QWidget *parent = nullptr);
    ~signup_Form();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::signup_Form *ui;
signals:
    void sig_signup(information&);
};

#endif // SIGNUP_FORM_H
