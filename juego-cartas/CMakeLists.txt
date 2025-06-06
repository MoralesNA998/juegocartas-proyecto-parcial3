cmake_minimum_required(VERSION 3.10)

project(juego_cartas)

set(CMAKE_CXX_STANDARD 11)

include_directories(src/barajas src/tipos)

file(GLOB SOURCES "src/*.cpp" "src/barajas/*.cpp")

add_executable(juego_cartas ${SOURCES})