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
    std::vector<std::vector<TorpedoButton*>> hajok1; // 3 hajó benne (kölönbözõ hossz)
    std::vector<std::vector<TorpedoButton*>> hajok2; // 3 hajó benne (kölönbözõ hossz)
    std::vector<std::vector<TorpedoButton*>> palya1;
    std::vector<std::vector<TorpedoButton*>> palya2;
    MainButton * jatekindit;
    MainButton * jatekos_valt;
    SimpleText * nyertes;
public:
    GameController();
    void eventloop();
    void uj_kepernyo();
    void jatek_elokeszit();
    void kilep();
    void kozos_palyabeallitas(bool palya1_e);
    void palya1_beallit();
    void kovetkezo_hajo_beallit();
    void irany_beallit();
    void beallitas_hajokent(int sor, int oszlop, int jatekos);
    void palya2_beallit();
    void jatek();
    void jatekos_valto();
    void lovoldoz(int sor, int oszlop, int jatekos);
};
#endif // GAMECONTROLLER_HPP
