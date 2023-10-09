#include <vector>
#include <iostream>
#include <ctime>
#include "aux.hpp"

void rellenarVector(std::vector<int> &v){
    std::srand(std::time(nullptr));
    for(int i = 0; i<v.size(); i++)
        v[i] = std::rand() % 9999999+1;
}

void printVect(std::vector<int> &v){
    for(int i = 0; i<v.size(); i++)
        std::cout << v[i] << " ";
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