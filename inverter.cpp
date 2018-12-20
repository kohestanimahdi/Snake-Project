#include "inverter.h"
#include "snake.h"
#include "snake_def.h"
#include <QPainter>
inverter::inverter()
{
    collectible_char=d_inverter;
}

void inverter::eat(snake &s, pair<int, int> &mm)
{
    s.push_back(mm);
    s.pop_front();
    s.reverse();

    snake::iterator p =s.end();
    --p;
    snake::iterator p2=s.end();
    --p2;
    --p2;
    if((*p).first==(*p2).first)
    {
        if((*p).second+1==(*p2).second)
        {
            s.change_move(Key_Left);
        }
        else
        {
            s.change_move(Key_Right);
        }
    }
    else
    {
        if((*p).first+1==(*p2).first)
        {
            s.change_move(Key_Up);
        }
        else
        {
            s.change_move(Key_Down);
        }
    }
}

void inverter::draw(QPainter &painter, int &x, int &y)
{
    string f[24];
    f[0 ] = "000000000000000000000000";
    f[1 ] = "000000000000000000000000";
    f[2 ] = "000000000000000000000000";
    f[3 ] = "000000000000000000000000";
    f[4 ] = "000000000000000000000000";
    f[5 ] = "000000000000000000000000";
    f[6 ] = "000000000000000000000000";
    f[7 ] = "000001100000000001100000";
    f[8 ] = "000011000000000000110000";
    f[9 ] = "000110000000000000011000";
    f[10] = "001100000000000000001100";
    f[11] = "001111111111111111111100";
    f[12] = "001111111111111111111100";
    f[13] = "001100000000000000001100";
    f[14] = "000110000000000000011000";
    f[15] = "000011000000000000110000";
    f[16] = "000001100000000001100000";
    f[17] = "000000000000000000000000";
    f[18] = "000000000000000000000000";
    f[19] = "000000000000000000000000";
    f[20] = "000000000000000000000000";
    f[21] = "000000000000000000000000";
    f[22] = "000000000000000000000000";
    f[23] = "000000000000000000000000";
    QPolygon qp;

    for(int i=0;i<24;i++)
    {
        for(int j=0;j<24;j++)
        {
            if(f[j][i]=='1')
            {
                qp<<QPoint(x*24+i,y*24+j);
            }
        }
    }
    painter.setPen(Qt::black);
    painter.drawPoints(qp);
    painter.setPen(Qt::black);
}
