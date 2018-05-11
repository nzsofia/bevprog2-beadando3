#include "widget.hpp"

Widget::Widget()
{
    meretx=rand()%40+20+16;
    merety=rand()%40+20+16;
    x=rand()%(max_x-meretx);
    y=rand()%(max_y-merety);
}
Widget::Widget(int _x, int _y,int _meretx,int _merety)
{
    x=_x;
    y=_y;
    meretx=_meretx;
    merety=_merety;
}
bool Widget::isOver(int px,int py) const
{
    if(px>=x && px<=x+meretx && py>=y && py<=y+merety)
    {
        return true;
    }
    return false;
}
void Widget::set_select(bool selected_val)
{
    selected=selected_val;
}
void Widget::set_position(int new_x, int new_y)
{
    x=new_x;
    y=new_y;
}

