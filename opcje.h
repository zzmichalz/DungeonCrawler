#pragma once
#include <iostream>
using namespace std;

#define iloscopcji 5

class opcje
{
private:

    int wybor;
    Font czcionka;
    Text menu[iloscopcji];
    Text opcja;
    Texture m1;
    Sprite menu1;

public:

    opcje(int x, int y)
    {
        m1.loadFromFile("menu.png");
        menu1.setTexture(m1);
        if (!czcionka.loadFromFile("arial.ttf"))
        {
            cout << "Nie wczytano czcionki!!";
        }
        opcja.setFont(czcionka);
        opcja.setColor(Color::Red);
        opcja.setString("Wybór Rozdzielczosci: ");
        opcja.setPosition(Vector2f(x/4,0));
        opcja.setCharacterSize(64);

        menu[0].setFont(czcionka);
        menu[0].setColor(Color::Red);
        menu[0].setString("1024x768");
        menu[0].setPosition(Vector2f(x/2, y/(iloscopcji + 1) * 1));

        menu[1].setFont(czcionka);
        menu[1].setColor(Color::White);
        menu[1].setString("1280x720");
        menu[1].setPosition(Vector2f(x/2,y/(iloscopcji + 1) * 2));

        menu[2].setFont(czcionka);
        menu[2].setColor(Color::White);
        menu[2].setString("1366x768");
        menu[2].setPosition(Vector2f(x/2,y/(iloscopcji + 1) * 3));

        menu[3].setFont(czcionka);
        menu[3].setColor(Color::White);
        menu[3].setString("1920x1080");
        menu[3].setPosition(Vector2f(x/2,y/(iloscopcji + 1) * 4));

        menu[4].setFont(czcionka);
        menu[4].setColor(Color::White);
        menu[4].setString("Fullscreen");
        menu[4].setPosition(Vector2f(x/2,y/(iloscopcji + 1) * 5));

        wybor = 0;

    }

    ~opcje() {}

    void rysuj(RenderWindow &okno)
    {

        okno.draw(menu1);
        okno.draw(opcja);

        for(int i = 0 ; i < iloscopcji ; i++)
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

        if (wybor + 1 < iloscopcji)
        {
            menu[wybor].setColor(Color::White);
            wybor++;
            menu[wybor].setColor(Color::Red);
        }

    }

    int oddajopcje()
    {
        return wybor;
    }

};
