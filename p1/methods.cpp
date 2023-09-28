#include "methods.hpp"
#include "sistemaEcuaciones.hpp"

void ordenacionSeleccion(std::vector<int> &v){
    int minPos;
    
    for(int i = 0; i<v.size()-1; i++){
        minPos = i;
        for(int j = i+1; j<v.size(); j++){
            if(v[j] < v[minPos])
                minPos = j;
        }
        int aux = v[i];
        v[i] = v[minPos];
        v[minPos] = aux;
    }
}

void cuadradoMatriz(std::vector<std::vector<double>> &M, std::vector<std::vector<double>> &C){
    multiplicarMatrices(M, M, C);
}