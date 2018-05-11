#include "GameController.hpp"

GameController::GameController()
{
    play= new MainButton(max_x/2-20,max_y/4,40,30, "Play",[this](){this->jatek_elokeszit();});
    exit= new MainButton(max_x/2-200,3*max_y/4,40,30, "Exit",[this](){this->kilep();});
    jatekos1_name=new SimpleText("1. jatekos neve:",max_x/2-30,10,60,30);
    jatekos2_name=new SimpleText("2. jatekos neve:",max_x/2-30,80,60,30);
    jatekos1_name_input=new InsertText(max_x/2-30,45,60,30);
    jatekos2_name_input=new InsertText(max_x/2-30,115,60,30);
    palyavalasztas1=new MainButton(max_x/2-40,max_y-50,80,30,"1. jatekos palya beallitasa", [this](){this->palya1_beallit();});
    hajotipus=new SimpleText("2 elemu hajo",max_x-100,10,60,30);
    irany=new MainButton(max_x-100,45,60,30,"vizszintes",[this](){this->irany_beallit();});
    hajovalaszto=new MainButton(max_x-100,80,60,30,"Hajo bevitele",[this](){this->hajo_veglegesit();});
    palyavalasztas2=new MainButton(max_x/2-40,max_y-50,80,30,"2. jatekos palya beallitasa", [this](){this->palya2_beallit();});
    jatekindit=new MainButton(max_x/2-40,max_y-50,80,30,"Jatek inditasa", [this](){this->jatek();});
    for (int i=0;i<hajok.size();i++)
    {
        vector<TorpedoButton*> hajo(i+2);
        hajok.push_back(hajo);
    }
    for (int i=0;i<palya1.size();i++)
    {
        for(int j=0; j<palya1[i].size();j++)
        {
            palya1[i][j].push_back(new TorpedoButton(10+i*10,15+i*10,10,10,"",[this](){this->beallitas_hajokent(i,j,1);}))
            palya1[i][j].push_back(new TorpedoButton(80+i*10,15+i*10,10,10,"",[this](){this->beallitas_hajokent(i,j,2);}))
        }
    }
}
void GameController::eventloop()
{
    event ev;
    while(gin >> ev)
    {
        for (int i=0; i<widgetek.size(); i++)
        {
            widgetek[i]->eventHandler(ev);
            widgetek[i]->draw();
        }
        gout<<refresh;
    }

}
