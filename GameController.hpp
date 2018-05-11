#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP
#include "window.hpp"
#include "mainbutton.hpp"
#include "TorpedoButton.hpp"
#include "inserttext.hpp"
#include "simpletext.hpp"
class GameController: public Window
{
    int kattintas_szam;
    int hajoszam;
    int sorszam=6;
    int oszlopszam=6;
    bool terminate=false;
    MainButton * play;
    MainButton * exit_button;
    InsertText * jatekos1_name_input;
    InsertText * jatekos2_name_input;
    SimpleText * jatekos1_name;
    SimpleText * jatekos2_name;
    MainButton * palyavalasztas1;
    MainButton * palyavalasztas2;
    MainButton * hajovalaszto;
    MainButton * irany;
    SimpleText * hajotipus;
    std::vector<std::vector<TorpedoButton*>> hajok; // 3 hajó benne (kölönbözõ hossz)
    std::vector<std::vector<TorpedoButton*>> palya1;
    std::vector<std::vector<TorpedoButton*>> palya2;
    MainButton * jatekindit;
public:
    GameController();
    void eventloop();
    void jatek_elokeszit();
    void kilep();
    void palya1_beallit();
    void hajo_veglegesit();
    void irany_beallit();
    void beallitas_hajokent(int sor, int oszlop, int jatekos);
    void palya2_beallit();
    void jatek();
};
#endif // GAMECONTROLLER_HPP
