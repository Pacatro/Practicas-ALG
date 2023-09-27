#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <cmath>
#include "aux.hpp"

void rellenarVector(std::vector<int> &v){
    std::srand(std::time(nullptr));
    for(int i = 0; i<v.size(); i++)
        v[i] = std::rand() % 50;
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

void calcularTiemposEstimadosPolinomico(const std::vector <double> &numeroElementos,
                                        const std::vector <double> &a,
                                        std::vector <double> &tiemposEstimados){
    //t(n) = a0 + a1*n + a2*n²
    for(int i = 0; i < numeroElementos.size(); i++){
        double t = a[0] + a[1]*numeroElementos[i] + a[2]*(numeroElementos[i]*numeroElementos[i]);
        tiemposEstimados.push_back(t);
    }

    // double t = 0;
    // for(int i = 0; i < numeroElementos.size(); i++){
    //     for(int j = 0; j < a.size(); j++)
    //         t += a[j] * std::pow(numeroElementos[i], j);            
    //     tiemposEstimados.push_back(t);
    // }
}

double calcularTiempoEstimadoPolinomico(const double &n, std::vector <double> &a){
    //t(n) = a0 + a1*n + a2*n²
    double t = a[0] + a[1]*n + a[2]*(n*n);
    return t;

    // double t = 0;

    // for(int i = 0; i < a.size(); i++)
    //     t += a[i] * std::pow(n, i);

    // return t;
}

void tiemposN(std::vector <double> &a){
    long int n;
    char option;

    while(true){
        std::cout << std::endl << "Introduzca numero elementos: ";
        std::cin >> n;
        if(n == 0) return;
        double t = calcularTiempoEstimadoPolinomico(n, a);
        double seg = t / 10e6;
        double min = seg / 60;
        int days = min / 1440;
        int years = days / 365;
        std::cout << "Para un tamaño " << n << " tardara: " << years << " años, " << days << " dias, " 
                  << min << " minutos, " << seg << " segundos" << std::endl;
    }
}

void rellenarMatriz(std::vector <std::vector <double>> &M){
    for(int i = 0; i < M.size(); i++){
        for(int j = 0; j < M[i].size(); j++)
            M[i][j] = 0.95 + static_cast<double>(std::rand()) / RAND_MAX * 0.1;
    }
}