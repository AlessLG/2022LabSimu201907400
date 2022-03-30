/*
Autor:          aless
Fecha:          03/29/22
Compilador:     gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Compilado:      gcc -o problema4.out problema4.c && ./problema4.out
Librerias:      stdio
Resumen:        Este programa lee un número mayor que 1 ingresado por el usuario y determina si es primo.
*/

//Librerias
#include <stdio.h>

int main() {
    int n, i=2, primo=1;                // 1. Inicializamos variables. En este código, el número (n) es primo hasta que se demuestre lo contrario.
    do {                                // 2. El usuario entra en un ciclo del cual solo puede salir si ingresa un número mayor a 1.
        puts("Ingrese el número a determinar si es primo o no (debe ser mayor a 1):");
        scanf("%d", &n);
    } while (n<=1);
    while( i<(n-1) && primo==1 ) {      // 3. En este ciclo, el valor de (i) irá aumentando de uno en uno. Hasta que: (a) Este sea igual a n-1 y
                                        // (b) Se haya determinado que el número (n) tiene un divisor tal que el residuo de su división es cero.
        if ((n%i)==0) {                 // 4. Si el residuo del cociente n/i es cero, es porque el número no es primo.
            primo=0;                    // 5. En dado caso se le cambia de valor a la variable primo.
        }
        i++;                            // 6. Si en cambio, el residuo del cociente n/i no es cero, se aumenta (i) en uno y se repite el ciclo.
    }
    if (primo==0) { puts("No es primo."); }     // 7. Si se cambió a 0 la variable (primo), se imprime este resultado.
    else { puts("Es primo."); }                 // 8. Si i=n-1, y no se cambió a 0 la variable (primo), se imprime este resultado.
return 0;
}