#include <iostream>
#include <vector>

#include "./headers/common.hpp"

void menu() {
    std::cout << std::endl << "Elija una implementacion:" << std::endl << std::endl;
    std::cout << "1. Backtracking con todas las soluciones (n-reinas)." << std::endl;
    std::cout << "2. Backtracking con una solucion. (n-reinas)" << std::endl;
    std::cout << "3. Las Vegas. (n-reinas)" << std::endl;
    std::cout << "4. Verficacion de producto de matrices con Montecarlo." << std::endl;
    std::cout << "5. Salir." << std::endl;
}

void escribirSoluciones(std::vector<std::vector<int>> &soluciones) {
    for(int i = 0; i < soluciones.size(); i++) {
        std::cout << "[ ";
        for(int j = 0; j < soluciones[i].size(); j++)
            std::cout << soluciones[i][j] << " ";

        std::cout << "]" << std::endl;
    }
}

void escribirSolucion(std::vector<int> &solucion) {
    std::cout << "[ ";
    for(int i = 0; i < solucion.size(); i++)
        std::cout << solucion[i] << " ";
    std::cout << "]" << std::endl;
}

void fillMatrix(std::vector<std::vector<int>> &m) {
    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[i].size(); j++)
            m[i][j] = (std::rand() % 3) - 1;
    }
}

void fillVector(int n, std::vector<std::vector<int>> &X) {
    std::vector<int> x(n);
    
    for(int i = 0; i < x.size(); i++)
        x[i] = std::rand() % 2;

    X.push_back(x);
}