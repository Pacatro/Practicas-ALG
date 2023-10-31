#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

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

void cambio(int cantidad, std::vector <Moneda> sistemaMonetario, std::vector <int> &solucion){
    solucion = std::vector <int> (sistemaMonetario.size(), 0);

    int s = 0, x, i;
    while(s != cantidad){
        for(i = 0; i < sistemaMonetario.size() && sistemaMonetario[i].getValor() + s > cantidad; i++);

        x = sistemaMonetario[i].getValor();

        solucion[i]++;
        s += x;
    }
}

void escribirSolucion(std::vector <int> &solucion, std::vector <Moneda> &sistemaMonetario){
    for(int i = 0; i < solucion.size(); i++){
        if(solucion[i] != 0)
            std::cout << "Cambio de " << solucion[i] << " monedas de " << sistemaMonetario[i].getValor() << std::endl;
    }
}

void changeProblem(){
    std::vector <Moneda> sistemaMonetario;
    cargarSistemaMonetario(sistemaMonetario, "../sistemamonetario.txt");

    int cantidad;
    std::vector <int> solucion;

    std::cout << "Introduce la cantidad: ";
    std::cin >> cantidad;

    cambio(cantidad, sistemaMonetario, solucion);
    std::cout << std::endl;
    escribirSolucion(solucion, sistemaMonetario);
}