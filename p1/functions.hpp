#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>


void menu();

void ordenacionSeleccion(std::vector<int> &v);
void tiemposOrdenacionSelección(int nMin, int nMax, int increment, int repeticiones, std::vector <double> &tiemposReales, std::vector <double> &numeroElementos);
void ajusteCuadratico(const std::vector <double> &numeroElementos, const std::vector <double> &tiemposReales, std::vector <double> &a);
double calcularCoeficienteDeterminacion(const std::vector <double> &tiemposReales, const std::vector <double> &tiemposEstimados);
void ordenacionSeleccion();

//Apartado 2
void tiemposCuadradoMatriz(int nMin, int nMax, int increment, std::vector <double> &tiemposReales, std::vector <double> &numeroOrdenes);
void ajusteCubico(const std::vector <double> &n, const std::vector <double> &tiemposReales, std::vector <double> &a);
void matrizCuadrado();

//Apartado 3
void fibonacciRecursivo();

#endif