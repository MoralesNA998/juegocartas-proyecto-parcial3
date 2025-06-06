#pragma once
#include <vector>
#include "Carta.h"

class Baraja {
private:
    std::vector<Carta> cartas;
public:
    Baraja();
    void mezclar();
    Carta repartir();
    int numeroDeCartas() const;
    void mostrar() const;
};