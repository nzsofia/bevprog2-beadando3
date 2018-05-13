#include "TorpedoButton.hpp"

using namespace genv;
TorpedoButton::TorpedoButton(int _x, int _y, int _meretx, int _merety, std::string _felirat, std::function <void()> _fv,bool _aktiv,int _sor,int _oszlop):
    MainButton(_x,_y,_meretx,_merety,_felirat, _fv,_aktiv),sor(_sor),oszlop(_oszlop)
{
    aktiv=_aktiv;
    hajo=sullyedt=jelolve=false;
}
void TorpedoButton::draw() const
{
    if (aktiv)
    {
        if(jelolve)
        {
            if(hajo)
            {
                if (!sullyedt) gout<<color(255,140,0); //talalt jeloles
                else gout<<color(0,255,0); //sullyedt
            }
            else  gout<<color(0,0,255); //nem talalt jeloles (viz)
            gout<<move_to(x+1,y+1)<<box(meretx-2,merety-2);
        }
        else gout<<color(0,0,0)<<move_to(x+1,y+1)<<box(meretx-2,merety-2);
        gout<<color(211,211,211); //keret szin
    }
    else
    {
        gout<<color(0,0,255);//viz
        if (jelolve || hajo)
        {
            if (hajo && !sullyedt) gout<<color(255,255,255); //hajó szín
            else if (hajo && sullyedt) gout<<color(255,0,0); //elsüllyedt hajó
            else gout<<color(0,0,120); //jelolt viz
        }
        gout<<move_to(x+1,y+1)<<box(meretx-2,merety-2);
        if (hajo && jelolve && !sullyedt)
        {
            gout<<color(255,0,0)<<move_to(x+meretx/2,y)<<line(0,merety)<<move_to(x,y+merety/2)<<line(meretx,0); //piros kereszt a hajon
        }
        gout<<color(57,255,20); //keret szin
    }
    gout<<move_to(x,y)<<line(meretx,0)<<line(0,merety)<<line(-meretx,0)<<line(0,-merety); //keret rajzolas
}
void TorpedoButton::eventHandler(const event &ev)
{
if (ev.type==ev_mouse && ev.button==btn_left){
        if(isOver(ev.pos_x,ev.pos_y)) set_select(true);
        else set_select(false);
    }
    if (selected){
        action(); //lehet be kéne rakni az aktívba, attól függ mit fog csinálni
        set_select(false);
    }
}
bool TorpedoButton::get_hajo()
{
    return hajo;
}
void TorpedoButton::set_hajo(bool hajo_val)
{
    hajo=hajo_val;
}
int TorpedoButton::get_sor()
{
    return sor;
}
int TorpedoButton::get_oszlop()
{
    return oszlop;
}
void TorpedoButton::set_fv(std::function <void()> fv_mod)
{
    fv=fv_mod;
}
void TorpedoButton::set_jelolve(bool jelolve_mod)
{
    jelolve=jelolve_mod;
}
bool TorpedoButton::get_jelolve()
{
    return jelolve;
}
void TorpedoButton::set_sullyedt(bool sullyedt_mod)
{
    sullyedt=sullyedt_mod;
}
