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
        double sum1 = 0, sum2 = 0;
        
        for(int j = 0; j < repeticiones; j++){
            //QS1
            std::vector<int> v(i);
            rellenarVector(v);
            Clock time1;
            time1.start();
            
            if(!estaOrdenado(v)){
                quicksort(0, v.size()-1, v);
            }

            if(time1.isStarted()){
                time1.stop();
                sum1 += time1.elapsed();
            }

            //QS2
            rellenarVector(v);
            Clock time2;
            time2.start();
            
            if(!estaOrdenado(v)){
                quicksortMejorado(0, v.size()-1, nMediana, nElementosMinimo, v);
            }

            if(time2.isStarted()){
                time2.stop();
                sum2 += time2.elapsed();
            }
            
        }

        double med1 = sum1 / repeticiones;
        double med2 = sum2 / repeticiones;

        std::cout << "n = " << i << " \tTQS1 = " << med1 << " \t\tTQS2 = " << med2 << std::endl;

        tiemposRealesQS1.push_back(med1);
        tiemposRealesQS2.push_back(med2);
        numeroElementos.push_back(i);
    }
}
