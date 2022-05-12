/*
Autor:          Alessandro Lavagnino González
Carnet:         201907400
Fecha:          2022/05/06
Compilador:     gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Compilado:      gcc -o Problema2.out Problema2.c && ./Problema2.out
Librerias:      stdio
Resumen:        Este programa lee 5 valores ingresados por el usuario, los almacena en un vector y posteriormente los ordena.
*/

// Librerias.
#include <stdio.h>

int main() {
    // Se declara el vector.
    int vector[5];
    // Se declaran variables de conteo.
    int pasada, j;
    // Se inicializa variable.
    int interruptor = 1;
    // Se le pide al usario ingresar los números y se registran.
    puts("Ingrese cinco números enteros al vector. Puede separarlos por espacios o por enters.");
    scanf("%d %d %d %d %d", &vector[0], &vector[1], &vector[2], &vector[3], &vector[4]);
    // for que controla la cantidad de pasadas.
    for (pasada = 0; pasada < 4 && interruptor; pasada++) {
        interruptor = 0;
        // for que maneja el paso por el vector.
        for (j = 0; j < 5-pasada-1; j++) {
            // Se valida que el valor seleccionado sea mayor al siguiente.
            if (vector[j] > vector[j+1]) {
                // Se declara una variable que almacenara temporalmente un valor.
                int aux;
                printf("Se cambió\t%d %d\ta\t", vector[j], vector[j+1]);
                // Se intercambian dos entradas de lugar.
                aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
                printf("%d %d\n", vector[j], vector[j+1]);
            }
            interruptor = 1;
        }
    }
    // Se imprime el vector ordenado.
    puts("\nVector Ordenado:");
    for (int i = 0; i < 5; i++)
        printf("%d ", vector[i]);
    puts("");
    return 0;
}