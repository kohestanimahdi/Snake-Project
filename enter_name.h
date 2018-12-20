#ifndef ENTER_NAME_H
#define ENTER_NAME_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include "person_score.h"
#include <QLabel>

class Enter_name:public QWidget
{
    Q_OBJECT
public:
    Enter_name(QWidget *pt=0);
    QPushButton *ok;
    QLineEdit *line;
    QLabel *nam;
    QLabel *gameov;
    person_score per;
private slots:
    void EnableBtn(QString);
    void okclicked();
};

#endif // ENTER_NAME_H
