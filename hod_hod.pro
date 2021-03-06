#-------------------------------------------------
#
# Project created by QtCreator 2018-05-30T04:47:57
#
#-------------------------------------------------

QT       += core gui widgets network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hod_hod
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    user.cpp \
    signup.cpp \
    signin.cpp \
    contaact_container.cpp \
    master.cpp \
    message_container.cpp

HEADERS += \
        mainwindow.h \
    user.h \
    signup.h \
    signin.h \
    contaact_container.h \
    master.h \
    message_container.h

FORMS += \
        mainwindow.ui \
    signup.ui \
    signin.ui \
    contaact_container.ui \
    master.ui \
    message_container.ui
