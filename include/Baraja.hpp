#include <iostream>
#include <string.h>
#include "Carta.hpp"
using namespace std;

class Baraja{
    Carta cartas[52];
    string tipoDeCarta[4]{
        tipoDeCarta[0]={"Espadas"};
        tipoDeCarta[1]="Corazones";
        tipoDeCarta[2]="Diamantes";
        tipoDeCarta[3]="Picas";
    };
    void Mezclar(){

    };
    void JugarCarta();
};
