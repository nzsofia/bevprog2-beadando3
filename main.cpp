#include "graphics.hpp"
#include <fstream>
#include <vector>
#include <time.h>
#include "widget.hpp"
#include "choose.hpp"
#include "window.hpp"
#include "GameController.hpp"
#include <iostream>
using namespace genv;
using namespace std;

int main()
{
    gout.open(max_x,max_y);
    srand(time(0));
    //gout<<move_to(20,30)<<color(255,255,255)<<text("Menteni az 's' billenytû megnyomásával lehet.");
    //event ev;
    /*ofstream ertekek_file;
    ertekek_file.open("ertekek.txt");
    vector<Widget*> tomb;
    Widget * Szamvalaszt1=new NumSet(5,20,62,100,30,-97,123);
    Widget * Szamvalaszt2=new NumSet(6,150,65,110,35,-29,80);
    vector<string> v= {"alma","korte","meggy","mango","malna","kiwi","barack","dio","eper"};
    vector<string> z= {"kutya","macska","lo","malac","panda","majom","foka","roka"};
    Widget * Kivalaszto1=new Choose(v,62,165,72,40,119);
    Widget * Kivalaszto2=new Choose(z,200,210,85,40);
    tomb.push_back(Szamvalaszt1);
    tomb.push_back(Szamvalaszt2);
    tomb.push_back(Kivalaszto1);
    tomb.push_back(Kivalaszto2);

    ertekek_file.close();
    for (int i=tomb.size()-1; i>-1; i--)
    {
        delete tomb[i];
        tomb[i]=NULL;
        tomb.erase(tomb.begin()+i);
    }*/
    GameController * win1= new GameController();
    cout << "constructor?" << endl;
    win1->eventloop();
    return 0;
}
