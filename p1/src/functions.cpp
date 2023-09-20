//#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include "./headers/functions.hpp"
#include "ClaseTiempo.cpp"

void menu() {
    std::cout << "1: Método de ordenación por selección" << std::endl;
    std::cout << "2: cálculo del cuadrado de una matriz" << std::endl;
    std::cout << "3: Cálculo del término n-ésimo de la sucesión de Fibonacci" << std::endl;
}

void rellenarVector(std::vector<int> &v){
    std::srand(std::time(nullptr));
    for(int i = 0; i<v.size(); i++){
        v[i] = std::rand() % 50;
    }
}

void ordenacionSeleccion(std::vector<int> &v){
    int minPos;
    
    for(int i = 0; i<v.size()-1; i++){
        minPos = i;
        for(int j = i+1; j<v.size(); j++){
            if(v[j] < v[minPos])
                minPos = j;
        }
        int aux = v[i];
        v[i] = v[minPos];
        v[minPos] = aux;
    }
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

void tiemposOrdenacionSelección(int nMin, int nMax, int increment, int repeticiones,
                                std::vector <double> &tiemposReales, std::vector <double> &numeroElementos){
    double sum = 0;

    for(int i = nMin; i <= nMax; i += increment){
        for(int j = 0; j<repeticiones; j++){
            std::vector<int> v(i);
            rellenarVector(v);
            Clock time;
            time.start();
            ordenacionSeleccion(v);
            if(time.isStarted() && estaOrdenado(v)){
                time.stop();
                sum += time.elapsed();
            }
        }

        double med = sum / repeticiones;
        tiemposReales.push_back(med);
        numeroElementos.push_back(i);
    }
}

void almacenarFichero(std::vector <double> &tiemposReales, std::vector <double> &numeroElementos){
    std::ofstream file("tiempoReales.txt");

    if(!file){
        std::cout << "No se ha podido abrir el fichero." << std::endl;
        return;
    }

    for(int i = 0; i < numeroElementos.size() && i < tiemposReales.size(); i++){
        file << numeroElementos[i] << " --> " << tiemposReales[i] << " microsegundos" << std::endl;
    }

    file.close();
}

void ordenacionSeleccion(){
    std::vector<double> tiemposReales;
    std::vector<double> numeroElementos;
    tiemposOrdenacionSelección(1000, 5000, 100, 5, tiemposReales, numeroElementos);

    std::cout << "Vector tiempos (" << tiemposReales.size() << "): ";
    for (double i : tiemposReales)
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "Vector elementos (" << numeroElementos.size() << "): ";
    for (double i : numeroElementos)
        std::cout << i << " ";
    std::cout << std::endl;

    almacenarFichero(tiemposReales, numeroElementos);
}
