#include <iostream>
#include <vector>
#include "midLevel.hpp"
#include "aux.hpp"
#include "methods.hpp"

void comparacionVariantesQuicksort(int nMin, int nMax, int incremento, 
                                   int repeticiones, int nMediana, int nElementosMinimo){
    std::vector <int> v(30);
    rellenarVector(v);

    std::cout << "Vector original: ";
    printVector(v);

    quicksortMejorado(0, v.size()-1, nMediana, nElementosMinimo, v);
    // std::cout << "Vector ordenado: ";
    // printVector(v);
}
