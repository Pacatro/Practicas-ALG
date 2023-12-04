#include <iostream>
#include <vector>

#include "./headers/midLevel.hpp"
#include "./headers/backtracking.hpp"
#include "./headers/lasVegas.hpp"
#include "./headers/common.hpp"
#include "./headers/ClaseTiempo.hpp"

void nReinasBacktracking() {
    int n;
    std::cout << std::endl << "Introduzca el numero de reinas: ";
    std::cin >> n;

    if(n <= 0) {
        std::cerr << "El valor de n deber ser > 0" << std::endl;
        return;
    }

    std::vector<std::vector<int>> soluciones;

    Clock time;
    time.start();

    nReinasBacktracking(n, soluciones);

    if(time.isStarted()) time.stop();

    std::cout << std::endl << "Soluciones:" << std::endl;
    escribirSoluciones(soluciones);
    std::cout << std::endl << "Tiempo de ejecucion: " << time.elapsed()*1e-6 << " segundos" << std::endl;
}

void nReinasBacktracking2() {
    int n;
    std::cout << std::endl << "Introduzca el numero de reinas: ";
    std::cin >> n;

    if(n <= 0) {
        std::cerr << "El valor de n deber ser > 0" << std::endl;
        return;
    }

    std::vector<int> solucion(n);

    Clock time;
    time.start();

    nReinasBacktracking(n, solucion);

    if(time.isStarted()) time.stop();

    std::cout << std::endl << "Solucion: ";
    escribirSolucion(solucion);
    std::cout << std::endl << "Tiempo de ejecucion: " << time.elapsed()*1e-6 << " segundos" << std::endl;
}

void nReinasLasVegas() {
    int n;
    std::cout << std::endl << "Introduzca el numero de reinas: ";
    std::cin >> n;

    if(n <= 0) {
        std::cerr << "El valor de n deber ser > 0" << std::endl;
        return;
    }

    Clock time;
    time.start();

    int trys = 0;
    bool success = false;
    std::vector<int> solucion(n);
    
    while(!success){
        success = nReinasLasVegas(n, solucion);
        trys++;
    }

    if(time.isStarted()) time.stop();

    std::cout << std::endl << "Solucion: ";
    escribirSolucion(solucion);

    std::cout << std::endl << "Tiempo de ejecucion: " << time.elapsed()*1e-6 << " segundos" << std::endl;
    std::cout << "Intentos: " << trys << std::endl;
}