#pragma once
#include "postac.h"

class wojownik : public postac
{
private:
    int hplimit;
public:

    int atak()
    {
        int liczba = (rand() % 25 ) + 10;
        czynnosc << "Atakujesz mieczem za " << liczba << " pkt zycia";
        return liczba;
    }

    int obrona()
    {
        int liczba = (rand() % 20 ) + 10;
        furia += liczba;
        czynnosc << "Blokujesz obrazenia o polowe, FURIA: +" << liczba;
        return 0;
    }

    int atakspecjalny()
    {
        if(furia < 25) czynnosc << "Nie masz dosc furii, aby zaatakowac";
        else
        {
            furia -= 25;
            int liczba = (rand() % 30 ) + 30;
            czynnosc << "Mocny Atak z wyskoku za " << liczba << " pkt zycia";
            return liczba;
        }
        return 0;
    }

    void reset()
    {
        x = 1;
        y = 1;
        hp = 200;
        mana = 0;
        furia = 0;
    }

    wojownik()
    {
        hplimit = 200;
        x = 1;
        y = 1;
        hp = 200;
        mana = 0;
        furia = 0;
    }

};
