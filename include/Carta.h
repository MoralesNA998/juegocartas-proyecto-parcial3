#pragma once
#include <string>

enum class Palo { Corazones, Diamantes, Treboles, Picas };

class Carta {
public:
    int valor; // 1 = As, 11 = J, 12 = Q, 13 = K
    Palo palo;
    bool boca_arriba;

    Carta(int v, Palo p, bool b = false);
    std::string str() const;
    std::string color() const;
    std::string key() const;
};