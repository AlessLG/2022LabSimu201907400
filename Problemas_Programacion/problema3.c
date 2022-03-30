/*
Autor:          aless
Fecha:          03/29/22
Compilador:     gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Compilado:      gcc -o problema3.out problema3.c && ./problema3.out
Librerias:      stdio
Resumen:        Sea (n) un entero mayor a cero. Sea (r) otro entero mayor a cero tal que (r^2 <= n). Dado un (n) ingresado por
                el usuario, este programa calcula el mayor (r) que cumpla esa condición.
*/

//Librerias
#include <stdio.h>

int main() {
int n=0, r=1;                                               // 1. Se inicializan las variables
    do {                                                    // 2. El usuario entra en un ciclo del cual solo puede salir si se cumple la condición.
        puts("Ingrese el número al que le quiere calcular su raíz (tiene que ser mayor o igual a 1):");
        scanf("%d", &n);
    } while (n<=0);
    while (r*r<=n) { r++; }                                 // 3. El ciclo aumenta el valor de (r) hasta que se deje de cumplir la condición.
    printf("La raíz entera aproximada es: %d \n", r-1);     // 4. En dado caso, se imprime (r-1). Que es el mayor número que cumplió la condición.
return 0;
}