#include <vector>
#include <iostream>

#include "./headers/methods.hpp"
#include "./headers/common.hpp"

bool lugar(int k, std::vector<int> &x) {
    for(int i = 0; i < k; i++) {
        if(x[i] == x[k] || std::abs(x[i]-x[k]) == std::abs(i-k))
            return false;
    }

    return true;
}


void nReinasBacktracking(int n, std::vector<std::vector<int>> &soluciones) {
    std::vector<int> x(n);
    x[0] = -1;
    int k = 0;

    while(k > -1) {
        x[k]++;

        while(x[k] < n && !lugar(k, x))
            x[k]++;

        if(x[k] < n) {
            if(k == n-1) {
                soluciones.push_back(x);
            } else {
                k++;
                x[k] = -1;
            }
        } else k--;
    }
}

void nReinasBacktracking(int n, std::vector<int> &solucion) {
    solucion[0] = -1;
    int k = 0;

    while(k > -1) {
        solucion[k]++;

        while(solucion[k] < n && !lugar(k, solucion))
            solucion[k]++;

        if(solucion[k] < n) {
            if(k == n-1) {
                return;
            } else {
                k++;
                solucion[k] = -1;
            }
        } else k--;
    }
}

bool nReinasLasVegas(int n, std::vector<int> &solucion) {
    for(int i = 0; i < n; i++)
        solucion[i] = 0;

    int cont;
    std::vector<int> ok(n);

    for(int k = 0; k < n; k++) {
        cont = -1;

        for(int j = 0; j < n; j++) {
            solucion[k] = j;

            if(lugar(k, solucion)) {
                cont++;
                ok[cont] = j;
            }   
        }

        if(cont == -1) break;

        int colum = ok[std::rand() % (cont+1)];
        solucion[k] = colum;
    }

    if(cont == -1)
        return false;
    
    return true;
}

void prodMatrix(std::vector<std::vector<int>> &A, std::vector<std::vector<int>> &B, std::vector<std::vector<int>> &AB) {
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < B[0].size(); j++) {
            AB[i][j] = 0;
            for(int k = 0; k < A[0].size(); k++)
                AB[i][j] += A[i][k] * B[k][j];
        }
    }
}

void generateC(std::vector<std::vector<int>> &AB, std::vector<std::vector<int>> &C) {
    int given = (std::rand() % 6) + 1;

    C = AB;

    if(given % 2 != 0) C[AB.size()/2][AB.size()/2]++;
}

bool verifyProd(int n, std::vector<std::vector<int>> &A, std::vector<std::vector<int>> &B, std::vector<std::vector<int>> &C) {    
    std::vector<std::vector<int>> X;
    std::vector<std::vector<int>> XA(1, std::vector<int>(n));
    std::vector<std::vector<int>> XAB(1, std::vector<int>(n));
    std::vector<std::vector<int>> XC(1, std::vector<int>(n));
    
    fillVector(n, X);
    
    prodMatrix(X, A, XA);
    prodMatrix(XA, B, XAB);
    prodMatrix(X, C, XC);

    if(XAB == XC)
        return true;
    
    return false;
}

bool verifyProdRep(int tests, int n, int &nTests, std::vector<std::vector<int>> &A, 
                                                  std::vector<std::vector<int>> &B, 
                                                  std::vector<std::vector<int>> &C) {
    for(int i = 0; i < tests; i++) {
        nTests = i+1;
        if(!verifyProd(n, A, B, C))
            return false;
    }

    return true;
}
