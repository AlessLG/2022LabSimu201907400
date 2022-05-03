/*
Autor:          Alessandro Lavagnino González
Carnet:         201907400
Fecha:          04/25/22
Compilador:     gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Compilado:      gcc -o NewtonRaphson.out NewtonRaphson.c -lm && ./NewtonRaphson.out
Librerias:      stdio, math, stdlib
Resumen:        Este programa utiliza el método de Newton-Raphson para calcular la raíz de la función exp(x)+x. La calidad de la respuesta depende de los
                parámetros ingresados por el usuario.
*/

// Librerías.
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// Prototipamos funciones.
float f(float x);
float df(float x);
float NewtonRaphson(float xant, float e, int N);
float absoluto(float x);

int main() {
    // Declaramos variables globales.
    float aprox = 0, toler = 0, resultNR = 0;
    int iter = 0;
    // Leemos los valores que se usaran para el algoritmo de N-R.
    printf("Ingrese una aproximación para la raíz: ");
    scanf("%f", &aprox);
    do {
        printf("Ingrese el valor de tolerancia (debe ser mayor a 0): ");
        scanf("%f", &toler);
    } while (toler <= 0);           // Introducimos al usuario en un ciclo del que solo saldra ingresando un valor que cumpla la condición.
    do {
        printf("Ingrese el máximo número de iteraciones que quiere hacer (debe ser mayor o igual a 1): ");
        scanf("%d", &iter);
    } while (iter < 1);             // Introducimos al usuario en un ciclo del que solo saldra ingresando un valor que cumpla la condición.
    // Asignamos el resultado del método a una variable.
    resultNR = NewtonRaphson(aprox, toler, iter);
    // Si el error de la respuesta del algoritmo es menor que la tolerancia aceptable, se muestra el resultado y su error.
    if (absoluto(f(resultNR)) <= toler) {
        printf("El resultado es:\t%f\n", resultNR);
        printf("Su error es de:\t\t%f\n", absoluto(f(resultNR)));
    }
    // Si no lo es, se muestra un mensaje de error.
    else
        printf("No hay solución luego de %d iteraciones.\n", iter);
    return 0;
}

float NewtonRaphson(float xant, float e, int N) {
    // Declaramos e inicializamos variables locales.
    float x = 0;
    int i = 0;
    printf("----------------------------------------------------------------------------------\n");
    printf("[i]\t[x_i]\t\t[f(x_i)]\t[f'(x_i)]\t[x_i - f(x_i)/f'(x_i)]\n");
    // Repetimos la fórmula del método mientras se cumplan las condiciones del while.
    while (i<N && f(xant)>e) {
    // Imprimimos los valores que obtenemos del método.
        printf("%d\t%f\t%f\t%f\t%f\n", i+1, xant, f(xant), df(xant), xant-(f(xant)/df(xant)));
    // Llamamos a otras funciones para realizar los cálculos.
        x = xant-f(xant)/df(xant);
        xant = x;
        i++;
    }
    printf("----------------------------------------------------------------------------------\n");
    // Una vez se haya cumplido una de las condiciones, devolvemos el resultado.
    return x;
}

float f(float x) {
    // Valuamos el valor ingresado en la siguiente función:
    x = exp(x)+x;
    return x;
}

float df(float x) {
    // Valuamos el valor ingresado en la siguiente función:
    x = exp(x)+1;
    return x;
}

float absoluto(float x) {
    // Se determina si el valor ingresado es menor a cero. Si lo es, se le cambia de signo. Si no, simplemente se regresa.
    if (x<0)
        x = -x;
    return x;
}