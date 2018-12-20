#ifndef SNAKE_H
#define SNAKE_H

#include <list>
#include <iostream>
#include "score.h"
#include "life.h"
#include "collectible.h"
#include "speedup.h"
#include "poison.h"
#include <QWidget>

using namespace std;
class snake:public list<pair<int,int> >
{
    int default_move;
    int move_number;
    Score score;
    Life life;
    speedup ss;
    static int length;
public:
    snake();
    unsigned char move(unsigned char **mp,collectible * c,int n);
    void change_move(int);

};

#endif // SNAKE_H
