#include "Juego.h"
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/event.hpp>
using namespace ftxui;

Juego::Juego() {
    Reiniciar();
}

void Juego::Reiniciar() {
    tablero.repartir();
    sel_col = 0;
    sel_row = 0;
    seleccionando = false;
    sel_from_col = -1;
    sel_from_row = -1;
    mensaje.clear();
    victoria = false;
}

Component Juego::Render() {
    auto render = Renderer([&] {
        std::vector<Element> columnas_ui;
        for (int i = 0; i < 7; ++i) {
            std::vector<Element> cartas_ui;
            for (size_t j = 0; j < tablero.columnas[i].size(); ++j) {
                auto& c = tablero.columnas[i][j];
                auto txt = text(c.str());
                if (c.boca_arriba) {
                    txt = txt | (c.color() == "red" ? color(Color::Red) : color(Color::White));
                }
                if (sel_col == i && sel_row == (int)j && !seleccionando)
                    txt = txt | inverted;
                if (seleccionando && sel_from_col == i && sel_from_row == (int)j)
                    txt = txt | inverted | bold;
                cartas_ui.push_back(txt);
            }
            if (columnas_ui.size() < 7)
                columnas_ui.push_back(vbox(std::move(cartas_ui)) | border | size(WIDTH, EQUAL, 7));
        }

        // Fundaciones
        std::vector<Element> fund_ui;
        for (int i = 0; i < 4; ++i) {
            std::string label = " ";
            if (!tablero.fundaciones[i].empty())
                label = tablero.fundaciones[i].back().str();
            fund_ui.push_back(text(label) | border);
        }

        // Mazo y descarte
        Element mazo_ui = text(tablero.mazo.vacio() ? " " : "##") | border;
        Element descarte_ui = text(tablero.descarte.empty() ? " " : tablero.descarte.back().str()) | border;

        // Mensaje de victoria
        Element msg = text(victoria ? "¡Victoria! (r para reiniciar)" : mensaje) | color(Color::Green);

        return vbox({
            hbox({ mazo_ui, text(" "), descarte_ui, text("   "), hbox(std::move(fund_ui)) }),
            separator(),
            hbox(std::move(columnas_ui)),
            separator(),
            msg,
            text("Flechas: mover | Espacio: seleccionar | m: mover | d: robar | f: a fundación | r: reiniciar")
        });
    });

    auto input = CatchEvent(render, [&](const ftxui::Event& event) -> bool {
        if (victoria && event != Event::Character('r')) return false;

        if (event == Event::Character('r')) {
            Reiniciar();
            return true;
        }
        if (event == Event::ArrowLeft && sel_col > 0) {
            sel_col--;
            sel_row = std::min(sel_row, (int)tablero.columnas[sel_col].size()-1);
            return true;
        }
        if (event == Event::ArrowRight && sel_col < 6) {
            sel_col++;
            sel_row = std::min(sel_row, (int)tablero.columnas[sel_col].size()-1);
            return true;
        }
        if (event == Event::ArrowUp && sel_row > 0) {
            sel_row--;
            return true;
        }
        if (event == Event::ArrowDown && sel_row < (int)tablero.columnas[sel_col].size()-1) {
            sel_row++;
            return true;
        }
        if (event == Event::Character('d')) {
            tablero.robar_mazo();
            mensaje.clear();
            return true;
        }
        if (event == Event::Character(' ')) {
            // Seleccionar carta
            if (!seleccionando && !tablero.columnas[sel_col].empty() && tablero.columnas[sel_col][sel_row].boca_arriba) {
                seleccionando = true;
                sel_from_col = sel_col;
                sel_from_row = sel_row;
                mensaje = "Selecciona columna destino y presiona 'm'";
            } else if (seleccionando) {
                seleccionando = false;
                sel_from_col = -1;
                sel_from_row = -1;
                mensaje.clear();
            }
            return true;
        }
        if (event == Event::Character('m')) {
            // Mover carta seleccionada a columna actual
            if (seleccionando && sel_from_col != -1 && sel_from_row != -1) {
                int cantidad = tablero.columnas[sel_from_col].size() - sel_from_row;
                if (tablero.mover_col_a_col(sel_from_col, sel_col, cantidad)) {
                    mensaje = "Movimiento realizado";
                    seleccionando = false;
                    sel_from_col = -1;
                    sel_from_row = -1;
                } else {
                    mensaje = "Movimiento inválido";
                }
                if (tablero.victoria()) {
                    victoria = true;
                    mensaje = "¡Victoria!";
                }
            }
            return true;
        }
        if (event == Event::Character('f')) {
            // Mover carta seleccionada o descarte a fundación
            if (seleccionando && sel_from_col != -1 && sel_from_row != -1) {
                if (tablero.mover_col_a_fund(sel_from_col)) {
                    mensaje = "A fundación";
                    seleccionando = false;
                    sel_from_col = -1;
                    sel_from_row = -1;
                } else {
                    mensaje = "No se puede mover a fundación";
                }
                if (tablero.victoria()) {
                    victoria = true;
                    mensaje = "¡Victoria!";
                }
            } else if (!tablero.descarte.empty()) {
                if (tablero.mover_descarte_a_fund()) {
                    mensaje = "Descarte a fundación";
                } else {
                    mensaje = "No se puede mover descarte";
                }
                if (tablero.victoria()) {
                    victoria = true;
                    mensaje = "¡Victoria!";
                }
            }
            return true;
        }
        if (event == Event::Character('c')) {
            // Mover descarte a columna seleccionada
            if (!tablero.descarte.empty()) {
                if (tablero.mover_descarte_a_col(sel_col)) {
                    mensaje = "Descarte a columna";
                } else {
                    mensaje = "No se puede mover descarte";
                }
            }
            return true;
        }
        return false;
    });

    return input;
}