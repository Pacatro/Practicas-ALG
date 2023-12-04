#include <vector>
#include <iostream>
#include <cstdlib>

#include "./headers/lasVegas.hpp"
#include "./headers/common.hpp"

bool nReinasLasVegas(int n, std::vector<int> &solucion) {
    for(int i = 0; i < n; i++)
        solucion[i] = 0;

    int cont;
    std::vector<int> ok(n);

    for(int k = 0; k < n; k++) {
        cont = -1;

        for(int j = 0; j < n; j++) {
            solucion[k] = j;

            if(lugar(k, solucion)) {
                cont++;
                ok[cont] = j;
            }   
        }

        if(cont == -1) break;

        int colum = ok[std::rand() % (cont+1)];
        solucion[k] = colum;
    }

    if(cont == -1)
        return false;
    
    return true;
}