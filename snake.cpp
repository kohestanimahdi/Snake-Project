#include "snake.h"
#include "snake_def.h"
#include "score.h"
#include "life.h"
#include "board_def.h"
#include "collectible.h"
#include <QKeyEvent>

//دو تا نقطه برای مار تعیین میکنه
snake::snake()
{
    default_move=Key_Right;
    pair<int,int> m;
    m.first=2;
    m.second=2;
    push_back(m);

}



//مار رو حرکت میده
unsigned char snake::move(unsigned char **mp,collectible * c,int n)
{

    iterator itr=end();
    itr--;
    pair<int,int> mm=*(itr),pb=*(begin());
    if(default_move==Key_Right)
        mm.second++;
    if(default_move==Key_Down)
        mm.first++;
    if(default_move==Key_Up)
        mm.first--;
    if(default_move==Key_Left)
        mm.second--;
    mm.first+=n;
    mm.first%=n;
    mm.second+=n;
    mm.second%=n;
    if(mp[mm.first][mm.second]==c->Getcollectible_char())
    {
        c->eat(*this,mm);
        return c->Getcollectible_char();
    }
    if(mp[mm.first][mm.second]==d_wall)
    {
        return d_wall;
    }


    if(mp[mm.first][mm.second]==d_snack)
    {
        if(mm.first==pb.first && mm.second==pb.second)
        {
            pop_front();
            push_back(mm);
            return 0;
        }

        return d_snack;
    }
    pop_front();
    push_back(mm);
//    collectible::collectible_second++;
    return 0;
}

//حرکت رو عوض میکنه
void snake::change_move(int newmove)
{
    if(default_move==newmove)
        return;
    if(poison::number_move<=0)
    {
        if((default_move==Key_Right || default_move==Key_Left)&&(newmove==Key_Up || newmove==Key_Down))
            default_move=newmove;
        else if((newmove==Key_Right || newmove==Key_Left)&&(default_move==Key_Up || default_move==Key_Down))
            default_move=newmove;
        else if(size()==1)
            default_move=newmove;
        else
        {
            snake::iterator p =end();
            --p;
            snake::iterator p2=end();
            --p2;
            --p2;
            if((*p).first==(*p2).first)
            {
                if((*p).second+1==(*p2).second && newmove!=Key_Right)
                {
                    default_move=newmove;
                }
                else if((*p).second==(*p2).second+1 && newmove!=Key_Left)
                {
                    default_move=newmove;
                }
            }
            else
            {
                if((*p).first+1==(*p2).first&& newmove!=Key_Down)
                {
                    default_move=newmove;
                }
                else if((*p).first==(*p2).first+1&&newmove!=Key_Up)
                {
                    default_move=newmove;
                }
            }
        }
    }
    else
    {
        if((default_move==Key_Right || default_move==Key_Left)&&newmove==Key_Up)
            default_move=Key_Down;
        else if((default_move==Key_Right || default_move==Key_Left)&& newmove==Key_Down)
            default_move=Key_Up;
        else if((default_move==Key_Up || default_move==Key_Down) && newmove ==Key_Left)
            default_move=Key_Right;
        else if((default_move==Key_Up || default_move==Key_Down)&&newmove ==Key_Right)
            default_move=Key_Left;
        else if(this->list::size()==1)
            default_move=newmove;
        poison::number_move--;


    }

}


