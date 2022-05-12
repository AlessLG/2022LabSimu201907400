/*
Autor:          Alessandro Lavagnino González
Carnet:         201907400
Fecha:          2022/05/06
Compilador:     gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Compilado:      gcc -o Problema4.out Problema4.c -lm && ./Problema4.out
Librerias:      stdio
Resumen:        Este programa lee dos matrices y una constante y realiza una serie de cálculos con ellas.
*/

// Librerías.
#include <stdio.h>
#include <math.h>

void impresion(float a[3][3]);
void matxConst(float a[3][3], float c);
void suma(float a[3][3], float b[3][3]);
void resta(float a[3][3], float b[3][3]);
void multi(float a[3][3], float b[3][3]);
float det(float a[3][3]);
void transpuesta(float a[3][3]);
//float inversa(float a[3][3]);

int main() {
    float matA[3][3], matB[3][3], c;
    int fila;
    puts("--------------------INSTRUCCIONES--------------------");
    puts("Separe las entradas de la matriz por un espacio o un\nenter. Una vez haya ingresado 3 entradas, presione\nenter y repita.");
    puts("-----------------------------------------------------");
    puts("Ingrese las coordenadas de la primera matriz.");
    for (fila = 0; fila < 3; fila++) {
        scanf("%f %f %f", &matA[fila][0], &matA[fila][1], &matA[fila][2]);
    }
    puts("Ingrese las coordenadas de la segunda matriz.");
    for (fila = 0; fila < 3; fila++) {
        scanf("%f %f %f", &matB[fila][0], &matB[fila][1], &matB[fila][2]);
    }
    printf("Ingrese una constante: ");
    scanf("%f", &c);
    puts("-----------------------------------------------------");
    puts("Las matrices ingresadas son:\n");
    impresion(matA);
    impresion(matB);
    puts("-----------------------------------------------------");
    puts("(a) Primera matriz por constante.\n");
    matxConst(matA, c);
    puts("(b) Suma de las dos matrices.\n");
    suma(matA, matB);
    puts("(c) Resta de las dos matrices.\n");
    resta(matA, matB);
    puts("(d) Multiplicación de la primera matriz por la segunda.\n");
    multi(matA, matB);
    puts("(e) Determinante de la primera matriz.\n");
    printf("R/. %f\n\n", det(matA));
    puts("(f) Transpuesta de la segunda matriz.\n");
    transpuesta(matB);
    /*puts("(g)");
    inversa(matA);
    puts("(h)");
    puts("(i)");*/
    puts("-----------------------------------------------------");
return 0;
}

void impresion(float a[3][3]) {
    int fila;
    for (fila = 0; fila < 3; fila++) {
        printf("| %f\t%f\t%f |\n", a[fila][0], a[fila][1], a[fila][2]);
    }
    puts("");
}

void matxConst(float a[3][3], float c) {
    int fila, col;
    float res[3][3];
    for (fila = 0; fila < 3; fila++) {
        for (col = 0; col < 3; col++) {
            res[fila][col] = c*a[fila][col];
        }
    }
    impresion(res);
}

void suma(float a[3][3], float b[3][3]) {
    int fila, col;
    float res[3][3];
    for (fila = 0; fila < 3; fila++) {
        for (col = 0; col < 3; col++) {
            res[fila][col] = a[fila][col] + b[fila][col];
        }
    }
    impresion(res);
}

void resta(float a[3][3], float b[3][3]) {
    int fila, col;
    float res[3][3];
    for (fila = 0; fila < 3; fila++) {
        for (col = 0; col < 3; col++) {
            res[fila][col] = a[fila][col] - b[fila][col];
        }
    }
    impresion(res);
}

void multi(float a[3][3], float b[3][3]) {
    float res[3][3], resp;
    int i, j, k;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                resp += a[i][k]*b[k][j];
            }
            res[i][j] = resp;
            resp = 0;
        }
    }
    impresion(res);
}

float det(float a[3][3]) {
    float res;
    res = a[0][0]*a[1][1]*a[2][2] + a[0][1]*a[1][2]*a[2][0] + a[0][2]*a[1][0]*a[2][1];
    res += - a[2][0]*a[1][1]*a[0][2] - a[2][1]*a[1][2]*a[0][0] - a[2][2]*a[1][0]*a[0][1];
    return res;
}

void transpuesta(float a[3][3]) {
    float res[3][3];
    int fila, col;
    for (fila = 0; fila < 3; fila++) {
        for (col = 0; col < 3; col++) {
            res[fila][col] = a[col][fila];
        }
    }
    impresion(res);
}

/*float inversa(float a[3][3]) {
    if (det(a) == 0.000000) {
        printf("La matriz no tiene inversa, porque su determinante es cero.");
        return 1;
    }

}*/