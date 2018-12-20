#ifndef START_BOARD_H
#define START_BOARD_H


#include <QWidget>
#include <snake.h>
#include <board.h>
#include <food.h>
#include "game_board.h"

class Start_Board: public Game_Board
{
    Q_OBJECT
public:
    Start_Board(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void Update_board();


protected:
    void paintEvent(QPaintEvent *event);
private:
};


#endif // START_BOARD_H
