#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "mag.h"
#include "wojownik.h"
#include "zlodziej.h"
#include "postac.h"
#include "kosciotrup.h"
#include "przeciwnik.h"

#define ataki 3

using namespace sf;
using namespace std;

class gra
{
private:
    int wybor;
    Font czcionka;
    Text menu[ataki];
    Text napis[10];
    int x,y,siz,hplimit,manalimit,L,Klucze;
    Texture m1,t0,t1,t2,t3,t4,t5,t6;
    Sprite tlo,mur,puste,potion,drzwi,post,kosci,postskal,kosciskal,skrzynia;
    vector<vector<int> > pole;
    fstream plik;
    postac *gracz;
    vector<kosciotrup> szkielet;

public:
    int P;
    bool czywalka;

    gra()
    {
        P = 1;
        czywalka = false;
        gracz = new mag;
        wczytajpoziom(P);
        t2.loadFromFile("mag32.png");
        hplimit = gracz->hp;
        manalimit = gracz->mana;
        siz = 32;
        L = 0;
        Klucze = 0;

        t0.loadFromFile("white32.png");
        t1.loadFromFile("mur32.png");
        t3.loadFromFile("kosciotrup32.png");
        t4.loadFromFile("potion32.png");
        t5.loadFromFile("skrzynia32.png");
        t6.loadFromFile("drzwi32.png");
        m1.loadFromFile("menu.png");

        mur.setTexture(t1);
        tlo.setTexture(m1);
        post.setTexture(t2);
        puste.setTexture(t0);
        kosci.setTexture(t3);
        potion.setTexture(t4);
        skrzynia.setTexture(t5);
        drzwi.setTexture(t6);
        postskal.setScale(10,10);
        postskal.setPosition(0,0);
        postskal.setTexture(t2);
        kosciskal.setScale(10,10);
        kosciskal.setPosition(400,0);
        kosciskal.setTexture(t3);

        if (!czcionka.loadFromFile("arial.ttf"))
        {
            cout << "Nie wczytano czcionki!!";
        }

        for(int i = 0 ; i < 10 ; i++)
        {
            napis[i].setFont(czcionka);
            napis[i].setColor(Color::White);
        }

        napis[0].setPosition(Vector2f(0,320));
        napis[1].setPosition(Vector2f(0,360));
        napis[2].setPosition(Vector2f(0,400));
        napis[3].setPosition(0,420);
        napis[3].setString("____________________________________________");
        napis[4].setPosition(340,140);
        napis[4].setColor(Color::Red);
        napis[4].setString("VS");
        napis[5].setPosition(400,320);
        napis[6].setPosition(400,460);
        napis[7].setPosition(400,500);
        napis[8].setCharacterSize(24);
        napis[8].setStyle(Text::Bold);
        napis[8].setColor(Color::Black);
        napis[9].setCharacterSize(256);
        napis[9].setStyle(Text::Bold);
        napis[9].setColor(Color::Red);

        menu[0].setFont(czcionka);
        menu[0].setColor(Color::Red);
        menu[0].setString("Atak");
        menu[0].setPosition(Vector2f(0, 460));

        menu[1].setFont(czcionka);
        menu[1].setColor(Color::White);
        menu[1].setString("Obrona");
        menu[1].setPosition(Vector2f(0,510));

        menu[2].setFont(czcionka);
        menu[2].setColor(Color::White);
        menu[2].setString("Atak specjalny");
        menu[2].setPosition(Vector2f(0,560));

        wybor = 0;

    }

    ~gra() {}

    void wczytajgracza(int a)
    {
        switch(a)
        {
        case 1:
            gracz = new mag;
            t2.loadFromFile("mag32.png");
            break;

        case 2:
            gracz = new wojownik;
            t2.loadFromFile("wojownik32.png");
            break;

        case 3:
            gracz = new zlodziej;
            t2.loadFromFile("zlodziej32.png");
            break;
        }

        post.setTexture(t2);
        hplimit = gracz->hp;
        manalimit = gracz->mana;
    }

