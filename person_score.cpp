#include "person_score.h"


person_score::person_score()
{

}

void score_list::fill_from_file()
{
    std::ifstream scorelist("scorelist.txt");
    if(!scorelist.is_open()) return;
    while(!scorelist.eof())
    {
        char sc[500];
        scorelist.getline(sc,500);
        QStringList cl=QString(sc).split(",");
        if(cl.size()!=2) continue;
        person_score tmp;
        tmp.name=cl[0];
        tmp.bscore=cl[1].toInt();
        insert(tmp);
    }
    scorelist.close();
}

void score_list::write_to_file()
{
    std::ofstream scorelist("scorelist.txt");
    if(!scorelist.is_open()) return;
    for(auto i=begin();i!=end();++i)
    {
        scorelist<<i->name.toStdString()<<","<<i->bscore<<endl;
    }
    scorelist.close();

}
