#pragma once
#include <iostream>
using namespace std;

#define gracze 3

class wyborgracza
{
private:

    int wybor;
    Font czcionka;
    Text menu[gracze];
    Text napis[2];
    Texture m1,s1;
    Sprite menu1,sterowanie;

public:

    wyborgracza(int x, int y)
    {
        m1.loadFromFile("menu.png");
        menu1.setTexture(m1);
        s1.loadFromFile("sterowanie.png");
        sterowanie.setTexture(s1);
        sterowanie.setPosition(300,100);

        if (!czcionka.loadFromFile("arial.ttf"))
        {
            cout << "Nie wczytano czcionki!!";
        }
        napis[0].setFont(czcionka);
        napis[0].setColor(Color::Red);
        napis[0].setString("Wybór postaci:");
        napis[0].setCharacterSize(64);
        napis[0].setPosition(300,0);

        menu[0].setFont(czcionka);
        menu[0].setColor(Color::Red);
        menu[0].setString("Mag");
        menu[0].setPosition(Vector2f(0, y/(gracze + 1) * 1));

        menu[1].setFont(czcionka);
        menu[1].setColor(Color::White);
        menu[1].setString("Wojownik");
        menu[1].setPosition(Vector2f(0,y/(gracze + 1) * 2));

        menu[2].setFont(czcionka);
        menu[2].setColor(Color::White);
        menu[2].setString("Zlodziej");
        menu[2].setPosition(Vector2f(0,y/(gracze + 1) * 3));

        wybor = 0;

    }

    ~wyborgracza() {}

    void rysuj(RenderWindow &okno)
    {
        okno.draw(menu1);
        okno.draw(napis[0]);
        okno.draw(sterowanie);


        for(int i = 0 ; i < gracze ; i++)
        {
            okno.draw(menu[i]);
        }

    }
    void UP()
    {

        if (wybor - 1 >= 0)
        {
            menu[wybor].setColor(Color::White);
            wybor--;
            menu[wybor].setColor(Color::Red);
        }

    }

    void DOWN()
    {

        if (wybor + 1 < gracze)
        {
            menu[wybor].setColor(Color::White);
            wybor++;
            menu[wybor].setColor(Color::Red);
        }

    }

    int oddajgracza()
    {
        return wybor;
    }

};

