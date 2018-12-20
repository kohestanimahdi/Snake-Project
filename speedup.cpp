#include "speedup.h"
#include "snake.h"
#include <QPainter>
#include <string>
int speedup::speed;
int speedup::number;
int speedup::snumber;
speedup::speedup()
{
    collectible_char=d_speedup;
}

void speedup::eat(snake &s, pair<int, int> &mm)
{
    number=200;
    speed=50;
    s.pop_front();
    s.push_back(mm);
//    (s.score.Score_Number)++;
}

int speedup::speedupf()
{
    if(number>0)
    {
        number--;
        return speed;
    }
    speed=5;
    return speed;

}

void speedup::draw(QPainter &painter, int &x, int &y)
{
    string f[24];
    f[0 ] = "000000000000000000000000";
    f[1 ] = "000000000000000000000000";
    f[2 ] = "000000000000000000000000";
    f[3 ] = "000000000000000000000000";
    f[4 ] = "000000000111111000000000";
    f[5 ] = "000000001111111100000000";
    f[6 ] = "000000011111111110000000";
    f[7 ] = "000000111110011111000000";
    f[8 ] = "000001111100001111100000";
    f[9 ] = "000011111000000111110000";
    f[10] = "000111110000000011111000";
    f[11] = "000111100000000001111000";
    f[12] = "000111000111111000111000";
    f[13] = "000000001111111100000000";
    f[14] = "000000011111111110000000";
    f[15] = "000000111110011111000000";
    f[16] = "000001111100001111100000";
    f[17] = "000011111000000111110000";
    f[18] = "000111110000000011111000";
    f[19] = "000111100000000001111000";
    f[20] = "000111000000000000111000";
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
    painter.setPen(Qt::blue);
    painter.drawPoints(qp);
    painter.setPen(Qt::black);
}
