#ifndef SCORE_LIST_MENU_H
#define SCORE_LIST_MENU_H
#include "person_score.h"

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class score_list_menu:public QWidget, public score_list
{
    QPushButton * back;
    QLabel *_1;
    score_list cl;
public:
    score_list_menu(QWidget *pt=0);

};

#endif // SCORE_LIST_MENU_H
