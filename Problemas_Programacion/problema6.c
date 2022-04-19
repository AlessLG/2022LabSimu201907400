/*
Autor:          aless
Fecha:          04/11/22
Compilador:     gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Compilado:      gcc -o problema6.out problema6.c && ./problema6.out
Librerias:      stdio
Resumen:        Este programa 
*/

#include <stdio.h>              // Librerias
int main() {
    int FM, CM=2, fila, col;    // Definimos las variables que definirán el tamaño de nuestra matriz. Y dos variables de conteo.
    do {
        printf("Escriba el número de vértices que tendrá el polígono. El número debe ser mayor o igual que 3.: ");
        scanf("%d", &FM);
    } while (FM<3);
    printf("El número de vértices es: %d\n", FM);

    int matriz[FM][CM];                       // Declaramos la matriz

    for (fila = 0; fila < FM; fila++) {         // Para ingresar los valores a la matriz.
        for (col = 0; col < CM; col++) {
            printf("Ingrese un valor: ");
            scanf("%d", &matriz[fila][col]);
        }
    }
    puts("Los valores de la matriz son:");
    for (fila = 0; fila < FM; fila++) {         // Para imprimir los valores a la matriz.
        for (col = 0; col < CM-1; col++) {
            printf("%d", matriz[fila][col]);
            printf("\t%d\n", matriz[fila][col+1]);
        }
    }
    puts("");
return 0;
}
