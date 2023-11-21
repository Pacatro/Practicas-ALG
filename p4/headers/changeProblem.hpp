#ifndef CHANGE_PROBLEM_HPP
#define CHANGE_PROBLEM_HPP

#include <vector>
#include "moneda.hpp"

void cargarSistemaMonetario(std::vector <Moneda> &sistemaMonetario, const char *nombreFichero);
void cambio(int cantidad, std::vector <Moneda> &sistemaMonetario, std::vector<std::vector <int>> &matrizEstados);
void obtenerSolución(std::vector<std::vector <int>> &matrizEstados, std::vector <Moneda> &sistemaMonetario, std::vector<int> &solucion);
void escribirSolucion(std::vector <int> &solucion, std::vector <Moneda> &sistemaMonetario);
void changeProblem();

#endif