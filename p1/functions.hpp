#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

void menu();

//Apartado 1
void rellenarVector(std::vector<int> &v);
void ordenacionSeleccion(std::vector<int> &v);
bool estaOrdenado(const std::vector <int> &v);
void tiemposOrdenacionSelección(int nMin, int nMax, int increment, int repeticiones, std::vector <double> &tiemposReales, std::vector <double> &numeroElementos);
void almacenarFichero(const std::vector <double> &tiemposReales, const std::vector <double> &numeroElementos);
void ajusteCuadratico(const std::vector <double> &numeroElementos, const std::vector <double> &tiemposReales, std::vector <double> &a);
double sumatorio(const std::vector <double> &n, const std::vector<double> &t, int expN, int expT); 
void calcularTiemposEstimadosPolinomico(const std::vector <double> &numeroElementos, const std::vector <double> &a, std::vector <double> &tiemposEstimados);
void almacenarDatosFichero(const std::vector <double> &tiemposReales, const std::vector <double> &numeroElementos, const std::vector <double> &tiemposEstimados);
double calcularTiempoEstimadoPolinomico(const double &n, std::vector <double> &a);
void tiemposN(std::vector <double> &a);
void ordenacionSeleccion();

//Apartado 2
void rellenarMatriz(std::vector <std::vector <double>> &M);
void matrizCuadrado();

//Apartado 3
void fibonacciRecursivo();

#endif