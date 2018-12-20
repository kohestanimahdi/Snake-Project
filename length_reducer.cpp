#include "length_reducer.h"
#include "snake.h"
#include "board_def.h"
#include <QPainter>
length_reducer::length_reducer()
{
    collectible_char=d_length_reducer;
}

void length_reducer::eat(snake &s, pair<int, int> &mm)
{
    if(s.size()>2)
        s.pop_front();
    if(s.size()>2)
        s.pop_front();
    if(s.size()>2)
        s.pop_front();
    s.push_back(mm);
    s.pop_front();
}

void length_reducer::draw(QPainter &painter, int &x, int &y)
{
    string f[24];
    f[0 ] = "000000000000000000000000";
    f[1 ] = "000000000000000000000000";
    f[2 ] = "000011000000000000110000";
    f[3 ] = "000111100000000001111000";
    f[4 ] = "001100100000000001001100";
    f[5 ] = "001100110000000011001100";
    f[6 ] = "000111111000000111111000";
    f[7 ] = "000011011100001110110000";
    f[8 ] = "000000001110011100000000";
    f[9 ] = "000000000111111000000000";
    f[10] = "000000000011110000000000";
    f[11] = "000000000011110000000000";
    f[12] = "000000000111111000000000";
    f[13] = "000000001111111100000000";
    f[14] = "000000011111111110000000";
    f[15] = "000000111110011111000000";
    f[16] = "000001111100001111100000";
    f[17] = "000011111000000111110000";
    f[18] = "000111110000000011111000";
    f[19] = "000111100000000001111000";
    f[20] = "001111000000000000111100";
    f[21] = "001110000000000000011100";
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
