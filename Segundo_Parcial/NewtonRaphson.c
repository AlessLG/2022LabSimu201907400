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
    float aprox, toler, resultNR;
    int iter;
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
    resultNR = f(NewtonRaphson(aprox, toler, iter));
    printf("f(resultNR) = %f, absoluto(f(resultNR)) = %f\n", resultNR, absoluto(resultNR));
    if (absoluto(resultNR) <= toler) {
        printf("El resultado es: %f\n", resultNR);
    }
    else {
        printf("No hay solución luego de %d iteraciones\n", iter);
    }
    return 0;
}

float NewtonRaphson(float xant, float e, int N) {
    float x;
    int i=0;
    printf("e = %f, N= %d\n", e, N);
    while (i<N) {
        x = xant-f(xant)/df(xant);
        xant = x;
        i++;
        printf("[%d.] x = %f,\tf(x)=%f\n", i, x, f(x));
    }
    return x;
}

float f(float x) {
    float res = 0;
    res = exp(x)+x;
    return res;
}

float df(float x) {
    float res = 0;
    res = exp(x)+1;
    return res;
}

float absoluto(float x) {
    float res = 0;
    if (x<0)
        res = -x;
    else if (x>=0)
        res = res;
    return res;
}