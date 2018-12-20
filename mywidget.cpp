#include <QApplication>
#include <QGridLayout>
#include <QDesktopWidget>
#include <QKeyEvent>
#include "mywidget.h"
#include "game_board.h"
#include "start_board.h"
#include "snake.h"
#include "snake_def.h"
#include "speedup.h"
#include <mutex>
#include <QTimer>
#include <QMenuBar>
#include <QMessageBox>
#include <startmenu.h>
#include <game_overmenu.h>


MyWidget::MyWidget(QWidget *parent)
    :  QMainWindow(parent)
{
    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QAction *mp1 = new QAction(tr("&Map 1"), this);
    connect(mp1, SIGNAL(triggered()), this,SLOT(changemap1()));
    QAction *mp2 = new QAction(tr("&Map 2"), this);
    connect(mp2, SIGNAL(triggered()), this,SLOT(changemap2()));
    QAction *mp3 = new QAction(tr("&Map 3"), this);
    connect(mp3,SIGNAL(triggered()), this,SLOT(changemap3()));
    QAction *mp4 = new QAction(tr("&Map 4"), this);
    connect(mp4, SIGNAL(triggered()), this,SLOT(changemap4()));
    QAction *mp5 = new QAction(tr("&Map 5"), this);
    connect(mp5, SIGNAL(triggered()), this,SLOT(changemap5()));
    QAction *mp6 = new QAction(tr("&Map 6"), this);
    connect(mp6, SIGNAL(triggered()), this,SLOT(changemap6()));
    QAction *mp7 = new QAction(tr("&Map 7"), this);
    connect(mp7, SIGNAL(triggered()), this,SLOT(changemap7()));
    QAction *mp8 = new QAction(tr("&Map 8"), this);
    connect(mp8, SIGNAL(triggered()), this,SLOT(changemap8()));
    QAction *mp9 = new QAction(tr("&Map 9"), this);
    connect(mp9, SIGNAL(triggered()), this,SLOT(changemap9()));


    QAction *PlayGameA = new QAction(tr("&Play"), this);
    connect(PlayGameA, SIGNAL(triggered()), this,SLOT(PlayGame()));
    PlayGameA->setShortcuts(QKeySequence::InsertParagraphSeparator);
    QAction *StopGameA = new QAction(tr("&Stop"), this);
    connect(StopGameA, SIGNAL(triggered()), this,SLOT(StopGame()));
    StopGameA->setShortcuts(QKeySequence::MoveToStartOfLine);
    QAction *NewGameA = new QAction(tr("&New Game"), this);
    connect(NewGameA, SIGNAL(triggered()), this,SLOT(NewGame()));
    NewGameA->setShortcuts(QKeySequence::New);

    QMenu *GameMenu;
    GameMenu = menuBar()->addMenu(tr("&Game"));
    GameMenu->addAction(NewGameA);
    GameMenu->addAction(PlayGameA);
    GameMenu->addAction(StopGameA);
    QMenu *MapsMenu;
    MapsMenu = menuBar()->addMenu(tr("&Maps"));
    MapsMenu->addAction(mp1);
    MapsMenu->addAction(mp2);
    MapsMenu->addAction(mp3);
    MapsMenu->addAction(mp4);
    MapsMenu->addAction(mp5);
    MapsMenu->addAction(mp6);
    MapsMenu->addAction(mp7);
    MapsMenu->addAction(mp8);
    MapsMenu->addAction(mp9);
    QMenu *HelpMenu;
    HelpMenu = menuBar()->addMenu(tr("&Help"));
    QAction *AboutA = new QAction(tr("&About"), this);
    connect(AboutA, SIGNAL(triggered()), this,SLOT(About()));
    HelpMenu->addAction(AboutA);


    board=new Start_Board(this);
    board->SetMap(1);
    gridLayout = new QGridLayout;
    QWidget *window = new QWidget();
    window->setLayout(gridLayout);
    setCentralWidget(window);
    gridLayout->addWidget(board, 1, 1,1, 1);
    gridLayout->setColumnStretch(1, 0);
    gridLayout->setMargin(0);
    Level=enStart_Board;
    this->setFixedSize(576,24*25+menuBar()->height());
    premapnum=1;

}

