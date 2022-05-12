/*
Autor:          Alessandro Lavagnino González
Carnet:         201907400
Fecha:          2022/05/06
Compilador:     gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Compilado:      gcc -o Problema1.out Problema1.c && ./Problema1.out
Librerias:      stdio, stdlib, time
Resumen:        Este programa ingresa 10 números pares aleatorios del 2 al 20 en un vector. Luego le pregunta al usuario como quiere ver ordenado este mismo.
*/

// Librerias.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Inicializamos vector.
    int vector[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // Inicializamos variable auxiliar y las de conteo.
    int i = 0, j = 0, k = 0, n = 10;
    int varRandom, pasada, interruptor;
    // Declaramos variable tipo caracter.
    char orden;
    // Definimos variable de tiempo.
    time_t t;

    // Inicializa RNG.
    srand((unsigned) time(&t));

    // El bucle se ejecuta mientras la última coordenada del vector está "vacía".
    while (vector[9]==0) {
        // Asignamos un número aleatorio del 0 al 20 a la variable auxiliar.
        varRandom = rand() % 21;
        // printf("aux=%d\n", aux);
        // Si el número aleatorio tiene residuo cero con 2 (es decir que es par) y es distinto de cero...
        if ((varRandom%2==0) && (varRandom!=0)) {
            // printf("Se pudo!\n");
            // Se le asigna a la j-ésima coordenada del vector inicial.
            vector[k]=varRandom;
            // Y se aumenta de valor a la variable de conteo j.
            k++;
        }
    }

    puts("El vector generado con números aleatorios pares del 2 al 20 es: ");
    for (k = 0; k < n; k++) {
        printf("%d ", vector[k]);
    }
    puts("");
    puts("¿Cómo desea ver ordenado el vector?");
    puts("Ingrese una letra 'a' si lo quiere visualizar de forma ascendente, y una 'd' si lo quiere de forma descendente.");
    scanf("%c", &orden);
    if ((orden!='a') && (orden != 'd')) {
        while (orden!='a' && orden!='d') {
            printf("La letra no es válida: ");
            scanf("%c", &orden);
        }
    }
    if (orden=='a') {
        // Se inicializa variable.
        interruptor = 1;
        for (pasada = 0; pasada < n-1 && interruptor; pasada++) {
        interruptor = 0;
        // for que maneja el paso por el vector.
            for (j = 0; j < n-pasada-1; j++) {
                // Se valida que el valor seleccionado sea mayor al siguiente.
                if (vector[j] > vector[j+1]) {
                    // Se declara una variable que almacenara temporalmente un valor.
                    int aux;
                    // Se intercambian dos entradas de lugar.
                    aux = vector[j];
                    vector[j] = vector[j+1];
                    vector[j+1] = aux;
                }
                interruptor = 1;
            }
        }
        puts("El vector ordenado en forma ascendente:");
        for (k = 0; k < n; k++) {
        printf("%d ", vector[k]);
        }
        puts("");
    }
    else if (orden='d') {
        // Se inicializa variable.
        interruptor = 1;
        for (pasada = 0; pasada < n-1 && interruptor; pasada++) {
        interruptor = 0;
        // for que maneja el paso por el vector.
            for (j = 0; j < n-pasada-1; j++) {
                // Se valida que el valor seleccionado sea mayor al siguiente.
                if (vector[j] < vector[j+1]) {
                    // Se declara una variable que almacenara temporalmente un valor.
                    int aux;
                    // Se intercambian dos entradas de lugar.
                    aux = vector[j];
                    vector[j] = vector[j+1];
                    vector[j+1] = aux;
                }
                interruptor = 1;
            }
        }
        puts("El vector ordenado en forma descendente:");
        for (k = 0; k < n; k++) {
        printf("%d ", vector[k]);
        }
        puts("");
    }
    return 0;
}
