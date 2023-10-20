#ifndef AUX_HPP
#define AUX_HPP

#include <vector>

void rellenarVector(std::vector<int> &v);
void printVector(std::vector<double> &v);
bool estaOrdenado(const std::vector <int> &v);
void printHelp();
void almacenarFichero(const std::vector <double> &tiemposRealesQS1, const std::vector <double> &tiemposRealesQS2, const std::vector <double> &numeroElementos);
double mejora(const std::vector <double> &tiemposRealesQS1, const std::vector <double> &tiemposRealesQS2);

#endif