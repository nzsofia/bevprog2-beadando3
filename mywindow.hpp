#ifndef MYWINDOW_HPP
#define MYWINDOW_HPP
#include "window.hpp"
#include "widget.hpp"
#include "choose.hpp"
#include "numset.hpp"
#include "inserttext.hpp"
#include "simpletext.hpp"
#include "koord.hpp"
#include "button.hpp"
#include <string>
class MessageButton;
class Mywindow: public Window{
int szamertek;
SimpleText * egyszeru_szov;
Button * egy;
Button * ketto;
Button * harom;
Button * egyenlo;
Button * osszead;
std::string muvelet;
public:
    Mywindow();
    void szambead(std::string szam);
    void muvelet_beallito(std::string muv);
    void kiertekel();
    ~Mywindow();
};
#endif // MYWINDOW_HPP
