#include "Tablero.h"
#include <algorithm>

Tablero::Tablero() : columnas(7), fundaciones(4), mazo() {}

void Tablero::repartir() {
    columnas = std::vector<std::vector<Carta>>(7);
    fundaciones = std::vector<std::vector<Carta>>(4);
    descarte.clear();
    mazo = Mazo();
    mazo.barajar();
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j <= i; ++j) {
            Carta c = mazo.robar();
            c.boca_arriba = (j == i);
            columnas[i].push_back(c);
        }
    }
}

bool Tablero::mover_col_a_col(int from, int to, int cantidad) {
    if (from < 0 || from >= 7 || to < 0 || to >= 7 || from == to) return false;
    if (columnas[from].size() < cantidad) return false;
    auto it = columnas[from].end() - cantidad;
    if (!it->boca_arriba) return false;

    // Validar reglas de movimiento
    Carta& carta_mover = *it;
    if (columnas[to].empty()) {
        if (carta_mover.valor != 13) return false; // Solo rey en columna vacía
    } else {
        Carta& carta_destino = columnas[to].back();
        if (!carta_destino.boca_arriba) return false;
        if (carta_mover.color() == carta_destino.color()) return false;
        if (carta_mover.valor != carta_destino.valor - 1) return false;
    }
    columnas[to].insert(columnas[to].end(), it, columnas[from].end());
    columnas[from].erase(it, columnas[from].end());
    if (!columnas[from].empty())
        columnas[from].back().boca_arriba = true;
    return true;
}

bool Tablero::mover_col_a_fund(int from) {
    if (from < 0 || from >= 7 || columnas[from].empty()) return false;
    Carta carta = columnas[from].back();
    if (!carta.boca_arriba) return false;
    int idx = static_cast<int>(carta.palo);
    if (fundaciones[idx].empty()) {
        if (carta.valor != 1) return false;
    } else {
        if (fundaciones[idx].back().valor != carta.valor - 1) return false;
    }
    fundaciones[idx].push_back(carta);
    columnas[from].pop_back();
    if (!columnas[from].empty())
        columnas[from].back().boca_arriba = true;
    return true;
}

bool Tablero::mover_descarte_a_col(int to) {
    if (descarte.empty()) return false;
    Carta carta = descarte.back();
    if (columnas[to].empty()) {
        if (carta.valor != 13) return false;
    } else {
        Carta& carta_destino = columnas[to].back();
        if (!carta_destino.boca_arriba) return false;
        if (carta.color() == carta_destino.color()) return false;
        if (carta.valor != carta_destino.valor - 1) return false;
    }
    columnas[to].push_back(carta);
    descarte.pop_back();
    return true;
}

bool Tablero::mover_descarte_a_fund() {
    if (descarte.empty()) return false;
    Carta carta = descarte.back();
    int idx = static_cast<int>(carta.palo);
    if (fundaciones[idx].empty()) {
        if (carta.valor != 1) return false;
    } else {
        if (fundaciones[idx].back().valor != carta.valor - 1) return false;
    }
    fundaciones[idx].push_back(carta);
    descarte.pop_back();
    return true;
}

bool Tablero::victoria() const {
    for (const auto& f : fundaciones)
        if (f.size() != 13) return false;
    return true;
}

void Tablero::robar_mazo() {
    if (mazo.vacio()) {
        reciclar_descarte();
        return;
    }
    Carta c = mazo.robar();
    c.boca_arriba = true;
    descarte.push_back(c);
}

void Tablero::reciclar_descarte() {
    std::reverse(descarte.begin(), descarte.end());
    for (auto& c : descarte) {
        c.boca_arriba = false;
        mazo.cartas.push_back(c);
    }
    descarte.clear();
}