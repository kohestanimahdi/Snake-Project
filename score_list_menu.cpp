#include "score_list_menu.h"
#include <QGridLayout>

score_list_menu::score_list_menu(QWidget *pt):QWidget(pt)
{
    back = new QPushButton("CLOSE");

    this->setFixedSize(400,700);
    int k=1;
    QGridLayout *sgrid=new QGridLayout;
    set<QString> ma;
    for(auto i=cl.begin();i!=cl.end()&&k<11;i++)
    {
        if(ma.find(i->name) != ma.end()) continue;
        ma.insert(i->name);
        _1=new QLabel;
             _1->setText(QString::number(k)+"-\t"+i->name+"\t"+QString::number(i->bscore));
        k++;
        sgrid->addWidget(_1,k+1,2);

    }

    sgrid->addWidget(back,12,3);

    this->setLayout(sgrid);

    connect(back,SIGNAL(clicked(bool)),this,SLOT(close()));

}

