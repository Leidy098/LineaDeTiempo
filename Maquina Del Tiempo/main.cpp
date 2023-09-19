#include <iostream>
#include <vector>
#include <random>
#include "LineaDeTiempo.h"
using namespace std;

int main() {
    LineaDeTiempo lineaDeTiempo;
    for (int i = 0; i < 22; ++i) {
       lineaDeTiempo.agregarNodoAleatorio();
    }
    lineaDeTiempo.imprimirEventos();
    lineaDeTiempo.imprimir();

    return 0;
}
