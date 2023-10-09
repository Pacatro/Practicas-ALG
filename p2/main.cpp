#include <iostream>
#include <vector>
#include "methods.hpp"
#include "aux.hpp"

int main(){
    std::vector <int> v(5);
    rellenarVector(v);

    std::cout << "Vector sin ordenar: ";
    printVect(v);

    std::cout << std::endl;

    quicksort(0, v.size()-1, v);

    if(!estaOrdenado(v)){
        std::cout << "No esta ordenado." << std::endl;
        return -1;
    }

    std::cout << "Vector ordenado: ";
    printVect(v);

    std::cout << std::endl;

    return 0;
}