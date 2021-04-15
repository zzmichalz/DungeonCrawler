#pragma once
#include <sstream>

class postac
{
public:
    int x,y,hp,mana,furia;
    std::ostringstream czynnosc;

    virtual int atak() = 0;
    virtual int obrona() = 0;
    virtual int atakspecjalny() = 0;
    virtual void reset() = 0;
};

