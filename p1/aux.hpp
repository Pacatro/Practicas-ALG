#ifndef AUX
#define AUX

#include <vector>

void rellenarVector(std::vector<int> &v);
bool estaOrdenado(const std::vector <int> &v);
void almacenarFichero(const std::vector <double> &tiemposReales, const std::vector <double> &numeroElementos);
double sumatorio(const std::vector <double> &n, const std::vector<double> &t, int expN, int expT); 
void calcularTiemposEstimadosPolinomico(const std::vector <double> &numeroElementos, const std::vector <double> &a, std::vector <double> &tiemposEstimados);
double calcularTiempoEstimadoPolinomico(const double &n, std::vector <double> &a);
void almacenarDatosFichero(const std::vector <double> &tiemposReales, const std::vector <double> &numeroElementos, const std::vector <double> &tiemposEstimados);
void tiemposN(std::vector <double> &a);
void rellenarMatriz(std::vector <std::vector <double>> &M);


#endif