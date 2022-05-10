/*
Autor:          Alessandro Lavagnino González
Carnet:         201907400
Fecha:          2022/05/06
Compilador:     gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Compilado:      gcc -o Problema3.out Problema3.c -lm && ./Problema3.out
Librerias:      stdio, math
Resumen:        Este programa lee dos coordenadas de un espacio de tres dimensiones y muestra algunos cálculos entre los vectores ingresados.
*/

// Librerías.
#include <stdio.h>
#include <math.h>

// Prototipamos funciones.
float multiplicacion(float a[], float b[]);
float sumaVectores(float a[], float b[]);
float vectorial(float a[], float b[]);

int main() {
    // Declaramos dos vectores de 3 entradas c/u.
    float v1[3], v2[3];
    // Pedimos las coordenadas de los vectores.
    puts("Ingrese las coordenadas del primer vector.");
    puts(" • Separe las las coordenadas por un espacio o un enter.");
    scanf("%f %f %f", &v1[0], &v1[1], &v1[2]);
    puts("Ingrese las coordenadas del segundo vector.");
    puts(" • Separe las coordenadas por un espacio o un enter.");
    scanf("%f %f %f", &v2[0], &v2[1], &v2[2]);
    // Mostramos los vectores al usuario.
    printf("v1 = [%f, %f, %f]\n", v1[0], v1[1], v1[2]);
    printf("v2 = [%f, %f, %f]\n", v2[0], v2[1], v2[2]);
    puts("----------------------------------------------------------------");
    // Imprimimos el resultado de llamar a las funciones.
    printf("(a) La magnitud del primer vector es:\t\t%.2f\n", sqrt(multiplicacion(v1, v1)));
    printf("    La magnitud del segundo vector es:\t\t%.2f\n", sqrt(multiplicacion(v2, v2)));
    printf("(b) La suma de los vectores es:\t\t\t");
    sumaVectores(v1, v2);
    printf("(c) El producto escalar de los vectores es:\t%.2f\n", multiplicacion(v1, v2));
    printf("(d) El producto vectorial v1 x v2 es:\t\t");
    vectorial(v1, v2);
    printf("\n    El producto vectorial v2 x v1 es:\t\t");
    vectorial(v2, v1);
    puts("\n----------------------------------------------------------------");
return 0;
}

// La función recibe dos vectores a y b.
float multiplicacion(float a[], float b[]) {
    // Se define una variable que almacenará el resultado (tipo flotante).
    float res = 0;
    // La variable almacena el valor de la sumatoria de las entradas 
    res = a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
    return res;
}

// La función que suma dos vectores a y b.
float sumaVectores(float a[], float b[]) {
    // Se define un vector que almacenará la sumatoria de las entradas.
    float res[3];
    // Se asignan valores a las entradas del vector previamente definido. Correspondiente a las entradas de los vectores ingresados.
    res[0] = a[0]+b[0];
    res[1] = a[1]+b[1];
    res[2] = a[2]+b[2];
    // Se imprimen las coordenadas del vector res[].
    printf("[%.2f, %.2f, %.2f]\n", res[0], res[1], res[2]);
}

// La función que calcula el producto vectorial de dos vectores a y b.
float vectorial(float a[], float b[]) {
    // Se define un vector que almacenará el resultado.
    float res[3];
    // Se realizan los cálculos correspondientes a cada coordenada y se guardan en el vector del resultado.
    res[0] = a[1]*b[2] - a[2]*b[1];
    res[1] = a[2]*b[0] - a[0]*b[2];
    res[2] = a[0]*b[1] - a[1]*b[0];
    // Se imprimen las coordenadas del vecor res[].
    printf("[%.2f i, %.2f j, %.2f k]", res[0], res[1], res[2]);
}