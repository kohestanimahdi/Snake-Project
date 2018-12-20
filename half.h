#ifndef HALF_H
#define HALF_H
#include "collectible.h"

class half: public collectible
{
public:
    half();
    void eat(snake & s,pair<int,int> & mm);
    void draw(QPainter &painter, int &x, int &y);
};

#endif // HALF_H
