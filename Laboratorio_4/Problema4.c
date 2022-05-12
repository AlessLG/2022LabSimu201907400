/*
Autor:          Alessandro Lavagnino González
Carnet:         201907400
Fecha:          2022/05/06
Compilador:     gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Compilado:      gcc -o Problema4.out Problema4.c -lm && ./Problema4.out
Librerias:      stdio, math
Resumen:        Este programa lee dos matrices y una constante y realiza una serie de cálculos con ellas.
*/

// Librerías.
#include <stdio.h>
#include <math.h>

// Se prototipan funciones.
void impresion(float a[3][3]);                  // Imprime las matriz que se le ingresa.
void matxConst(float a[3][3], float c);         // Multiplica la matriz por una constante.
void suma(float a[3][3], float b[3][3]);        // Suma dos matrices.
void resta(float a[3][3], float b[3][3]);       // Resta dos matrices.
void multi(float a[3][3], float b[3][3]);       // Multiplica dos matrices.
float det(float a[3][3]);                       // Calcula el determinante de la matriz que se le ingresa.
void transpuesta(float a[3][3]);                // Obtiene la transpuesta de la matriz que se le ingresa.

int main() {
    // Se declaran dos matrices de 3x3. Y una constante.
    float matA[3][3], matB[3][3], c;
    // Se declara una variable de conteo.
    int fila;
    // Se muestran las instrucciones para ingresar las entradas a las matrices.
    puts("--------------------INSTRUCCIONES--------------------");
    puts("Separe las entradas de la matriz por un espacio o un\nenter. Una vez haya ingresado 3 entradas, presione\nenter y repita.");
    puts("-----------------------------------------------------");
    puts("Ingrese las coordenadas de la primera matriz.");
    // Se leen las entradas de la primera matriz.
    for (fila = 0; fila < 3; fila++) {
        scanf("%f %f %f", &matA[fila][0], &matA[fila][1], &matA[fila][2]);
    }
    puts("Ingrese las coordenadas de la segunda matriz.");
    // Se leen las entradas de la segunda matriz.
    for (fila = 0; fila < 3; fila++) {
        scanf("%f %f %f", &matB[fila][0], &matB[fila][1], &matB[fila][2]);
    }
    // Se lee una constante.
    printf("Ingrese una constante: ");
    scanf("%f", &c);
    // Se le muestran al usuario las matrices que ingresó.
    puts("-----------------------------------------------------");
    puts("Las matrices ingresadas son:\n");
    impresion(matA);
    impresion(matB);
    puts("-----------------------------------------------------");
    // Se identifican los incisos del problema y se llaman a las funciones que realizan los cálculos. A estas, se les indica que parámetros tomar.
    puts("(a) Primera matriz por constante.\n");
    matxConst(matA, c);
    puts("(b) Suma de las dos matrices.\n");
    suma(matA, matB);
    puts("(c) Resta de las dos matrices.\n");
    resta(matA, matB);
    puts("(d) Multiplicación de la primera matriz por la segunda.\n");
    multi(matA, matB);
    puts("(e) Determinante de la primera matriz.\n");
    // Esta función devuelve un valor flotante.
    printf("R/. %f\n\n", det(matA));
    puts("(f) Transpuesta de la segunda matriz.\n");
    transpuesta(matB);
    puts("-----------------------------------------------------");
return 0;
}

void impresion(float a[3][3]) {
    // Se declara una variable de conteo.
    int fila;
    // Se imprimen las matrices fila por fila.
    for (fila = 0; fila < 3; fila++) {
        printf("| %f\t%f\t%f |\n", a[fila][0], a[fila][1], a[fila][2]);
    }
    puts("");
}

void matxConst(float a[3][3], float c) {
    // Se declaran dos variables de conteo.
    int fila, col;
    // Se declara una matriz de 3x3 que almacenara el resultado.
    float res[3][3];
    // Usando las variables de conteo, nos desplazamos por las matrices para almacenar el resultado del cálculo.
    for (fila = 0; fila < 3; fila++) {
        for (col = 0; col < 3; col++) {
            res[fila][col] = c*a[fila][col];
        }
    }
    // Se llama a la función impresión para mostrar la matriz que contiene el resultado.
    impresion(res);
}

void suma(float a[3][3], float b[3][3]) {
    // Se declaran dos variables de conteo.
    int fila, col;
    // Se declara una matriz de 3x3 que almacenara el resultado.
    float res[3][3];
    // Usando las variables de conteo, nos desplazamos por las matrices para almacenar el resultado del cálculo.
    for (fila = 0; fila < 3; fila++) {
        for (col = 0; col < 3; col++) {
            res[fila][col] = a[fila][col] + b[fila][col];
        }
    }
    // Se llama a la función impresión para mostrar la matriz que contiene el resultado.
    impresion(res);
}

void resta(float a[3][3], float b[3][3]) {
    // Se declaran dos variables de conteo.
    int fila, col;
    // Se declara una matriz de 3x3 que almacenara el resultado.
    float res[3][3];
    // Usando las variables de conteo, nos desplazamos por las matrices para almacenar el resultado del cálculo.
    for (fila = 0; fila < 3; fila++) {
        for (col = 0; col < 3; col++) {
            res[fila][col] = a[fila][col] - b[fila][col];
        }
    }
    // Se llama a la función impresión para mostrar la matriz que contiene el resultado.
    impresion(res);
}

void multi(float a[3][3], float b[3][3]) {
    // Se declaran tres variables de conteo.
    int i, j, k;
    // Se declara una matriz de 3x3 que almacenara el resultado. Y una variable que almacenara el resultado de cada multiplicación.
    float res[3][3], resp;
    // Usando las variables de conteo, nos desplazamos por las matrices para almacenar el resultado del cálculo.
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                // Se iguala a la variable al resultado de la operación.
                resp += a[i][k]*b[k][j];
            }
            // Se iguala la entrada i, j de la matriz res a la respuesta de la operación anterior.
            res[i][j] = resp;
            resp = 0;
        }
    }
    // Se llama a la función impresión para mostrar la matriz que contiene el resultado.
    impresion(res);
}

float det(float a[3][3]) {
    // Se declara una variable que almacenara el resultado.
    float res;
    res = a[0][0]*a[1][1]*a[2][2] + a[0][1]*a[1][2]*a[2][0] + a[0][2]*a[1][0]*a[2][1];
    res += - a[2][0]*a[1][1]*a[0][2] - a[2][1]*a[1][2]*a[0][0] - a[2][2]*a[1][0]*a[0][1];
    // Se envía al main la respuesta.
    return res;
}

void transpuesta(float a[3][3]) {
    // Se declara una matriz de 3x3 que almacenara el resultado.
    float res[3][3];
    // Se declaran variables de conteo.
    int fila, col;
    // Usando las variables de conteo, nos desplazamos por las matrices para almacenar el resultado del cálculo.
    for (fila = 0; fila < 3; fila++) {
        for (col = 0; col < 3; col++) {
            res[fila][col] = a[col][fila];
        }
    }
    // Se llama a la función impresión para mostrar la matriz que contiene el resultado.
    impresion(res);
}