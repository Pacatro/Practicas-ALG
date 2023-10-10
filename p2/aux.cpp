#include <vector>
#include <iostream>
#include <ctime>
#include "aux.hpp"
#include "methods.hpp"

void rellenarVector(std::vector<int> &v){
    std::srand(std::time(nullptr));
    for(int i = 0; i<v.size(); i++)
        v[i] = std::rand() % 9999999+1;
}

void printVector(std::vector<int> &v){
    for(int i = 0; i<v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

bool estaOrdenado(const std::vector <int> &v){
    if(v.size() <= 1)
        return true;

    for(int i = 1; i < v.size(); i++){
        if (v[i] < v[i-1]) 
            return false;
    }

    return true;
}

int getMedian(int n, const std::vector <int> &v){
    std::vector <int> med(n);

    std::cout << "hola";
    for(int i = 0; i < n; i++)
        med[i] = v[i];

    ordenacionSeleccion(med);

    if(!estaOrdenado(med)){
        std::cout << "No esta ordenado." << std::endl;
        return -1;
    }

    int median = med[med.size()/2];

    return median;
}

void printHelp(){
    std::cout << "Debe introducir los siguientes parametros:" << std::endl;
    std::cout << "\t-m, --min\t\t\tNumero minimo de elementos." << std::endl;
    std::cout << "\t-M, --max\t\t\tNumero maximo de elementos." << std::endl;
    std::cout << "\t-i, --increment\t\t\tNumero de incrementos." << std::endl;
    std::cout << "\t-r, --repetitions\t\tNumero de repeticiones." << std::endl;
    std::cout << "\t-e, --median\t\t\tNumero minimo de elementos del vector para obtener la mediana." << std::endl;
    std::cout << "\t-n, --minelements\t\tNumero minimo de elementos del vector para tomar aleatoriamente." << std::endl;
}