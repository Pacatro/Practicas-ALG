#include <iostream>
#include <vector>
#include "methods.hpp"
#include "aux.hpp"

int main(){
    std::vector <int> v(50);
    rellenarVector(v);

    std::cout << "Vector sin ordenar: ";
    printVect(v);

    std::cout << std::endl;

    quicksortMejorado(0, v.size()-1, 5, v);

    if(!estaOrdenado(v)){
        std::cout << "No esta ordenado." << std::endl;
        std::cout << "Vector: ";
        printVect(v);
        return -1;
    }

    std::cout << "Vector ordenado: ";
    printVect(v);

    std::cout << std::endl;

    return 0;
}