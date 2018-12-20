#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <snake.h>
#include "game_board.h"
#include "enter_name.h"


class StartMenu;
class game_overmenu;
class QGridLayout;
enum Level_Form{enStart_Board,enStart_Form,enGameIsRunning,enGameOver};
class MyWidget : public QMainWindow
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent * event);
    bool isStartGame;
    int Level;
    Game_Board * board;
    StartMenu * form;
    game_overmenu * game_overform;
    QTimer * tme ;
    Enter_name *enm;
    QGridLayout *gridLayout;
    QGridLayout * game_overgridLayout;
    int premapnum;

signals:

public slots:
    void isGameOver();
    void changemap1();
    void changemap2();
    void changemap3();
    void changemap4();
    void changemap5();
    void changemap6();
    void changemap7();
    void changemap8();
    void changemap9();
    void PlayGame();
    void StopGame();
    void NewGame();
    void About();
    void StartGame();

};

#endif // MYWIDGET_H
