/*
Autor:          aless
Fecha:          04/25/22
Compilador:     gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Compilado:      gcc -o NewtonRaphson.out NewtonRaphson.c -lm && ./NewtonRaphson.out
Librerias:      stdio, math
Resumen:        Este programa 
*/

#include <math.h>
#include <stdio.h>              //Librerias

#define e 2.7182818284590452353602874

int main() {
    double x=1, res, y;
    unsigned int j;
    int i;
    printf("Ingrese un número y: ");
    scanf("%lf", &y);
    printf("Ingrese el número de iteraciones que quiere hacer: ");
    scanf("%d", &j);
    for (i = 0; i < j+1; i++) {
        x += x - (exp(x)+x-y)/(exp(x)+1);
    }
    printf("El resultado es: %lf\n", x);
return 0;
}