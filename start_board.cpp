#include "Start_Board.h"
#include "snake.h"
#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include "board.h"
#include "collectible.h"
#include "food.h"
#include "snake_def.h"
#include "poison.h"
#include "speedup.h"
#include <mutex>
#include <string>


Start_Board::Start_Board(QWidget *parent)
    : Game_Board(parent)
{
    poison::number_move=0;
    s=new snake;
    b= new Board(24);
    c=new collectible;
    b->SetMap(1);
    b->GetMap();
    collectiblex=14;
    collectibley=10;
    collectible::collectible_Number=0;
    collectible::collectible_second=0;
    cp=new food;

    b->GetMp()[collectiblex][collectibley]=cp->Getcollectible_char();
    premp=b->GetBoard();
    setPalette(QPalette(Qt::green));
    setAutoFillBackground(true);
    speedup::speed=130;
    speedup::number=0;
    speedup::snumber=0;
    isEnd=false;

}


void Start_Board::Update_board()
{
    speedup::snumber+=10;
    if(speedup::speed==speedup::snumber)
    {
        if(speedup::number>0)
        {
            speedup::number--;
            speedup::speed=85;
        }
        else
        {
            speedup::speed=130;
        }
        speedup::snumber=0;
        update();

    }
}

void Start_Board::paintEvent(QPaintEvent *event)
{
    static int Level=0;
    QPainter painter(this);
    QFont font=painter.font();
    font.setPixelSize(24);
    painter.setFont(font);
    if(Level==33)
    {
        painter.drawText(24*13-4,24*17,"L");
    }
    if(Level==34)
    {
        painter.drawText(24*13-9-4,24*17,"LA");
    }
    if(Level==35)
    {
        painter.drawText(24*13-9*2-4,24*17,"LAS");
    }
    if(Level==36)
    {
        painter.drawText(24*13-9*3-4,24*17,"LAST");
    }
    if(Level==37)
    {
        painter.drawText(24*13-9*4-4,24*17,"LAST ");
    }
    if(Level==38)
    {
        painter.drawText(24*13-9*5-4,24*17,"LAST O");
    }
    if(Level==39)
    {
        painter.drawText(24*13-9*6-4,24*17,"LAST OF");
    }
    if(Level==40)
    {
        painter.drawText(24*13-9*7-4,24*17,"LAST OF ");
    }
    if(Level==41)
    {
        painter.drawText(24*13-9*8-4,24*17,"LAST OF U");
    }
    if(Level>=42)
    {
        painter.drawText(24*13-9*9-4,24*17,"LAST OF US");
    }
    if(Level>42)
    {
        isEnd=true;
        if(Level%3==0)
            painter.drawText(24*9,24*19,"Press Any key .");
        if(Level%3==1)
            painter.drawText(24*9,24*19,"Press Any key ..");
        if(Level%3==2)
            painter.drawText(24*9,24*19,"Press Any key ...");
    }

    if(Level<14 )
    {
        pair<int,int> m;
        m.first=2;
        m.second=2;
        s->push_front(m);
    }
    if(Level==11)
    {
        s->change_move(Key_Down);
    }
    if(Level==17)
    {
        s->change_move(Key_Left);
    }
    if(Level==20)
    {
        s->change_move(Key_Down);
    }
    if(Level==23)
    {
        s->change_move(Key_Right);
    }
    if(Level==26)
    {
        s->change_move(Key_Down);
    }
    if(Level==29)
    {
        s->change_move(Key_Left);
    }
    if(Level<32)
        s->move(premp,cp,b->Getn());
    b->GetMap();
    snake::iterator p =s->begin();
    for(;p!=s->end();++p)
    {

        b->GetMp()[(*p).first][(*p).second]=d_snack;
        snake::iterator pp=p;
        ++pp;
        bool isleft=false;
        bool isright=false;
        bool istop=false;
        bool isbottom=false;
        if(pp!=s->end())
        {
            if((*p).first==(*pp).first)
            {
                if((*p).second==(*pp).second+1)
                {
                    isleft=true;
                }
                else
                {
                    isright=true;
                }
            }
            else
            {
                if((*p).first==(*pp).first+1)
                {
                    istop=true;
                }
                else
                {
                    isbottom=true;
                }
            }
        }
        drawSnake(painter,(*p).second,(*p).first,isleft,isright,istop,isbottom);
    }
    b->GetMp()[collectiblex][collectibley]=cp->Getcollectible_char();
    mutex m;
    m.lock();
    Game_Board::printPlan(b->GetMp(),painter,b->Getn());
    if(Level<31)
        cp->draw(painter,collectibley,collectiblex);
    m.unlock();
    premp=b->GetBoard();
    b->clear();
    painter.drawText(4,24*24+24,"Score : "+ QString::number(Score::Score_Number,10));
    painter.drawText(24*12-12,24*24+24,"Life : ");
    for(int i=0;i<Life::Life_Number;i++)
    {
        Life::draw(painter,14+i,24);
    }
    Sleep(100);
    Level++;
    update();
}

void Start_Board::keyPressEvent(QKeyEvent *event)
{

}
