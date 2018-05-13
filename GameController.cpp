#include "GameController.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;
using namespace genv;

inline int stoi(string a)
{
    stringstream ss;
    ss<<a;
    int b;
    ss>>b;
    return b;
}
inline string itos(int a)
{
    stringstream ss;
    ss<<a;
    string b;
    ss>>b;
    return b;
}
GameController::GameController()
{
    play= new MainButton(max_x/2-50,max_y/2-33,100,30, "Play",[this]()
    {
        this->jatek_elokeszit();
    },true);
    exit_button= new MainButton(max_x/2-50,max_y/2+3,100,30, "Exit",[this]()
    {
        this->kilep();
    },true);
    jatekos1_name=new SimpleText("1. jatekos neve:",max_x/2-70,10,140,30);
    jatekos2_name=new SimpleText("2. jatekos neve:",max_x/2-70,80,140,30);
    jatekos1_name_input=new InsertText(max_x/2-30,45,60,30);
    jatekos2_name_input=new InsertText(max_x/2-30,115,60,30);
    palyavalasztas1=new MainButton(max_x/2-120,max_y-50,240,30,"1. jatekos palya beallitasa", [this]()
    {
        this->palya1_beallit();
    },true);
    hajotipus=new SimpleText("2 elemu hajo",max_x-180,10,160,30);
    irany=new MainButton(max_x-180,45,100,30,"vizszintes",[this]()
    {
        this->irany_beallit();
    },true);
    hajovalaszto=new MainButton(max_x-180,80,120,30,"Kovetkezo hajo",[this]()
    {
        this->kovetkezo_hajo_beallit();
    },true);
    palyavalasztas2=new MainButton(max_x/2-120,max_y-50,240,30,"2. jatekos palya beallitasa", [this]()
    {
        this->palya2_beallit();
    },true);
    jatekindit=new MainButton(max_x/2-60,max_y-50,120,30,"Jatek inditasa", [this]()
    {
        this->jatek();
    },true);
    jatekos_valt=new MainButton(max_x/2-60,max_y-50,120,30,"Jatekos valtas", [this]()
    {
        this->jatekos_valto();
    },true);
    nyertes=new SimpleText("A nyertes: ", max_x/2-130,15,260,30);
    palya1=vector<vector<TorpedoButton*>> (sorszam,vector<TorpedoButton*> (oszlopszam));
    palya2=vector<vector<TorpedoButton*>> (sorszam,vector<TorpedoButton*> (oszlopszam));
    for (int i=0; i<palya1.size(); i++)
    {
        for(int j=0; j<palya1[i].size(); j++)
        {
            palya1[i][j]=new TorpedoButton(10+j*60,150+i*60,60,60,"",[this,i,j]()
            {
                this->beallitas_hajokent(i,j,1);
            },false,i,j);
            palya2[i][j]=new TorpedoButton(420+j*60,150+i*60,60,60,"",[this,i,j](){this->beallitas_hajokent(i,j,2);},false,i,j);
        }
    }
    widgetek.push_back(play);
    widgetek.push_back(exit_button);
}
void GameController::eventloop()
{
    event ev;
    while(gin >> ev)
    {
        for (int i=0; i<widgetek.size(); i++)
        {
            widgetek[i]->eventHandler(ev);
            if(terminate) break;
            widgetek[i]->draw();
        }
        terminate=false;
        gout<<refresh;
    }

}
void GameController::jatek_elokeszit()
{
    widgetek.clear();
    terminate=true;
    gout<<move_to(0,0)<<color(0,0,0)<<box(max_x,max_y);
    hajok1.clear();
    hajok2.clear();
    hajok1=vector<vector<TorpedoButton*>>(3);
    hajok2=vector<vector<TorpedoButton*>>(3);
    for (int i=0; i<hajok1.size(); i++)
    {
        vector<TorpedoButton*> hajo(i+2);
        hajok1[i]=hajo;
        hajok2[i]=hajo;
    }
    for (int i=0; i<palya1.size(); i++)
    {
        for(int j=0; j<palya1[i].size(); j++)
        {
            delete palya1[i][j];
            palya1[i][j]=new TorpedoButton(10+j*60,150+i*60,60,60,"",[this,i,j]()
            {
                this->beallitas_hajokent(i,j,1);
            },false,i,j);
            delete palya2[i][j];
            palya2[i][j]=new TorpedoButton(420+j*60,150+i*60,60,60,"",[this,i,j](){this->beallitas_hajokent(i,j,2);},false,i,j);
        }
    }
    jatekos1_name->set_position(max_x/2-70,10);
    jatekos1_name->kiurit();
    jatekos1_name->setText("1. jatekos neve:");
    jatekos2_name->set_position(max_x/2-70,80);
    jatekos2_name->kiurit();
    jatekos2_name->setText("2. jatekos neve:");
    widgetek.push_back(jatekos1_name);
    widgetek.push_back(jatekos2_name);
    widgetek.push_back(jatekos1_name_input);
    widgetek.push_back(jatekos2_name_input);
    widgetek.push_back(palyavalasztas1);
}
void GameController::kilep()
{
    exit(0);
}
void GameController::palya1_beallit()
{
    jatekos1_name->kiurit();
    jatekos2_name->kiurit();
    if(jatekos1_name_input->get_value().length()==0) jatekos1_name->setText("Jatekos 1");
    else jatekos1_name->setText(jatekos1_name_input->get_value());
    if(jatekos2_name_input->get_value().length()==0) jatekos2_name->setText("Jatekos 2");
    else jatekos2_name->setText(jatekos2_name_input->get_value());
    widgetek.clear();
    terminate=true;
    gout<<move_to(0,0)<<color(0,0,0)<<box(max_x,max_y);
    for (int i=0; i<palya1.size(); i++)
    {
        for (int j=0; j<palya1[i].size(); j++)
        {
            widgetek.push_back(palya1[i][j]);
        }
    }
    widgetek.push_back(palyavalasztas2);
    widgetek.push_back(hajovalaszto);
    irany->set_felirat("vizszintes");
    widgetek.push_back(irany);
    widgetek.push_back(jatekos1_name);
    kattintas_szam=hajok1[0].size();
    hajotipus->kiurit();
    hajotipus->setText(itos(kattintas_szam)+" elemu hajo");
    widgetek.push_back(hajotipus);
    hajoszam=0;
}
void GameController::kovetkezo_hajo_beallit()
{
    if (kattintas_szam==0)
    {
        if (hajoszam<hajok1.size()-1)
        {
            hajoszam++;
            kattintas_szam=hajok1[hajoszam].size();
            hajotipus->kiurit();
            hajotipus->setText(itos(kattintas_szam)+" elemu hajo");
            irany->set_aktiv(true);
        }
        else
        {
            hajotipus->kiurit();
            hajotipus->setText("nincs tobb hajo");
        }
    }
}
void GameController::irany_beallit()
{
    if (irany->get_value()=="vizszintes") irany->set_felirat("fuggoleges");
    else irany->set_felirat("vizszintes");
}
void GameController::beallitas_hajokent(int sor, int oszlop, int jatekos)
{
    if (kattintas_szam>0)
    {
        vector<vector<TorpedoButton*>> * palya;
        vector<vector<TorpedoButton*>> * hajok;
        if (jatekos==1)
        {
            palya= &palya1;
            hajok= &hajok1;
        }
        else {palya= &palya2; hajok= &hajok2;}
        if((*palya)[sor][oszlop]->get_hajo()==false)
        {
            if(irany->get_value()=="vizszintes")
            {
                if(kattintas_szam==(*hajok)[hajoszam].size() && (oszlop-kattintas_szam+1>=0 || oszlop+kattintas_szam-1<oszlopszam))
                {
                    bool utban_van_hajo=false;
                    int helyek_szama=1;
                    int maxi;
                    oszlop+kattintas_szam-1>oszlopszam ? maxi=oszlopszam : maxi= oszlop+kattintas_szam-1;
                    for (int i=oszlop-kattintas_szam+1<0 ? 0 : oszlop-kattintas_szam+1; i<maxi; i++)
                    {
                        if ((*palya)[sor][i]->get_hajo())
                        {
                            utban_van_hajo=true;
                            if (helyek_szama<kattintas_szam) helyek_szama=1;
                        }
                        else helyek_szama++;
                    }
                    if(helyek_szama>=kattintas_szam)
                    {
                        (*palya)[sor][oszlop]->set_hajo(true);
                        (*hajok)[hajoszam][kattintas_szam-1]=(*palya)[sor][oszlop];
                        irany->set_aktiv(false);
                        kattintas_szam--;
                    }
                }
                else if(kattintas_szam<(*hajok)[hajoszam].size() && sor==(*hajok)[hajoszam][kattintas_szam]->get_sor()) //abban a sorban van ahol a hajo többi eleme
                {
                    int elotte;
                    int utana;
                    oszlop-1<0 ? elotte=1 : elotte=oszlop-1;
                    oszlop+1>oszlopszam-1 ? utana=oszlopszam-2 : utana=oszlop+1;
                    if((*palya)[sor][elotte]==(*hajok)[hajoszam][kattintas_szam] || (*palya)[sor][elotte]==(*hajok)[hajoszam][(*hajok)[hajoszam].size()-1] || (*palya)[sor][utana]==(*hajok)[hajoszam][kattintas_szam] || (*palya)[sor][utana]==(*hajok)[hajoszam][(*hajok)[hajoszam].size()-1])
                    {
                        (*palya)[sor][oszlop]->set_hajo(true);
                        (*hajok)[hajoszam][kattintas_szam-1]=(*palya)[sor][oszlop];
                        kattintas_szam--;
                    }
                }
            }
            else
            {
                if(kattintas_szam==(*hajok)[hajoszam].size() && (sor-kattintas_szam+1>=0 || sor+kattintas_szam-1<sorszam))
                {
                    bool utban_van_hajo=false;
                    int maxi;
                    int helyek_szama=1;
                    sor+kattintas_szam-1>sorszam ? maxi=sorszam : maxi= sor+kattintas_szam-1;
                    for (int i=sor-kattintas_szam+1<0 ? 0 : sor-kattintas_szam+1; i<maxi; i++)
                    {
                        if ((*palya)[i][oszlop]->get_hajo())
                        {
                            utban_van_hajo=true;
                            if (helyek_szama<kattintas_szam) helyek_szama=1;
                        }
                        else helyek_szama++;
                    }
                    if(helyek_szama>=kattintas_szam)
                    {
                        (*palya)[sor][oszlop]->set_hajo(true);
                        (*hajok)[hajoszam][kattintas_szam-1]=(*palya)[sor][oszlop];
                        irany->set_aktiv(false);
                        kattintas_szam--;
                    }
                }
                else if(kattintas_szam<(*hajok)[hajoszam].size() && oszlop==(*hajok)[hajoszam][kattintas_szam]->get_oszlop()) //abban az oszlopban van ahol a hajo többi eleme
                {
                    int elotte;
                    int utana;
                    sor-1<0 ? elotte=1 : elotte=sor-1;
                    sor+1>sorszam-1 ? utana=sorszam-2 : utana=sor+1;
                    if((*palya)[elotte][oszlop]==(*hajok)[hajoszam][kattintas_szam] || (*palya)[elotte][oszlop]==(*hajok)[hajoszam][(*hajok)[hajoszam].size()-1] || (*palya)[utana][oszlop]==(*hajok)[hajoszam][kattintas_szam] || (*palya)[utana][oszlop]==(*hajok)[hajoszam][(*hajok)[hajoszam].size()-1])
                    {
                        (*palya)[sor][oszlop]->set_hajo(true);
                        (*hajok)[hajoszam][kattintas_szam-1]=(*palya)[sor][oszlop];
                        kattintas_szam--;
                    }
                }
            }


        }
    }
}
void GameController::palya2_beallit()
{
    if(hajoszam==hajok1.size()-1 && kattintas_szam==0)
    {
        widgetek.clear();
        terminate=true;
        gout<<move_to(0,0)<<color(0,0,0)<<box(max_x,max_y);
        for (int i=0; i<palya2.size(); i++)
        {
            for (int j=0; j<palya2[i].size(); j++)
            {
                widgetek.push_back(palya2[i][j]);
            }
        }
        jatekos2_name->set_position(max_x/2-70,10);
        widgetek.push_back(jatekindit);
        widgetek.push_back(hajovalaszto);
        irany->set_felirat("vizszintes");
        widgetek.push_back(irany);
        widgetek.push_back(jatekos2_name);
        widgetek.push_back(hajotipus);
        hajoszam=0;
        kattintas_szam=hajok1[hajoszam].size();
        hajotipus->kiurit();
        hajotipus->setText(itos(kattintas_szam)+" elemu hajo");
        irany->set_aktiv(true);
    }
}
void GameController::jatek()
{
    if(hajoszam==hajok1.size()-1 && kattintas_szam==0)
    {
        widgetek.clear();
        terminate=true;
        gout<<move_to(0,0)<<color(0,0,0)<<box(max_x,max_y);
        for (int i=0; i<palya1.size(); i++)
        {
            for (int j=0; j<palya1[i].size(); j++)
            {
                palya1[i][j]->set_aktiv(true);
                palya1[i][j]->set_fv([this,i,j](){this->lovoldoz(i,j,1);});
                widgetek.push_back(palya1[i][j]);
                palya2[i][j]->set_aktiv(true);
                palya2[i][j]->set_fv([this,i,j](){this->lovoldoz(i,j,2);});
                widgetek.push_back(palya2[i][j]);
            }
        }
        jatekos_valt->set_aktiv(true);
        jatekos_valt->set_felirat("Kezdodhet");
        widgetek.push_back(jatekos_valt);
        jatekos1_name->set_position(10,80);
        jatekos2_name->set_position(420,80);
        widgetek.push_back(jatekos1_name);
        widgetek.push_back(jatekos2_name);
    }
}
void GameController::jatekos_valto()
{
    if (kattintas_szam==0)
    {
        if(jatekos_valt->get_value()=="Kezdodhet")jatekos_valt->set_felirat("Jatekos valtas");
        terminate=true;
        gout<<move_to(0,0)<<color(0,0,0)<<box(max_x,max_y);
         bool jatekos1=false;
         if(widgetek[widgetek.size()-1]==jatekos1_name)jatekos1=true;//a widgetek utolso helyén a jatekos neve van
         vector<vector<TorpedoButton*>> * ellenfelpalya;
         vector<vector<TorpedoButton*>> * sajatpalya;
        if(jatekos1)
        {
        widgetek.pop_back();
        widgetek.pop_back();//kiszedi az eddigi jatekos nevet
        widgetek.push_back(jatekos1_name);
        widgetek.push_back(jatekos2_name);
        ellenfelpalya=&palya1;
        sajatpalya=&palya2;
        }
        else
        {
            widgetek.pop_back();
            widgetek.pop_back(); //kiszedi az eddigi jatekos nevet
            widgetek.push_back(jatekos2_name);
            widgetek.push_back(jatekos1_name);
            ellenfelpalya=&palya2;
            sajatpalya=&palya1;
        }
        for (int i=0; i<palya1.size(); i++)
        {
            for (int j=0; j<palya1[i].size(); j++)
            {
                //(*ellenfelpalya)[i][j]->set_aktiv(true); //azert aktiv, mert az ellenfel palyajan lehet kattintgatni
                (*sajatpalya)[i][j]->set_aktiv(false);
            }
        }
        jatekos_valt->set_aktiv(false);
        kattintas_szam=1;
    }
}
void GameController::lovoldoz(int sor, int oszlop, int jatekos) //ellenfél pályáján történő dolgokat ellenőrzi
{
    if(kattintas_szam>0)
    {
        if((widgetek[widgetek.size()-1]== jatekos1_name && jatekos==2) || (widgetek[widgetek.size()-1]== jatekos2_name && jatekos==1))//ellenfél pályája-e
        {vector<vector<TorpedoButton*>> * palya; //ellenfel palya
        vector<vector<TorpedoButton*>> * sajatpalya;
        vector<vector<TorpedoButton*>> * hajok;
        if (jatekos==1) {palya= &palya1; sajatpalya= &palya2; hajok=&hajok1;}
        else {palya= &palya2; sajatpalya= &palya1; hajok=&hajok2;}
        (*palya)[sor][oszlop]->set_jelolve(true);
        kattintas_szam--;
        for(int i=0;i<(*hajok).size();i++)
        {
            int jeloltek_szama=0;
            for (int j=0; j<(*hajok)[i].size();j++)
            {
                if((*hajok)[i][j]->get_jelolve()) jeloltek_szama++;
                //elsullyedt?
            }
            if(jeloltek_szama==(*hajok)[i].size())//ha a hajó minden eleme meg van jelölve akkor elsüllyedt
            {
                for(TorpedoButton* torp: (*hajok)[i])
                {
                    torp->set_sullyedt(true);
                }
                (*hajok)[i]=(*hajok)[(*hajok).size()-1];//töröljük a hajót a hajók közül
                (*hajok).pop_back();
            }
        }
        if((*hajok).size()==0)//Game over
        {
            nyertes->kiurit();
            nyertes->setText("A nyertes: "+widgetek.back()->get_value());
            widgetek.pop_back();//kiszedem a nevet
            widgetek.pop_back();//kiszedem a nevet
            widgetek.pop_back();//kiszedem a jatekosváltót
            terminate=true;
            gout<<move_to(0,0)<<color(0,0,0)<<box(max_x,max_y);
            widgetek.push_back(nyertes);
            play->set_position(3*max_x/4-20,max_y-50);
            play->set_felirat("Play again");
            exit_button->set_position(max_x/4-20,max_y-50);
            widgetek.push_back(nyertes);
            widgetek.push_back(play);
            widgetek.push_back(exit_button);
        }
            for (int i=0; i<palya1.size(); i++)
            {
                for (int j=0; j<palya1[i].size(); j++)
                {
                    (*sajatpalya)[i][j]->set_aktiv(true);//azert aktiv, hogy ne lehessen látni az elhelyezett hajókat
                }
            }
            jatekos_valt->set_aktiv(true);
        }
    }
}

