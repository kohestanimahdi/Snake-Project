#include "board.h"
#include "qtextstream.h"
#include "board_def.h"
#include <QPainter>
Board::Board(int n)
{
    Map_Number=8;
    //یه مپ خالی میسازه
    {
        mp=new unsigned char*[n];
        for(int i=0;i<n;i++)
        {
            mp[i]=new unsigned char[n];
            for(int j=0;j<n;j++)
            {
                mp[i][j]=' ';
            }
        }
    }
    Board::n=n;
}

//حاشیه رو داخل مپ میریزه
void Board::margin()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            mp[i][j]=' ';
        }
    }
    for(int i=0;i<n;i++)
    {
        mp[0][i]=d_wall;
    }
    for(int i=0;i<n;i++)
    {
        mp[n-1][i]=d_wall;
    }
    for(int i=0;i<n;i++)
    {
        mp[i][0]=d_wall;
    }
    for(int i=0;i<n;i++)
    {
        mp[i][n-1]=d_wall;
    }
}

void Board::page1()
{
    margin();
    //S رو تو مپ میریزه
    {
        mp[(n-7)/2][(n-4)/2]=219;
        mp[(n-7)/2][(n-4)/2+1]=219;
        mp[(n-7)/2][(n-4)/2+2]=219;
        mp[(n-7)/2][(n-4)/2+3]=219;

        mp[(n-7)/2+1][(n-4)/2]=219;
        mp[(n-7)/2+2][(n-4)/2]=219;
        mp[(n-7)/2+3][(n-4)/2]=219;

        mp[(n-7)/2+3][(n-4)/2+1]=219;
        mp[(n-7)/2+3][(n-4)/2+2]=219;
        mp[(n-7)/2+3][(n-4)/2+3]=219;
        mp[(n-7)/2+4][(n-4)/2+3]=219;
        mp[(n-7)/2+5][(n-4)/2+3]=219;
        mp[(n-7)/2+6][(n-4)/2+3]=219;
        mp[(n-7)/2+6][(n-4)/2+2]=219;
        mp[(n-7)/2+6][(n-4)/2+1]=219;
        mp[(n-7)/2+6][(n-4)/2]=219;
    }
    writh((n-4)/2-3,(n-7)/2+8,"LAST OF US");
    writh((n-4)/2-7,(n-7)/2+10,"Pleas press any key");
}

void Board::writh(int x, int y, string str)
{
    for(unsigned int i=0;i<str.size();i++)
    {
        mp[y][x+i]=str[i];
    }
}
//مپ رو چاپ میکنه
void Board::printPlan(unsigned char **mp2, QPainter &painter)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mp[i][j]!=mp2[i][j])
            {
            }
        }
    }
}
//مپ رو بر می گردونه
unsigned char **Board::GetBoard()
{
    unsigned char **mp2;
    mp2=new unsigned char*[n];
    for(int i=0;i<n;i++)
    {
        mp2[i]=new unsigned char[n];
        for(int j=0;j<n;j++)
        {
            mp2[i][j]=mp[i][j];
        }
    }
    return mp2;
}

void Board::SetMp(unsigned char **mp2)
{
    mp=mp2;
}

unsigned char **Board::GetMp()
{
    return mp;
}

int  Board::Getn()
{
    return n;
}

void Board::SetMap(int m)
{
    Board::m=m;
}

void Board::GetMap()
{
    switch (m) {
    case 1:
        Map1();
        break;
    case 2:
        Map2();
        break;
    case 3:
        Map3();
        break;
    case 4:
        Map4();
        break;
    case 5:
        Map5();
        break;
    case 6:
        Map6();
        break;
    case 7:
        Map7();
        break;
    case 8:
        Map8();
        break;
    case 9:
        clear();
        break;
    }
}

void Board::Map1()
{
    margin();
}

void Board::Map2()
{
    margin();
    for(int j=0;j<n/2;j++)
    {
        mp[n/3][j]=d_wall;
    }
    for(int j=0;j<n/2;j++)
    {
        mp[2*n/3][n-j]=d_wall;
    }

}

