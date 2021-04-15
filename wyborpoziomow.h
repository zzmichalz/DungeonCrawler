#pragma once
#include <iostream>
using namespace std;

#define ilepoziomow 5

class wyborpoziomow
{
private:

    int wybor;
    Font czcionka;
    Text menu[ilepoziomow];
    Text opcja;
    Texture m1;
    Sprite menu1;

public:

    wyborpoziomow(int x, int y)
    {
        m1.loadFromFile("menu.png");
        menu1.setTexture(m1);
        if (!czcionka.loadFromFile("arial.ttf"))
        {
            cout << "Nie wczytano czcionki!!";
        }

        opcja.setFont(czcionka);
        opcja.setColor(Color::Red);
        opcja.setString("Wybór Poziomu: ");
        opcja.setPosition(Vector2f(x/4,0));
        opcja.setCharacterSize(64);

        menu[0].setFont(czcionka);
        menu[0].setColor(Color::Red);
        menu[0].setString("Poziom 1");
        menu[0].setPosition(Vector2f(x/2, y/(ilepoziomow + 1) * 1));

        menu[1].setFont(czcionka);
        menu[1].setColor(Color::White);
        menu[1].setString("Poziom 2");
        menu[1].setPosition(Vector2f(x/2,y/(ilepoziomow + 1) * 2));

        menu[2].setFont(czcionka);
        menu[2].setColor(Color::White);
        menu[2].setString("Poziom 3");
        menu[2].setPosition(Vector2f(x/2,y/(ilepoziomow + 1) * 3));

        menu[3].setFont(czcionka);
        menu[3].setColor(Color::White);
        menu[3].setString("Poziom 4");
        menu[3].setPosition(Vector2f(x/2,y/(ilepoziomow + 1) * 4));

        menu[4].setFont(czcionka);
        menu[4].setColor(Color::White);
        menu[4].setString("Poziom 5");
        menu[4].setPosition(Vector2f(x/2,y/(ilepoziomow + 1) * 5));

        wybor = 0;

    }

    ~wyborpoziomow() {}

    void rysuj(RenderWindow &okno)
    {
        okno.draw(menu1);
        okno.draw(opcja);

        for(int i = 0 ; i < ilepoziomow ; i++)
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

        if (wybor + 1 < ilepoziomow)
        {
            menu[wybor].setColor(Color::White);
            wybor++;
            menu[wybor].setColor(Color::Red);
        }

    }

    int oddajpoziom()
    {
        return wybor;
    }

};

