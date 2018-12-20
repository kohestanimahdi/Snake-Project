#ifndef QUARTER_H
#define QUARTER_H
#include "collectible.h"

class quarter:public collectible
{
public:
    quarter();
    void eat(snake & s,pair<int,int> & mm);
    void draw(QPainter &painter, int &x, int &y);
};

#endif // QUARTER_H
