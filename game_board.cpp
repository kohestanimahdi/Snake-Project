#include "game_board.h"
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

extern snake *s;

void Game_Board::drawWall(QPainter & painter,int &x,int &y)
{


    QPolygon qp;
    for(int i=0;i<24;i++)
    {
        for(int j=0;j<24;j++)
        {
            qp<<QPoint(x*24+i,y*24+j);
        }
    }
    painter.drawPoints(qp);
}

void Game_Board::drawSnake(QPainter & painter,int &x,int &y,bool isleft,bool isright,bool istop,bool isbottom)
{

    QPolygon qp;
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<4;j++)
        {
            qp<<QPoint(x*24+2+i,y*24+2+j);
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<12;j++)
        {
            qp<<QPoint(x*24+2+i,y*24+6+j);
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<12;j++)
        {
            qp<<QPoint(x*24+18+i,y*24+6+j);
        }
    }
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<4;j++)
        {
            qp<<QPoint(x*24+2+i,y*24+18+j);
        }
    }
    painter.drawPoints(qp);
    qp.clear();
    painter.setPen(Qt::yellow);
    for(int i=0;i<12;i++)
    {
        for(int j=0;j<12;j++)
        {
            qp<<QPoint(x*24+6+i,y*24+6+j);
        }
    }
    painter.drawPoints(qp);
    qp.clear();
    painter.setPen(Qt::red);
    if(isbottom)
    {
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<4;j++)
            {
                qp<<QPoint(x*24+2+i,y*24+22+j);
            }
        }
    }
    if(isright)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<20;j++)
            {
                qp<<QPoint(x*24+22+i,y*24+2+j);
            }
        }
    }
    if(isleft)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<20;j++)
            {
                qp<<QPoint(x*24+i-2,y*24+2+j);
            }
        }
    }
    if(istop)
    {
        for(int i=0;i<20;i++)
        {
            for(int j=0;j<4;j++)
            {
                qp<<QPoint(x*24+2+i,y*24+j-2);
            }
        }
    }
    painter.drawPoints(qp);
    painter.setPen(Qt::black);
}

void Game_Board::printPlan(unsigned char **mp, QPainter &painter,int  n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mp[i][j]==d_wall)
            {
                drawWall(painter,j,i);
            }
        }
    }
}

bool Game_Board::GetisEnd()
{
    return isEnd;
}

Game_Board::Game_Board(QWidget *parent)
    : QWidget(parent)
{
    poison::number_move=0;
    s=new snake;
    b= new Board(24);
    c=new collectible;
    b->SetMap(mapnumber);
    b->GetMap();
    collectiblex=0;
    collectibley=0;
    collectible::collectible_Number=0;
    collectible::ocl=false;
    collectible::collectible_second=0;
    cp=c->collect(b->GetMp(),collectiblex,collectibley,b->Getn());
    while(b->GetMp()[collectiblex][collectibley]!=' ')
        cp=c->collect(b->GetMp(),collectiblex,collectibley,b->Getn());
    b->GetMp()[collectiblex][collectibley]=cp->Getcollectible_char();
    premp=b->GetBoard();
    setPalette(QPalette(Qt::green));
    setAutoFillBackground(true);
    speedup::speed=200;
    speedup::number=0;
    speedup::snumber=0;
}

void Game_Board::SetMap()
{
    b->SetMap(mapnumber);
}

void Game_Board::SetMap(int n)
{
    mapnumber=n;
    b->SetMap(mapnumber);
}

void Game_Board::Update_board()
{
    speedup::snumber+=10;
    if(speedup::speed==speedup::snumber)
    {
        if(speedup::number>0)
        {
            speedup::number--;
            speedup::speed=90;
        }
        else
        {
            speedup::speed=150;
        }
        speedup::snumber=0;


        update();

    }
}

void Game_Board::paintEvent(QPaintEvent *event)
{
    static int error=0;
    if(error==0)
    {

        if(poison::number_move<=0)
        {
            setPalette(QPalette(Qt::green));
            setAutoFillBackground(true);
        }
        if(poison::number_move>0)
        {
            setPalette(QPalette(Qt::yellow));
            this->setAutoFillBackground(true);
        }
    }
    QPainter painter(this);
    unsigned char returnMove=s->move(premp,cp,b->Getn());
    if(returnMove==d_wall || returnMove==d_snack)
    {
        if(Life::Life_Number>0)
        {
            if(error==1)
            {
                Life::Life_Number--;
                b->clear();
                premp=b->GetBoard();
                error=0;
            }
            else
            {
                error=1;
                setPalette(QPalette(Qt::red));
                this->repaint();
                Sleep(500);
                return;
            }

        }
        else
        {
            return;
        }

    }
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
    if(returnMove==cp->Getcollectible_char())
    {

        while(b->GetMp()[collectiblex][collectibley]!=' ')
            cp=c->collect(b->GetMp(),collectiblex,collectibley,b->Getn());
    }
    collectible::collectible_second++;
    b->GetMp()[collectiblex][collectibley]=cp->Getcollectible_char();
    if(collectible::collectible_second%50==0 && collectible::ocl)
    {
        collectible::collectible_second=1;

        while(b->GetMp()[collectiblex][collectibley]!=' ')
            cp=c->collect(b->GetMp(),collectiblex,collectibley,b->Getn());
    }
    mutex m;
    m.lock();
    printPlan(b->GetMp(),painter,b->Getn());
    cp->draw(painter,collectibley,collectiblex);
    m.unlock();
    premp=b->GetBoard();
    b->clear();
    if(poison::number_move<=0)
    {
        setPalette(QPalette(Qt::green));
        setAutoFillBackground(true);
    }
    if(poison::number_move>0)
    {
        setPalette(QPalette(Qt::yellow));
        this->setAutoFillBackground(true);
    }
    error=0;
    QFont font=painter.font();
    font.setPixelSize(24);
    painter.setFont(font);
    painter.drawText(4,24*24+24,"Score : "+ QString::number(Score::Score_Number,10));
    painter.drawText(24*12-12,24*24+24,"Life : ");
    for(int i=0;i<Life::Life_Number;i++)
    {
        Life::draw(painter,14+i,24);
    }
}

void Game_Board::keyPressEvent(QKeyEvent *event)
{
    mutex m;
    m.lock();
    switch(event->key()){
    case Qt::Key_Up:
        s->change_move(Key_Up);
        break;
    case Qt::Key_Left:

        s->change_move(Key_Left);
        break;
    case Qt::Key_Right:
        s->change_move(Key_Right);
        break;
    case Qt::Key_Down:

        s->change_move(Key_Down);
        break;
    }
    m.unlock();

}
