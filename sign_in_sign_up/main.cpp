#include "sign_in_sign_up.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SIGN_IN_SIGN_UP w;
    w.show();
    return a.exec();
}
