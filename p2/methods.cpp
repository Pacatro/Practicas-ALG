#include <vector>
#include <iostream>
#include "headers/methods.hpp"
#include "headers/aux.hpp"

void quicksort(int iz, int de, std::vector <int> &v){
    int i = iz;
    int j = de;
    int x = v[(iz+de)/2];

    do {
        while(v[i] < x)
            i++;

        while(v[j] > x)
            j--;

        if(i <= j){
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    } while(i < j);

    if(iz < j)
        quicksort(iz, j, v);

    if(i < de)
        quicksort(i, de, v);
}

void ordenacionSeleccion(std::vector<int> &v, int min, int max){
    int minPos;
    
    for(int i = min; i < max-1; i++){
        minPos = i;
        for(int j = i+1; j < max; j++){
            if(v[j] < v[minPos])
                minPos = j;
        }
        int aux = v[i];
        v[i] = v[minPos];
        v[minPos] = aux;
    }
}

//Si no se nota mejora, usar el quicksort de la stl en vez de la ordenación de seleccion
void quicksortMejorado(int iz, int de, int median, int minN, std::vector <int> &v){
    int i = iz;
    int j = de;
    int x;

    if((de-iz) > minN){
        int z = (iz+de)/2;
        z -= median/2;
        ordenacionSeleccion(v, z, z+median);
        //quicksort(z, z+median, v);
    }

    x = v[(iz+de)/2];

    do {
        while(v[i] < x)
            i++;

        while(v[j] > x)
            j--;

        if(i <= j){
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    } while(i < j);

    if(iz < j)
        quicksortMejorado(iz, j, median, minN, v);

    if(i < de)
        quicksortMejorado(i, de, median, minN, v);
}