#ifndef LENGTH_REDUCER_H
#define LENGTH_REDUCER_H
#include "collectible.h"

class length_reducer: public collectible
{
public:
    length_reducer();
    void eat(snake & s,pair<int,int> & mm);
    void draw(QPainter &painter, int &x, int &y);
};

#endif // LENGTH_REDUCER_H
