#ifndef POISON_H
#define POISON_H
#include "collectible.h"
class poison:public collectible
{
public:
  static  int number_move;
    poison();
    void eat(snake & s,pair<int,int> & mm);
    void draw(QPainter &painter, int &x, int &y);
};

#endif // POISON_H
