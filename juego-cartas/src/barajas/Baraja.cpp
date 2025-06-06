#include "Baraja.h"
#include <algorithm>
#include <random>
#include <iostream>

Baraja::Baraja() {
    cartas.clear();
    for (int p = 0; p < 4; ++p) {
        for (int v = 1; v <= 13; ++v) {
            cartas.emplace_back(v, static_cast<Palo>(p));
        }
    }
}

void Baraja::mezclar() {
    std::shuffle(cartas.begin(), cartas.end(), std::mt19937{std::random_device{}()});
}

Carta Baraja::repartir() {
    Carta carta = cartas.back();
    cartas.pop_back();
    return carta;
}

int Baraja::numeroDeCartas() const {
    return cartas.size();
}

void Baraja::mostrar() const {
    for (const auto& carta : cartas) {
        std::cout << carta.toString() << std::endl;
    }
}