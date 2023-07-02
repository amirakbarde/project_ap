#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFile>
#include"information.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QFile* file;

private slots:
    void on_signin_button_clicked();

    void on_signup_button_clicked();
    void slot_signup(information&);


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
