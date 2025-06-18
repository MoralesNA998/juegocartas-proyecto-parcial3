#pragma once
#include "Tablero.h"
#include <SFML/Graphics.hpp>

class Juego {
public:
    Juego();
    void Reiniciar();

    void Draw(sf::RenderWindow& window);
    void HandleInput(sf::Keyboard::Key key);

private:
    Tablero tablero;
    int sel_col;
    int sel_row;
    bool seleccionando;
    int sel_from_col;
    int sel_from_row;
    std::string mensaje;
    bool victoria;

    sf::Font font;
    std::map<std::string, sf::Texture> card_textures;

    void LoadAssets();
    sf::Sprite GetCardSprite(const Carta& carta);
};