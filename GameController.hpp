#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP
class GameController: public Window
{
    int kattintas_szam;
    int hajoszam;
    int sorszam;
    int oszlopszam;
    MainButton * play;
    MainButton * exit;
    Choose * jatekos1_name_input;
    Choose * jatekos2_name_input;
    SimpleText * jatekos1_name;
    SimpleText * jatekos2_name;
    MainButton * palyavalasztas1;
    MainButton * palyavalasztas2;
    MainButton * hajovalaszto;
    MainButton * irany;
    SimpleText * hajotipus;
    vector<vector<TorpedoButton*>> hajok(3); // 3 hajó benne (kölönbözõ hossz)
    vector<vector<TorpedoButton*>> palya1;
    vector<vector<TorpedoButton*>> palya2;
    MainButton * jatekindit;
    public:
    GameController();
    void eventloop();
    void jatek_elokeszit()
    {
        widgetek.clear();
        widgetek.push_back(jatekos1_name_input);
        widgetek.push_back(jatekos2_name_input);
        widgetek.push_back(palyavalasztas1);
    }
    void palya1_beallit()
    {
        jatekos1_name->setText(jatekos1_name_input->get_value());
        jatekos2_name->setText(jatekos2_name_input->get_value());
        widgetek.clear();
        for (int i=0; i<Palya1.size();i++)
        {
            for (int j=0; j<Palya1[i].size();j++)
            {
                widgetek.push_back(Palya1[i][j]);
            }
        }
        widgetek.push_back(palyavalasztas2);
        widgetek.push_back(hajovalaszto);
        widgetek.push_back(jatekos1_name);
        widgetek.push_back(hajotipus);
        hajoszam=0;
        kattintas_szam=hajok[0].size();
    }
    void hajo_valasztas()
    {
        if (kattintas_szam==0)
        {
            if (hajoszam<hajok.size()-1)
            {
                hajoszam++;
                kattintas_szam=hajok[hajoszam].size();
                hajotipus->setText(itos(kattintas_szam)+" elemu hajo");
            }
        }
    }
    void beallitas_hajokent(int sor, int oszlop, int jatekos)
    {
        if (kattintas_szam>0)
        {
            vector<vector<TorpedoButton*>> * palya;
            if (jatekos==1) palya= &palya1;
            else palya= &palya2;
            if((palya*)[sor][oszlop]->get_hajo()==false)
            {
            if(irany->get_value()=="vizszintes")
            {
                if(kattintas_szam==hajok[hajoszam].size() && oszlop-kattintas_szam-1>=0 && oszlop+kattintas_szam-1<oszlopszam)
                {
                    bool utban_van_hajo=false;
                    for (i=oszlop-kattintas_szam-1; i<oszlop+kattintas_szam; i++)
                    {
                        if ((palya*)[sor][i]->get_hajo())
                        {
                            utban_van_hajo=true;
                        }
                    }
                    if(!utban_van_hajo)
                    {
                        (palya*)[sor][oszlop]->set_hajo(true);
                        hajok[hajoszam][kattintas_szam-1]=(palya*)[sor][oszlop];
                        kattintas_szam--;
                    }
                }
                if(kattintas_szam<hajok[hajoszam].size() && sor==hajok[hajoszam][kattintas_szam]->get_sor())
                {
                    if((palya*)[sor][oszlop-1]==hajok[hajoszam][kattintas_szam-1] || (palya*)[sor][oszlop-1]==hajok[hajoszam][hajok[hajoszam].size()] || (palya*)[sor][oszlop+1]==hajok[hajoszam][kattintas_szam-1] || (palya*)[sor][oszlop+1]==hajok[hajoszam][hajok[hajoszam].size()])
                    {
                        (palya*)[sor][oszlop]->set_hajo(true);
                        hajok[hajoszam][kattintas_szam-1]=(palya*)[sor][oszlop];
                        kattintas_szam--;
                    }
                }
            }

            }
        }
    }
    void palya2_beallit()
    {
        widgetek.clear();
        for (int i=0; i<Palya2.size();i++)
        {
            for (int j=0; j<Palya2[i].size();j++)
            {
                widgetek.push_back(Palya2[i][j]);
            }
        }
        widgetek.push_back(jatekindit);
        widgetek.push_back(hajovalaszto);
        widgetek.push_back(jatekos2_name);
        widgetek.push_back(hajotipus);
        hajoszam=0;
        kattintas_szam=hajok[0].size();
    }
    void jatek()
    {

    }
};
#endif // GAMECONTROLLER_HPP
