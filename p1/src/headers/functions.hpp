#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

void menu();
void rellenarVector(std::vector<int> &v);
void ordenacionSeleccion(std::vector<int> &v);
bool estaOrdenado(const std::vector <int> &v);
void tiemposOrdenacionSelección(int nMin, int nMax, int increment, int repeticiones, std::vector <double> &tiemposReales, std::vector <double> &numeroElementos);
void almacenarFichero(std::vector <double> &tiemposReales, std::vector <double> &numeroElementos);
void ordenacionSeleccion();
void matrizCuadrado();
void fibonacciRecursivo();

#endif