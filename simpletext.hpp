#ifndef SIMPLETEXT_HPP
#define SIMPLETEXT_HPP
#include "widget.hpp"
#include <string>
class SimpleText: public Widget{
std::string szoveg;
public:
SimpleText(std::string kezdeti_szov,int _x, int _y, int _meretx, int _merety);
void draw() const override;
void eventHandler(const genv::event &ev) override;
void setText(const std::string szov);
void kiurit();
std::string get_value() const;

};
#endif // SIMPLETEXT_HPP
