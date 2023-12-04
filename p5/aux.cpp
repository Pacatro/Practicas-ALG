#include <iostream>
#include <vector>

#include "./headers/aux.hpp"

void menu() {
    std::cout << std::endl << "Elija una implementacion de las nReinas:" << std::endl;
    std::cout << "1. Backtracking con todas las soluciones." << std::endl;
    std::cout << "2. Backtracking con una solucion." << std::endl;
    std::cout << "3. Las Vegas." << std::endl;
    std::cout << "4. Salir." << std::endl;
}

bool lugar(int k, std::vector<int> &x) {
    for(int i = 0; i < k; i++) {
        if(x[i] == x[k] || std::abs(x[i]-x[k]) == std::abs(i-k))
            return false;
    }

    return true;
}