#ifndef SIGN_IN_CLASS_HEADER_H
#define SIGN_IN_CLASS_HEADER_H

#include <QMainWindow>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QString>

namespace Ui {
class sign_in_class_header;
}

class sign_in_class_header : public QMainWindow
{
    Q_OBJECT

public:
    explicit sign_in_class_header(QWidget *parent = nullptr);
    ~sign_in_class_header();
    void first_page();

private slots:
    void forgot_password();
    void line_getting_username_password();
    void line_getting_telephone();
private:
    Ui::sign_in_class_header *ui;
    QMainWindow *window_forgot_password;
    QLineEdit *telephone;
    QLineEdit *telepho_username;
    QLineEdit *userna;
    QLineEdit *passwo;

};

#endif // SIGN_IN_CLASS_HEADER_H
