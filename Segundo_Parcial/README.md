### Número de carnet: 201907400
# Problema 1: Producción agrícola
## Enunciado
Guatemala es un alto productor de cardamomo, por lo que se ha documentado de forma anual el valor del cultivo en miles de quetzales.    
*(ver tabla)*

Genere un programa el cual cumpla con las siguientes condiciones:
* Una gráfica que compare los valores tabulados y la recta que mejor aproxima el crecimiento en las ganancias.
* Estime la ganancia que se obtendrá en el presente año. Compárelo con la estimación del gobierno el cual es de Q920,100, explique la diferencia.

<table><thead><tr><th>Año</th><th>Valor total</th></tr></thead><tbody><tr><td>2013</td><td>660.0</td></tr><tr><td>2014</td><td>671.4</td></tr><tr><td>2015</td><td>668.0</td></tr><tr><td>2016</td><td>695.5</td></tr><tr><td>2017</td><td>717.1</td></tr><tr><td>2018</td><td>759.2</td></tr><tr><td>2019</td><td>807.0</td></tr><tr><td>2020</td><td>859.7</td></tr></tbody></table>



## Metodología
El método de mínimos cuadrados intenta encontrar una función continua que mejor aproxime a un grupo de datos. De acuerdo al criterio del mínimo error cuadrático.   
Si el conjunto de datos aproxima una línea recta, la ecuación: `y=mx+b` es la que mejor lo aproximaría.     
Además, tenemos el coeficiente de correlación `r`.
Donde estos están dados por las fórmulas:
<p align="center">
<img src="https://github.com/AlessLG/2022LabSimu201907400/blob/323f20200ba2e2253ee994be18bc03617c58dbab/Segundo_Parcial/Imagenes/Ecuaciones_minimos_cuadrados.png" alt="Fórmulas mínimos cuadrados" width="800"/>
</p>



## Abstracción del problema
Con una tabla de datos de 2 columnas (como con la que contamos), podemos interpretar los valores de cada fila como pares ordenados. Los cuales podemos colocar en un plano cartesiano. Luego, podemos usar el método de mínimos cuadrados para encontrar la ecuación de la recta que mejor se ajuste, y poder predecir la tendencia de los datos de nuestra gráfica.

El programa se divide en cuatro partes:
* <a href="#int-main-problema-1">`int main()` Problema 1</a>
* <a href="#void-imprimir">`void imprimir()`</a>
* <a href="#float-suma">`float suma()`</a>
* <a href="#float-sumamulti">`float sumaMulti()`</a>

### `int main()` Problema 1
Dados los valores almacenados en los vectores descritos en el código. Se calcula `b`, `m` y `r`.    
Se pide al usuario además, un año al que quiera estimar el valor de los cultivos.

---
<details>
<summary> <b> Variables </b> </summary>
</br>
Variables de entrada:

    • float x[]: Vector con los años. Tipo flotante.
    • float y[]: Vector con el valor de los cultivos en miles de quetzales. Tipo flotante.
    • year: Año del cual se quiere sacar la estimación del valor del cultivo. Tipo flotante.
    
Variables de salida:

    • b: Altura en la cual la recta intersecta el eje "y". Tipo flotante.
    • m: Pendiente de la recta. Tipo flotante.
    • r: Coeficiente de correlación. Tipo flotante.
    
Variables globales:
    
    • n: Longitud del vector de los años. Tipo flotante.

</details>

---

### `void imprimir()`
Esta función imprime de forma similar a una tabla, el contenido de los vectores que se usan en los cálculos.

---
<details>
<summary> <b> Variables </b> </summary>
</br>
Variables de entrada:

    • float[anios]: El vector con los años.
    • float[datos]: El vector con los precios.
</details>

---

### `float suma()`
Esta función realiza la suma de todas las entradas del vector que se le ingrese.

---
<details>
<summary> <b> Variables </b> </summary>
</br>
Variables de entrada:

    • datos[]: Cualquier vector que se le indique.
    • n: La longitud del vector que se ingresa.
    
Variables de salida:

    • resp: Contiene el resultado.
    
 Variables locales:

    • i: Variable de conteo.
</details>

---

### `float sumaMulti()`
Esta función realiza la multiplicación de las entradas de dos vectores que se le ingresan.

---
<details>
<summary> <b> Variables </b> </summary>
</br>
Variables de entrada:

    • datos1[]: Cualquier vector que se le indique.
    • datos1[]: Cualquier vector que se le indique
    • n: La longitud de los vectores que se le ingresan.
    
Variables de salida:

    • resp: Contiene el resultado.
    
 Variables locales:

    • i: Variable de conteo.
</details>

---