void MyWidget::keyPressEvent(QKeyEvent *event)
{
    if(Level==enStart_Board)
    {
        if(board->GetisEnd() ==true)
        {
            delete board;
            form=new StartMenu(this);
            gridLayout = new QGridLayout;
            QWidget *window = new QWidget();
            window->setLayout(gridLayout);
            setCentralWidget(window);
            QWidget  f1;
            QWidget f2;
            gridLayout->addWidget(&f1, 1,1);
            gridLayout->addWidget(&f2, 3,3);
            gridLayout->addWidget(form, 2,2);
            gridLayout->setColumnStretch(1,1);
            gridLayout->setColumnStretch(2,2);
            gridLayout->setColumnStretch(3,1);
            gridLayout->setRowStretch(1,2);
            gridLayout->setRowStretch(2,1);
            gridLayout->setRowStretch(3,2);
            gridLayout->setMargin(0);
            connect(form,SIGNAL(Startclicked()),this,SLOT(StartGame()));
            connect(form,SIGNAL(Quitclicked()),qApp,SLOT(quit()));


            setLayout(gridLayout);
            Level=enStart_Form;
            return;
        }
    }
    else if(tme->isActive())
    {
        mutex m;
        m.lock();
        board->keyPressEvent(event);
        Sleep(speedup::speed-speedup::snumber);
        board->update();
        speedup::snumber=0;
        m.unlock();
    }
}

void MyWidget::isGameOver()
{
    if(Life::Life_Number==0)
    {
       // QMessageBox qm;
       // qm.warning(this,"Warning","Game Over!");
        enm =new Enter_name;
        enm->show();
        delete tme;
        delete board;
        Level=enGameOver;
        game_overform=new game_overmenu(this);
        game_overgridLayout = new QGridLayout;
        QWidget *game_overwindow = new QWidget();
        game_overwindow->setLayout(game_overgridLayout);
        setCentralWidget(game_overwindow);
        QWidget  f1;
        QWidget f2;
        game_overgridLayout->addWidget(&f1, 1,1);
        game_overgridLayout->addWidget(&f2, 3,3);
        game_overgridLayout->addWidget(game_overform, 2,2);
        game_overgridLayout->setColumnStretch(1,1);
        game_overgridLayout->setColumnStretch(2,2);
        game_overgridLayout->setColumnStretch(3,1);
        game_overgridLayout->setRowStretch(1,2);
        game_overgridLayout->setRowStretch(2,1);
        game_overgridLayout->setRowStretch(3,2);
        game_overgridLayout->setMargin(0);
        connect(game_overform,SIGNAL(Startclicked()),this,SLOT(StartGame()));
        connect(game_overform,SIGNAL(Quitclicked()),qApp,SLOT(quit()));


    }
}

void MyWidget::changemap1()
{
    if(enGameIsRunning==Level)
    {
    delete tme;
    delete board;
    board=new Game_Board(this);
    board->SetMap(1);
    gridLayout->addWidget(board, 1, 1, 2, 1);
    setLayout(gridLayout);
    tme = new QTimer ;
    tme->start ( 10 ) ;
    QObject::connect (tme,SIGNAL (timeout()),board, SLOT(Update_board()));
    connect(tme,SIGNAL (timeout()),this, SLOT(isGameOver()));
    }
    premapnum=1;
}

void MyWidget::changemap2()
{
    if(enGameIsRunning==Level)
    {
    delete tme;
    delete board;
    board=new Game_Board(this);
    board->SetMap(2);
    gridLayout->addWidget(board, 1, 1, 2, 1);
    setLayout(gridLayout);
    tme = new QTimer ;
    tme->start ( 10 ) ;
    QObject::connect (tme,SIGNAL (timeout()),board, SLOT(Update_board()));
    connect(tme,SIGNAL (timeout()),this, SLOT(isGameOver()));
    }
    premapnum=2;
}

void MyWidget::changemap3()
{

    if(enGameIsRunning==Level)
    {
    delete tme;
    delete board;
    board=new Game_Board(this);
    board->SetMap(3);
    gridLayout->addWidget(board, 1, 1, 2, 1);
    setLayout(gridLayout);
    tme = new QTimer ;
    tme->start ( 10 ) ;
    QObject::connect (tme,SIGNAL (timeout()),board, SLOT(Update_board()));
    connect(tme,SIGNAL (timeout()),this, SLOT(isGameOver()));
    }
    premapnum=3;
}

