#include "functions.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

void menu() {
    std::cout << "1: Método de ordenación por selección" << std::endl;
    std::cout << "2: cálculo del cuadrado de una matriz" << std::endl;
    std::cout << "3: Cálculo del término n-ésimo de la sucesión de Fibonacci" << std::endl;
}

void rellenarVector(std::vector<int> &v){
    std::srand(std::time(nullptr));
    for(int i = 0; i<v.size(); i++){
        v[i] = std::rand() % 9999999;
    }
}

void ordenacionSeleccion(std::vector<int> &v){
    for(int i = 0; i<v.size()-2; i++){
        int minPos = i;
        for(int j = i+1; j<v.size()-1; j++){
            if(v[i] < v[minPos])
                minPos = j;
        }
        int aux = v[i];
        v[i] = v[minPos];
        v[minPos] = aux;
    }
}