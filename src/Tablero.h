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
    bool mover_col_a_col(int from, int to, int cantidad);
    bool mover_col_a_fund(int from);
    bool mover_descarte_a_col(int to);
    bool mover_descarte_a_fund();
    bool victoria() const;
    void robar_mazo();
    void reciclar_descarte();
};