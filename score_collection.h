#ifndef SCORE_COLLECTION_H
#define SCORE_COLLECTION_H
#include "collectible.h"

class score_collection: public collectible
{
public:
    score_collection();
    void eat(snake & s,pair<int,int> & mm);
    void draw(QPainter &painter, int &x, int &y);
};

#endif // SCORE_COLLECTION_H
