### Número de carnet: 201907400
# Problema 1: Producción agrícola

# Problema 2: Newton-Raphson
## Enunciado
Utilizando un método numérico, encuentre una raíz de la ecuación: `f(x) = exp(x) + x`   
Debe realizar la gráfica de la ecuación y comparar el resultado obtenido con el programa realizado en C.

## Metodología
El método de Newton-Raphson es un algoritmo que encuentra aproximaciones a la raíz de una función.
Parte de un valor inicial, el cual se usa para obtener una mejor estimación. Este resultado se usa en la siguiente iteración, y así sucesivamente.

Tres condiciones definen cuántas veces se ejecuta el algoritmo:
* El márgen de error en la respuesta que el usuario considera aceptable.
* El máximo número de iteraciones que el usuario quiera realizar.
* Que tan buena es la primera aproximación.

La ecuación que se usa para el algoritmo es:

<p align="center">
<img src="https://github.com/AlessLG/2022LabSimu201907400/blob/f1dc2f861c7fc702d9c0cd13ce1694f24a4e2f5f/Segundo_Parcial/Imagenes/Ecuaci%C3%B3n_NR3.png" alt="Ecuación_NR" width="260"/>
</p>

## Abstracción del problema
El programa se divide en cinco partes:
* <a href="#int-main">`int main()`</a>
* <a href="#float-newtonraphsonfloat-xant-float-e-int-n">`float NewtonRaphson(float xant, float e, int N)`</a>
* <a href="#float-ffloat-x">`float f(float x)`</a>
* <a href="#float-dffloat-x">`float df(float x)`</a>
* <a href="#float-absolutofloat-x">`float absoluto(float x)`</a>

### `int main()`
Primero se leen las variables que se usaran en la función `float NewtonRaphson()`. Se exigen ciertas condiciones para el valor de estas.    
Luego, se determina si el resultado que devolvió la función cumple las condiciones que se le impusieron. Si sí las cumple, se imprime y se muestra su margen de error. Si no, se muestra un mensaje de error.

**Variables de entrada**

    • aprox: Aproximación inicial. Tipo flotante.
    • toler: Márgen de error tolerable. Debe ser mayor a cero. Tipo flotante.
    • iter: Número máximo de iteraciones. Debe ser mayor a cero. Tipo entero.
**Variables de salida**

    • resultNR: Resultado de la n-ésima iteración de N-R. Tipo flotante.
    • absoluto(f(resultNR): Margen de error del resultado. Tipo flotante.
    • "mensaje de error con el número de iteraciones realizadas".

Podemos usar una función que tome las condiciones
El método necesita que el usuario ingrese una primera aproximación

### `float NewtonRaphson(float xant, float e, int N)`

**Variables de entrada**

    aprox: Aproximación inicial. Tipo flotante.
    toler: Márgen de error tolerable. Debe ser mayor a cero. Tipo flotante.
    iter: Número máximo de iteraciones. Debe ser mayor a cero. Tipo entero.
**Variables de salida**

    resultNR: Resultado de la n-ésima iteración de N-R. Tipo flotante.

### `float f(float x)`
**Variables de entrada**

    x
**Variables de salida**

    x

### `float df(float x)`
**Variables de entrada**

    x
**Variables de salida**

    x

### `float absoluto(float x)`
**Variables de entrada**

    x
**Variables de salida**

    x


## Diagrama de flujo

