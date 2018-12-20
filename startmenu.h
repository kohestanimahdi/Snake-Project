#ifndef STARTMENU_H
#define STARTMENU_H

#include <QWidget>
#include "score_list_menu.h"

class QPushButton;
class QVBoxLayout;
class StartMenu : public QWidget
{
    Q_OBJECT
    QPushButton * BtnStart;
    QPushButton * BtnScoreBoard;
    QPushButton * BtnQuit;
    QVBoxLayout * layout ;
public:
    explicit StartMenu(QWidget *parent = 0);
signals:
    void Startclicked();
    void Quitclicked();
public slots:
    void startscore();
};

#endif // STARTMENU_H
