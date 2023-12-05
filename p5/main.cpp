#include <iostream>
#include <cstdlib>
#include <ctime>

#include "./headers/methods.hpp"
#include "./headers/midLevel.hpp"
#include "./headers/common.hpp"

int main() {
    std::srand(std::time(0));
    unsigned int opt;

    do {
        menu();
        std::cout << std::endl << "Opcion: ";
        std::cin >> opt;

        switch(opt){
            case 1:
                nReinasBacktracking();
            break;

            case 2:
                nReinasBacktracking2();
            break;

            case 3:
                nReinasLasVegas();
            break;

            case 4:
                monteCarlo();
            break;

            case 5: return EXIT_SUCCESS;
        }

        if(opt <= 0 || opt > 5)
            std::cerr << std::endl << "ERROR: La opcion elegida no es válida" << std::endl;

    } while (true);
}