    void rysuj(RenderWindow &okno)
    {
        ostringstream napisy,koniec;
        napisy << "HP: " << gracz->hp << ", MANA: " << gracz->mana << ", FURIA: " << gracz->furia <<", Pokonani przeciwnicy: " << L << ", Klucze do zebrania: " << Klucze ;
        koniec << "KONIEC" << endl << "GRY";
        napis[8].setString(napisy.str());
        napis[9].setString(koniec.str());

        okno.draw(tlo);

        for(int i = 0; i<x ; i++)
        {
            for(int j = 0 ; j<y ; j++)
            {
                if(pole[i][j] == 2)
                {
                    post.setPosition(j*siz, i*siz);
                    okno.draw(post);
                }

                if(pole[i][j] == 3)
                {
                    kosci.setPosition(j*siz,i*siz);
                    okno.draw(kosci);
                }

                if(pole[i][j] == 4)
                {
                    potion.setPosition(j*siz,i*siz);
                    okno.draw(potion);
                }

                if(pole[i][j] == 5)
                {
                    skrzynia.setPosition(j*siz,i*siz);
                    okno.draw(skrzynia);
                }

                if(pole[i][j] == 6)
                {
                    drzwi.setPosition(j*siz,i*siz);
                    okno.draw(drzwi);
                }

                if(pole[i][j] == 1)
                {
                    mur.setPosition(j*siz,i*siz);
                    okno.draw(mur);
                }

                else if(pole[i][j] == 0)
                {
                    puste.setPosition(j*siz,i*siz);
                    okno.draw(puste);
                }
            }
        }
        okno.draw(napis[8]);

        if(P == 6)
        {
            okno.draw(napis[9]);
        }
    }

    void wczytajpoziom(int a)
    {
        P = a;
        Klucze = 0;
        gracz->reset();
        szkielet.clear();
        czywalka = false;
        L = 0;

        switch(a)
        {
        case 1:
            plik.open( "level1.txt", ios::in);
            break;

        case 2:
            plik.open( "level2.txt", ios::in);
            break;

        case 3:
            plik.open( "level3.txt", ios::in);
            break;

        case 4:
            plik.open( "level4.txt", ios::in);
            break;

        case 5:
            plik.open( "level5.txt", ios::in);
            break;

        default:
            break;
        }

        plik >> x;
        plik >> y;

        pole.resize(x);
        for (int i = 0; i<x; i++)
        {
            pole[i].resize(y);
        }
        for (int i = 0; i<x; i++)
        {
            for(int j = 0; j<y; j++)
            {
                plik >> pole[i][j];
                if(pole[i][j] == 3)
                {
                    szkielet.push_back(kosciotrup());
                }
                if(pole[i][j] == 5)
                {
                    Klucze++;
                }
            }
        }

        plik.close();
    }

    void miksturka()
    {
        if(gracz->hp + 50 >= hplimit) gracz->hp = hplimit;
        else gracz->hp += 50;
        if(gracz->mana + 25 >= manalimit) gracz->mana = manalimit;
        else gracz->mana += 25;
    }

    void UP()
    {
        if(pole[gracz->x-1][gracz->y] == 1)
        {

        }

        else if(pole[gracz->x-1][gracz->y] == 4)
        {
            miksturka();

            pole[gracz->x--][gracz->y] = 0;
            pole[gracz->x][gracz->y] = 2;
        }

        else if(pole[gracz->x-1][gracz->y] == 3)
        {
            czywalka = true;
            pole[gracz->x--][gracz->y] = 0;
            pole[gracz->x][gracz->y] = 2;
        }

        else if(pole[gracz->x-1][gracz->y] == 6)
        {
            if(Klucze == 0)
            {
                P++;
                wczytajpoziom(P);
            }
        }
        else if(pole[gracz->x-1][gracz->y] == 5)
        {
            Klucze--;
            pole[gracz->x--][gracz->y] = 0;
            pole[gracz->x][gracz->y] = 2;
        }

        else
        {
            pole[gracz->x--][gracz->y] = 0;
            pole[gracz->x][gracz->y] = 2;
        }
    }

    void DOWN()
    {
        if(pole[gracz->x+1][gracz->y] == 1)
        {

        }
        else if(pole[gracz->x+1][gracz->y] == 4)
        {
            miksturka();
            pole[gracz->x++][gracz->y] = 0;
            pole[gracz->x][gracz->y] = 2;
        }

        else if(pole[gracz->x+1][gracz->y] == 3)
        {
            czywalka = true;
            pole[gracz->x++][gracz->y] = 0;
            pole[gracz->x][gracz->y] = 2;
        }
        else if(pole[gracz->x+1][gracz->y] == 6)
        {
            if(Klucze == 0)
            {
                P++;
                wczytajpoziom(P);
            }

        }
        else if(pole[gracz->x+1][gracz->y] == 5)
        {
            Klucze--;
            pole[gracz->x++][gracz->y] = 0;
            pole[gracz->x][gracz->y] = 2;
        }

        else
        {
            pole[gracz->x++][gracz->y] = 0;
            pole[gracz->x][gracz->y] = 2;
        }
    }

