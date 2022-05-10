/*
Autor:          Alessandro Lavagnino González
Carnet:         201907400
Fecha:          2022/05/06
Compilador:     gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Compilado:      gcc -o Problema6.out Problema6.c -lm && ./Problema6.out
Librerias:      stdio, math
Resumen:        Este programa realiza la sumatoria 4 sumatorias distintas. Desde un k predefinido, hasta un número que el usuario ingrese. 
*/

// Librerias.
#include <math.h>
#include <stdio.h>

#define phi 1.618033            // (1+sqrt(5))/(2)
#define nphi -0.618033          // (1-sqrt(5))/(2)
#define raiz 0.447213           // 1/sqrt(5)

// Prototipamos funciones. 
float sumatoriaA(int n);
float sumatoriaB(int n);
float sumatoriaC(int n);
float sumatoriaD(int n);

int main() {
    // Declaramos variables.
    int n;
    // Se introduce al usuario a un bucle del cual solo podrá salir si ingresa n>=0.
    do {
        printf("Ingrese un número entero mayor o igual a cero: ");
        scanf("%d", &n);
    } while (n < 0);
    // Imprimimos los resultados de las funciones.
    printf("(a) La sumatoria desde k=1 hasta n=%d de k^2(k-3) es:\t\t\t%.2f\n", n, sumatoriaA(n));
    printf("(b) La sumatoria desde k=2 hasta n=%d de 3/(k-1) es:\t\t\t%.2f\n", n, sumatoriaB(n));
    printf("(c) La sumatoria desde k=1 hasta n=%d del tercer inciso es:\t\t%.2f\n", n, sumatoriaC(n));
    printf("(d) La sumatoria desde k=2 hasta n=%d de la sucesión de Bode es:\t\t%.2f\n", n, sumatoriaD(n));
return 0;
}

float sumatoriaA(int n){
    // Declaramos y definimos variables.
    int k;
    float res=0;
    // El conteo de la variable debe de llegar hasta n.
    for (k = 1; k <= n; k++)
        // Efectuamos el cálculo.
        res += pow(k,2)*(k-3);
    // Regresamos la respuesta.        
    return res;
}

// Los comentarios de la función anterior aplican para el resto de funciones.
float sumatoriaB(int n){
    int k;
    float res=0;
    for (k = 2; k <= n; k++)
        res += 3.0/(k-1);
    return res;
}

float sumatoriaC(int n){
    int k;
    float res=0;
    for (k = 1; k <= n; k++)
        res += raiz*pow(phi, k) - raiz*pow(nphi, k);
    return res;
}

float sumatoriaD(int n){
    int k;
    float res=0;
    for (k = 2; k <= n; k++)
        res += 0.1*(3*pow(2, k-2)+4);
    return res;
}