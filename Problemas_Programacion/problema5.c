/*
Autor:          aless
Fecha:          03/29/22
Compilador:     gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Compilado:      gcc -o problema5.out problema5.c && ./problema5.out
Librerias:      stdio
Resumen:        Este programa lee dos números enteros, los cuales usa como rango para imprimir todos los números primos en ese rango.
*/

// Librerías
#include <stdio.h>

int n1, n2, i, j, primo;                // A1. Inicializamos variables.

int es_primo(int i, int j);             // A2. Prototipamos la función que nos dice si un número es primo o no.

int main() {
    do {                                // A3. Le pedimos al usuario que ingrese los números del rango. Y que cumplan con las condiciones especificadas.
        puts("Ingrese el primer número del rango (debe ser mayor a 1, pues 1 no es primo):");
        scanf("%d", &n1);
    } while (n1<=1);
    do {
        puts("Ingrese el segundo número del rango (debe ser mayor al número anterior):");
        scanf("%d", &n2);
    } while (n2<=n1);
    i=n1;                               // A4. Valuamos a (i) con el primer número del rango.
    printf("Los números primos en el rango son: \n");
    while (i<=n2) {                     // A5. Mientras (i) esté en el rango, imprimimos números primos
        es_primo(i, j);                 // A6. Llamamos a la función para que nos diga si el valor actual de (i) es primo o no.
        if (primo==1) {
            printf("- %d ", i);         // A7. Si lo es, lo imprimimos.
        }
        i++;                            // A8. Si no lo es, (i) pasa al siguiente número y se vuelve a hacer el test.
    }
    printf("\n");
return 0;    
}

int es_primo(int i, int j) {
    j=2;                                // B1. Valuamos las variables. 
    primo=1;                            // Nota: En esta función, un número es primo hasta que se demuestre lo contrario.
    while( j<i && primo==1 ) {          // B2. En este ciclo, el valor de (j) irá aumentando de uno en uno. Hasta que: (a) Este sea igual a i y
                                        // (b) Se haya determinado que el número (i) tiene un divisor tal que el residuo de su división es cero.
        if ((i%j)==0) {                 // B3. Si el residuo del cociente i/j es cero, es porque el número no es primo.
            primo=0;                    // B4. En dado caso se le cambia de valor a la variable primo.
        }
        j++;                            // B5. Si en cambio, el residuo del cociente i/j no es cero, se aumenta (j) en uno y se repite el ciclo.
    }
}
