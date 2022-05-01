/*
Autor:          aless
Fecha:          04/25/22
Compilador:     gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Compilado:      gcc -o NewtonRaphson.out NewtonRaphson.c -lm && ./NewtonRaphson.out
Librerias:      stdio, math, stdlib
Resumen:        Este programa 
*/

#include <math.h>                   // Librerías.
#include <stdlib.h>
#include <stdio.h>

float f(float x);
float df(float x);
float NewtonRaphson(float x, float e, int N);
float absoluto(float x);

int main() {
    float aprox = 0, toler = 0, resultNR = 0;
    int iter = 0;
    printf("Ingrese una aproximación para la raíz: ");
    scanf("%f", &aprox);
    do {
        printf("Ingrese el valor de tolerancia (debe ser mayor a 0): ");
        scanf("%f", &toler);
    } while (toler <= 0);
    do {
        printf("Ingrese el máximo número de iteraciones que quiere hacer (debe ser mayor o igual a 1): ");
        scanf("%d", &iter);
    } while (iter < 1);

    resultNR = NewtonRaphson(aprox, toler, iter);
    //printf("resultNR = %f, f(resultNR) = %f, absoluto(f(resultNR)) = %f\n", resultNR, f(resultNR), absoluto(f(resultNR)));
    if (absoluto(f(resultNR)) <= toler) {
        printf("El resultado es:\t%f\n", resultNR);
        printf("Su error es de:\t\t%f\n", absoluto(f(resultNR)));
    }
    else
        printf("No hay solución luego de %d iteraciones.\n", iter);
    return 0;
}

float NewtonRaphson(float xant, float e, int N) {
    float x = 0;
    int i = 0;
    // printf("xant = %f, e = %f, N = %d\n", xant, e, N);
    printf("----------------------------------------------------------------------------------\n");
    printf("[i]\t[x_i]\t\t[f(x_i)]\t[f'(x_i)]\t[x_i - f(x_i)/f'(x_i)]\n");
    while (i<N && f(xant)>e) {
        printf("%d\t%f\t%f\t%f\t%f\n", i+1, xant, f(xant), df(xant), xant-(f(xant)/df(xant)));
        x = xant-f(xant)/df(xant);
        xant = x;
        i++;
    }
    printf("----------------------------------------------------------------------------------\n");
    return x;
}

float f(float x) {
    x = exp(x)+x;
    return x;
}

float df(float x) {
    x = exp(x)+1;
    return x;
}

float absoluto(float x) {
    if (x<0)
        x = -x;
    return x;
}