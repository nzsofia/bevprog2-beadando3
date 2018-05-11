#include "inserttext.hpp"
#include <string>

using namespace genv;
using namespace std;

InsertText::InsertText(int _x,int _y, int _meretx, int _merety):Widget(_x,_y,_meretx,_merety){}
void InsertText::draw() const
{
    gout<<color(255,255,255)<<move_to(x,y)<<box(meretx,merety);
        if(selected) gout<<color(51,15,255);
        else gout<<color(51,153,255);
        gout<<move_to(x+1,y+1)<<box(meretx-2,merety-2);
        if(gout.twidth(szoveg)>meretx-4)
        {
            string kiirando="";
            int i=0;
            while(gout.twidth(kiirando)<meretx-4)
            {
                kiirando=szoveg[szoveg.size()-1-szov_veg-i]+kiirando;
                i++;
            }
            gout<<color(255,255,255)<<move_to(x+2,y+merety/2+gout.cascent()/2)<<text(kiirando);
        }
        else gout<<color(255,255,255)<<move_to(x+2,y+merety/2+gout.cascent()/2)<<text(szoveg);
}
void InsertText::eventHandler(const event &ev)
{
    if (ev.type==ev_mouse && ev.button==btn_left)
    {
        if(isOver(ev.pos_x,ev.pos_y)) set_select(true);
        else set_select(false);
    }
    if (selected)
        {
            if(ev.type==ev_key && ev.keycode>=20 && ev.keycode<=126 && ev.keycode!=key_backspace && ev.keycode!=key_right && ev.keycode!=key_left)//>=20 és <=126
            {
                char a=char(ev.keycode);
                if(szoveg.length()>0) szoveg.pop_back();
                szoveg=szoveg+a+'|';
            }
            if(ev.type==ev_key && ev.keycode==key_backspace && szoveg.length()>1)
            {
                szoveg.pop_back();
                szoveg.pop_back();
                szoveg+='|';
            }
            if (ev.type==ev_key && ev.keycode==key_right && szov_veg>0)
            {
                szov_veg--;
            }
            if (ev.type==ev_key && ev.keycode==key_left && szov_veg<szoveg.length())
            {
                szov_veg++;
            }
        }
}
string InsertText::get_value() const
{
    string kurzormentes=szoveg;
    kurzormentes.pop_back();
    return kurzormentes;
}
