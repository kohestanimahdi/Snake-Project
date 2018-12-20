#ifndef PERSON_SCORE_H
#define PERSON_SCORE_H
#include <set>
#include <fstream>
#include <QString>
#include <QStringList>

using namespace std;

class person_score
{
public:
    QString name;
    int bscore;
    person_score();
};


inline bool operator < (person_score  const & a , person_score  const & b)
{
    if(a.bscore>b.bscore) return true;
    if(a.bscore<b.bscore) return false;
    if(a.name>b.name) return true;
    return false;
}
class score_list:public std::set<person_score>
{
    void fill_from_file();
public:
    void write_to_file();
    score_list()
    {
        fill_from_file();
    }
    ~score_list()
    {
//        write_to_file();
    }


};
#endif // PERSON_SCORE_H
