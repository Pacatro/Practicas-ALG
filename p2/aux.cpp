#include <vector>
#include <iostream>
#include <ctime>
#include <fstream>
#include "headers/aux.hpp"
#include "headers/methods.hpp"

void rellenarVector(std::vector<int> &v){
    std::srand(std::time(nullptr));
    for(int i = 0; i<v.size(); i++)
        v[i] = std::rand() % 9999999+1;
}

void printVector(std::vector<double> &v){
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

void almacenarFichero(const std::vector <double> &tiemposRealesQS1, 
                      const std::vector <double> &tiemposRealesQS2, 
                      const std::vector <double> &numeroElementos){
    std::ofstream file("tiemposReales.txt");

    if(!file){
        std::cout << "No se ha podido abrir el fichero." << std::endl;
        return;
    }

    for(int i = 0; i < numeroElementos.size(); i++)
        file << numeroElementos[i] << " " << tiemposRealesQS1[i] << " " << tiemposRealesQS2[i] << std::endl;

    file.close();
}

double mejora(const std::vector <double> &tiemposRealesQS1, const std::vector <double> &tiemposRealesQS2){
    double sumQS1 = 0, sumQS2 = 0;

    for(int e : tiemposRealesQS1)
        sumQS1+=e;

    for(int e : tiemposRealesQS2)
        sumQS2+=e;

    double medQS1 = sumQS1 / tiemposRealesQS1.size();
    double medQS2 = sumQS2 / tiemposRealesQS2.size();

    return medQS1/medQS2;
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