#include <iostream>
#include <vector>
#include "headers/midLevel.hpp"
#include "headers/aux.hpp"
#include "headers/methods.hpp"

void comparacionVariantesQuicksort(int nMin, int nMax, int incremento, 
                                   int repeticiones, int nMediana, int nElementosMinimo){
    std::vector <int> v(5);
    rellenarVector(v);

    std::cout << "Vector original: ";
    printVector(v);

    quicksortMejorado(0, v.size()-1, nMediana, nElementosMinimo, v);
    std::cout << "Vector ordenado: ";
    printVector(v);
}
