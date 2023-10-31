#include <iostream>

void changeProblem();
void backpackProblem();
void menu();

int main(){
    int opt;

    while(true){
        menu();
        std::cin >> opt;
        std::cout << std::endl;

        switch(opt){
            case 1: 
                changeProblem();
            break;

            case 2:
                std::cout << "2" << std::endl;
            break;

            case 3:
                return 0;
        }
    }

    return 0;
}