#include "choose.hpp"
#include <iostream>
#include <cmath>
using namespace genv;
using namespace std;

Choose::Choose(vector<string> _valasztek,int _x, int _y,int _meretx,int _merety):Widget(_x,_y,_meretx,_merety),valasztek(_valasztek)
{
    int maximum=0;
    for(string &szoveg: valasztek)
    {
        if(maximum<gout.twidth(szoveg)) maximum=gout.twidth(szoveg);
    }
    szelesseg=maximum+10+16;
    hossz=(gout.cascent()+gout.cdescent()+10)*3;
}
Choose::Choose(vector<string> _valasztek,int _x, int _y,int _meretx,int _merety, int _hossz):Widget(_x,_y,_meretx,_merety),valasztek(_valasztek),hossz(_hossz)
{
    int maximum=0;
    for(string &szoveg: valasztek)
    {
        if(maximum<gout.twidth(szoveg)) maximum=gout.twidth(szoveg);
    }
    szelesseg=maximum+10+16;
}

void Choose::draw() const
{
    gout<<color(0,0,0)<<move_to(x,y)<<box(meretx,merety)<<move_to(x,y+merety)<<box(szelesseg,hossz);
    if (selected && !legordul)
    {
        gout<<color(255,255,255)<<move_to(x,y)<<box(meretx,merety);
        gout<<color(51,15,255)<<move_to(x+1,y+1)<<box(meretx-2,merety-2);
        gout<<color(255,255,255)<<move_to(x+meretx-16,y)<<line(0,merety);
        gout<<move_to(x+meretx-16+2,y+2)<<line(16/2-2,merety-3)<<line(16/2-2,-(merety-3));
        gout<<color(255,255,255)<<move_to(x+(meretx-16)/2-gout.twidth(ertek)/2,y+merety/2+gout.cascent()/2)<<text(ertek);
    }
    else if(!selected && !legordul)
    {
        gout<<color(255,255,255)<<move_to(x,y)<<box(meretx,merety);
        gout<<color(51,153,255)<<move_to(x+1,y+1)<<box(meretx-2,merety-2);
        gout<<color(255,255,255)<<move_to(x+meretx-16,y)<<line(0,merety);
        gout<<move_to(x+meretx-16+2,y+2)<<line(16/2-2,merety-3)<<line(16/2-2,-(merety-3));
        gout<<color(255,255,255)<<move_to(x+(meretx-16)/2-gout.twidth(ertek)/2,y+merety/2+gout.cascent()/2)<<text(ertek);
    }
    else
    {
        gout<<color(255,255,255)<<move_to(x,y)<<box(meretx,merety);
        gout<<color(51,15,255)<<move_to(x+1,y+1)<<box(meretx-2,merety-2);
        gout<<color(255,255,255)<<move_to(x+meretx-16,y)<<line(0,merety);
        gout<<move_to(x+meretx-16+2,y+2)<<line(16/2-2,merety-3)<<line(16/2-2,-(merety-3));
        gout<<color(255,255,255)<<move_to(x+(meretx-16)/2-gout.twidth(ertek)/2,y+merety/2+gout.cascent()/2)<<text(ertek);
        for(int i=0; i<valasztek.size()-listakezdet; i++)
        {

            gout<<color(51,15,255);
            gout<<move_to(x,y+merety+(gout.cascent()+gout.cdescent()+10)*(i))<<box(szelesseg,(gout.cascent()+gout.cdescent()+10));
            if(valasztek[listakezdet+i]==ertek)
            {
                gout<<color(255,0,0);
                gout<<move_to(x,y+merety+(gout.cascent()+gout.cdescent()+10)*(i))<<box(szelesseg-16,(gout.cascent()+gout.cdescent()+10));
            }
            gout<<color(255,255,255)<<move_to(x+(szelesseg-16)/2-gout.twidth(valasztek[listakezdet+i])/2,y+merety+(gout.cascent()+gout.cdescent()+10)*(i)+(gout.cascent()+gout.cdescent()+10)/2+gout.cascent()/2)<<text(valasztek[listakezdet+i]);
            gout<<move_to(x+szelesseg-16,y+merety)<<line(0,hossz)<<genv::move(0,-hossz/2)<<line(16,0);
            gout<<move_to(x+szelesseg-16+2,y+merety+hossz/4)<<line(16/2-2,-(hossz/4-1))<<line(16/2-2,hossz/4-1);
            gout<<move_to(x+szelesseg-16+2,y+merety+3*hossz/4)<<line(16/2-2,hossz/4-1)<<line(16/2-2,-(hossz/4-1));
            if (i==valasztek.size()-listakezdet-1 && (gout.cascent()+gout.cdescent()+10)*(i+1)<hossz)
            {
                gout<<color(51,15,255)<<move_to(x,y+merety+(gout.cascent()+gout.cdescent()+10)*(i+1))<<box(szelesseg,hossz-(gout.cascent()+gout.cdescent()+10)*(i+1));
            }
            gout<<color(255,255,255);
            gout<<move_to(x+szelesseg-16,y+merety)<<line(0,hossz)<<genv::move(0,-hossz/2)<<line(16,0);
            gout<<move_to(x+szelesseg-16+2,y+merety+hossz/4)<<line(16/2-2,-(hossz/4-1))<<line(16/2-2,hossz/4-1);
            gout<<move_to(x+szelesseg-16+2,y+merety+3*hossz/4)<<line(16/2-2,hossz/4-1)<<line(16/2-2,-(hossz/4-1));
            if ((gout.cascent()+gout.cdescent()+10)*(i+1)>hossz)
            {
                gout<<move_to(x,y+merety+hossz)<<color(0,0,0)<<box(szelesseg,(gout.cascent()+gout.cdescent()+10)*(i+1)-hossz);
                break;
            }
        }
    }

}
void Choose::eventHandler(const genv::event &ev)
{
    if(ev.type==ev_mouse && ev.button==btn_left)
    {
        if(!isOver(ev.pos_x,ev.pos_y) && legordul && !(ev.pos_x>=x && ev.pos_x<=x+szelesseg && ev.pos_y>=y+merety && ev.pos_y<=y+merety+hossz))
        {
            legordul=false;
        }
        if(ev.pos_x>x+meretx-16 && ev.pos_x<x+meretx-1 && ev.pos_y>y+1 && ev.pos_y<y+merety-1)
        {
            if(legordul==true) legordul=false;
            else legordul=true;
            selected=true;
        }
        if(legordul)
        {
            if(ev.pos_x>x && ev.pos_x<x+szelesseg-16 && ev.pos_y>y+merety && ev.pos_y<y+merety+hossz)
            {
                if(listakezdet+(ev.pos_y-(y+merety))/(gout.cascent()+gout.cdescent()+10)<valasztek.size())
                {
                    ertek=valasztek[listakezdet+(ev.pos_y-(y+merety))/(gout.cascent()+gout.cdescent()+10)];
                    legordul=false;
                }
            }
            if(ev.pos_x>x+szelesseg-16 && ev.pos_x<x+szelesseg && ev.pos_y>y+merety && ev.pos_y<y+merety+hossz/2 && listakezdet>0)
            {
                listakezdet--;
            }
            if(ev.pos_x>x+szelesseg-16 && ev.pos_x<x+szelesseg && ev.pos_y>y+merety+hossz/2 && ev.pos_y<y+merety+hossz && listakezdet<=valasztek.size()-1-round(double(hossz)/double(gout.cascent()+gout.cdescent()+10)))
            {
                listakezdet++;
            }
        }
    }
    if(legordul)
    {
        if(ev.type==ev_key && ev.keycode==key_up && listakezdet>0)
        {
            listakezdet--;
        }
        if(ev.type==ev_key && ev.keycode==key_down && listakezdet<=valasztek.size()-1-round(double(hossz)/double(gout.cascent()+gout.cdescent()+10)))
        {
            listakezdet++;
        }
    }
}
string Choose::get_value() const
{
    return ertek;
}

