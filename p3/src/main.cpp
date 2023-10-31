#include <iostream>

void changeProblem();
void backpackProblem();
void menu();

int main(){
    int opt;

    while(true){
        menu();
        std::cin >> opt;

        switch(opt){
            case 1: 
                std::cout << "1" << std::endl;
            break;

            case 2:
                std::cout << "2" << std::endl;
            break;

            case 3:
                return 0;
        }
    }
}