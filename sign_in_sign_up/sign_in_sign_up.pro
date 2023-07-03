QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cards.cpp \
    client_king_1.cpp \
    main.cpp \
    menue.cpp \
    server_king1.cpp \
    sign_in_class_header.cpp \
    sign_in_sign_up.cpp \
    sign_up.cpp

HEADERS += \
    ../qt projects/server_king1/cards.h \
    cards.h \
    client_king_1.h \
    menue.h \
    server_king1.h \
    sign_in_class_header.h \
    sign_in_sign_up.h \
    sign_up.h

FORMS += \
    client_king_1.ui \
    menue.ui \
    server_king1.ui \
    sign_in_class_header.ui \
    sign_in_sign_up.ui \
    sign_up.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

SUBDIRS += \

DISTFILES += \
