/*
Autor:          Alessandro Lavagnino González
Carnet:         201907400
Fecha:          2022/05/06
Compilador:     gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Compilado:      gcc -o Problema5.out Problema5.c && ./Problema5.out
Librerias:      stdio
Resumen:        Este programa encuentra el factorial de un número ingresado.
*/

// Librerías.
#include <stdio.h>

// Prototipamos la función factorial.
int factorial(int n);

int main() {
    // Declaramos variables.
    int n;
    // Se introduce al usuario a un bucle del cual solo podrá salir si ingresa n>=0.
    do {
        printf("Ingrese un número entero mayor o igual a cero: ");
        scanf("%d", &n);
    } while (n < 0);              
    // Se imprime el resultado, llamando a la función.
    printf("El factorial de %d es: %d\n", n, factorial(n));
    return 0;
}

int factorial(int n){
    // Valuamos si n es mayor a 1.
    if (n > 1)
        // Si lo es, realizamos el cálculo que representa a la ecuación: n! = n(n-1)!
        n = n*factorial(n-1);
    // Cuando n = 1, devolvemos el resultado.
    else
        return n;
}
