#ifndef LIFE_COLLECTION_H
#define LIFE_COLLECTION_H
#include "collectible.h"


class life_collection:public collectible
{
public:
    life_collection();
    void eat(snake & s,pair<int,int> & mm);
    void draw(QPainter &painter, int &x, int &y);
};

#endif // LIFE_COLLECTION_H
