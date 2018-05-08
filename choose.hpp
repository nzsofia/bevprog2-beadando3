#ifndef CHOOSE_HPP
#define CHOOSE_HPP
#include <vector>
#include <string>
#include "widget.hpp"
#include "koord.hpp"
class Choose: public Widget
{
    std::vector<Koord> valasztek;
    int szelesseg;
    int hossz;
    bool legordul=false;
    int listakezdet=0;
    std::string ertek;
public:
    Choose(std::vector<Koord> _valasztek,int _x, int _y,int _meretx,int _merety);
    Choose(std::vector<Koord> _valasztek, int _x, int _y,int _meretx,int _merety,int _hossz);
    void draw() const override;
    void eventHandler(const genv::event &ev);
    std::string get_value() const override;
    void hozzaad(const std::string val);
    void torol(const int elem);
    int get_darab();
};
#endif // CHOOSE_HPP
