#!/bin/bash

#OJO: adaptar las leyendas a los nombres de las variables. En el eje Y se miden tiempos y en el eje X es el tamaño del ejemplar.
cat << _end_ | gnuplot
set terminal postscript eps color
set output "grafico.eps"
set key right bottom
set xlabel "Etiqueta eje X"
set ylabel "Etiqueta Eje Y"
plot 'Datos.txt' using 1:2 t "Datos columna 2 frente a 1" w l, 'Datos.txt' using 1:3 t "Datos columna 3 frente a 1" w l, 'Datos.txt' using 1:5 t "Datos columna 5 frente a 1" w l, 'Datos.txt' using 1:6 t "Datos columna 6 frente a 1" w l 
_end_
