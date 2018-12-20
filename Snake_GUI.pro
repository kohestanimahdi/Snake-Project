TARGET = Snake_Gui
TEMPLATE = app

QT       += core gui


CONFIG +=c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Snake_Gui

TEMPLATE = app
CONFIG   += c++11


SOURCES += main.cpp \
    collectible.cpp \
    food.cpp \
    half.cpp \
    quarter.cpp \
    snake.cpp \
    speedup.cpp \
    poison.cpp \
    score.cpp \
    length_reducer.cpp \
    board.cpp \
    game_board.cpp \
    inverter.cpp \
    life.cpp \
    life_collection.cpp \
    mywidget.cpp \
    score_collection.cpp \
    start_board.cpp \
    startmenu.cpp \
    enter_name.cpp \
    score_list_menu.cpp \
    person_score.cpp \
    game_overmenu.cpp

HEADERS += \
    collectible.h \
    food.h \
    half.h \
    quarter.h \
    board_def.h \
    snake.h \
    speedup.h \
    poison.h \
    score.h \
    length_reducer.h \
    board.h \
    game_board.h \
    inverter.h \
    life.h \
    life_collection.h \
    mywidget.h \
    score_collection.h \
    start_board.h \
    snake_def.h \
    startmenu.h \
    enter_name.h \
    score_list_menu.h \
    person_score.h \
    game_overmenu.h
