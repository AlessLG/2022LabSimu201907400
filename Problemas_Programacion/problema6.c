/*
Autor:          aless
Fecha:          04/11/22
Compilador:     gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Compilado:      gcc -o problema6.out problema6.c && ./problema6.out
Librerias:      stdio
Resumen:        Este programa calcula el área de un polígono, dada una serie de coordenadas de vértices ingresadas.
*/

#include <stdio.h>              // Librerias

int main() {
    int FM, N, fila, i;         // Definimos variables.
    float A;
    puts("----Calculadora del área de un polígono, dado sus vértices----");
    do {                        // Pedimos el número de vértices.
        puts("Escriba el número de vértices que tendrá el polígono. El número debe ser mayor o igual que 3.");
        scanf("%d", &FM);
    } while (FM<3);

    int matriz[FM][2];          // Declaramos la matriz como una de FM filas x 2 columnas.

    puts("--------------------------------");
    puts("Ingrese las coordenadas de los vértices del polígono.");
    puts(" • Ingrese las entradas de las coordenadas (deben ser dos) separadas por un espacio o un enter. Luego presione enter e ingrese nuevamente dos entradas.");
    puts(" • Deben ser números enteros.");
    puts(" • Las coordenadas deben de ser ingresadas ordenadamente, de tal forma que vayan en contra de las manecillas del reloj.");
    puts(" • El cálculo no funciona si el polígono se intersecta a si mismo o si tiene agujeros.");
    puts("--------------------------------");
    for (fila = 0; fila < FM; fila++) {                                     // Se pide ingresar los valores a la matriz. Fila por fila,
        scanf("%d %d", &matriz[fila][0], &matriz[fila][1]);                 // las dos columnas de un solo.
    }

    puts("Las coordenadas de los vértices del polígono son:");
    for (fila = 0; fila < FM; fila++) {                                     // Se muestran las coordenadas ingresadas.
        printf("(%d, %d)\n", matriz[fila][0], matriz[fila][1]);
    }

    N = FM-1;                                                               // Definimos la variable N

    for (i = 0; i < N; i++) {                                               // Hacemos los cálculos que corresponden a la sumatoria.
        A += (matriz[i][0]*matriz[i+1][1]) - (matriz[i+1][0]*matriz[i][1]);
    }
    A += (matriz[N][0]*matriz[0][1])-(matriz[0][0]*matriz[N][1]);           // Hacemos el cálculo que está afuera de la sumatoria.
    printf("El área del polígono es: %.2f\n", A/2);                         // Mostramos el resultado.
return 0;
}