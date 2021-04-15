#pragma once
#include "postac.h"
#include <iostream>

class mag : public postac
{
private:

    int hplimit;

public:

    int atak()
    {
        int liczba = (rand() % 10 ) + 10;
        int manadd = (rand() % 10 ) + 10;
        czynnosc << "Uderzasz przeciwnika kosturem za " << liczba << " pkt zycia";
        if((mana + manadd) >= 100) mana = 100;
        else mana += manadd;
        return liczba;
    }

    int obrona()
    {
        int liczba = (rand() % 20 ) + 20;

        if((mana - 25) < 0) czynnosc << "Nie masz dosc many, by sie uleczyc";
        else
        {
            mana -= 25;
            czynnosc << "Leczysz sie za " << liczba << " pkt zycia";
            if(hp + liczba >= hplimit) hp = hplimit;
            else hp += liczba;
        }
        return liczba;
    }

    int atakspecjalny()
    {

        if((mana - 25) < 0)
        {
            czynnosc << "Nie masz dosc many, by rzucic kule ognia";

        }

        else
        {
            mana -= 25;
            int liczba = (rand() % 50 ) + 30;
            czynnosc << "Rzucasz kule ognia za " << liczba << " pkt zycia";
            return liczba;
        }
        return 0;

    }

    void reset()
    {
        x = 1;
        y = 1;
        hp = 100;
        mana = 100;
        furia = 0;
    }

    mag()
    {
        hplimit = 100;
        x = 1;
        y = 1;
        hp = 100;
        mana = 100;
        furia = 0;
    }

};

