#include <vector>
#include "methods.hpp"
#include "aux.hpp"

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

void quicksortMejorado(int iz, int de, int n, std::vector <int> &v){
    int i = iz;
    int j = de;
    int x;

    if(v.size() < 1000)
        x = v[(iz+de)/2];
    else
        x = getMediana(n, v);

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
        quicksortMejorado(iz, j, n, v);

    if(i < de)
        quicksortMejorado(i, de, n, v);
}