#include <iostream>
#include <cstdlib>
#include <ctime>

#include "./headers/backtracking.hpp"
#include "./headers/lasVegas.hpp"
#include "./headers/midLevel.hpp"
#include "./headers/common.hpp"

int main() {
    std::srand(std::time(0));
    int opt;

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
        }
    } while (opt > 0 && opt != 4);

    return EXIT_SUCCESS;
}