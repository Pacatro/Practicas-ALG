#ifndef COMMON_HPP
#define COMMON_HPP

#include <vector>

void menu();
void escribirSoluciones(std::vector<std::vector<int>> &soluciones);
void escribirSolucion(std::vector<int> &solucion);
void fillMatrix(std::vector<std::vector<int>> &m);
void fillVector(int n, std::vector<std::vector<int>> &X);

#endif