/*
Autor:          aless
Fecha:          03/29/22
Compilador:     gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Compilado:      gcc -o problema5.out problema5.c && ./problema5.out
Librerias:      stdio
Resumen:        Este programa lee dos números enteros, los cuales usa como rango para imprimir todos los números primos en ese rango.
*/

//Librerias
#include <stdio.h>

int n1, n2, i, j, primo;

int es_primo(int i, int j);

int main() {
    do {
        puts("Ingrese el primer número del rango (debe ser mayor a 1):");
        scanf("%d", &n1);
    } while (n1<=1);
    do {
        puts("Ingrese el segundo número del rango (debe ser mayor al número anterior):");
        scanf("%d", &n2);
    } while (n2<=n1);
    i=n1;
    while (i<=n2) {
        es_primo(i, j);
        if (primo==1) {
            printf("%d, ", i);
        }
        i++;
    }
return 0;    
}

int es_primo(int i, int j) {
    j=2;
    primo=1;
    while( j<i && primo==1 ) {
        if ((i%j)==0) {
            primo=0;
        }
        j++;
    }
}
