#ifndef TORPEDOBUTTON_HPP
#define TORPEDOBUTTON_HPP
#include "mainbutton.hpp"

class TorpedoButton: public MainButton
{
    bool hajo;
    bool jelolve;//rálőtt az ellenfél
    bool sullyedt;
    int sor;
    int oszlop;
public:
    TorpedoButton(int _x, int _y, int _meretx, int _merety, std::string _felirat, std::function <void()> _fv,bool _aktiv,int _sor,int _oszlop);
    void draw() const;
    void eventHandler(const genv::event &ev);
    bool get_hajo();
    void set_hajo(bool hajo_val);
    int get_sor();
    int get_oszlop();
    void set_fv(std::function <void()> fv_mod);
    void set_jelolve(bool jelolve_mod);
    bool get_jelolve();
    void set_sullyedt(bool sullyedt_mod);
};
#endif // TORPEDOBUTTON_HPP
