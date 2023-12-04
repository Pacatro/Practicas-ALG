#include <vector>
#include <iostream>

#include "./headers/backtracking.hpp"
#include "./headers/aux.hpp"

void nReinasBacktracking(int n, std::vector<std::vector<int>> &soluciones) {
    std::vector<int> x(n);
    x[0] = -1;
    int k = 0;

    while(k > -1) {
        x[k]++;

        while(x[k] < n && !lugar(k, x))
            x[k]++;

        if(x[k] < n) {
            if(k == n-1) {
                soluciones.push_back(x);
            } else {
                k++;
                x[k] = -1;
            }
        } else k--;
    }
}

void escribirSoluciones(std::vector<std::vector<int>> &soluciones) {
    for(int i = 0; i < soluciones.size(); i++) {
        std::cout << "[ ";
        for(int j = 0; j < soluciones[i].size(); j++)
            std::cout << soluciones[i][j] << " ";

        std::cout << "]" << std::endl;
    }
}

void nReinasBacktracking(int n, std::vector<int> &solucion) {
    solucion[0] = -1;
    int k = 0;

    while(k > -1) {
        solucion[k]++;

        while(solucion[k] < n && !lugar(k, solucion))
            solucion[k]++;

        if(solucion[k] < n) {
            if(k == n-1) {
                return;
            } else {
                k++;
                solucion[k] = -1;
            }
        } else k--;
    }
}

void escribirSolucion(std::vector<int> &solucion) {
    std::cout << "[ ";
    for(int i = 0; i < solucion.size(); i++)
        std::cout << solucion[i] << " ";
    std::cout << "]" << std::endl;
}