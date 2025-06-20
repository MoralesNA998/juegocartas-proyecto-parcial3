#include "Juego.h"
#include <filesystem>
#include <iostream>

Juego::Juego() {
    Reiniciar();
    font.loadFromFile("assets/arial.ttf");
    LoadAssets();
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

void Juego::HandleInput(sf::Keyboard::Key key) {
     std::cout << "Key pressed: " << key << "\n";
    if (victoria && key != sf::Keyboard::R) return;

    if (key == sf::Keyboard::R) {
        std::cout << "Restarting game\n";
        Reiniciar();
    } else if (key == sf::Keyboard::Left && sel_col > 0) {
        sel_col--;
        std::cout << "sel_col: " << sel_col << "\n";
    } else if (key == sf::Keyboard::Right && sel_col < 6) {
        sel_col++;
    } else if (key == sf::Keyboard::Up && sel_row > 0) {
        sel_row--;
    } else if (key == sf::Keyboard::Down) {
        int max_row = tablero.columnas[sel_col].size() - 1;
        if (sel_row < max_row) sel_row++;
    } else if (key == sf::Keyboard::D) {
        tablero.robar_mazo();
    } else if (key == sf::Keyboard::Space) {
        // handle selection logic...
    } else if (key == sf::Keyboard::M) {
        // move selected card
    } else if (key == sf::Keyboard::F) {
        // move to foundation
    } else if (key == sf::Keyboard::C) {
        // move discard to column
    }
}

void Juego::Draw(sf::RenderWindow& window) {
    int x_offset = 20;
    int y_offset = 100;

    for (int col = 0; col < 7; ++col) {
        for (size_t row = 0; row < tablero.columnas[col].size(); ++row) {
            const Carta& carta = tablero.columnas[col][row];
            sf::Sprite sprite = GetCardSprite(carta);
            sprite.setPosition(x_offset + col * 100, y_offset + row * 30);
            window.draw(sprite);

            // Draw selection rectangle
            if (col == sel_col && row == sel_row) {
                sf::RectangleShape rect(sf::Vector2f(sprite.getLocalBounds().width, sprite.getLocalBounds().height));
                rect.setPosition(sprite.getPosition());
                rect.setFillColor(sf::Color::Transparent);
                rect.setOutlineColor(sf::Color::Yellow);
                rect.setOutlineThickness(3);
                window.draw(rect);
            }
        }
    }

    sf::Text msg(mensaje, font, 20);
    msg.setFillColor(sf::Color::White);
    msg.setPosition(10, 10);
    window.draw(msg);
}

void Juego::LoadAssets() {
    std::string path = "assets";
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        if (!entry.is_regular_file()) continue;

        if (entry.path().extension() != ".png") continue;

        std::string key = entry.path().stem().string();  // e.g., "10H", "AS", etc.

        sf::Texture tex;
        if (tex.loadFromFile(entry.path().string())) {
            card_textures[key] = tex;
        } else {
            std::cerr << "Failed to load image: " << entry.path() << '\n';
        }
    }
}

sf::Sprite Juego::GetCardSprite(const Carta& carta) {
    std::string name = carta.key(); // should return "2H", "AS", etc.
    if (!carta.boca_arriba)
        name = "back"; // back.png for face-down

    sf::Sprite sprite;
    if (card_textures.count(name))
        sprite.setTexture(card_textures[name]);
    return sprite;
}