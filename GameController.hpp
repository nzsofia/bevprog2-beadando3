#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP
#include "mainbutton.hpp"
#include "TorpedoButton.hpp"
#include "inserttext.hpp"
#include "simpletext.hpp"
#include <vector>

class GameController
{
    int kattintas_szam; //meghatározza, hogy az adott képernyőn hányat lehet kattintani
    int hajoszam;
    int sorszam=6;
    int oszlopszam=6;
    bool terminate=false; //ha a widget vektorban változás történt, a ciklus újraindtását kezdeményezi
    std::vector<Widget*> widgetek; //felületen megjelenő widgetek tárolása
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
    std::vector<std::vector<TorpedoButton*>> hajok1; // egyes játékos hajóinak tárolója
    std::vector<std::vector<TorpedoButton*>> hajok2; // kettes játékos hajóinak tárolója
    std::vector<std::vector<TorpedoButton*>> palya1;
    std::vector<std::vector<TorpedoButton*>> palya2;
    MainButton * jatekindit;
    MainButton * jatekos_valt; //váltja hogy épp melyik játékos van soron
    SimpleText * nyertes;
public:
    GameController();
    void eventloop();
    void uj_kepernyo(); //új felépítésű képernyő megjelenését segíti elő
    void jatek_elokeszit();
    void kilep();
    void kozos_palyabeallitas(bool palya1_e);//első és második pálya beállításának közös lépései
    void palya1_beallit();
    void kovetkezo_hajo_beallit();//következő hajó letételét teszi lehetővé
    void irany_beallit();//beállítja hogy vízszintes vagy függőleges hajót lehessen lerakni
    void beallitas_hajokent(int sor, int oszlop, int jatekos); //hajóelem felvétele a hajók közé
    void palya2_beallit();
    void jatek();//tényleges játék megkezdését segíti
    void jatekos_valto();//váltja hogy épp melyik játékos van soron
    void lovoldoz(int sor, int oszlop, int jatekos);//játék során a másik pályájára lövést teszi lehetővé
    ~GameController();
};
#endif // GAMECONTROLLER_HPP
