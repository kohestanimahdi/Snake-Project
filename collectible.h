#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H
#include "board_def.h"
#include <list>
using namespace std;

class snake;
class QPainter ;
class collectible
{
protected:
    unsigned char collectible_char;

public:
    static int collectible_Number;
    static int collectible_second;
    static bool ocl;
    collectible();
    collectible *collect(unsigned char ** mp, int &x, int &y, int n);
    virtual void eat(snake & s,pair<int,int> & mm);
    virtual void draw(QPainter &painter,int &x,int &y);
    unsigned char Getcollectible_char();
};

#endif // COLLECTIBLE_H
