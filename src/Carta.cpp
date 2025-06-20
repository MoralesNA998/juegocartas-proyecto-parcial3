#include "Carta.h"

Carta::Carta(int v, Palo p, bool b) : valor(v), palo(p), boca_arriba(b) {}

std::string Carta::key() const {
    std::string val;
    if (valor == 1) val = "A";
    else if (valor == 11) val = "J";
    else if (valor == 12) val = "Q";
    else if (valor == 13) val = "K";
    else val = std::to_string(valor);

    char suitChar;
    switch (palo) {
        case Palo::Corazones: suitChar = 'H'; break;
        case Palo::Diamantes: suitChar = 'D'; break;
        case Palo::Treboles:  suitChar = 'C'; break; // C for clubs
        case Palo::Picas:     suitChar = 'S'; break;
    }

    return val + suitChar;
}

std::string Carta::color() const {
    if (palo == Palo::Corazones || palo == Palo::Diamantes)
        return "red";
    return "black";
}