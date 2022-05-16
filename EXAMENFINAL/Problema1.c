/*
Autor:          Alessandro Lavagnino González
Carnet:         201907400
Fecha:          2022/05/16
Compilador:     gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
Compilado:      gcc -o Problema1.out Problema1.c -lm && ./Problema1.out
Librerias:      stdio, math
Resumen:        Este programa simula el movimiento de un cohete.
*/

// Librerías.
#include <stdio.h>
#include <math.h>

// Definición de constantes. Notar que todas son de tipo flotante.
#define G 0.00000000006693
#define RT 6378000.0
#define MT 5973600000000000000000000.0
#define R 287.06
#define L 0.0065
#define g0 9.81
#define T0 288.15
#define P0 101325.0

// Prototipado de funciones.
float dmasaf(float a[]); // Derivada de la masa del combustible.
float masac(float a[], float t);
float gravedad(float y);
//float Fa(float y, float a[]);
float rho(float y);
float absoluto(float x);

int main() {
    // Usamos vectores para guardar la información de los cohetes.
    float Mun[]={30000000.0, 0.0003248, 61.27, 201.06, 110000.0, 1500000.0};
    float Kin[]={27000000.0, 0.0002248, 61.27, 201.06, 110000.0, 1500000.0};
    float Chac[]={25000000.0, 0.0002248, 70.25, 215.06, 180000.0, 2100000.0};
    float y=0.01, t=0, h=0.1; // altura, tiempo, paso de integración.
    float aceleracion, masaf, masac, velocidad; // fuerza vertical del cohete, masa del combustible, masa del cohete.

    masaf=Mun[5];
    while (masaf >= (Mun[0]*Mun[1]) ) { // Mientras la masa del combustible sea mayor a la cantidad de combustible que el cohete gasta en un segundo, ejecutamos el bucle.
        masaf += dmasaf(Mun); // Ejecutamos el método numérico para la masa del combustible.
        masac = masaf + Mun[4]; // La masa del cohete es igual a la masa del combustible más la masa del propulsor.
        velocidad += velocidad + a
        //y += velocidad()
        //aceleracion += daceleracion()
        t += h; // Sumamos el paso de integración al tiempo.
        printf("Masa del combustible: %.2f, tiempo: %f\n", masaf, t);
        // printf("\n La altura en %f segundos es de: %f \n", t, y);
        // m += dm/dt
        // dy/dt += d2y/dt2*delta t
        // y += dy/dt* delta

    }
    

    return 0;
}

/*float mda(float y, float t, float a[]) {
    float res;
    res = a[0] - Fa(y);
}*/

// Derivada de la masa del combustible respecto del tiempo
float dmasaf(float a[]) {
    float res;
    res = - a[0] * a[1];
    return res;
}

float gravedad(float y) {
    float res, a;
    a = RT + y;
    a = pow(a, 2);
    res = (G*MT)/a;
    return res;
}

/*float Fa(float y, float a[]) {
    float res;
    res = 0.5*rho(y)*a[2]*a[3]*velocidad(y)*absoluto(velocidad(y));
    return res;
}*/

float rho(float y) {
    float res, a, b;
    a = (1 - L*y/T0);
    b = g0/(R*L);
    a = pow(a, b);
    res = (P0/(R*T0))*a;
    return res;
}

float absoluto(float x){
    if (x<0)
        x = -x;
    return x;
}