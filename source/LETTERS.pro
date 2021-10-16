QT       += core gui \
         multimedia\
         sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    tutorial.cpp

HEADERS += \
    entity.h \
    item.h \
    mainwindow.h \
    otherChar.h \
    tutorial.h \
    vocabBack.h

FORMS += \
    mainwindow.ui \
    tutorial.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    bg.png \
    correct.png \
    dict.txt \
    dududu.png \
    fiveBank.txt \
    hurtenemy.png \
    hurtplayer.png \
    incorrect.png \
    tenBank.txt \
    threeBank.txt

RESOURCES += \
    resource.qrc
