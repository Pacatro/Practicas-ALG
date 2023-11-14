#ifndef BACKPACK_PROBLEM_HPP
#define BACKPACK_PROBLEM_HPP

#include <vector>
#include "./material.hpp"
#include "./materialUsado.hpp"

void cargarMateriales(std::vector<Material> &materiales, const char *nombreFichero);
void mochila(float volumenMochila, std::vector<Material> &materiales, std::vector<MaterialUsado> &solucion);
void escribirSolucion(std::vector<MaterialUsado> &solucion);
void backpackProblem();

#endif