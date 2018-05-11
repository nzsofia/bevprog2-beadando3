#include "mainbutton.hpp"

using namespace genv;
using namespace std;

MainButton::MainButton(int _x, int _y, int _meretx, int _merety,std::string _felirat, std::function <void()> _fv,bool _aktiv): Widget(_x,_y,_meretx,_merety)
{
    fv=_fv;
    felirat=_felirat;
    aktiv=_aktiv;
}
void MainButton::draw() const
{
    gout<<color(255,255,255)<<move_to(x,y)<<box(meretx,merety);
    if(selected) gout<<color(51,15,255);
    else gout<<color(51,153,255);
    gout<<move_to(x+1,y+1)<<box(meretx-2,merety-2);
    gout<<color(255,255,255)<<move_to(x+meretx/2-gout.twidth(felirat)/2,y+merety/2+gout.cascent()/2)<<text(felirat);
}
void MainButton::eventHandler(const event &ev)
{
    if(aktiv)
    {
        if (ev.type==ev_mouse && ev.button==btn_left){
            if(isOver(ev.pos_x,ev.pos_y)) set_select(true);
            else set_select(false);
        }
    }
    if (selected){
        action();
        set_select(false);
    }
}
void MainButton::action()
{
    fv();
}
void MainButton::set_felirat(string mod_felirat)
{
    felirat=mod_felirat;
}
void MainButton::set_aktiv(bool aktiv_val)
{
    aktiv=aktiv_val;
}
std::string MainButton::get_value() const
{
    return felirat;
}
