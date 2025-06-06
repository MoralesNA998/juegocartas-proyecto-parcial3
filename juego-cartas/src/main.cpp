#include <iostream>
#include "barajas/Baraja.h"

using namespace std;

int main() {
    Baraja baraja;
    baraja.mezclar();
    std::cout << "Baraja mezclada:\n";
    baraja.mostrar();
    std::cout << "\nCartas restantes: " << baraja.numeroDeCartas() << std::endl;

    return 0;
}