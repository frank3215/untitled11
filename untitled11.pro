QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accuracy.cpp \
    buttonevent.cpp \
    game.cpp \
    judge.cpp \
    main.cpp \
    mainwindow.cpp \
    mybutton.cpp \
    mypushbutton.cpp \
    note.cpp \
    playfield.cpp \
    score.cpp \
    widget.cpp

HEADERS += \
    accuracy.h \
    buttonevent.h \
    game.h \
    judge.h \
    mainwindow.h \
    mybutton.h \
    mypushbutton.h \
    note.h \
    playfield.h \
    score.h \
    widget.h

FORMS += \
    form.ui \
    mainwindow.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc \
    res.qrc \
    res.qrc \
    res2.qrc

DISTFILES += \
    README.md \
    back.png \
    background.png \
    playbtn.png \
    untitled10.pro.user \
    untitled11.pro.user

SUBDIRS += \
    untitled10.pro \
    untitled10.pro
