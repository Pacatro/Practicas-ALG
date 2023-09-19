#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

void menu();
void rellenarVector(std::vector<int> &v);
void ordenacionSeleccion(std::vector<int> &v);
bool estaOrdenado(const std::vector <int> &v);
void tiemposOrdenacionSelección(int nMin, int nMax, int repeticiones, int icrement ,std::vector <double> &tiemposReales, std::vector <double> &numeroElementos);

#endif