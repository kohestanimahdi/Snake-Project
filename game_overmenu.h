#ifndef GAME_OVERMENU_H
#define GAME_OVERMENU_H

#include <QWidget>
#include "score_list_menu.h"

class QPushButton;
class QVBoxLayout;
class game_overmenu : public QWidget
{
    Q_OBJECT
    QPushButton * BtnStart;
    QPushButton * BtnScoreBoard;
    QPushButton * BtnQuit;
    QVBoxLayout * layout ;
public:
    explicit game_overmenu(QWidget *parent = 0);
signals:
    void Startclicked();
    void Quitclicked();
public slots:
    void startscore();
};

#endif // GAME_OVERMENU_H
