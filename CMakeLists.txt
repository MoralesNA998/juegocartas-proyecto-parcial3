cmake_minimum_required(VERSION 3.14)
project(Solitario)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(programa
    src/main.cpp
    src/Carta.cpp
    src/Mazo.cpp
    src/Tablero.cpp
    src/Juego.cpp
)

target_include_directories(programa PRIVATE include)
target_link_libraries(programa PRIVATE sfml-graphics sfml-window sfml-system)