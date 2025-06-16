#pragma once
#include "Tablero.h"
#include <ftxui/include/component/component.hpp>

class Juego {
public:
    Tablero tablero;
    int sel_col = 0;
    int sel_row = 0;
    bool seleccionando = false;
    int sel_from_col = -1;
    int sel_from_row = -1;
    std::string mensaje;
    bool victoria = false;

    Juego();
    ftxui::Component Render();
    void Reiniciar();
};