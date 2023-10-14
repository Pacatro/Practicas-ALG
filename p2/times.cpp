#include <vector>
#include <iostream>
#include "headers/times.hpp"
#include "headers/aux.hpp"
#include "headers/ClaseTiempo.hpp"
#include "headers/methods.hpp"

void tiemposOrdenacionVariantesQuicksort(int nMin, int nMax, int incremento, int repeticiones, 
                                         int nMediana, int nElementosMinimo, 
                                         std::vector <double> &tiemposRealesQS1, 
                                         std::vector <double> &tiemposRealesQS2, 
                                         std::vector <double> &numeroElementos){
    for(int i = nMin; i <= nMax; i += incremento){
        double sum = 0, med = 0;
        
        for(int j = 0; j < repeticiones; j++){
            std::vector<int> v(i);
            rellenarVector(v);
            std::cout << "Ordenando vector con QS1, n = " << i << ", rep = " << j+1 << std::endl;
            Clock time;
            time.start();
            quicksort(0, v.size()-1, v);

            if(time.isStarted()){
                time.stop();
                sum += time.elapsed();
            }
            
            if(!estaOrdenado(v)){
                std::cout << "El vector no está ordenado." << std::endl;
                return;
            }
        }

        med = sum / repeticiones;
        tiemposRealesQS1.push_back(med);

        med = 0;
        sum = 0;
        for(int k = 0; k < repeticiones; k++){
            std::vector<int> v(i);
            rellenarVector(v);
            std::cout << "Ordenando vector con QS2, n = " << i << ", rep = " << k+1 << std::endl;
            Clock time;
            time.start();
            quicksortMejorado(0, v.size()-1, nMediana, nElementosMinimo, v);

            if(time.isStarted()){
                time.stop();
                sum += time.elapsed();
            }
            
            if(!estaOrdenado(v)){
                std::cout << "El vector no está ordenado." << std::endl;
                return;
            }
        }

        med = sum / repeticiones;
        tiemposRealesQS2.push_back(med);

        numeroElementos.push_back(i);
    }
}
