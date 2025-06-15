#include "Carta.h"

Carta::Carta(int v, Palo p, bool b) : valor(v), palo(p), boca_arriba(b) {}

std::string Carta::str() const {
    if (!boca_arriba) return "??";
    std::string val;
    if (valor == 1) val = "A";
    else if (valor == 11) val = "J";
    else if (valor == 12) val = "Q";
    else if (valor == 13) val = "K";
    else val = std::to_string(valor);

    std::string pal;
    switch (palo) {
        case Palo::Corazones: pal = "♥"; break;
        case Palo::Diamantes: pal = "♦"; break;
        case Palo::Treboles:  pal = "♣"; break;
        case Palo::Picas:     pal = "♠"; break;
    }
    return val + pal;
}

std::string Carta::color() const {
    if (palo == Palo::Corazones || palo == Palo::Diamantes)
        return "red";
    return "black";
}