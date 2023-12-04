#include <iostream>
#include <vector>

#include "./headers/midLevel.hpp"
#include "./headers/backtracking.hpp"
#include "./headers/ClaseTiempo.hpp"

void nReinasBacktracking() {
    int n;
    std::cout << std::endl << "Introduzca el numero de reinas: ";
    std::cin >> n;

    if(n <= 0) {
        std::cout << "El valor de n deber ser > 0" << std::endl;
        return;
    }

    std::vector<std::vector<int>> soluciones;

    Clock time();
    

    nReinasBacktracking(n, soluciones);

    std::cout << std::endl << "Soluciones:" << std::endl;
    escribirSoluciones(soluciones);
}

void nReinasBacktracking2() {
    int n;
    std::cout << std::endl << "Introduzca el numero de reinas: ";
    std::cin >> n;

    if(n <= 0) {
        std::cout << "El valor de n deber ser > 0" << std::endl;
        return;
    }

    std::vector<int> solucion(n);

    nReinasBacktracking(n, solucion);

    std::cout << std::endl << "Solucion: ";
    escribirSolucion(solucion);
}

void nReinasLasVegas() {
    return;
}