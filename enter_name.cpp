#include "enter_name.h"
#include <QVBoxLayout>
#include "score.h"
Enter_name::Enter_name(QWidget *pt):QWidget(pt)
{
    ok=new QPushButton("OK");
    ok->setDisabled(1);
    per.bscore=Score::Score_Number;
    line=new QLineEdit;
    gameov =new QLabel("\tGAME OVER");
    gameov->setSizeIncrement(60,70);
    nam=new QLabel("    Please enter your name");
    QGridLayout *box=new QGridLayout;
    box->addWidget(gameov,0,3);
    box->addWidget(nam,1,3);
    box->addWidget(line,2,3);
    box->addWidget(ok,3,3);
    this->setLayout(box);
    this->setFixedSize(220,170);
    connect(line,SIGNAL(textChanged(QString)),this,SLOT(EnableBtn(QString)));
    connect(ok,SIGNAL(clicked(bool)),this,SLOT(okclicked()));
}


void Enter_name::EnableBtn(QString text)
{
    if(!text.isEmpty()) ok->setEnabled(true);
    else
    {
        ok->setDisabled(true);
    }
}
void Enter_name::okclicked()
{
    score_list m;

    per.name=line->text();
    m.insert(per);
    m.write_to_file();
    this->close();
}
