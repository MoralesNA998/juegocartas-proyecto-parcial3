# Juego de Cartas

Este proyecto es un juego de cartas que permite mezclar y repartir cartas utilizando una baraja. A continuación se detallan los archivos y su propósito dentro del proyecto.

## Estructura del Proyecto

```
juego-cartas
├── src
│   ├── main.cpp          # Punto de entrada de la aplicación.
│   ├── barajas
│   │   ├── Baraja.h     # Declaración de la clase Baraja.
│   │   ├── Baraja.cpp   # Implementación de la clase Baraja.
│   │   └── index.h      # Exporta la clase Baraja para otros módulos.
│   └── tipos
│       └── index.h      # Definiciones de tipos y estructuras del juego.
├── CMakeLists.txt       # Configuración para CMake.
└── README.md            # Documentación del proyecto.
```

## Instrucciones para Compilar y Ejecutar

1. **Instalar CMake**: Asegúrate de tener CMake instalado en tu sistema.
2. **Clonar el Repositorio**: Clona este repositorio en tu máquina local.
3. **Crear un Directorio de Construcción**:
   ```bash
   mkdir build
   cd build
   ```
4. **Ejecutar CMake**:
   ```bash
   cmake ..
   ```
5. **Compilar el Proyecto**:
   ```bash
   make
   ```
6. **Ejecutar el Juego**:
   ```bash
   ./juego-cartas
   ```

## Contribuciones

Las contribuciones son bienvenidas. Si deseas mejorar el proyecto, por favor abre un issue o un pull request.