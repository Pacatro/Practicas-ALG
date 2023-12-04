#ifndef COMMON_HPP
#define COMMON_HPP

#include <vector>

void menu();
bool lugar(int k, std::vector<int> &x);
void escribirSoluciones(std::vector<std::vector<int>> &soluciones);
void escribirSolucion(std::vector<int> &solucion);
void fillMatrix(std::vector<std::vector<int>> &m);
void fillVector(std::vector<int> &x);

#endif