    void LEFT()
    {
        if(pole[gracz->x][gracz->y-1] == 1)
        {

        }
        else if(pole[gracz->x][gracz->y-1] == 4)
        {
            miksturka();

            pole[gracz->x][gracz->y--] = 0;
            pole[gracz->x][gracz->y] = 2;
        }

        else if(pole[gracz->x][gracz->y-1] == 3)
        {
            czywalka = true;
            pole[gracz->x][gracz->y--] = 0;
            pole[gracz->x][gracz->y] = 2;
        }
        else if(pole[gracz->x][gracz->y-1] == 6)
        {
            if(Klucze == 0)
            {
                P++;
                wczytajpoziom(P);
            }

        }
        else if(pole[gracz->x][gracz->y-1] == 5)
        {
            Klucze--;
            pole[gracz->x][gracz->y--] = 0;
            pole[gracz->x][gracz->y] = 2;
        }

        else
        {
            pole[gracz->x][gracz->y--] = 0;
            pole[gracz->x][gracz->y] = 2;
        }
    }

    void RIGHT()
    {
        if(pole[gracz->x][gracz->y+1] == 1)
        {

        }
        else if(pole[gracz->x][gracz->y+1] == 4)
        {
            miksturka();

            pole[gracz->x][gracz->y++] = 0;
            pole[gracz->x][gracz->y] = 2;
        }
        else if(pole[gracz->x][gracz->y+1] == 3)
        {
            czywalka = true;
            pole[gracz->x][gracz->y++] = 0;
            pole[gracz->x][gracz->y] = 2;
        }

        else if(pole[gracz->x][gracz->y+1] == 6)
        {
            if(Klucze == 0)
            {
                P++;
                wczytajpoziom(P);
            }

        }
        else if(pole[gracz->x][gracz->y+1] == 5)
        {
            Klucze--;
            pole[gracz->x][gracz->y++] = 0;
            pole[gracz->x][gracz->y] = 2;
        }

        else
        {
            pole[gracz->x][gracz->y++] = 0;
            pole[gracz->x][gracz->y] = 2;
        }
    }

    void walkaUP()
    {

        if (wybor - 1 >= 0)
        {
            menu[wybor].setColor(Color::White);
            wybor--;
            menu[wybor].setColor(Color::Red);
        }

    }

    void walkaDOWN()
    {

        if (wybor + 1 < ataki)
        {
            menu[wybor].setColor(Color::White);
            wybor++;
            menu[wybor].setColor(Color::Red);
        }

    }

    int oddajwybor()
    {
        return wybor;
    }

    void walka(int a)
    {
        int oddaj;

        if(a == 1)
        {
            szkielet[L].hp -= gracz->atak();
            napis[6].setString(gracz->czynnosc.str());
            gracz->czynnosc.str("");
        }
        if(a == 2)
        {
            int spr = gracz -> obrona();
            if(spr == 0)
            {
                oddaj = szkielet[L].atak()/2;
            }
            else if(spr == 1)
            {
                oddaj = szkielet[L].atak()*(rand()&1);
                int hpadd = 25*(rand()&1);
                if(gracz->hp + hpadd >= hplimit) gracz->hp = hplimit;
                else gracz->hp += hpadd;
            }
            else oddaj = szkielet[L].atak();

            napis[6].setString(gracz->czynnosc.str());
            gracz->czynnosc.str("");
        }
        if(a == 3)
        {
            szkielet[L].hp -= gracz->atakspecjalny();
            napis[6].setString(gracz->czynnosc.str());
            gracz->czynnosc.str("");
        }

        if(a != 2)
        {
            oddaj = szkielet[L].atak();
        }

        if(szkielet[L].hp > 0)
        {
            gracz->hp -= oddaj;
            ostringstream atakwroga;
            atakwroga <<"Przeciwnik atakuje za " << oddaj << " pkt zycia";
            napis[7].setString(atakwroga.str());
        }

        else if(szkielet[L].hp <= 0)
        {
            czywalka = false;
            szkielet.erase(szkielet.begin()+L);
            napis[6].setString("");
            napis[7].setString("");
            L++;
        }

        if(gracz->hp <= 0)
        {
            czywalka = false;
            wczytajpoziom(P);
            napis[6].setString("");
            napis[7].setString("");
        }



    }

    void rysujwalka(RenderWindow &okno)
    {
        okno.draw(tlo);
        okno.draw(postskal);
        okno.draw(kosciskal);
        ostringstream hp,mana,furia,hpenemy;
        hp << "Twoje HP: " << gracz->hp;
        napis[0].setString(hp.str());
        mana << "MANA(Mag): " << gracz->mana;
        napis[1].setString(mana.str());
        furia << "FURIA(Wojownik): " << gracz->furia;
        napis[2].setString(furia.str());
        hpenemy << "HP przeciwnika: " << szkielet[L].hp;
        napis[5].setString(hpenemy.str());

        for(int i = 0 ; i < 8 ; i ++)
        {
            okno.draw(napis[i]);
        }

        for(int i = 0 ; i < ataki ; i++)
        {
            okno.draw(menu[i]);
        }

    }
};
