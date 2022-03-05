#! /bin/bash

: << 'Header'
Autor:              Alessandro Lavagnino
Carnet:             201907400
Tipo de archivo:    Script de bash
Ejecución:          ./ejercicio2.sh
Resumen:            Este script crea headers de archivos de C, requiriendo poco esfuerzo por parte del
                    usuario.
Header

echo Introduzca el nombre del archivo a crear       # Se da la instrucción de dar un nombre de archivo.
read nombre                                         # La terminal lee el resultado y lo asigna a la variable
                                                    # "nombre". Que crea en la misma línea.
if [ -n "$nombre" ]; then                           # En el condicional, detecta si a la variable se le asignó algún
                                                    # valor. Si sí, ejecuta los siguientes comandos.
    echo "/*" > $nombre.c                           # Inserta el inicio del comentario de párrafo en el archivo.
    echo -e "Autor: \t\t\t$USER" >> $nombre.c       # Inserta el nombre del usuario en la siguiente línea del archivo.
        gcc --version > temporalversionC            # Creamos un archivo temporal y le introducimos la información
                                                    # obtenida del comando gcc --version.
        version=$(head temporalversionC --lines=1)  # Creamos una variable que lee la primera línea del
                                                    # archivo temporal que creamos.
    echo -e "Compilador: \t$version" >> $nombre.c   # Inserta el valor de la variable recién creada en la
                                                    # siguiente línea del archivo.
        rm temporalversionC                         # Eliminamos el archivo temporal.
    echo -e "Compilado: \t\tgcc $nombre.c -o $nombre" >> $nombre.c      #Indicamos la forma de compilar el programa.
        date +%D > temporalfecha                    # Creamos un nuevo archivo temporal con la información del comando.
        fecha=$(cat temporalfecha)                  # Creamos otra variable que lee el nuevo archivo temporal.
    echo -e "Fecha: \t\t\t$fecha" >> $nombre.c      # Inserta el valor de la variable en el archivo
        rm temporalfecha                            # Eliminamos el nuevo archivo temporal.
    echo -e "Librerias:      stdio" >> $nombre.c    # Escribimos el nombre de las librerías que incluiremos.
    echo "Ingrese el resumen del programa"          # Se pide el resumen del programa.
        read resumen                                # Este se lee y se le asignan a una variable.
    echo "Ingrese las entradas del programa"        # Se piden las entradas del programa.
        read entrada                                # Estas se leen y se le asignan a una variable.
    echo "Ingrese las salidas del programa"         # Se piden las salidas del programa.
        read salida                                 # Estas se leen y se le asignan a una variable.
    echo -e "Resumen: \t\t$resumen" >> $nombre.c    # Se incluyen los valores de las variables en el archivo.
    echo -e "Entrada: \t\t$entrada" >> $nombre.c
    echo -e "Salida: \t\t$salida" >> $nombre.c
    echo -e "*/ \n\n//Librerias \n#include <stdio.h> \n//Numerar los pasos del pseudocódigo." >> $nombre.c
                                                    # Se introduce el resto de la información al archivo.
    chmod +x $nombre.c                              # Se le agrega el permiso de ejecución
elif [ -z "$nombre" ]; then                         # Si en cambio, se detecta que la variable nombre está vacía,
    exit                                            # se finaliza el programa.
fi