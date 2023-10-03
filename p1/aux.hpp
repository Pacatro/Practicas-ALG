#ifndef AUX
#define AUX

#include <vector>

void menu();
void rellenarVector(std::vector<int> &v);
bool estaOrdenado(const std::vector <int> &v);
void almacenarFichero(const std::vector <double> &tiemposReales, const std::vector <double> &numeroElementos);
void almacenarDatosFichero(const std::vector <double> &tiemposReales, const std::vector <double> &numeroElementos, const std::vector <double> &tiemposEstimados);
void rellenarMatriz(std::vector <std::vector <double>> &M);

#endif