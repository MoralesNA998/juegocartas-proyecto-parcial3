#pragma once
#include "Carta.h"
#include <vector>
#include <random>

class Mazo {
public:
    std::vector<Carta> cartas;
    Mazo();
    void barajar();
    bool vacio() const;
    Carta robar();
    void poner_Abajo(const Carta& c);
    size_t tam() const;
};