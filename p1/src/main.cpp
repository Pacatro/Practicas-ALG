#include <iostream>
#include "./headers/functions.h"

int main(){
    int choice;

    while(true){
        menu();
        std::cin >> choice;

        switch (choice){
            case 1:
                break;
            default:
                return 0;
        }
    }

    return 0;

}
