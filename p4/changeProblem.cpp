#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

#include "headers/changeProblem.hpp"
#include "headers/moneda.hpp"

void cargarSistemaMonetario(std::vector <Moneda> &sistemaMonetario, const char *nombreFichero){
    auto nombreFicheroStr = std::string(nombreFichero);
    
    std::ifstream file(nombreFichero);

    if(!file){
        std::cerr << "Error al abrir el fichero" << std::endl << std::endl;
        return;
    }

    std::string line;

    while(file >> line){
        int val = std::stoi(line);
        Moneda m(val);
        sistemaMonetario.push_back(m);
    }
}

void cambio(int cantidad, std::vector <Moneda> &sistemaMonetario, std::vector<std::vector <int>> &matrizEstados){
    for(int i = 0; i < sistemaMonetario.size(); i++)
        matrizEstados[i][0] = 0;

    for(int i = 0; i < sistemaMonetario.size(); i++){
        for(int j = 1; j <= cantidad; j++){
            if(i == 0){
                matrizEstados[i][j] = 1 + matrizEstados[i][j-sistemaMonetario[0].getValor()];
            } else {
                if(j < sistemaMonetario[i].getValor())
                    matrizEstados[i][j] = matrizEstados[i-1][j];
                else
                    matrizEstados[i][j] = std::min(matrizEstados[i-1][j], 1 + matrizEstados[i][j-sistemaMonetario[i].getValor()]);
            }
        }
    }
}

void obtenerSolución(std::vector<std::vector <int>> &matrizEstados, 
                     std::vector <Moneda> &sistemaMonetario, 
                     std::vector<int> &solucion){
    // for(int i = 0; i < matrizEstados.size(); i++){
    //     for(int j = 0; j < matrizEstados[i].size(); j++){
    //         if(matrizEstados[i][j] == matrizEstados[i-1][j])
    //             i--;
    //         if(matrizEstados[i][j] == 1 + matrizEstados[i][j-sistemaMonetario[i].getValor()])
    //             j -= sistemaMonetario[i].getValor();
    //     }
    // }

    int i = matrizEstados.size()-1;
    int j = matrizEstados[0].size()-1;

    while(j != 0 && i != 0){
        if(matrizEstados[i][j] == matrizEstados[i-1][j])
            i--;
        if(matrizEstados[i][j] == 1 + matrizEstados[i][j-sistemaMonetario[i].getValor()]){
            j -= sistemaMonetario[i].getValor();
            solucion[i]++;
        }
    }
}

void escribirSolucion(std::vector <int> &solucion, std::vector <Moneda> &sistemaMonetario){
    std::cout << std::endl;
    for(int i = 0; i < solucion.size(); i++){
        if(solucion[i] != 0)
            std::cout << "Cambio de " << solucion[i] << " monedas de " << sistemaMonetario[i].getValor() << std::endl;
    }
}

void changeProblem(){
    std::vector <Moneda> sistemaMonetario;
    cargarSistemaMonetario(sistemaMonetario, "../sistemamonetario.txt");

    int cantidad;
    std::vector <int> solucion(sistemaMonetario.size(), 0);

    std::cout << "Introduce la cantidad: ";
    std::cin >> cantidad;

    std::vector<std::vector<int>> matrizEstados(sistemaMonetario.size(), std::vector<int>(cantidad+1));

    cambio(cantidad, sistemaMonetario, matrizEstados);
    obtenerSolución(matrizEstados, sistemaMonetario, solucion);
    escribirSolucion(solucion, sistemaMonetario);
}