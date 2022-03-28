/*
Autor:          aless
Fecha:          03/18/22
Compilador:     gcc (Ubuntu 9.4.0-1ubuntu1~20.04) 9.4.0
Compilado:      gcc -o problema2.out problema2.c && ./problema2.out
Librerias:      stdio
Resumen:        El programa lee un número indeterminado de alturas y termina hasta que se ingrese una negativa.
                Luego calcula la media, máxima y mínima de las ingresadas.
*/

//Librerias
#include <stdio.h>

int main() {
    int n=0;                                    // Inicializamos variables
    float x=0, med=0, max=0, min=0;
    puts("Ingrese una altura");
    scanf("%f", &x);                            // Leemos lo escrito y lo asignamos a la variable x. La cual servirá para almacenar las alturas.
    max=x;                                      // Asignamos el valor de x a las variables max y min.
    min=x;
        while (x>=0) {                          // Si la altura ingresada es mayor o igual a cero, entramos al siguiente ciclo
            n++;                                // Se suma "1" al contador de números positivos ingresados.
            med+=x;                             // Se suma el valor de la variable x a la variable med
            if (x>max) {                        // 
                max=x;
            }
            if (x<min) {
                min=x;
            }
            puts("Ingrese otra altura");
            scanf("%f", &x);
        }
        if (n==0) {
            puts("No positivos");
        }
        else {
            printf("La media es: %.2f \n", med/n);
            printf("El valor máximo es: %.2f \n", max);
            printf("El valor mínimo es: %.2f \n", min);
        }
return 0;
}

