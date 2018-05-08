#include "mywindow.hpp"
#include <sstream>

using namespace genv;
using namespace std;

inline int stoi(string a)
{
    stringstream ss;
    ss<<a;
    int b;
    ss>>b;
    return b;
}
inline string itos(int a)
{
    stringstream ss;
    ss<<a;
    string b;
    ss>>b;
    return b;
}
Mywindow::Mywindow()
{
    egy=new Button(10,100,45,45,"1",[this](){this->szambead("1");});
    ketto=new Button(60,100,45,45,"2",[this](){this->szambead("2");});
    harom=new Button(110,100,45,45,"3",[this](){this->szambead("3");});
    osszead=new Button(110,150,45,45,"+",[this](){this->muvelet_beallito("+");});
    egyenlo=new Button(170,150,45,45,"=",[this](){this->kiertekel();});
    egyszeru_szov=new SimpleText("",50,50,180,40);
    widgetek.push_back(egy);
    widgetek.push_back(ketto);
    widgetek.push_back(harom);
    widgetek.push_back(egyszeru_szov);
    widgetek.push_back(osszead);
    widgetek.push_back(egyenlo);
}

void Mywindow::szambead(string szam)
{
    egyszeru_szov->setText(szam);
}
void Mywindow::muvelet_beallito(string muv)
{
    muvelet=muv;
    szamertek=stoi(egyszeru_szov->get_value());
    egyszeru_szov->kiurit();
}
void Mywindow::kiertekel()
{
    int ertek2=stoi(egyszeru_szov->get_value());
    if (muvelet=="+")
    {
        szamertek=szamertek+ertek2;
    }
    egyszeru_szov->kiurit();
    egyszeru_szov->setText(itos(szamertek));
}
Mywindow::~Mywindow()
{
     for (int i=widgetek.size()-1; i>-1; i--)
    {
        delete widgetek[i];
        widgetek[i]=NULL;
        widgetek.erase(widgetek.begin()+i);
    }
    egy=NULL;
    ketto=NULL;
    harom=NULL;
    osszead=NULL;
    egyenlo=NULL;
}

