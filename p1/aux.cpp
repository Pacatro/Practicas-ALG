#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <cmath>
#include "aux.hpp"
#include "times.hpp"

void menu() {
    std::cout << std::endl;
    std::cout << "**Introduzca cualquier valor para salir**" << std::endl;
    std::cout << std::endl;
    std::cout << "1: Método de ordenación por selección" << std::endl;
    std::cout << "2: Cálculo del cuadrado de una matriz" << std::endl;
    std::cout << "3: Cálculo del término n-ésimo de la sucesión de Fibonacci" << std::endl;
}

void rellenarVector(std::vector<int> &v){
    std::srand(std::time(nullptr));
    for(int i = 0; i<v.size(); i++)
        v[i] = std::rand() % 9999999+1;
}

bool estaOrdenado(const std::vector <int> &v){
    if(v.size() <= 1)
        return true;

    for(int i = 1; i < v.size(); i++){
        if (v[i] < v[i - 1]) 
            return false;
    }

    return true;
}

void almacenarFichero(const std::vector <double> &tiemposReales,
                      const std::vector <double> &numeroElementos){
    std::ofstream file("tiempoReales.txt");

    if(!file){
        std::cout << "No se ha podido abrir el fichero." << std::endl;
        return;
    }

    for(int i = 0; i < numeroElementos.size() && i < tiemposReales.size(); i++)
        file << numeroElementos[i] << " " << tiemposReales[i] << std::endl;

    file.close();
}

double sumatorio(const std::vector <double> &n, 
                 const std::vector <double> &t, 
                 int expN, int expT){
    double sum = 0;
    
    for(int i = 0; i<n.size() && i<t.size(); i++)
        sum += std::pow(n[i], expN) * std::pow(t[i], expT);

    return sum;
}

void almacenarDatosFichero(const std::vector <double> &tiemposReales, 
                           const std::vector <double> &numeroElementos,
                           const std::vector <double> &tiemposEstimados){
    
    std::ofstream file("datosFinales.txt");

    if(!file){
        std::cout << "No se ha podido abrir el fichero." << std::endl;
        return;
    }

    for(int i = 0; i < numeroElementos.size() && i < tiemposReales.size() && i < tiemposEstimados.size(); i++)
        file << numeroElementos[i] << " " << tiemposReales[i] << " " << tiemposEstimados[i] << std::endl;

    file.close();
}

void rellenarMatriz(std::vector <std::vector <double>> &M){
    for(int i = 0; i < M.size(); i++){
        for(int j = 0; j < M[i].size(); j++)
            M[i][j] = 0.95 + static_cast<double>(std::rand()) / RAND_MAX * 0.1;
    }
}