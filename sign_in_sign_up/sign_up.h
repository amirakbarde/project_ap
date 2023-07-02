#ifndef SIGN_UP_H
#define SIGN_UP_H

#include <QMainWindow>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>

namespace Ui {
class sign_up;
}

class sign_up : public QMainWindow
{
    Q_OBJECT

public:
    explicit sign_up(QWidget *parent = nullptr);
    void creating();
    ~sign_up();

private slots:
    void checking_sign_up();

private:
    Ui::sign_up *ui;
    QPushButton *ok;
    QLineEdit *gmail_e;
    QLineEdit *number_e;
    QLineEdit *name_e;
    QLineEdit *user_e;
    QLineEdit *pass_e;
    QLineEdit *path_e;

};

#endif // SIGN_UP_H
