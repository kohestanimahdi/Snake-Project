#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <QWidget>
#include <snake.h>
#include <board.h>
#include <food.h>

class Game_Board: public QWidget
{
    Q_OBJECT
protected:
    int mapnumber;
    bool isEnd;
    int collectiblex=0;
    int collectibley=0;
    Board * b;
    collectible * c;
    snake * s;
    collectible * cp;
    unsigned char ** premp;
public:
    Game_Board(QWidget *parent = 0);
    void SetMap();
    void SetMap(int n);
    void keyPressEvent(QKeyEvent *event);
    void drawWall(QPainter & painter,int &x,int &y);
    void drawSnake(QPainter & painter,int &x,int &y,bool isleft,bool isright,bool istop,bool isbottom);
    void printPlan(unsigned char **mp, QPainter &painter, int n);
    bool GetisEnd();
public slots:
    void Update_board();


protected:
    void paintEvent(QPaintEvent *event);
private:
    int currentAngle;
};

#endif // GAME_BOARD_H
