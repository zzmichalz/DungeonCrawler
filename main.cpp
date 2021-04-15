#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "gra.h"
#include "menu.h"
#include "opcje.h"
#include "wyborgracza.h"
#include "wyborpoziomow.h"

using namespace std;
using namespace sf;

enum class StatusGry
{
    menus,
    opcje,
    poziom,
    gra,
    wyborpostaci,

};

int main()
{
    StatusGry gdziejest = StatusGry::menus;
    srand( time( NULL ) );

    RenderWindow okno(VideoMode(1024,768,32), "GRA", Style::Close/*, Style::Fullscreen*/);
    okno.setVerticalSyncEnabled(true);

    Menu menu(okno.getSize().x, okno.getSize().y);
    opcje settings(okno.getSize().x, okno.getSize().y);
    wyborgracza nowygracz(okno.getSize().x, okno.getSize().y);
    wyborpoziomow nowypoziom(okno.getSize().x, okno.getSize().y);
    gra nowa;

    while(okno.isOpen())
    {

        switch(gdziejest)
        {
        case StatusGry::menus:
            Event e;
            while(okno.pollEvent(e))
            {

                switch (e.type)
                {
                case Event::KeyReleased:
                    switch (e.key.code)
                    {
                    case Keyboard::Up:
                        menu.UP();
                        break;

                    case Keyboard::Down:
                        menu.DOWN();
                        break;

                    case Keyboard::Return:
                        switch (menu.oddajwybor())
                        {
                        case 0:
                            gdziejest = StatusGry::wyborpostaci;
                            break;
                        case 1:
                            gdziejest = StatusGry::poziom;
                            break;
                        case 2:
                            gdziejest = StatusGry::opcje;
                            break;
                        case 3:
                            okno.close();
                            break;
                        }
                    default:
                        break;
                    }

                    break;
                case Event::Closed:
                    okno.close();

                default:
                    break;

                }
            }
            okno.clear();
            menu.rysuj(okno);
            okno.display();
            break;

        case StatusGry::wyborpostaci:
            while(okno.pollEvent(e))
            {
                switch (e.type)
                {
                case Event::KeyReleased:
                    switch (e.key.code)
                    {
                    case Keyboard::Up:
                        nowygracz.UP();
                        break;

                    case Keyboard::Down:
                        nowygracz.DOWN();
                        break;

                    case Keyboard::Escape:
                        gdziejest = StatusGry::menus;
                        break;

                    case Keyboard::Return:
                        switch (nowygracz.oddajgracza())
                        {
                        case 0:
                            nowa.wczytajgracza(1);
                            nowa.wczytajpoziom(nowa.P);
                            gdziejest = StatusGry::gra;
                            break;
                        case 1:
                            nowa.wczytajgracza(2);
                            nowa.wczytajpoziom(nowa.P);
                            gdziejest = StatusGry::gra;
                            break;
                        case 2:
                            nowa.wczytajgracza(3);
                            nowa.wczytajpoziom(nowa.P);
                            gdziejest = StatusGry::gra;
                            break;

                        }
                    default:
                        break;
                    }

                    break;
                case Event::Closed:
                    okno.close();

                default:
                    break;

                }
            }
            okno.clear();
            nowygracz.rysuj(okno);
            okno.display();
            break;

        case StatusGry::gra:
            while(okno.pollEvent(e))
            {
                switch (e.type)
                {
                case Event::KeyReleased:
                    switch (e.key.code)
                    {
                    case Keyboard::Up:
                        if(nowa.czywalka == false) nowa.UP();
                        else nowa.walkaUP();
                        break;

                    case Keyboard::Down:
                        if(nowa.czywalka == false) nowa.DOWN();
                        else nowa.walkaDOWN();
                        break;

                    case Keyboard::Left:
                        if(nowa.czywalka == false) nowa.LEFT();
                        break;

                    case Keyboard::Right:
                        if(nowa.czywalka == false) nowa.RIGHT();
                        break;

                    case Keyboard::Escape:
                        gdziejest = StatusGry::menus;
                        break;

                    case Keyboard::Return:

                        if(nowa.czywalka == true)
                        {
                            switch (nowa.oddajwybor())
                            {
                            case 0:
                                nowa.walka(1);
                                break;
                            case 1:
                                nowa.walka(2);
                                break;
                            case 2:
                                nowa.walka(3);
                                break;
                            }
                        }


                    default:
                        break;
                    }

                    break;
                case Event::Closed:
                    okno.close();

                default:
                    break;

                }
            }
            okno.clear();
            if(nowa.czywalka == false)
            {
                nowa.rysuj(okno);
            }
            else nowa.rysujwalka(okno);

            okno.display();
            break;

        case StatusGry::opcje:
            while(okno.pollEvent(e))
            {
                switch (e.type)
                {
                case Event::KeyReleased:
                    switch (e.key.code)
                    {
                    case Keyboard::Up:
                        settings.UP();
                        break;

                    case Keyboard::Down:
                        settings.DOWN();
                        break;

                    case Keyboard::Escape:
                        gdziejest = StatusGry::menus;
                        break;

                    case Keyboard::Return:
                        switch (settings.oddajopcje())
                        {
                        case 0:
                            okno.create(VideoMode(1024,768,32), "GRA", Style::Close);
                            okno.setVerticalSyncEnabled(true);
                            break;
                        case 1:
                            okno.create(VideoMode(1280,720,32), "GRA", Style::Close);
                            okno.setVerticalSyncEnabled(true);
                            break;
                        case 2:
                            okno.create(VideoMode(1366,768,32), "GRA", Style::Close);
                            okno.setVerticalSyncEnabled(true);
                            break;
                        case 3:
                            okno.create(VideoMode(1920,1080,32), "GRA", Style::Close);
                            okno.setVerticalSyncEnabled(true);
                            break;
                        case 4:
                                okno.create(VideoMode(okno.getSize().x,okno.getSize().y,32), "GRA", Style::Fullscreen);
                                okno.setVerticalSyncEnabled(true);
                            break;
                        }
                    default:
                        break;
                    }

                    break;
                case Event::Closed:
                    okno.close();

                default:
                    break;

                }
            }
            okno.clear();
            settings.rysuj(okno);
            okno.display();
            break;

        case StatusGry::poziom:
            while(okno.pollEvent(e))
            {
                switch (e.type)
                {
                case Event::KeyReleased:
                    switch (e.key.code)
                    {
                    case Keyboard::Up:
                        nowypoziom.UP();
                        break;

                    case Keyboard::Down:
                        nowypoziom.DOWN();
                        break;

                    case Keyboard::Escape:
                        gdziejest = StatusGry::menus;
                        break;

                    case Keyboard::Return:
                        switch (nowypoziom.oddajpoziom())
                        {
                        case 0:
                            nowa.wczytajpoziom(1);
                            gdziejest = StatusGry::menus;
                            break;
                        case 1:
                            nowa.wczytajpoziom(2);
                            gdziejest = StatusGry::menus;
                            break;
                        case 2:
                            nowa.wczytajpoziom(3);
                            gdziejest = StatusGry::menus;
                            break;
                        case 3:
                            nowa.wczytajpoziom(4);
                            gdziejest = StatusGry::menus;
                            break;
                        case 4:
                            nowa.wczytajpoziom(5);
                            gdziejest = StatusGry::menus;
                            break;
                        }
                    default:
                        break;
                    }

                    break;
                case Event::Closed:
                    okno.close();

                default:
                    break;

                }
            }
            okno.clear();
            nowypoziom.rysuj(okno);
            okno.display();
            break;

        default:
            break;

        }
    }

    return 0;
}



