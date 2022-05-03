/*
Autor:          Alessandro Lavagnino
Carnet:         201907400
Fecha:          05/01/22
Compilador:     gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Compilado:      gcc -o ProduccionAgricola.out ProduccionAgricola.c -lm && ./ProduccionAgricola.out
Librerias:      stdio, math
Resumen:        Este programa calcula la recta que mejor aproxima un conjunto de puntos, utilizando el método de mínimos cuadrados.
*/

#include <stdio.h>              //Librerias
#include <math.h>

// Declaramos e inicializamos los vectores cuyos datos usaremos en los cálculos.
float x[]={2013, 2014, 2015, 2016, 2017, 2018, 2019, 2020}, y[]={660.0,671.4,668.0,695.5,717.1,759.2,807.0,859.7};
// Medimos el tamaño del vector por medio del peso en bytes que ocupa cada elemento.
int n = sizeof(x)/sizeof(x[0]);

// Prototipamos funciones.
void imprimir(float anios[], float datos[]);
float suma(float datos[]);
float sumaMulti(float datos1[], float datos2[]);

int main() {
    // Declaramos variables.
    float b, m, r, year;
    // Imprimimos los valores de los vectores.
    imprimir(x,y);
    // Calculamos los valores de la recta que mejor se ajusta a los datos, y el coeficiente de correlación.
    m = (n*sumaMulti(x,y)-(suma(x)*suma(y)))/(n*sumaMulti(x,x)-(suma(x)*suma(x)));
    b = (suma(y)-m*suma(x))/n;
    r = (n*sumaMulti(x,y)-(suma(x)*suma(y)))/sqrt((n*sumaMulti(x,x)-(suma(x)*suma(x)))*(n*sumaMulti(y,y)-(suma(y)*suma(y))));
    // Imprimimos la ecuación de la recta.
    printf("y = %.3fx + %.3f\n",m,b);
    // Imprimimos el coeficiente de correlación
    printf("Coeficiente de correlación (r^2): %f\n\n",r*r);
    printf("Ingrese el año del cual quiere predecir el valor del cultivo: ");
    scanf("%f", &year);
    // Una vez se tiene el año al cual se quiere predecir, realizamos el cálculo y lo mostramos.
    printf("Para el año %.0f el valor del cultivo probablemente sea: Q%.1f mil.\n", year, year*m+b);
    return 0;
}

// Función que imprime una 'tabla' con los datos de los vectores de años y de valor de los cultivos.
void imprimir(float anios[], float datos[]){
    puts("Año\tValor total");
    for (int i = 0; i < n; i++)
        printf("%.0f\t%.1f\n", anios[i], datos[i]);
    printf("\n");
}

// Funcion que realiza la suma de los elementos de un vector ingresado.
float suma(float datos[]){
    float resp = 0;
    for (int i = 0; i < n; i++)
        resp += datos[i];
    return resp;
}

// Funcion que realiza la suma de los elementos de dos vectores ingresados.
float sumaMulti(float datos1[], float datos2[]){
    float resp = 0;
    for (int i = 0; i < n; i++)
        resp += datos1[i]*datos2[i];
    return resp;
}