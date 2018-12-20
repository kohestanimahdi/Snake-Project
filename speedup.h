#ifndef SPEEDUP_H
#define SPEEDUP_H
#include "collectible.h"

class speedup:public collectible
{
public:
    static int speed;
    static int number;
    static int snumber;
    speedup();
    void eat(snake & s,pair<int,int> & mm);
    void draw(QPainter &painter, int &x, int &y);
    static int speedupf();
};

#endif // SPEEDUP_H
