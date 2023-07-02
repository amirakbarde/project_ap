QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    menue.cpp \
    sign_in_class_header.cpp \
    sign_in_sign_up.cpp \
    sign_up.cpp

HEADERS += \
    menue.h \
    sign_in_class_header.h \
    sign_in_sign_up.h \
    sign_up.h

FORMS += \
    menue.ui \
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
