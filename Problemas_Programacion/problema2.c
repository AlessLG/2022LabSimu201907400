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
    int n=0;                                    // 1. Inicializamos variables
    float x=0, med=0, max=0, min=0;
    puts("Ingrese una altura");                 // 2. Le pedimos al usuario que ingrese una altura...
    scanf("%f", &x);                            //    ...y se la asignamos a la variable x.
    max=x;                                      // 3. Asignamos x como valor de las variables max y min. Para luego tener algo con qué compararlas.
    min=x;
        while (x>=0) {                          // 4. Entramos al siguiente ciclo si la altura ingresada es mayor o igual a cero.
            n++;                                // 5. Acumulamos los datos de conteo y media para su uso al final.
            med+=x;
            if (x>max) {                        // 6. Comparamos si el valor ingresado es mayor al máximo. Si sí, será el nuevo max.
                max=x;
            }
            if (x<min) {                        // 7. Comparamos si el valor ingresado es menor al mínimo. Si sí, será el nuevo min.
                min=x;
            }
            puts("Ingrese otra altura");        // 8. Se pide otra altura para que se puedan hacer nuevamente las comparaciones en este bucle.
            scanf("%f", &x);
        }
        if (n==0) {                             // 9. Al ingresar una altura negativa, validamos que se haya ingresado al menos una mayor o igual a cero.
            puts("No positivos");
        }
        else {                                  // 10. Si sí se ingresó al menos una mayor o igual a cero, se imprimen los resultados.
            printf("La media es: %.2f \n", med/n);
            printf("El valor máximo es: %.2f \n", max);
            printf("El valor mínimo es: %.2f \n", min);
        }
return 0;
}

