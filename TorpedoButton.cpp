#include "TorpedoButton.hpp"

void TorpedoButton::draw() const
{
    if (aktiv)
    {
        if(jelolve)
        {
            if(hajo)
            {
                if (!sullyedt) gout<<color(255,255,0); //talalt jeloles
                else gout<<color(0,255,0); //sullyedt
            }
            else  gout<<color(139,0,139); //nem talalt jeloles
            gout<<move_to(x+1,y+1)<<box(meretx-2,merety-2);
        }
        gout<<color(211,211,211); //keret szin
    }
    else
    {
        if (jelolve || hajo)
        {
            if (hajo && !sullyedt) gout<<color(0,0,255);
            else if (hajo && sullyedt) gout<<color(255,0,0);
            else gout<<color(128,128,128);
            gout<<move_to(x+1,y+1)<<box(meretx-2,merety-2);
        }
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
    }
    if (selected){
        if(aktiv)
        {
            if(!jelolve) jelolve=true;
        }
        action();
        set_select(false);
    }
}
