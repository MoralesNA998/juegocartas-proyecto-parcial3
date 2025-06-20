#pragma once
#include "Carta.h"
#include "Mazo.h"
#include <vector>

class Tablero {
public:
    std::vector<std::vector<Carta>> columnas; // 7 columnas
    std::vector<std::vector<Carta>> fundaciones; // 4 fundaciones
    std::vector<Carta> descarte;
    Mazo mazo;

    Tablero();
    void repartir();
    bool mover_Col_a_Col(int from, int to, int cantidad);
    bool mover_Col_a_Fund(int from);
    bool mover_Descarte_a_Col(int to);
    bool mover_Descarte_a_Fund();
    bool victoria() const;
    void robar_Mazo();
    void reciclar_Descarte();
};