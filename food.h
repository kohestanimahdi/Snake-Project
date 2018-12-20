#ifndef FOOD_H
#define FOOD_H
#include "collectible.h"
#include "snake.h"



class food:public collectible
{
public:
    food();
    void eat(snake & s,pair<int,int> & mm);
    void draw(QPainter &painter,int &x,int &y);

};

#endif // FOOD_H
