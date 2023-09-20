#include <iostream>
#include "./headers/functions.hpp"

int main(){
    int choice;
    std::vector<int> v = {1, 2, 3};

    while(true){
        menu();
        std::cin >> choice;

        switch(choice){
            case 1:
                ordenacionSeleccion();
            break;

            case 2:
                //matrizCuadrado();
            break;

            case 3:
                //fibonacciRecursivo();
            break;

            default:
                return 0;
        }
    }

    return 0;

}
