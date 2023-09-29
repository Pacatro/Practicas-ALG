#include <vector>
#include "times.hpp"
#include "ClaseTiempo.hpp"
#include "methods.hpp"
#include "aux.hpp"
#include "sistemaEcuaciones.hpp"

void tiemposOrdenacionSelección(int nMin, int nMax, int increment, int repeticiones,
                                std::vector <double> &tiemposReales, std::vector <double> &numeroElementos){

    for(int i = nMin; i <= nMax; i += increment){
        double sum = 0;
        for(int j = 0; j<repeticiones; j++){
            std::vector<int> v(i);
            rellenarVector(v);
            //std::cout << "Ordenando vector, n = " << i << ", rep = " << j+1 << std::endl;
            Clock time;
            time.start();
            ordenacionSeleccion(v);

            if(time.isStarted()){
                time.stop();
                sum += time.elapsed();
            }
            
            if(!estaOrdenado(v)){
                std::cout << "El vector no está ordenado." << std::endl;
                return;
            }
        }

        double med = sum / repeticiones;
        tiemposReales.push_back(med);
        numeroElementos.push_back(i);
    }
}

void tiemposCuadradoMatriz(int nMin, int nMax, int increment,
                           std::vector <double> &tiemposReales, std::vector <double> &numeroOrdenes){

    for(int i = nMin; i <= nMax; i += increment){
        std::vector<std::vector<double>> M(i, std::vector<double>(i));
        std::vector<std::vector<double>> C(i, std::vector<double>(i));
        rellenarMatriz(M);
        //std::cout << "Calculando cuadrado matriz " << i << "x" << i << std::endl;
        Clock time;
        time.start();
        cuadradoMatriz(M, C);

        if(time.isStarted()){
            time.stop();
        }

        tiemposReales.push_back(time.elapsed());
        numeroOrdenes.push_back(i);
    }
}

void tiemposFibonacciRecursivo(int nMin, int nMax, int increment, 
                               std::vector <double> &tiemposReales, std::vector <double> &numeroOrdenes){
    for(int i = nMin; i < nMax; i += increment){
        //std::cout << "Calculando Fibonacci hasta el termino " << i << std::endl;
        Clock time;
        time.start();
        fibonacciRecursivo(i);

        if(time.isStarted()){
            time.stop();
        }

        tiemposReales.push_back(time.elapsed());
        numeroOrdenes.push_back(i);
    }
}

void calcularTiemposEstimadosPolinomico(const std::vector <double> &numeroElementos,
                                        const std::vector <double> &a,
                                        std::vector <double> &tiemposEstimados){

    for(int i = 0; i < numeroElementos.size(); i++){
        double t = 0;
        for(int j = 0; j < a.size(); j++)
            t += a[j] * std::pow(numeroElementos[i], j);          
        tiemposEstimados.push_back(t);
    }
}

double calcularTiempoEstimadoPolinomico(const double &n, std::vector <double> &a){
    double t = 0;

    for(int i = 0; i < a.size(); i++)
        t += a[i] * std::pow(n, i);

    return t;
}

void calcularTiemposEstimadosExponencial(const std::vector <double> &n, 
                                         const std::vector <double> &tiemposReales, 
                                         const std::vector <double> &a, 
                                         std::vector <double> &tiemposEstimados){
    double t;           
    for(int i = 0; i < n.size(); i++){
        t = a[0] + a[1]*std::pow(2, n[i]);
        tiemposEstimados.push_back(t);
    }
}

double calcularTiempoEstimadoExponencial(const double &n, const std::vector <double> &a){
    double t = a[0] + a[1]*std::pow(2, n);
    return t;
}

void tiemposN(std::vector <double> &a){
    long int n;
    char option;

    while(true){
        std::cout << std::endl << "Introduzca n: ";
        std::cin >> n;
        if(n == 0) return;
        long double t = calcularTiempoEstimadoPolinomico(n, a);
        long double seg = t / 10e6;
        long int min = seg / 60;
        long int days = min / 1440;
        long int years = days / 365;
        std::cout << "Para un tamaño " << n << " tardara: " << years << " años, " << days << " dias, " 
                  << min << " minutos, " << seg << " segundos" << std::endl;
    }
}

void tiemposExponencialN(std::vector <double> &a){
    long int n;
    char option;

    while(true){
        std::cout << std::endl << "Introduzca n: ";
        std::cin >> n;
        if(n == 0) return;
        long double t = calcularTiempoEstimadoExponencial(n, a);
        long double seg = t / 10e6;
        long int min = seg / 60;
        long int days = min / 1440;
        long int years = days / 365;
        std::cout << "Para un tamaño " << n << " tardara: " << years << " años, " << days << " dias, " 
                  << min << " minutos, " << seg << " segundos" << std::endl;
    }
}