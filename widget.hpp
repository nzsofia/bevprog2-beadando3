#ifndef WIDGET_HPP
#define WIDGET_HPP
#include <cstdlib>
#include <sstream>
#include "graphics.hpp"

const int max_x=800;
const int max_y=600;
class Widget
{
protected:
    int x;
    int y;
    int meretx,merety;
    bool selected=false;
public:
    Widget();
    Widget(int _x, int _y,int _meretx,int _merety);
    virtual void draw() const =0;
    virtual void eventHandler(const genv::event &ev)=0;
    bool isOver(int px,int py) const;
    void set_select(bool selected_val);
    void set_position(int new_x, int new_y);
    virtual std::string get_value() const =0;

};
#endif // WIDGET_HPP
