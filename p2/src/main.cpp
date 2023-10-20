#include <iostream>
#include <vector>
#include <getopt.h>
#include "headers/midLevel.hpp"
#include "headers/aux.hpp"

int main(int argc, char** argv ){
    int command, nMin, nMax, increment, rep, nMedian, minN;
    bool hFlag = false;

    static struct option long_options[] = {
        {"min", required_argument, NULL, 'm'},
        {"max", required_argument, NULL, 'M'},
        {"increment", required_argument, NULL, 'i'},
        {"repetitions", required_argument, NULL, 'r'},
        {"nmedian", required_argument, NULL, 'e'},
        {"minelements", required_argument, NULL, 'n'},
        {"help", no_argument, NULL, 'h'},
        {0, 0, 0}
    };

    while((command = getopt_long(argc, argv, "hm:M:i:r:e:n:", long_options, nullptr)) != -1){   
        switch(command){
            case 'm':
                nMin = std::stoi(optarg);
            break;

            case 'M':
                nMax = std::stoi(optarg);
            break;

            case 'i':
                increment = std::stoi(optarg);
            break;

            case 'r':
                rep = std::stoi(optarg);
            break;

            case 'e':
                nMedian = std::stoi(optarg);
            break;

            case 'n':
                minN = std::stoi(optarg);
            break;

            case 'h':
                hFlag = true;
            break;

            default:
                abort();
        }
    }

    if(hFlag){
        printHelp();
        return 0;
    }

    comparacionVariantesQuicksort(nMin, nMax, increment, rep, nMedian, minN);

    return 0;
}