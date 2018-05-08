#ifndef TORPEDOBUTTON_HPP
#define TORPEDOBUTTON_HPP
#include "mainbutton.hpp"

class TorpedoButton: public MainButton
{
    bool aktiv; //lehet rá kattintani stb, ellenfél tábláján aktívak az elemek
    bool hajo;
    bool jelolve;
    bool sullyedt;
public:
    void draw() const;
    void eventHandler(const genv::event &ev);
};
#endif // TORPEDOBUTTON_HPP
