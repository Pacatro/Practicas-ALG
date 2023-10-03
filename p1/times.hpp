#ifndef TIMES_H
#define TIMES_H

#include <vector>

void tiemposOrdenacionSelección(int nMin, int nMax, int increment, int repeticiones, std::vector <double> &tiemposReales, std::vector <double> &numeroElementos);
void tiemposCuadradoMatriz(int nMin, int nMax, int increment, std::vector <double> &tiemposReales, std::vector <double> &numeroOrdenes);
void tiemposFibonacciRecursivo(int nMin, int nMax, int increment, std::vector <double> &tiemposReales, std::vector <double> &numeroOrdenes);
void calcularTiemposEstimadosPolinomico(const std::vector <double> &numeroElementos, const std::vector <double> &a, std::vector <double> &tiemposEstimados);
double calcularTiempoEstimadoPolinomico(const double &n, std::vector <double> &a);
void calcularTiemposEstimadosExponencial(const std::vector <double> &n, const std::vector <double> &tiemposReales, const std::vector <double> &a, std::vector <double> &tiemposEstimados);
double calcularTiempoEstimadoExponencial(const double &n, const std::vector <double> &a);
void tiemposN(const long int &n, const double &t);

#endif