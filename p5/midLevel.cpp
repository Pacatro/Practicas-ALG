#include <iostream>
#include <vector>
#include <cmath>

#include "./headers/midLevel.hpp"
#include "./headers/methods.hpp"
#include "./headers/common.hpp"
#include "./headers/ClaseTiempo.hpp"

void nReinasBacktracking() {
    unsigned int n;
    std::cout << std::endl << "Introduzca el numero de reinas: ";
    std::cin >> n;

    if(n <= 0) {
        std::cerr << std::endl << "ERROR: El valor de n deber ser > 0" << std::endl;
        return;
    }

    std::vector<std::vector<int>> soluciones;

    Clock time;
    time.start();

    nReinasBacktracking(n, soluciones);

    if(time.isStarted()) time.stop();

    if(soluciones.empty()) {
        std::cout << std::endl << "No se ha encontrado ninguna solucion para n = " << n << std::endl;
        return;
    }

    std::cout << std::endl << "Soluciones:" << std::endl;
    escribirSoluciones(soluciones);
    std::cout << std::endl << "Tiempo de ejecucion: " << time.elapsed()*1e-6 << " segundos" << std::endl;
}

void nReinasBacktracking2() {
    unsigned int n;
    std::cout << std::endl << "Introduzca el numero de reinas: ";
    std::cin >> n;

    if(n <= 0) {
        std::cerr << std::endl << "ERROR: El valor de n deber ser > 0" << std::endl;
        return;
    }

    std::vector<int> solucion(n);

    Clock time;
    time.start();

    nReinasBacktracking(n, solucion);

    if(time.isStarted()) time.stop();

    if(solucion.empty()) {
        std::cout << std::endl << "No se ha encontrado ninguna solucion para n = " << n << std::endl;
        return;
    }

    std::cout << std::endl << "Solucion: ";
    escribirSolucion(solucion);
    std::cout << std::endl << "Tiempo de ejecucion: " << time.elapsed()*1e-6 << " segundos" << std::endl;
}

void nReinasLasVegas() {
    unsigned int n;
    std::cout << std::endl << "Introduzca el numero de reinas: ";
    std::cin >> n;

    if(n <= 0) {
        std::cerr << std::endl << "ERROR: El valor de n deber ser > 0" << std::endl;
        return;
    }

    int trys = 0;
    bool success = false;
    std::vector<int> solucion(n);
    
    Clock time;
    time.start();
    
    while(!success){
        success = nReinasLasVegas(n, solucion);
        trys++;
    }

    if(time.isStarted()) time.stop();

    if(solucion.empty()) {
        std::cout << std::endl << "No se ha encontrado ninguna solucion para n = " << n << std::endl;
        return;
    }

    std::cout << std::endl << "Solucion: ";
    escribirSolucion(solucion);

    std::cout << std::endl << "Tiempo de ejecucion: " << time.elapsed()*1e-6 << " segundos" << std::endl;
    std::cout << std::endl << "Intentos: " << trys << std::endl;
}

void monteCarlo() {
    unsigned int n;
    std::cout << std::endl << "Introduzca el orden de la matriz: ";
    std::cin >> n;

    if(n <= 0) {
        std::cerr << std::endl << "ERROR: El valor de n deber ser > 0" << std::endl;
        return;
    }

    std::vector<std::vector<int>> A(n, std::vector<int>(n));
    std::vector<std::vector<int>> B(n, std::vector<int>(n));
    std::vector<std::vector<int>> AB(n, std::vector<int>(n));
    std::vector<std::vector<int>> C(n, std::vector<int>(n));

    fillMatrix(A);
    fillMatrix(B);

    Clock time;
    time.start();

    prodMatrix(A, B, AB);

    if(time.isStarted()) time.stop();

    std::cout << std::endl << "Tiempo en calcular el producto: " << time.elapsed()*1e-6 << " segundos" << std::endl;

    generateC(AB, C);

    int tests;
    std::cout << std::endl << "Indique el numero de pruebas a realizar: ";
    std::cin >> tests;
    
    std::cout << std::endl;

    int nTests;

    time.restart();
    bool success = verifyProdRep(tests, n, nTests, A, B, C);
    if(time.isStarted()) time.stop();

    if(success) {
        double prob = 1.0 - std::pow(0.5, tests);
        std::cout << "El producto si se puede verificar, la probabilidad es del " << prob*100 << "%" << std::endl;
    } else {
        std::cout << "El producto no se puede verificar" << std::endl;
    }

    std::cout << std::endl << "Numero de pruebas realizadas: " << nTests << std::endl;

    std::cout << std::endl << "Tiempo en verificar el producto: " << time.elapsed()*1e-6 << " segundos" << std::endl;
}
