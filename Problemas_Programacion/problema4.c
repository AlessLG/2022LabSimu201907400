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
    int n, i, primo;
    do
    {
        puts("Ingrese el número a determinar si es primo o no (debe ser mayor a 1):");
        scanf("%d", &n);
    } while (n<=1);
    i=2;
    primo=1;
    while( i<(n-1) && primo==1 ) {
        if ((n%=i)==0) {
            primo=0;
        }
        i++;
    }
    if (primo==0) { puts("No es primo."); }
    else { puts("Es primo."); }
return 0;
}