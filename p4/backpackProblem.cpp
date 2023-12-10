#include <iostream>

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

#include "headers/backpackProblem.hpp"
#include "headers/material.hpp"

void cargarMateriales(std::vector<Material> &materiales, const char *nombreFichero){
    auto nombreFicheroStr = std::string(nombreFichero);
    
    std::ifstream file(nombreFichero);

    if(!file){
        std::cerr << "Error al abrir el fichero" << std::endl << std::endl;
        return;
    }

    std::string line;
    int etiqueta;
    float volumen, precio;

    while(file >> etiqueta >> volumen >> precio)
        materiales.push_back(Material(etiqueta, volumen, precio));

    file.close();
}

void mochila(float volumenMochila, std::vector<Material> &materiales, std::vector<std::vector <double>>& matrizEstados){
    for(int i = 0; i < materiales.size(); i++)
        matrizEstados[i][0] = 0;

    for(int j = 0; j <= volumenMochila; j++){
        if(j < materiales[0].getVolumen())
            matrizEstados[0][j] = 0;
        else
            matrizEstados[0][j] = materiales[0].getPrecio() * materiales[0].getVolumen();
    }

    for(int i = 1; i < materiales.size(); i++){
        for(int j = 1; j <= volumenMochila; j++){
            if(j < materiales[i].getVolumen())
                matrizEstados[i][j] = matrizEstados[i-1][j];
            else
                matrizEstados[i][j] = std::max(matrizEstados[i-1][j], materiales[i].getPrecio() * materiales[i].getVolumen() 
                                                                      + matrizEstados[i-1][j-materiales[i].getVolumen()]);
        }
    }
}

void obtenerSolucion(std::vector<std::vector <double>>& matrizEstados, 
                     std::vector<Material> &materiales, 
                     std::vector<MaterialUsado> &solucion){
    int i = matrizEstados.size()-1;
    int j = matrizEstados[0].size()-1;

    while(j != 0 && i != 0){
        if(matrizEstados[i][j] == matrizEstados[i-1][j])
            i--;
        else {
            j -= materiales[i].getVolumen();
            solucion[i].setMaterial(materiales[i]);
            solucion[i].setVolumenUsado(materiales[i].getVolumen());
            i--;
        }
    }

    if(i == 0 && matrizEstados[i][j] != 0){
        solucion[0].setVolumenUsado(materiales[0].getVolumen());
        solucion[0].setMaterial(materiales[0]);
    }
}

void escribirSolucion(std::vector<MaterialUsado> &solucion){
    double total = 0;
    
    std::cout << std::endl;
    for(int i = 0; i < solucion.size(); i++){
        if(solucion[i].getVolumenUsado() != 0){
            std::cout << "Material: " << solucion[i].getMaterial().getEtiqueta() << " | " 
                      << "Volumen: " << solucion[i].getMaterial().getVolumen() << " | " 
                      << "Precio: " << solucion[i].getMaterial().getPrecio() << std::endl;
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
    cargarMateriales(materiales, "../materialesmochila.txt");

    std::vector<MaterialUsado> solucion;

    for(int i = 0; i < materiales.size(); i++)
        solucion.push_back(MaterialUsado(materiales[i], 0));

    std::vector<std::vector<double>> matrizEstados(materiales.size(), std::vector<double>(v+1));

    mochila(v, materiales, matrizEstados);
    obtenerSolucion(matrizEstados, materiales, solucion);
    escribirSolucion(solucion);
}