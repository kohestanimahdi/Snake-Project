#include "life.h"
#include <QPainter>
#include <string>
using namespace std;
int Life::Life_Number;



Life::Life()
{

    Life_Number=3;
}

void Life::draw(QPainter &painter,const int &x,const int &y)
{

    string f[24];
    f[0 ] = "000000000000000000000000";
    f[1 ] = "000000000000000000000000";
    f[2 ] = "000000111100001111000000";
    f[3 ] = "000001111110011111100000";
    f[4 ] = "000011111111111111110000";
    f[5 ] = "000111111111111111111000";
    f[6 ] = "001111111111111111111100";
    f[7 ] = "001111111111111111111100";
    f[8 ] = "001111111111111111111100";
    f[9 ] = "001111111111111111111100";
    f[10] = "001111111111111111111100";
    f[11] = "001111111111111111111100";
    f[12] = "000111111111111111111000";
    f[13] = "000111111111111111111000";
    f[14] = "000011111111111111110000";
    f[15] = "000011111111111111110000";
    f[16] = "000001111111111111100000";
    f[17] = "000000111111111111000000";
    f[18] = "000000011111111110000000";
    f[19] = "000000001111111100000000";
    f[20] = "000000000111111000000000";
    f[21] = "000000000011110000000000";
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
    painter.setPen(Qt::red);
    painter.drawPoints(qp);
    painter.setPen(Qt::black);
    f[0 ] = "000000000000000000000000";
    f[1 ] = "000000000000000000000000";
    f[2 ] = "000000111100001111000000";
    f[3 ] = "000001000010010000100000";
    f[4 ] = "000010000000000000010000";
    f[5 ] = "000100000000000000001000";
    f[6 ] = "001000000000000000000100";
    f[7 ] = "001000000000000000000100";
    f[8 ] = "001000000000000000000100";
    f[9 ] = "001000000000000000000100";
    f[10] = "001000000000000000000100";
    f[11] = "001000000000000000000100";
    f[12] = "000100000000000000001000";
    f[13] = "000100000000000000001000";
    f[14] = "000010000000000000010000";
    f[15] = "000010000000000000010000";
    f[16] = "000001000000000000100000";
    f[17] = "000000100000000001000000";
    f[18] = "000000010000000010000000";
    f[19] = "000000001000000100000000";
    f[20] = "000000000100001000000000";
    f[21] = "000000000011110000000000";
    f[22] = "000000000000000000000000";
    f[23] = "000000000000000000000000";
    qp.clear();
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
    painter.setPen(QColor(170,0,4,255));
    painter.drawPoints(qp);
    painter.setPen(Qt::black);
}
