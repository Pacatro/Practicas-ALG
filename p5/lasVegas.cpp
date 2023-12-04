#include <vector>
#include <iostream>
#include <cstdlib>

#include "./headers/lasVegas.hpp"
#include "./headers/common.hpp"

bool nReinasLasVegas(int n, std::vector<int> &solucion) {
    for(int i = 0; i < solucion.size(); i++)
        solucion[i] = 0;

    
    for(int k = 0; k < n; k++) {
        int cont = -1;
        std::vector<int> ok(n);

        for(int j = 0; j < n; j++) {
            solucion[k] = j;

            if(lugar(k, solucion)) {
                cont++;
                ok[cont] = j;
            }   
        }

        if(cont == -1) return false;

        int colum = ok[std::rand() % (cont+1)];
        solucion[k] = colum;
    }

    return true;
}