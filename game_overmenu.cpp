#include "game_overmenu.h"
#include <QGridLayout>
#include <QPushButton>
game_overmenu::game_overmenu(QWidget *parent) : QWidget(parent)
{
    BtnStart=new QPushButton("Start again");
    BtnStart->setFont(QFont("SansSerif",15,6));
    BtnScoreBoard=new QPushButton("Score Board");
    BtnScoreBoard->setFont(QFont("SansSerif",15,6));
    BtnQuit=new QPushButton("Quit");
    BtnQuit->setFont(QFont("SansSerif",15,6));
    layout=new QVBoxLayout(this);

    layout->addWidget(BtnStart);
    layout->addWidget(BtnScoreBoard);
    layout->addWidget(BtnQuit);
    connect(BtnScoreBoard,SIGNAL(clicked(bool)),this,SLOT(startscore()));
    connect(BtnStart,SIGNAL(clicked()),this,SIGNAL(Startclicked()));
    connect(BtnQuit,SIGNAL(clicked()),this,SIGNAL(Quitclicked()));
    setLayout(layout);
}

void game_overmenu::startscore()
{
    score_list_menu *m =new score_list_menu;

    m->show();
}
