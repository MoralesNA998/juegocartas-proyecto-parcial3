cmake_minimum_required(VERSION 3.14)
project(Solitario)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch FTXUI from your local directory (you already cloned it)
add_subdirectory(FTXUI)

# Define your executable
add_executable(programa
    src/main.cpp
    src/Carta.cpp
    src/Mazo.cpp
    src/Tablero.cpp
    src/Juego.cpp
)

# Add include directory
target_include_directories(programa PRIVATE include)

# Link with FTXUI
target_link_libraries(programa PRIVATE ftxui::component ftxui::screen ftxui::dom)