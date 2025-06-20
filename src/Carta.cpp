#include "Carta.h"

Carta::Carta(int v, Palo p, bool b) : valor(v), palo(p), boca_arriba(b) {}

std::string Carta::key() const
{
    std::string val;
    if (valor == 1)
        val = "A";
    else if (valor == 11)
        val = "J";
    else if (valor == 12)
        val = "Q";
    else if (valor == 13)
        val = "K";
    else
        val = std::to_string(valor);

    char suitChar;
    switch (palo)
    {
    case Palo::Corazones:
        suitChar = 'H';
        break; //H para Hearts
    case Palo::Diamantes:
        suitChar = 'D';
        break; //D para Diamonds
    case Palo::Treboles:
        suitChar = 'C';
        break; // C para clubs (Como lo escriben en ingles)
    case Palo::Picas:
        suitChar = 'S';
        break; //S para Spades
    }

    return val + suitChar;
}

std::string Carta::color() const
{
    if (palo == Palo::Corazones || palo == Palo::Diamantes)
        return "red";
    return "black";
}