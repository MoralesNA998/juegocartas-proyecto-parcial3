# juegocartas-proyecto-parcial3
# Solitario

Implementación del clásico Solitario Klondike en C++ con gráficos usando SFML.

---

# 📁 Estructura del Proyecto # 

```
solitario
├── src
│   ├── main.cpp        # Punto de entrada de la aplicación
│   ├── Juego.cpp       # Lógica principal del juego y controles
│   ├── Carta.cpp       # Implementación de la clase Carta
│   ├── Mazo.cpp        # Implementación de la clase Mazo
│   └── Tablero.cpp     # Implementación de la clase Tablero
├── include   
│   ├── Juego.h         # Declaración de la clase Juego
│   ├── Carta.h         # Declaración de la clase Carta
│   ├── Mazo.h          # Declaración de la clase Mazo
│   └── Tablero.h       # Declaración de la clase Tablero
├── assets              # Imágenes y fuentes utilizadas por el juego
├── bin                 # Binarios generados después de compilar
├── Makefile            # Instrucciones para compilar el proyecto
└── README.md           # Documentación del proyecto
```

---

## ⚙️ Requisitos ##

- **C++17** o superior
- **SFML** (Simple and Fast Multimedia Library)
- Imágenes de cartas y fuente (`assets/`)

---

### 🚀 Instalación y Ejecución ###

1. **Clona el repositorio:**
   ```
   git clone https://github.com/MoralesNA998/juegocartas-proyecto-parcial3.git
   cd juegocartas-proyecto-parcial3
   ```

2. **Instala las dependencias necesarias** (por ejemplo, SFML).

3. **Compila el proyecto:**
   ```
   make clean && make
   ```
   El ejecutable aparecerá en el directorio `bin`.

4. **Ejecuta el juego:**
   ```
   ./bin/programa
   ```

---

#### 🃏 ¿Cómo se juega? ####

- El juego comienza con un mazo de cartas barajadas y repartidas en 7 columnas.
- El objetivo es mover todas las cartas a las fundaciones (parte superior) en orden ascendente (A, 2, 3, ..., K) y por palo.
- Puedes mover cartas entre columnas siguiendo las reglas clásicas del Solitario Klondike: alternando colores y en orden descendente.
- Solo los Reyes pueden moverse a columnas vacías.

---

##### 🎮 Controles #####

- **Flechas Izquierda/Derecha**: Mover la selección entre columnas.
- **Flechas Arriba/Abajo**: Mover la selección entre cartas de la columna.
- **Espacio**: Seleccionar o marcar carta.
- **M**: Mover la carta seleccionada.
- **F**: Mover la carta seleccionada a la fundación.
- **C**: Mover la carta del descarte a una columna.
- **D**: Robar carta del mazo.
- **R**: Reiniciar la partida.

> **Nota:** Consulta los mensajes en pantalla para ayuda adicional.

---

###### 🤝 Contribuciones ######

¡Las contribuciones son bienvenidas! Si deseas mejorar el juego o agregar nuevas características, haz un fork del repositorio y envía un pull request.

---

###### Imagenes del proyecto ######
![Foto proyecto compilado](/Imagenes_proyecto_links_en_README/Captura1.png)
![Carta seleccionada](/Imagenes_proyecto_links_en_README/Captura2.png)
![Carta movida](/Imagenes_proyecto_links_en_README/Captura3.png)