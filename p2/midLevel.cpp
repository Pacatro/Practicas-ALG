#include <iostream>
#include <vector>
#include "headers/midLevel.hpp"
#include "headers/aux.hpp"
#include "headers/times.hpp"

void comparacionVariantesQuicksort(int nMin, int nMax, int incremento, 
                                   int repeticiones, int nMediana, int nElementosMinimo){
    std::vector <double> tiemposRealesQS1;
    std::vector <double> tiemposRealesQS2;
    std::vector <double> numeroElementos;

    tiemposOrdenacionVariantesQuicksort(nMin, nMax, incremento, repeticiones, nMediana, nElementosMinimo, 
                                        tiemposRealesQS1, tiemposRealesQS2, numeroElementos);

    printVector(tiemposRealesQS1);
    printVector(tiemposRealesQS2);
}
