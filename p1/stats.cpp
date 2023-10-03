#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include <cmath>
#include "stats.hpp"
#include "ClaseTiempo.hpp"
#include "sistemaEcuaciones.hpp"
#include "methods.hpp"

double sumatorio(const std::vector <double> &n, 
                 const std::vector <double> &t, 
                 int expN, int expT){
    double sum = 0;
    
    for(int i = 0; i<n.size() && i<t.size(); i++)
        sum += std::pow(n[i], expN) * std::pow(t[i], expT);

    return sum;
}

double media(const std::vector <double> v){
    double sum = 0;
    
    for(int i = 0; i < v.size(); i++)
        sum += v[i];

    double med = sum / v.size();
    return med;
}

double varianza(const std::vector <double> v){
    double sum = 0;
    
    for(int i = 0; i < v.size(); i++)
        sum += (v[i] - media(v)) * (v[i] - media(v));
    
    double var = sum / (v.size() - 1);

    return var;
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

double calcularCoeficienteDeterminacion(const std::vector <double> &tiemposReales, 
                                        const std::vector <double> &tiemposEstimados){
    
    double coefDet = varianza(tiemposEstimados) / varianza(tiemposReales);
    return coefDet;
}

void ajusteCubico(const std::vector <double> &n, 
                  const std::vector <double> &tiemposReales, 
                  std::vector <double> &a){

    ajusteCuadratico(n, tiemposReales, a);
}

void ajusteExponencial(const std::vector <double> &n, 
                       const std::vector <double> &tiemposReales, 
                       std::vector <double> &a){
    
    std::vector <double> exp(n.size());

    for(int i = 0; i < n.size(); i++)
        exp[i] = std::pow(2, n[i]);
    
    ajusteCuadratico(exp, tiemposReales, a);
}