void MyWidget::changemap4()
{

    if(enGameIsRunning==Level)
    {
    delete tme;
    delete board;
    board=new Game_Board(this);
    board->SetMap(4);
    gridLayout->addWidget(board, 1, 1, 2, 1);
    setLayout(gridLayout);
    tme = new QTimer ;
    tme->start ( 10 ) ;
    QObject::connect (tme,SIGNAL (timeout()),board, SLOT(Update_board()));
    connect(tme,SIGNAL (timeout()),this, SLOT(isGameOver()));
    }
    premapnum=4;
}

void MyWidget::changemap5()
{

    if(enGameIsRunning==Level)
    {
    delete tme;
    delete board;
    board=new Game_Board(this);
    board->SetMap(5);
    gridLayout->addWidget(board, 1, 1, 2, 1);
    setLayout(gridLayout);
    tme = new QTimer ;
    tme->start ( 10 ) ;
    QObject::connect (tme,SIGNAL (timeout()),board, SLOT(Update_board()));
    connect(tme,SIGNAL (timeout()),this, SLOT(isGameOver()));
    }
    premapnum=5;
}
void MyWidget::changemap6()
{

    if(enGameIsRunning==Level)
    {
    delete tme;
    delete board;
    board=new Game_Board(this);
    board->SetMap(6);
    gridLayout->addWidget(board, 1, 1, 2, 1);
    setLayout(gridLayout);
    tme = new QTimer ;
    tme->start ( 10 ) ;
    QObject::connect (tme,SIGNAL (timeout()),board, SLOT(Update_board()));
    connect(tme,SIGNAL (timeout()),this, SLOT(isGameOver()));
    }
    premapnum=6;
}
void MyWidget::changemap7()
{

    if(enGameIsRunning==Level)
    {
    delete tme;
    delete board;
    board=new Game_Board(this);
    board->SetMap(7);
    gridLayout->addWidget(board, 1, 1, 2, 1);
    setLayout(gridLayout);
    tme = new QTimer ;
    tme->start ( 10 ) ;
    QObject::connect (tme,SIGNAL (timeout()),board, SLOT(Update_board()));
    connect(tme,SIGNAL (timeout()),this, SLOT(isGameOver()));
    }
    premapnum=7;
}
void MyWidget::changemap8()
{

    if(enGameIsRunning==Level)
    {
    delete tme;
    delete board;
    board=new Game_Board(this);
    board->SetMap(8);
    gridLayout->addWidget(board, 1, 1, 2, 1);
    setLayout(gridLayout);
    tme = new QTimer ;
    tme->start ( 10 ) ;
    QObject::connect (tme,SIGNAL (timeout()),board, SLOT(Update_board()));
    connect(tme,SIGNAL (timeout()),this, SLOT(isGameOver()));
    }
    premapnum=8;
}

void MyWidget::changemap9()
{

    if(enGameIsRunning==Level)
    {
    delete tme;
    delete board;
    board=new Game_Board(this);
    board->SetMap(9);
    gridLayout->addWidget(board, 1, 1, 2, 1);
    setLayout(gridLayout);
    tme = new QTimer ;
    tme->start ( 10 ) ;
    QObject::connect (tme,SIGNAL (timeout()),board, SLOT(Update_board()));
    connect(tme,SIGNAL (timeout()),this, SLOT(isGameOver()));
    }
    premapnum=9;
}

void MyWidget::PlayGame()
{
    if(Level==enGameIsRunning)
    {
        tme->start(10);
        return;
    }
    if(Level==enStart_Board)
    {
        if(board->GetisEnd() ==true)
        {
            delete board;
            form=new StartMenu(this);
            gridLayout = new QGridLayout;
            QWidget *window = new QWidget();
            window->setLayout(gridLayout);
            setCentralWidget(window);
            QWidget  f1;
            QWidget f2;
            gridLayout->addWidget(&f1, 1,1);
            gridLayout->addWidget(&f2, 3,3);
            gridLayout->addWidget(form, 2,2);
            gridLayout->setColumnStretch(1,1);
            gridLayout->setColumnStretch(2,2);
            gridLayout->setColumnStretch(3,1);
            gridLayout->setRowStretch(1,2);
            gridLayout->setRowStretch(2,1);
            gridLayout->setRowStretch(3,2);
            gridLayout->setMargin(0);
            connect(form,SIGNAL(Startclicked()),this,SLOT(StartGame()));
            connect(form,SIGNAL(Quitclicked()),qApp,SLOT(quit()));


            setLayout(gridLayout);
            Level=enStart_Form;
            return;
        }
    }

}

