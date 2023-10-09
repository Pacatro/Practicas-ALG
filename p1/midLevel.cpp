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
    long int n;
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

    //std::cout << "Calculando tiempos..." << std::endl;
    std::cout << std::endl;

    tiemposOrdenacionSelección(nMin, nMax, increment, rep, tiemposReales, numeroElementos);
    almacenarFichero(tiemposReales, numeroElementos);
    ajusteCuadratico(numeroElementos, tiemposReales, a);

    std::cout << std::endl;
    std::cout << "t = " << a[0] << " + " << a[1] << "*n + " << a[2] << "*n²" << std::endl;

    calcularTiemposEstimadosPolinomico(numeroElementos, a, tiemposEstimados);

    coefDet = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);

    std::cout << "Coeficiente de determinacion: " << coefDet << std::endl;

    almacenarDatosFichero(tiemposReales, numeroElementos, tiemposEstimados);

    while(true){
        std::cout << std::endl << "Introduzca n (0 para salir): ";
        std::cin >> n;
        if(n == 0) return;
        long double t = calcularTiempoEstimadoPolinomico(n, a);
        tiemposN(n, t);
    }
}

void matrizCuadrado(){
    std::vector <double> tiemposReales;
    std::vector <double> numeroOrdenes;
    std::vector <double> a(4);
    std::vector <double> tiemposEstimados;
    int nMin, nMax, increment;
    long int n;
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

    //std::cout << "Calculando tiempos..." << std::endl;
    std::cout << std::endl;

    tiemposCuadradoMatriz(nMin, nMax, increment, tiemposReales, numeroOrdenes);
    almacenarFichero(tiemposReales, numeroOrdenes);
    ajusteCubico(numeroOrdenes, tiemposReales, a);

    std::cout << std::endl;
    std::cout << "t = " << a[0] << " + " << a[1] << "*n + " << a[2] << "*n² + " << a[3] << "*n³" << std::endl;

    calcularTiemposEstimadosPolinomico(numeroOrdenes, a, tiemposEstimados);
    
    coefDet = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);

    std::cout << "Coeficiente de determinacion: " << coefDet << std::endl;

    almacenarDatosFichero(tiemposReales, numeroOrdenes, tiemposEstimados);
    
    while(true){
        std::cout << std::endl << "Introduzca n (0 para salir): ";
        std::cin >> n;
        if(n == 0) return;
        long double t = calcularTiempoEstimadoPolinomico(n, a);
        tiemposN(n, t);
    }
}

void fibonacciRecursivo(){
    std::vector <double> tiemposReales;
    std::vector <double> tiemposEstimados;
    std::vector <double> n;
    std::vector <double> a(2);
    int nMin, nMax, increment;
    long int term;
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

    //std::cout << "Calculando tiempos..." << std::endl;
    std::cout << std::endl;
    
    tiemposFibonacciRecursivo(nMin, nMax, increment, tiemposReales, n);
    almacenarFichero(tiemposReales, n);
    ajusteExponencial(n, tiemposReales, a);

    std::cout << std::endl;
    std::cout << "t = " << a[0] << " + " << a[1] << "*2^n" << std::endl;


    calcularTiemposEstimadosExponencial(n, tiemposReales, a, tiemposEstimados);

    coefDet = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);

    std::cout << "Coeficiente de determinacion: " << coefDet << std::endl;

    almacenarDatosFichero(tiemposReales, n, tiemposEstimados);
    
    while(true){
        std::cout << std::endl << "Introduzca termino n-esimo (0 para salir): ";
        std::cin >> term;
        if(term == 0) return;
        long double t = calcularTiempoEstimadoExponencial(term, a);
        tiemposN(term, t);
    }
}
