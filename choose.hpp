#ifndef CHOOSE_HPP
#define CHOOSE_HPP
#include <vector>
#include <string>
#include "widget.hpp"
class Choose: public Widget
{
    std::vector<std::string> valasztek;
    int szelesseg;
    int hossz;
    bool legordul=false;
    int listakezdet=0;
    std::string ertek;
public:
    Choose(std::vector<std::string> _valasztek,int _x, int _y,int _meretx,int _merety);
    Choose(std::vector<std::string> _valasztek, int _x, int _y,int _meretx,int _merety,int _hossz);
    void draw() const override;
    void eventHandler(const genv::event &ev);
    std::string get_value() const override;
};
#endif // CHOOSE_HPP
