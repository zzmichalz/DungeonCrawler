#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;
using namespace std;

#define ilosc 4

class Menu
{
private:

    int wybor;
    Font czcionka;
    Text menu[ilosc];
    Text napis;
    Texture m1;
    Sprite menu1;

public:

    Menu(int x, int y)
    {
        m1.loadFromFile("menu.png");
        menu1.setTexture(m1);
        if (!czcionka.loadFromFile("arial.ttf"))
        {
            cout << "Nie wczytano czcionki!!";
        }

        napis.setFont(czcionka);
        napis.setColor(Color::White);
        napis.setString("Stworzyl: Michal Zieba");
        napis.setPosition(Vector2f(x/4,0));
        napis.setCharacterSize(64);

        menu[0].setFont(czcionka);
        menu[0].setColor(Color::Red);
        menu[0].setString("Graj");
        menu[0].setPosition(Vector2f(x/2, y/(ilosc + 1) * 1));

        menu[1].setFont(czcionka);
        menu[1].setColor(Color::White);
        menu[1].setString("Wybierz poziom");
        menu[1].setPosition(Vector2f(x/2,y/(ilosc + 1) * 2));

        menu[2].setFont(czcionka);
        menu[2].setColor(Color::White);
        menu[2].setString("Opcje");
        menu[2].setPosition(Vector2f(x/2,y/(ilosc + 1) * 3));

        menu[3].setFont(czcionka);
        menu[3].setColor(Color::White);
        menu[3].setString("Wyjscie");
        menu[3].setPosition(Vector2f(x/2,y/(ilosc + 1) * 4));

        wybor = 0;

    }

    ~Menu() {}

    void rysuj(RenderWindow &okno)
    {
        okno.draw(menu1);
        okno.draw(napis);

        for(int i = 0 ; i < ilosc ; i++)
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

        if (wybor + 1 < ilosc)
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

};
