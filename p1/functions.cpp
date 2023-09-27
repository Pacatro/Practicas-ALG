#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <cmath>
#include "functions.hpp"
#include "ClaseTiempo.hpp"
#include "sistemaEcuaciones.hpp"

void menu() {
    std::cout << std::endl;
    std::cout << "**Introduzca cualquier valor para salir**" << std::endl;
    std::cout << std::endl;
    std::cout << "1: Método de ordenación por selección" << std::endl;
    std::cout << "2: Cálculo del cuadrado de una matriz" << std::endl;
    std::cout << "3: Cálculo del término n-ésimo de la sucesión de Fibonacci" << std::endl;
}

void rellenarVector(std::vector<int> &v){
    std::srand(std::time(nullptr));
    for(int i = 0; i<v.size(); i++)
        v[i] = std::rand() % 50;
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

bool estaOrdenado(const std::vector <int> &v){
    if(v.size() <= 1)
        return true;

    for(int i = 1; i < v.size(); i++){
        if (v[i] < v[i - 1]) 
            return false;
    }

    return true;
}

void tiemposOrdenacionSelección(int nMin, int nMax, int increment, int repeticiones,
                                std::vector <double> &tiemposReales, std::vector <double> &numeroElementos){
    double sum = 0;

    for(int i = nMin; i <= nMax; i += increment){
        for(int j = 0; j<repeticiones; j++){
            std::vector<int> v(i);
            rellenarVector(v);
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

void almacenarFichero(const std::vector <double> &tiemposReales,
                      const std::vector <double> &numeroElementos){
    std::ofstream file("tiempoReales.txt");

    if(!file){
        std::cout << "No se ha podido abrir el fichero." << std::endl;
        return;
    }

    for(int i = 0; i < numeroElementos.size() && i < tiemposReales.size(); i++)
        file << numeroElementos[i] << " " << tiemposReales[i] << std::endl;

    file.close();
}

void ajusteCuadratico(const std::vector<double> &numeroElementos,
                      const std::vector<double> &tiemposReales,
                      std::vector<double> &a){
    
    std::vector<std::vector<double>> A(a.size(), std::vector<double>(a.size()));
    std::vector<std::vector<double>> B(a.size(), std::vector<double>(1));
    std::vector<std::vector<double>> X(a.size(), std::vector<double>(1));

    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a.size(); j++)
            A[i][j] = sumatorio(numeroElementos, tiemposReales, i+j, 0);
        
        B[i][0] = sumatorio(numeroElementos, tiemposReales, i, 1);
    }

    resolverSistemaEcuaciones(A, B, a.size(), X);

    for(int i = 0; i < X.size(); i++)
        a[i] = X[i][0];
}

double sumatorio(const std::vector <double> &n, 
                 const std::vector <double> &t, 
                 int expN, int expT){
    double sum = 0;
    
    for(int i = 0; i<n.size() && i<t.size(); i++)
        sum += std::pow(n[i], expN) * std::pow(t[i], expT);

    return sum;
}

void calcularTiemposEstimadosPolinomico(const std::vector <double> &numeroElementos,
                                        const std::vector <double> &a,
                                        std::vector <double> &tiemposEstimados){
    //t(n) = a0 + a1*n + a2*n²
    for(int i = 0; i < numeroElementos.size(); i++){
        double t = a[0] + a[1]*numeroElementos[i] + a[2]*(numeroElementos[i]*numeroElementos[i]);
        tiemposEstimados.push_back(t);
    }
}

void almacenarDatosFichero(const std::vector <double> &tiemposReales, 
                           const std::vector <double> &numeroElementos,
                           const std::vector <double> &tiemposEstimados){
    
    std::ofstream file("datosFinales.txt");

    if(!file){
        std::cout << "No se ha podido abrir el fichero." << std::endl;
        return;
    }

    for(int i = 0; i < numeroElementos.size() && i < tiemposReales.size() && i < tiemposEstimados.size(); i++)
        file << numeroElementos[i] << " " << tiemposReales[i] << " " << tiemposEstimados[i] << std::endl;

    file.close();
}

double calcularTiempoEstimadoPolinomico(const double &n, std::vector <double> &a){
    //t(n) = a0 + a1*n + a2*n²
    double t = a[0] + a[1]*n + a[2]*(n*n);
    return t;
}

void tiemposN(std::vector <double> &a){
    long int n;
    char option;

    while(true){
        std::cout << std::endl << "Introduzca numero elementos: ";
        std::cin >> n;
        if(n == 0) return;
        double t = calcularTiempoEstimadoPolinomico(n, a);
        double seg = t / 10e6;
        double min = seg / 60;
        int days = min / 1440;
        int years = days / 365;
        std::cout << "Para un tamaño " << n << " tardara: " << years << " años, " << days << " dias, " 
                  << min << " minutos, " << seg << " segundos" << std::endl;
    }
}

void ordenacionSeleccion(){
    std::vector<double> tiemposReales;
    std::vector<double> numeroElementos;
    std::vector<double> a(3);
    std::vector<double> tiemposEstimados;
    int nMin, nMax, increment, rep;

    std::cout << "Introduzca el minimo de elementos: ";
    std::cin >> nMin;

    std::cout << "Introduzca el maximo de elementos: ";
    std::cin >> nMax;

    std::cout << "Introduzca el incremento: ";
    std::cin >> increment;

    std::cout << "Introduzca el numero de repeticiones: ";
    std::cin >> rep;

    if(nMax < nMin || nMax == 0 || nMin == 0 || increment == 0 || rep == 0){
        std::cout << std::endl << "Numeros incorrectos." << std::endl;
        return;
    }

    std::cout << "Calculando tiempos..." << std::endl;

    tiemposOrdenacionSelección(nMin, nMax, increment, rep, tiemposReales, numeroElementos);
    almacenarFichero(tiemposReales, numeroElementos);
    ajusteCuadratico(numeroElementos, tiemposReales, a);

    std::cout << std::endl;
    std::cout << "Incognitas: " << std::endl;
    std::cout << "a0 = " << a[0] << std::endl;
    std::cout << "a1 = " << a[1] << std::endl;
    std::cout << "a2 = " << a[2] << std::endl;

    calcularTiemposEstimadosPolinomico(numeroElementos, a, tiemposEstimados);
    almacenarDatosFichero(tiemposReales, numeroElementos, tiemposEstimados);
    tiemposN(a);
}

void rellenarMatriz(std::vector <std::vector <double>> &M){
    for(int i = 0; i < M.size(); i++){
        for(int j = 0; j < M[i].size(); j++)
            M[i][j] = 0.95 + static_cast<double>(std::rand()) / RAND_MAX * 0.1;
    }
}

void tiemposCuadradoMatriz(int nMin, int nMax, int increment,
                           std::vector <double> &tiemposReales, std::vector <double> &numeroOrdenes){

    for(int i = nMin; i <= nMax; i += increment){
        std::vector<std::vector<double>> M(i, std::vector<double>(i));
        std::vector<std::vector<double>> C(i, std::vector<double>(i));
        rellenarMatriz(M);
        Clock time;
        time.start();
        multiplicarMatrices(M, M, C);

        if(time.isStarted()){
            time.stop();
        }

        tiemposReales.push_back(time.elapsed());
        numeroOrdenes.push_back(i);
    }
}

void matrizCuadrado(){
    std::vector<double> tiemposReales;
    std::vector<double> numeroOrdenes;
    std::vector<double> a(4);
    std::vector<double> tiemposEstimados;
    int nMin, nMax, increment, rep;

    std::cout << "Introduzca el minimo de elementos: ";
    std::cin >> nMin;

    std::cout << "Introduzca el maximo de elementos: ";
    std::cin >> nMax;

    std::cout << "Introduzca el incremento: ";
    std::cin >> increment;

    if(nMax < nMin || nMax == 0 || nMin == 0 || increment == 0){
        std::cout << std::endl << "Numeros incorrectos." << std::endl;
        return;
    }

    std::cout << "Calculando tiempos..." << std::endl;

    tiemposCuadradoMatriz(nMin, nMax, increment, tiemposReales, numeroOrdenes);
    almacenarFichero(tiemposReales, numeroOrdenes);
    ajusteCuadratico(numeroOrdenes, tiemposReales, a);

    std::cout << std::endl;
    std::cout << "Incognitas: " << std::endl;
    std::cout << "a0 = " << a[0] << std::endl;
    std::cout << "a1 = " << a[1] << std::endl;
    std::cout << "a2 = " << a[2] << std::endl;
    std::cout << "a3 = " << a[3] << std::endl;

    //calcularTiemposEstimadosPolinomico(numeroOrdenes, a, tiemposEstimados);
    //almacenarDatosFichero(tiemposReales, numeroOrdenes, tiemposEstimados);
}
