#ifndef TORPEDOBUTTON_HPP
#define TORPEDOBUTTON_HPP
#include "mainbutton.hpp"

class TorpedoButton: public MainButton
{
    //lehet rá kattintani stb, ellenfél tábláján aktívak az elemek
    bool hajo;
    bool jelolve;
    bool sullyedt;
    int sor;
    int oszlop;
public:
    TorpedoButton(int _x, int _y, int _meretx, int _merety, std::string _felirat, std::function <void()> _fv,int _sor,int _oszlop);
    void draw() const;
    void eventHandler(const genv::event &ev);
    bool get_hajo();
    void set_hajo(bool hajo_val);
    int get_sor();
    int get_oszlop();
};
#endif // TORPEDOBUTTON_HPP