void MyWidget::StopGame()
{
    if(Level==enGameIsRunning)
    {
        tme->stop();
    }if(Level==enStart_Board)
    {
        if(board->GetisEnd() ==true)
        {
            delete board;
            form=new StartMenu(this);
            gridLayout = new QGridLayout;
            QWidget *window = new QWidget();
            window->setLayout(gridLayout);
            setCentralWidget(window);
            QWidget  f1;
            QWidget f2;
            gridLayout->addWidget(&f1, 1,1);
            gridLayout->addWidget(&f2, 3,3);
            gridLayout->addWidget(form, 2,2);
            gridLayout->setColumnStretch(1,1);
            gridLayout->setColumnStretch(2,2);
            gridLayout->setColumnStretch(3,1);
            gridLayout->setRowStretch(1,2);
            gridLayout->setRowStretch(2,1);
            gridLayout->setRowStretch(3,2);
            gridLayout->setMargin(0);
            connect(form,SIGNAL(Startclicked()),this,SLOT(StartGame()));
            connect(form,SIGNAL(Quitclicked()),qApp,SLOT(quit()));


            setLayout(gridLayout);
            Level=enStart_Form;
            return;
        }
    }
}

void MyWidget::NewGame()
{


    if(Level==enGameIsRunning)
    {
        delete tme;
        delete board;
        board=new Game_Board(this);
        gridLayout->addWidget(board, 1, 1, 2, 1);
        setLayout(gridLayout);
        tme = new QTimer ;
        tme->start ( 10 ) ;
        QObject::connect (tme,SIGNAL (timeout()),board, SLOT(Update_board()));
        connect(tme,SIGNAL (timeout()),this, SLOT(isGameOver()));
    }if(Level==enStart_Board)
    {
        if(board->GetisEnd() ==true)
        {
            delete board;
            form=new StartMenu(this);
            gridLayout = new QGridLayout;
            QWidget *window = new QWidget();
            window->setLayout(gridLayout);
            setCentralWidget(window);
            QWidget  f1;
            QWidget f2;
            gridLayout->addWidget(&f1, 1,1);
            gridLayout->addWidget(&f2, 3,3);
            gridLayout->addWidget(form, 2,2);
            gridLayout->setColumnStretch(1,1);
            gridLayout->setColumnStretch(2,2);
            gridLayout->setColumnStretch(3,1);
            gridLayout->setRowStretch(1,2);
            gridLayout->setRowStretch(2,1);
            gridLayout->setRowStretch(3,2);
            gridLayout->setMargin(0);
            connect(form,SIGNAL(Startclicked()),this,SLOT(StartGame()));
            connect(form,SIGNAL(Quitclicked()),qApp,SLOT(quit()));


            setLayout(gridLayout);
            Level=enStart_Form;
            return;
        }
    }
}

void MyWidget::About()
{
    QMessageBox::about(this,"About","Authers : \nMahdi Malverdi\nMahdi Kohestani\nNarges Asadi");
}

void MyWidget::StartGame()
{
    if(enGameIsRunning==Level ||(enStart_Board==Level))
    {
        delete board;
    }
    if(enStart_Form==Level)
    {
        delete form;
    }
    if(enGameOver== Level)
    {
       delete game_overform;
    }
    board=new Game_Board(this);
    board->SetMap(premapnum);
    gridLayout = new QGridLayout;
    QWidget *window = new QWidget();
    window->setLayout(gridLayout);
    setCentralWidget(window);
    gridLayout->addWidget(board, 1, 1,1, 1);
    gridLayout->setColumnStretch(1, 0);
    gridLayout->setMargin(0);
    setLayout(gridLayout);
    Level=enGameIsRunning;
    tme = new QTimer ;
    tme->start ( 10 ) ;
    connect (tme,SIGNAL (timeout()),board, SLOT(Update_board()));
    connect(tme,SIGNAL (timeout()),this, SLOT(isGameOver()));
}
