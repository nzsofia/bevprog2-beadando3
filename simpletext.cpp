#include "simpletext.hpp"
using namespace std;
using namespace genv;
SimpleText::SimpleText(string kezdeti_szov, int _x, int _y, int _meretx, int _merety)
{
    meretx=_meretx;
    merety=_merety;
    x=_x;
    y=_y;
    szoveg=kezdeti_szov;
}
void SimpleText::draw() const
{
    gout<<color(255,255,255)<<move_to(x,y)<<box(meretx,merety);
    if(selected) gout<<color(51,15,255);
    else gout<<color(51,153,255);
    gout<<move_to(x+1,y+1)<<box(meretx-2,merety-2);
    gout<<color(255,255,255)<<move_to(x+meretx/2-gout.twidth(szoveg)/2,y+merety/2+gout.cascent()/2)<<text(szoveg);
}

void SimpleText::eventHandler(const event &ev)
{
    if (ev.type==ev_mouse && ev.button==btn_left) isOver(ev.pos_x,ev.pos_y);
}
void SimpleText::setText(const string szov)
{
    szoveg=szoveg+szov;
}
void SimpleText::kiurit()
{
    szoveg="";
}
string SimpleText::get_value() const
{
    return szoveg;
}
