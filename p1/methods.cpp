#include "methods.hpp"
#include "sistemaEcuaciones.hpp"

//O(n²)
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

//O(n²)
void cuadradoMatriz(std::vector<std::vector<double>> &M, std::vector<std::vector<double>> &C){
    multiplicarMatrices(M, M, C);
}

//O(2^n)
int fibonacciRecursivo(int n){
    if(n <= 1)
        return 1;
    return fibonacciRecursivo(n-1) + fibonacciRecursivo(n-2);
}