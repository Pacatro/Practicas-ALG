#include <iostream>
#include "midLevel.hpp"
#include "aux.hpp"

int main(){
    int choice;

    while(true){
        menu();
        std::cin >> choice;

        switch(choice){
            case 1:
                ordenacionSeleccion();
            break;

            case 2:
                matrizCuadrado();
            break;

            case 3:
                fibonacciRecursivo();
            break;

            default:
                return 0;
        }
    }

    return 0;

}
