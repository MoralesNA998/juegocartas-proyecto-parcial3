# Solitario Klondike

Este proyecto es una implementación del clásico juego de Solitario Klondike en C++, utilizando la biblioteca FTXUI para crear una interfaz de usuario en terminal.

## Estructura del Proyecto

El proyecto está organizado de la siguiente manera:

```
solitario-klondike
├── src
│   ├── main.cpp        # Punto de entrada de la aplicación.
│   ├── Juego.cpp       # Implementación de la lógica del juego.
│   ├── Juego.h         # Declaración de la clase Juego.
│   ├── Carta.cpp       # Implementación de la clase Carta.
│   ├── Carta.h         # Declaración de la clase Carta.
│   ├── Mazo.cpp        # Implementación de la clase Mazo.
│   ├── Mazo.h          # Declaración de la clase Mazo.
│   ├── Tablero.cpp     # Implementación de la clase Tablero.
│   └── Tablero.h       # Declaración de la clase Tablero.
├── include              # Archivos de encabezado adicionales.
├── bin                  # Binarios generados después de compilar.
├── Makefile             # Instrucciones para compilar el proyecto.
└── README.md            # Documentación del proyecto.
```

## Requisitos

- C++17
- Biblioteca FTXUI

## Compilación

Para compilar el proyecto, navega al directorio del proyecto y ejecuta:

```
make
```

Esto generará el ejecutable en el directorio `bin`.

## Ejecución

Para ejecutar el juego, utiliza el siguiente comando:

```
./bin/programa
```

## Instrucciones de Juego

- El juego comienza con un mazo de cartas que se barajan y se reparten en 7 columnas.
- Las cartas se pueden mover entre columnas y apilar en las fundaciones siguiendo las reglas del Solitario.
- El objetivo es mover todas las cartas a las fundaciones en orden ascendente.

## Contribuciones

Las contribuciones son bienvenidas. Si deseas mejorar el juego o agregar nuevas características, siéntete libre de hacer un fork del repositorio y enviar un pull request.

## Licencia

Este proyecto está bajo la Licencia MIT.