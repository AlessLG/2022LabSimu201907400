/*
Autor:          aless
Fecha:          03/29/22
Compilador:     gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Compilado:      gcc -o problema3.out problema3.c && ./problema3.out
Librerias:      stdio
Resumen:        Sea (n) un entero mayor a cero. Sea (r) otro entero mayor a cero tal que (r^2 <= n). Este programa calcula (r) dado un (n) ingresado por
                el usuario.
*/

//Librerias
#include <stdio.h>

int main() {
    int n=0, r=0;                                                   // 1. Se inicializan las variables
    puts("Ingrese el número al que le quiere calcular su raíz:");   // 2. Se pide que se ingrese (n) y se lee.
    scanf("%d", &n);
    if (n>0) {                                                      // 3. Se valida que (n) sea mayor a cero
        r=1;
            while (r*r<=n) {                                        // 4. El ciclo aumenta el valor de (r) hasta que se cumpla la condición.
                r++;
            }
        printf("La raíz aproximada es: %d \n", r-1);                // 5. Cuando se cumpla la condición, se imprime (r-1)
    }
    else if (n<1) {                                                 // 6. Si (n) es menor a uno, se termina el programa.
        puts("El valor ingresado tiene que ser mayor a cero.");
    }
return 0;
}