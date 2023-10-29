#!/bin/bash
cd build/src
echo "Ejecutando pruebas..."

numeroMedianas=(3 5 9 15 25)
numeroMinimo=(500 1000 5000 10000 50000)

for med in "${numeroMedianas[@]}"; do
    for n in "${numeroMinimo[@]}"; do
        echo -e "\nPrueba para numeroMediana = $med y numeroMinimo = $n\n"
        ./p2 -m 1000000 -M 5000000 -i 100000 -r 3 -e "$med" -n "$n"
    done
done