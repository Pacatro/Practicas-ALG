#ifndef METHODS_HPP
#define METHODS_HPP

#include <vector>

bool lugar(int k, std::vector<int> &x);
void nReinasBacktracking(int n, std::vector<std::vector<int>> &soluciones);
void nReinasBacktracking(int n, std::vector<int> &solucion);
bool nReinasLasVegas(int n, std::vector<int> &solucion);
void prodMatrix(std::vector<std::vector<int>> &A, std::vector<std::vector<int>> &B, std::vector<std::vector<int>> &AB);
void generateC(std::vector<std::vector<int>> &AB, std::vector<std::vector<int>> &C);
bool verifyProd(int n, std::vector<std::vector<int>> &A, std::vector<std::vector<int>> &B, std::vector<std::vector<int>> &C);
bool verifyProdRep(int tests, int n, int &nTests, std::vector<std::vector<int>> &A, 
                                                  std::vector<std::vector<int>> &B, 
                                                  std::vector<std::vector<int>> &C);

#endif