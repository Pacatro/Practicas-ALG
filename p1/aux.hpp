#ifndef AUX
#define AUX

#include <vector>

void menu();
void rellenarVector(std::vector<int> &v);
bool estaOrdenado(const std::vector <int> &v);
void almacenarFichero(const std::vector <double> &tiemposReales, const std::vector <double> &numeroElementos);
double sumatorio(const std::vector <double> &n, const std::vector<double> &t, int expN, int expT); 
double media(const std::vector <double> v);
double varianza(const std::vector <double> v);
void almacenarDatosFichero(const std::vector <double> &tiemposReales, const std::vector <double> &numeroElementos, const std::vector <double> &tiemposEstimados);
void rellenarMatriz(std::vector <std::vector <double>> &M);

#endif