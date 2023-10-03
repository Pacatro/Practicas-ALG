#ifndef STATS_H
#define STATS_H

#include <vector>

double sumatorio(const std::vector <double> &n, const std::vector<double> &t, int expN, int expT); 
double media(const std::vector <double> v);
double varianza(const std::vector <double> v);
void ajusteCuadratico(const std::vector <double> &numeroElementos, const std::vector <double> &tiemposReales, std::vector <double> &a);
double calcularCoeficienteDeterminacion(const std::vector <double> &tiemposReales, const std::vector <double> &tiemposEstimados);
void ajusteCubico(const std::vector <double> &n, const std::vector <double> &tiemposReales, std::vector <double> &a);
void ajusteExponencial(const std::vector <double> &n, const std::vector <double> &tiemposReales, std::vector <double> &a);

#endif