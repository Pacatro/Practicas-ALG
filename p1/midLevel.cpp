#include <vector>
#include <iostream>
#include "aux.hpp"
#include "stats.hpp"
#include "times.hpp"

void ordenacionSeleccion(){
    std::vector <double> tiemposReales;
    std::vector <double> numeroElementos;
    std::vector <double> a(3);
    std::vector <double> tiemposEstimados;
    int nMin, nMax, increment, rep;
    double coefDet;

    std::cout << "Introduzca el minimo de elementos: ";
    std::cin >> nMin;

    std::cout << "Introduzca el maximo de elementos: ";
    std::cin >> nMax;

    std::cout << "Introduzca el incremento: ";
    std::cin >> increment;

    std::cout << "Introduzca el numero de repeticiones: ";
    std::cin >> rep;

    if(nMax < nMin || nMax == 0 || nMin == 0 || increment == 0 || rep == 0){
        std::cout << std::endl << "Numeros incorrectos." << std::endl;
        return;
    }

    std::cout << "Calculando tiempos..." << std::endl;

    tiemposOrdenacionSelección(nMin, nMax, increment, rep, tiemposReales, numeroElementos);
    almacenarFichero(tiemposReales, numeroElementos);
    ajusteCuadratico(numeroElementos, tiemposReales, a);

    std::cout << std::endl;
    std::cout << "Incognitas: " << std::endl;
    std::cout << "a0 = " << a[0] << std::endl;
    std::cout << "a1 = " << a[1] << std::endl;
    std::cout << "a2 = " << a[2] << std::endl;

    calcularTiemposEstimadosPolinomico(numeroElementos, a, tiemposEstimados);

    coefDet = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);

    std::cout << "Coeficiente de determinacion: " << coefDet << std::endl;

    almacenarDatosFichero(tiemposReales, numeroElementos, tiemposEstimados);
    tiemposN(a);
}

void matrizCuadrado(){
    std::vector <double> tiemposReales;
    std::vector <double> numeroOrdenes;
    std::vector <double> a(4);
    std::vector <double> tiemposEstimados;
    int nMin, nMax, increment;
    double coefDet;

    std::cout << "Introduzca el orden minimo de la matriz: ";
    std::cin >> nMin;

    std::cout << "Introduzca el orden maximo de la matriz: ";
    std::cin >> nMax;

    std::cout << "Introduzca el incremento: ";
    std::cin >> increment;

    if(nMax < nMin || nMax == 0 || nMin == 0 || increment == 0){
        std::cout << std::endl << "Numeros incorrectos." << std::endl;
        return;
    }

    std::cout << "Calculando tiempos..." << std::endl;

    tiemposCuadradoMatriz(nMin, nMax, increment, tiemposReales, numeroOrdenes);
    almacenarFichero(tiemposReales, numeroOrdenes);
    ajusteCubico(numeroOrdenes, tiemposReales, a);

    std::cout << std::endl;
    std::cout << "Incognitas: " << std::endl;
    std::cout << "a0 = " << a[0] << std::endl;
    std::cout << "a1 = " << a[1] << std::endl;
    std::cout << "a2 = " << a[2] << std::endl;
    std::cout << "a3 = " << a[3] << std::endl;

    calcularTiemposEstimadosPolinomico(numeroOrdenes, a, tiemposEstimados);
    
    coefDet = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);

    std::cout << "Coeficiente de determinacion: " << coefDet << std::endl;

    almacenarDatosFichero(tiemposReales, numeroOrdenes, tiemposEstimados);
    tiemposN(a);
}

void fibonacciRecursivo(){
    std::vector <double> tiemposReales;
    std::vector <double> tiemposEstimados;
    std::vector <double> n;
    std::vector <double> a(2);
    int nMin, nMax, increment;
    double coefDet;
    
    std::cout << "Introduzca el minimo de elementos: ";
    std::cin >> nMin;

    std::cout << "Introduzca el maximo de elementos: ";
    std::cin >> nMax;

    std::cout << "Introduzca el incremento: ";
    std::cin >> increment;

    if(nMax < nMin || nMax == 0 || nMin == 0 || increment == 0){
        std::cout << std::endl << "Numeros incorrectos." << std::endl;
        return;
    }

    std::cout << "Calculando tiempos..." << std::endl;
    
    tiemposFibonacciRecursivo(nMin, nMax, increment, tiemposReales, n);
    almacenarFichero(tiemposReales, n);
    ajusteExponencial(n, tiemposReales, a);

    std::cout << std::endl;
    std::cout << "Incognitas: " << std::endl;
    std::cout << "a0 = " << a[0] << std::endl;
    std::cout << "a1 = " << a[1] << std::endl;

    calcularTiemposEstimadosExponencial(n, tiemposReales, a, tiemposEstimados);

    coefDet = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);

    std::cout << "Coeficiente de determinacion: " << coefDet << std::endl;

    almacenarDatosFichero(tiemposReales, n, tiemposEstimados);
    tiemposExponencialN(a);
}
