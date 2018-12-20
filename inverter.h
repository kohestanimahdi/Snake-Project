#ifndef INVERTER_H
#define INVERTER_H
#include "collectible.h"

class inverter:public collectible
{
public:
    inverter();
    void eat(snake & s,pair<int,int> & mm);
    void draw(QPainter &painter, int &x, int &y);
};

#endif // INVERTER_H
