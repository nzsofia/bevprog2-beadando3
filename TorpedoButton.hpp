#ifndef TORPEDOBUTTON_HPP
#define TORPEDOBUTTON_HPP
#include "mainbutton.hpp"

class TorpedoButton: public MainButton
{
    bool aktiv; //lehet r� kattintani stb, ellenf�l t�bl�j�n akt�vak az elemek
    bool hajo;
    bool jelolve;
    bool sullyedt;
public:
    void draw() const;
    void eventHandler(const genv::event &ev);
};
#endif // TORPEDOBUTTON_HPP
