QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Square.cpp \
    bridge.cpp \
    care_taker.cpp \
    commanddown.cpp \
    commandleft.cpp \
    commandright.cpp \
    commandup.cpp \
    correct_class.cpp \
    enemy001.cpp \
    enemy002.cpp \
    enemy003.cpp \
    iter.cpp \
    main.cpp \
    mainwindow.cpp \
    memento_player.cpp \
    memento_scene.cpp \
    modifiers.cpp \
    money_adder.cpp \
    openlog.cpp \
    player.cpp \
    scene.cpp \
    score_adder.cpp \
    speed_adder.cpp \
    subscriber_player.cpp \
    subscriber_square.cpp

HEADERS += \
    Square.h \
    abstract_enemy.h \
    bridge.h \
    care_taker.h \
    command_interface.h \
    commanddown.h \
    commandleft.h \
    commandright.h \
    commandup.h \
    correct_class.h \
    enemy001.h \
    enemy002.h \
    enemy003.h \
    item_object.h \
    iter.h \
    libs.h \
    mainwindow.h \
    memento.h \
    memento_player.h \
    memento_scene.h \
    modifiers.h \
    money_adder.h \
    openlog.h \
    player.h \
    publisher.h \
    scene.h \
    score_adder.h \
    sh_enemy.h \
    shablon_enemy.h \
    speed_adder.h \
    subscriber.h \
    subscriber_player.h \
    subscriber_square.h

TRANSLATIONS += \
    game_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
