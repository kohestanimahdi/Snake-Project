#include "collectible.h"
#include<stdlib.h>
#include <QPainter>
#include "board_def.h"
#include "food.h"
#include "half.h"
#include "length_reducer.h"
#include "life_collection.h"
#include "quarter.h"
#include "score_collection.h"
#include "speedup.h"
#include "poison.h"
#include "inverter.h"
int collectible::collectible_Number;
int collectible::collectible_second;
bool collectible::ocl;
collectible::collectible()
{
}

collectible* collectible::collect(unsigned char ** mp, int &x, int &y, int n)
{
    x = rand ()% (n-2)+1;
    y = rand ()% (n-2)+1;
    if(mp[x][y]!=' ')
        collect( mp, x, y, n);
//    collectible_Number ++;
    collectible * c;
//    if(collectible_Number%5==0)
//    {
        //return new poison;

        int w= rand()% 40;
        switch (w) {
        case 0:
            c=new quarter;
            ocl=true;
            break;
        case 1:
            c=new length_reducer;
            ocl=true;
            break;
        case 2:
            c=new half;
            ocl=true;
            break;
        case 3:
            c=new score_collection;
            ocl=true;
            break;
        case 4:
            c=new life_collection;
            ocl=true;
            break;
        case 5:
            c=new speedup;
            ocl=true;
            break;
        case 6:
            c=new poison;
            ocl=true;
            break;
        case 7:
            c=new inverter;
            ocl=true;
            break;
        case 8:
            c=new poison;
            ocl=true;
            break;
        case 9:
            c=new speedup;
            ocl=true;
            break;
        case 10:
            c=new speedup;
            ocl=true;
            break;
        case 11:
            c=new poison;
            ocl=true;
            break;
        case 12:
            c=new score_collection;
            ocl=true;
            break;
        case 13:
            c=new speedup;
            ocl=true;
            break;
        default:
            c=new food;
            ocl=false;
            collectible_second=0;

            return c;
        }

        return c;
//    }
//    c=new food;
//    ocl=false;
//    return c;
}

void collectible::eat(snake &s, pair<int, int> &mm)
{

    s.push_back(mm);
    (Score::Score_Number)++;
}

