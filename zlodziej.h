#pragma once
#include "postac.h"

class zlodziej : public postac
{
private:
    int hplimit;
public:

    int atak()
    {
        int liczba = (rand() % 15 ) + 10;
        czynnosc << "Atakujesz sztyletem za " << liczba << " pkt zycia";
        return liczba;
    }

    int obrona()
    {
        czynnosc << "50% szans na unik i na uleczenie 25 HP";
        return 1;
    }

    int atakspecjalny()
    {

        if(hp < 25) czynnosc << "Nie masz dosc hp, aby zaatakowac";
        else
        {
            hp -= 25;
            int liczba = (rand() % 50 ) + 50;
            czynnosc << "Atak od tylu za " << liczba << " pkt zycia";
            return liczba;
        }
        return 0;
    }

    void reset()
    {
        x = 1;
        y = 1;
        hp = 150;
        mana = 0;
        furia = 0;
    }

    zlodziej()
    {
        hplimit = 150;
        x = 1;
        y = 1;
        hp = 150;
        mana = 0;
        furia = 0;
    }

};

