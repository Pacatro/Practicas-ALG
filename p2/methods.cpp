#include <vector>
#include "methods.hpp"

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