void collectible::draw(QPainter &painter, int &x, int &y)
{
    QPolygon qp;
    qp<<QPoint(x*24+11,y*24+3)<<QPoint(x*24+12,y*24+3);

    qp<<QPoint(x*24+11,y*24+4)<<QPoint(x*24+12,y*24+4);

    qp<<QPoint(x*24+11,y*24+5)<<QPoint(x*24+12,y*24+5);
    qp<<QPoint(x*24+5,y*24+5)<<QPoint(x*24+6,y*24+5);
    qp<<QPoint(x*24+17,y*24+5)<<QPoint(x*24+18,y*24+5);

    qp<<QPoint(x*24+11,y*24+6)<<QPoint(x*24+12,y*24+6);
    qp<<QPoint(x*24+10,y*24+6)<<QPoint(x*24+13,y*24+6);
    qp<<QPoint(x*24+5,y*24+6)<<QPoint(x*24+6,y*24+6);
    qp<<QPoint(x*24+7,y*24+6);
    qp<<QPoint(x*24+16,y*24+6)<<QPoint(x*24+17,y*24+6);
    qp<<QPoint(x*24+18,y*24+6);

    qp<<QPoint(x*24+6,y*24+7)<<QPoint(x*24+7,y*24+7);
    qp<<QPoint(x*24+8,y*24+7)<<QPoint(x*24+9,y*24+7);
    qp<<QPoint(x*24+10,y*24+7)<<QPoint(x*24+11,y*24+7);
    qp<<QPoint(x*24+12,y*24+7)<<QPoint(x*24+13,y*24+7);
    qp<<QPoint(x*24+14,y*24+7)<<QPoint(x*24+15,y*24+7);
    qp<<QPoint(x*24+16,y*24+7)<<QPoint(x*24+17,y*24+7);

    qp<<QPoint(x*24+7,y*24+8);
    qp<<QPoint(x*24+8,y*24+8)<<QPoint(x*24+9,y*24+8);
    qp<<QPoint(x*24+14,y*24+8)<<QPoint(x*24+15,y*24+8);
    qp<<QPoint(x*24+16,y*24+8);

    qp<<QPoint(x*24+7,y*24+9);
    qp<<QPoint(x*24+8,y*24+9);
    qp<<QPoint(x*24+15,y*24+9);
    qp<<QPoint(x*24+16,y*24+9);

    qp<<QPoint(x*24+6,y*24+10);
    qp<<QPoint(x*24+7,y*24+10);
    qp<<QPoint(x*24+16,y*24+10);
    qp<<QPoint(x*24+17,y*24+10);


    qp<<QPoint(x*24+4,y*24+11)<<QPoint(x*24+5,y*24+11);
    qp<<QPoint(x*24+6,y*24+11)<<QPoint(x*24+7,y*24+11);
    qp<<QPoint(x*24+16,y*24+11)<<QPoint(x*24+17,y*24+11);
    qp<<QPoint(x*24+18,y*24+11)<<QPoint(x*24+19,y*24+11);


    qp<<QPoint(x*24+4,y*24+12)<<QPoint(x*24+5,y*24+12);
    qp<<QPoint(x*24+6,y*24+12)<<QPoint(x*24+7,y*24+12);
    qp<<QPoint(x*24+16,y*24+12)<<QPoint(x*24+17,y*24+12);
    qp<<QPoint(x*24+18,y*24+12)<<QPoint(x*24+19,y*24+12);

    qp<<QPoint(x*24+6,y*24+13);
    qp<<QPoint(x*24+7,y*24+13);
    qp<<QPoint(x*24+16,y*24+13);
    qp<<QPoint(x*24+17,y*24+13);

    qp<<QPoint(x*24+7,y*24+14);
    qp<<QPoint(x*24+8,y*24+14);
    qp<<QPoint(x*24+15,y*24+14);
    qp<<QPoint(x*24+16,y*24+14);

    qp<<QPoint(x*24+7,y*24+15);
    qp<<QPoint(x*24+8,y*24+15)<<QPoint(x*24+9,y*24+15);
    qp<<QPoint(x*24+14,y*24+15)<<QPoint(x*24+15,y*24+15);
    qp<<QPoint(x*24+16,y*24+15);

    qp<<QPoint(x*24+6,y*24+16)<<QPoint(x*24+7,y*24+16);
    qp<<QPoint(x*24+8,y*24+16)<<QPoint(x*24+9,y*24+16);
    qp<<QPoint(x*24+10,y*24+16)<<QPoint(x*24+11,y*24+16);
    qp<<QPoint(x*24+12,y*24+16)<<QPoint(x*24+13,y*24+16);
    qp<<QPoint(x*24+14,y*24+16)<<QPoint(x*24+15,y*24+16);
    qp<<QPoint(x*24+16,y*24+16)<<QPoint(x*24+17,y*24+16);


    qp<<QPoint(x*24+11,y*24+17)<<QPoint(x*24+12,y*24+17);
    qp<<QPoint(x*24+10,y*24+17)<<QPoint(x*24+13,y*24+17);
    qp<<QPoint(x*24+5,y*24+17)<<QPoint(x*24+6,y*24+17);
    qp<<QPoint(x*24+7,y*24+17);
    qp<<QPoint(x*24+16,y*24+17)<<QPoint(x*24+17,y*24+17);
    qp<<QPoint(x*24+18,y*24+17);

    qp<<QPoint(x*24+11,y*24+18)<<QPoint(x*24+12,y*24+18);
    qp<<QPoint(x*24+5,y*24+18)<<QPoint(x*24+6,y*24+18);
    qp<<QPoint(x*24+17,y*24+18)<<QPoint(x*24+18,y*24+18);

    qp<<QPoint(x*24+11,y*24+19)<<QPoint(x*24+12,y*24+19);

    qp<<QPoint(x*24+11,y*24+20)<<QPoint(x*24+12,y*24+20);
    painter.drawPoints(qp);
}

unsigned char collectible::Getcollectible_char()
{
    return collectible_char;
}


