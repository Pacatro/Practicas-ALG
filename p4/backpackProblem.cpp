#include <iostream>

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

#include "headers/backpackProblem.hpp"
#include "headers/material.hpp"

// INTERCAMBIAR VOLUMEN Y PRECIO DEL MATERIAL 1 Y 5 PARA PROBAR

void cargarMateriales(std::vector<Material> &materiales, const char *nombreFichero){
    auto nombreFicheroStr = std::string(nombreFichero);
    
    std::ifstream file(nombreFichero);

    if(!file){
        std::cerr << "Error al abrir el fichero" << std::endl << std::endl;
        return;
    }

    std::string line, etiqueta, volumen, precio;

    while(std::getline(file, line)){
        std::istringstream iss(line);
        iss >> etiqueta >> volumen >> precio;
        Material m(std::stoi(etiqueta), std::stof(volumen), std::stof(precio));
        materiales.push_back(m);
    }

    file.close();
}

void mochila(float volumenMochila, std::vector<Material> &materiales, std::vector<std::vector <double>>& matrizEstados){
    // TODO
}

void obtenerSolucion(std::vector<std::vector <double>>& matrizEstados, 
                     std::vector<Material> &materiales, 
                     std::vector<MaterialUsado> &solucion){
    // TODO
}

void escribirSolucion(std::vector<MaterialUsado> &solucion){
    double total = 0;
    
    std::cout << std::endl;
    for(int i = 0; i < solucion.size(); i++){
        if(solucion[i].getVolumenUsado() != 0){
            std::cout << "Material: " << solucion[i].getMaterial().getEtiqueta() << " Volumen: " << solucion[i].getMaterial().getVolumen() << " Precio: " << solucion[i].getMaterial().getPrecio() << std::endl;
            total += solucion[i].getMaterial().getPrecio() * solucion[i].getVolumenUsado();
        }
    }

    std::cout << std::endl << "Precio total: " << total << std::endl;
}

void backpackProblem(){
    int v;
    std::cout << "Introduzca el volumen de la mochila: ";
    std::cin >> v;

    std::vector<Material> materiales;
    std::vector<MaterialUsado> solucion;

    cargarMateriales(materiales, "../materialesmochila.txt");
    //mochila(v, materiales, solucion);
    escribirSolucion(solucion);
}