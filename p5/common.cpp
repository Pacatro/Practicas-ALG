#include <iostream>
#include <vector>

#include "./headers/common.hpp"

void menu() {
    std::cout << std::endl << "Elija una implementacion de las nReinas:" << std::endl << std::endl;
    std::cout << "1. Backtracking con todas las soluciones." << std::endl;
    std::cout << "2. Backtracking con una solucion." << std::endl;
    std::cout << "3. Las Vegas." << std::endl;
    std::cout << "4. Verficacion de producto de matrices con Montecarlo." << std::endl;
    std::cout << "5. Salir." << std::endl;
}

bool lugar(int k, std::vector<int> &x) {
    for(int i = 0; i < k; i++) {
        if(x[i] == x[k] || std::abs(x[i]-x[k]) == std::abs(i-k))
            return false;
    }

    return true;
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

void fillVector(std::vector<int> &x) {
    for(int i = 0; i < x.size(); i++)
        x[i] = std::rand() % 2;
}