#ifndef INSERTTEXT_HPP
#define INSERTTEXT_HPP
#include "widget.hpp"
class InsertText: public Widget
{
    std::string szoveg;
    int szov_veg=0;
public:
    InsertText(int _x,int _y, int _meretx, int _merety);
    void draw() const;
    void eventHandler(const genv::event &ev);
    std::string get_value() const;
};
#endif // INSERTTEXT_HPP
