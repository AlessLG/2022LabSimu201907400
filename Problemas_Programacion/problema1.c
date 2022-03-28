/*
Autor:          aless
Fecha:          03/23/22
Compilador:     gcc (Ubuntu 9.4.0-1ubuntu1~20.04) 9.4.0
Compilado:      gcc -o problema1.out problema1.c && ./problema1.out
Librerias:      stdio
Resumen:        El programa lee tres números reales ingresados por el usuario y escribe la media aritmética únicamente de los números
                positivos.
*/

//Librerias
#include <stdio.h>

int main() {
    int n=0, i=0;                       // Se incian las variables enteras.
    float x=0, media=0;                 // Se incian las flotantes.
    while (i<3) {                       // Se incia el while que contará cuantos números se han ingresado.
        puts("Ingrese un número");      
        scanf("%f", &x);
        if (x>=0) {                     // Si el número que se ingreso es mayor o igual a cero:
            n++;                        // se aumenta el contador de cuántos números *positivos* se han ingresado...
            media+=x;                   // ...se "guarda" la sumatoria de los números positivos.
        }
        i++;                            // Independientemente de si se cumpla el if, se aumenta el contador de cuantos números se han ingresado.
    }
    if (n==0) {                         // Si el número de positivos es cero se imprime el siguiente mensaje.
        puts("No positivos");
    }
    else {                              // De lo contrario, se calcula la media.
        printf("La media es: %f \n", media/n);
    }
return 0;
}