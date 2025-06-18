#include "Juego.h"
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Juego de Cartas");

    Juego juego;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                juego.HandleInput(event.key.code);
            }
        }

        window.clear(sf::Color::Green);
        juego.Draw(window);
        window.display();
    }

    return 0;
}