void Board::Map3()
{
    margin();
    for(int j=0;j<n/3;j++)
    {
        mp[n/2][j]=d_wall;
    }
    for(int j=0;j<n/3;j++)
    {
        mp[n/2][n-j]=d_wall;
    }
}

void Board::Map5()
{
    margin();
    for(int i=0;i<n/4;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            mp[n/2-i+j][n/2+j]=d_wall;
        }
        for(int j=0;j<i+1;j++)
        {
            mp[n/2-i+j][n/2-j-1]=d_wall;
        }
    }
    for(int i=0;i<n/4;i++)
    {
        for(int j=0;j<n/4-i;j++)
        {
            mp[n/2+i][n/2+j]=d_wall;
        }
        for(int j=0;j<n/4-i;j++)
        {
            mp[n/2+i][n/2-j-1]=d_wall;
        }
    }
}

void Board::Map4()
{
    margin();
    for(int j=0;j<n/3;j++)
    {
        mp[n/4][n/3+j]=d_wall;
    }
    for(int j=0;j<n/3;j++)
    {
        mp[n/2][j]=d_wall;
    }
    for(int j=0;j<n/3;j++)
    {
        mp[n/2][n-j]=d_wall;
    }
    for(int j=0;j<n/3;j++)
    {
        mp[3*n/4][n/3+j]=d_wall;
    }
}

void Board::Map6()
{
    margin();
    mp[(n-7)/2][(n-4)/2]=219;
    mp[(n-7)/2][(n-4)/2+1]=219;
    mp[(n-7)/2][(n-4)/2+2]=219;
    mp[(n-7)/2][(n-4)/2+3]=219;

    mp[(n-7)/2+1][(n-4)/2]=219;
    mp[(n-7)/2+2][(n-4)/2]=219;
    mp[(n-7)/2+3][(n-4)/2]=219;

    mp[(n-7)/2+3][(n-4)/2+1]=219;
    mp[(n-7)/2+3][(n-4)/2+2]=219;
    mp[(n-7)/2+3][(n-4)/2+3]=219;
    mp[(n-7)/2+4][(n-4)/2+3]=219;
    mp[(n-7)/2+5][(n-4)/2+3]=219;
    mp[(n-7)/2+6][(n-4)/2+3]=219;
    mp[(n-7)/2+6][(n-4)/2+2]=219;
    mp[(n-7)/2+6][(n-4)/2+1]=219;
    mp[(n-7)/2+6][(n-4)/2]=219;
}

void Board::Map7()
{
    margin();

    for(int j=0;j<2*n/3;j++)
    {
        mp[n/5][j]=d_wall;
    }
    for(int j=0;j<2*n/3;j++)
    {
        mp[2*n/5][n-j]=d_wall;
    }
    for(int j=0;j<2*n/3;j++)
    {
        mp[3*n/5][j]=d_wall;
    }
    for(int j=0;j<2*n/3;j++)
    {
        mp[4*n/5][n-j]=d_wall;
    }
}


void Board::Map8()
{
    margin();

    for(int j=0;j<n/2;j++)
    {
        mp[n/4][n/4+j]=d_wall;
    }
    for(int j=0;j<n/2;j++)
    {
        mp[2*n/4][n/4+j]=d_wall;
    }
    for(int j=0;j<n/2;j++)
    {
        mp[3*n/4][n/4+j]=d_wall;
    }
}

//کرسر رو جابه جا میکنه
void Board::gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = {(SHORT) x,(SHORT) y };
    SetConsoleCursorPosition(h,c);
}

void Board::GameOver()
{
    margin();
    writh((n-10)/2,(n)/2-2,"           ");
    writh((n-10)/2,(n)/2-1," GAME OVER ");
    writh((n-19)/2,(n)/2,"                   ");
    writh((n-19)/2,(n)/2+1,"Pleas press any key");
    writh((n-19)/2,(n)/2+2,"                   ");
}

//مپ رو خالی میکنه
void Board::clear()
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            mp[i][j]=' ';
        }
    }
}

