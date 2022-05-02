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

Podemos usar una función que tome las condiciones
El método necesita que el usuario ingrese una primera aproximación
## Diagrama de flujo

