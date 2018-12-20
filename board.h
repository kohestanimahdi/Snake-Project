#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <QPainter>
using namespace std;




class Board
{

    unsigned char **mp;
    int n;
    int m;
    int Map_Number;
public:
    Board(int n);
    void margin();
    void page1();
    void writh(int x,int y,string str);
    void printPlan(unsigned char ** mp2,QPainter & painter);
    unsigned char ** GetBoard();
    void SetMp(unsigned char **mp2);
    unsigned char ** GetMp();
    int Getn();

    void SetMap(int m);
    void GetMap();
    void Map1();
    void Map2();
    void Map3();
    void Map4();
    void Map5();
    void Map6();
    void Map7();
    void Map8();

    void gotoxy(int x,int y);

    void GameOver();
    void clear();
};

#endif // BOARD_H
