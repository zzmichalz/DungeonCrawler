#pragma once
#include "przeciwnik.h"

using namespace std;

class kosciotrup : public przeciwnik
{
public:

    int atak()
    {
        int liczba = (rand() % 10 ) + 10;
        return liczba;
    }

    kosciotrup()
    {
        hp = 100;
        mana = 0;
    }

    ~kosciotrup()
    {

    }

};
