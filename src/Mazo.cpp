#include "Mazo.h"
#include <algorithm>
#include <random>

Mazo::Mazo()
{
    for (int p = 0; p < 4; ++p)
        for (int v = 1; v <= 13; ++v)
            cartas.emplace_back(v, static_cast<Palo>(p), false);
}

void Mazo::barajar()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cartas.begin(), cartas.end(), g);
}

bool Mazo::vacio() const
{
    return cartas.empty();
}

Carta Mazo::robar()
{
    Carta c = cartas.back();
    cartas.pop_back();
    return c;
}

void Mazo::poner_Abajo(const Carta &c)
{
    cartas.insert(cartas.begin(), c);
}

size_t Mazo::tam() const
{
    return cartas.size();
}