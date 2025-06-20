#include "Juego.h"
#include <filesystem>
#include <iostream>

Juego::Juego()
{
    Reiniciar();
    font.loadFromFile("assets/arial.ttf");
    loadAssets();
}

void Juego::Reiniciar()
{
    tablero.repartir();
    sel_col = 0;
    sel_row = 0;
    seleccionando = false;
    sel_from_col = -1;
    sel_from_row = -1;
    mensaje.clear();
    victoria = false;
}

void Juego::handleInput(sf::Keyboard::Key key)
{
    //std::cout << "Key pressed: " << key << "\n";
    if (victoria && key != sf::Keyboard::R)
        return;

    if (key == sf::Keyboard::R)
    {
        //std::cout << "Restarting game\n";
        Reiniciar();
    }
    else if (key == sf::Keyboard::Left && sel_col > 0)
    {
        sel_col--;
        //std::cout << "sel_col: " << sel_col << "\n";
    }
    else if (key == sf::Keyboard::Right && sel_col < 6)
    {
        sel_col++;
    }
    else if (key == sf::Keyboard::Up && sel_row > 0)
    {
        sel_row--;
    }
    else if (key == sf::Keyboard::Down)
    {
        int max_row = tablero.columnas[sel_col].size() - 1;
        if (sel_row < max_row)
            sel_row++;
    }
    else if (key == sf::Keyboard::D)
    {
        tablero.robar_Mazo();
    }
    else if (key == sf::Keyboard::Space)
    {
        if (!seleccionando)
        {
            if (sel_row < static_cast<int>(tablero.columnas[sel_col].size()) &&
                tablero.columnas[sel_col][sel_row].boca_arriba)
            {
                sel_from_col = sel_col;
                sel_from_row = sel_row;
                seleccionando = true;
                mensaje = "Carta seleccionada";
                //std::cout << "Seleccionando carta en columna " << sel_col << ", fila " << sel_row << "\n";
            }
            else
            {
                mensaje = "No se puede seleccionar esta carta";
            }
        }
        else
        {
            seleccionando = false;
            mensaje = "Seleccion cancelada";
            //std::cout << "Seleccion cancelada\n";
        }
    }
    else if (key == sf::Keyboard::M)
    {
        if (seleccionando)
        {
            int cantidad = tablero.columnas[sel_from_col].size() - sel_from_row;
            bool ok = tablero.mover_Col_a_Col(sel_from_col, sel_col, cantidad);
            mensaje = ok ? "Movimiento exitoso" : "Movimiento invalido";
            std::cout << (ok ? "Movido!" : "Movimiento fallido") << "\n";
            seleccionando = false;
        }
        else
        {
            mensaje = "No hay carta seleccionada";
        }
    }
    else if (key == sf::Keyboard::F)
    {
        if (!seleccionando)
        {
            bool ok = tablero.mover_Col_a_Fund(sel_col);
            mensaje = ok ? "Enviado a fundacion" : "No se pudo mover a fundacion";
            std::cout << mensaje << "\n";
        }
        else
        {
            mensaje = "No se puede usar fundacion con carta seleccionada";
        }
    }
    else if (key == sf::Keyboard::C)
    {
        bool ok = tablero.mover_Descarte_a_Col(sel_col);
        mensaje = ok ? "Carta movida desde descarte" : "Movimiento invalido desde descarte";
        std::cout << mensaje << "\n";
    }
    else if (key == sf::Keyboard::N)
        if (sel_row < static_cast<int>(tablero.columnas[sel_col].size()))
        {
            Carta &carta = tablero.columnas[sel_col][sel_row];
            carta.boca_arriba = !carta.boca_arriba;
            mensaje = carta.boca_arriba ? "Carta volteada boca arriba" : "Carta volteada boca abajo";
            //std::cout << "Carta en columna " << sel_col << ", fila " << sel_row
                      //<< " ahora está " << (carta.boca_arriba ? "boca arriba" : "boca abajo") << "\n";
        }
        else
        {
            mensaje = "No hay carta para voltear";
            std::cout << "Intento de voltear carta inexistente\n";
        }
}

void Juego::Draw(sf::RenderWindow &window)
{
    int x_offset = 20;
    int y_offset = 100;

    for (int col = 0; col < 7; ++col)
    {
        for (size_t row = 0; row < tablero.columnas[col].size(); ++row)
        {
            const Carta &carta = tablero.columnas[col][row];
            sf::Sprite sprite = getCardSprite(carta);
            sprite.setPosition(x_offset + col * 100, y_offset + row * 30);
            window.draw(sprite);

            // Para el rectangulo de seleccion, permitiendo conocer que carta esta seleccionada
            if (col == sel_col && row == sel_row)
            {
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

void Juego::loadAssets()
{
    std::string path = "assets";
    for (const auto &entry : std::filesystem::directory_iterator(path))
    {
        if (!entry.is_regular_file())
            continue;

        if (entry.path().extension() != ".png")
            continue;

        std::string key = entry.path().stem().string(); // e.g., "10H", etc.

        sf::Texture tex;
        if (tex.loadFromFile(entry.path().string()))
        {
            card_textures[key] = tex;
        }
        else
        {
            std::cerr << "Failed to load image: " << entry.path() << '\n';
        }
    }
}

sf::Sprite Juego::getCardSprite(const Carta &carta)
{
    std::string name = carta.key();
    if (!carta.boca_arriba)
        name = "back";

    sf::Sprite sprite;
    if (card_textures.count(name))
    {
        sprite.setTexture(card_textures[name]);
    }
    else
    {
        //std::cerr << "Missing texture: " << name << "\n";
    }

    return sprite;
}