## Diagrama de flujo
<p align="center">
<img src="https://github.com/AlessLG/2022LabSimu201907400/blob/907083dc0d42ea516609271bf7494ec40f3df5e0/Segundo_Parcial/Imagenes/Diagrama_de_flujoP1.png" alt="Valor cardamomo" width="1000"/>
</p>

## Respuestas

    Siguiendo la recta del ajuste lineal, se uso el programa en C para determinar que en el año 2022 el precio de los cultivos      
    debería de rondar los Q884.9 mil. Una diferencia de Q35.2 mil. No es exagerada, pero puede deberse a que los precios de
    los cultivos han subido consistentemente desde el 2017. Hecho al cual la recta no se ajusta, precisamente porque esa    
    subida es bastante reciente.
    
<p align="center">
<img src="https://github.com/AlessLG/2022LabSimu201907400/blob/45fdf87d7d4df3e7e36b63a49c97c07b99cf09e1/Segundo_Parcial/Imagenes/Valor_Cardamomo.jpg" alt="Valor cardamomo" width="500"/>
</p>


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
* <a href="#int-main-problema-2">`int main()`</a>
* <a href="#float-newtonraphsonfloat-xant-float-e-int-n">`float NewtonRaphson(float xant, float e, int N)`</a>
* <a href="#float-ffloat-x">`float f(float x)`</a>
* <a href="#float-dffloat-x">`float df(float x)`</a>
* <a href="#float-absolutofloat-x">`float absoluto(float x)`</a>

### `int main()` Problema 2
Primero se leen las variables que se usaran en la función `float NewtonRaphson()`. Se exigen ciertas condiciones para el valor de estas.    
Luego, se determina si el resultado que devolvió la función cumple las condiciones que se le impusieron. Si sí las cumple, se imprime y se muestra su margen de error. Si no, se muestra un mensaje de error.

---
<details>
<summary> <b> Variables </b> </summary>
</br>
Variables de entrada:

    • aprox: Aproximación inicial. Tipo flotante.
    • toler: Márgen de error tolerable. Debe ser mayor a cero. Tipo flotante.
    • iter: Número máximo de iteraciones. Debe ser mayor a cero. Tipo entero.
    
Variables de salida:

    • resultNR: Resultado de la n-ésima iteración de N-R. Tipo flotante.
    • absoluto(f(resultNR): Margen de error del resultado. Tipo flotante. Utiliza dos funciones.
    • "mensaje de error con el número de iteraciones realizadas".
</details>

---

### `float NewtonRaphson(float xant, float e, int N)`
Esta funcion ejecuta la ecuación de Newton-Raphson hasta que:

* Se hayan cumplido las `N` iteraciones. 
* El resultado de una iteración esté dentro del margen de error `e`.

También se encarga de imprimir la tabla que se muestra en la terminal.

---
<details>
<summary> <b> Variables </b> </summary>
</br>
    
Variables de entrada:
    
    Esta función recibe las variables de int main(). Hace la correspondencia:
    • aprox > xant
    • toler > e
    • iter > N
    • x: Variable local que almacena el resultado de cada iteración. Tipo flotante
    • i: Variable de conteo. Tipo entero.

Variables de salida:

    • x: Regresa la misma variable que usa para hacer los cálculos, una vez terminan.

</details>

---

### `float f(float x)`
Valua el valor ingresado `x` en la función `exp(x)+x` y lo devuelve en la misma variable.

### `float df(float x)`
Valua el valor ingresado `x` en la función `exp(x)+1` y lo devuelve en la misma variable.

### `float absoluto(float x)`
Comprueba si el valor ingresado `x` es menor a cero.    
Si es mayor a cero, lo regresa sin cambios. Si es menor a cero, lo cambia a positivo y lo regresa en la misma variable.


## Diagrama de flujo
<p align="center">
<img src="https://github.com/AlessLG/2022LabSimu201907400/blob/bcbf89d5f462805efdc082ba190fd175889bf0c8/Segundo_Parcial/Imagenes/Diagrama_de_flujoP2.png" alt="Diagramas de Flujo Problema 2" width="1000"/>
</p>

## Respuestas
    x = -0.567143 cuando f(x)=0

**Gráfica generada por gnuplot:**
<p align="center">
<img src="https://github.com/AlessLG/2022LabSimu201907400/blob/0a7a132c9bb607edaa9ebca2ace8341b2ef77e36/Segundo_Parcial/Imagenes/Grafica_exp(x)+x.jpg" alt="Gráfica generada por gnuplot" width="500"/>
</p>

**Gráfica aumentada generada por gnuplot:**
<p align="center">
<img src="https://github.com/AlessLG/2022LabSimu201907400/blob/0a7a132c9bb607edaa9ebca2ace8341b2ef77e36/Segundo_Parcial/Imagenes/Grafica_aumentada_exp(x)+x.jpg" alt="Gráfica aumentada generada por gnuplot" width="500"/>
</p>
