#! /bin/bash

: << 'Header'
Autor:              Alessandro Lavagnino
Carnet:             201907400
Tipo de archivo:    Script de bash
Ejecución:          ./ej2v3.sh
Resumen:            Este script crea headers de archivos de C, requiriendo poco esfuerzo por parte del usuario.
Header

read -p "Introduzca el nombre del archivo a crear: " nombre     # Se pide un nombre de archivo. La terminal lee el
                                                                # resultado y lo asigna a una variable.
if [ -z "$nombre" ]; then                                       # Si la variable está vacía, se finaliza el programa.
    exit 2
fi
    touch $nombre.c && chmod +x $nombre.c                       # En caso contrario, se crea un archivo con el nombre
                                                                # de la variable y se le dan permisos de ejecución.
    read -p "Ingrese el resumen del programa: " resumen         # Se pide el resumen del programa.
    read -p "Ingrese las entradas del programa: " entrada       # Se piden las entradas del programa.
    read -p "Ingrese las salidas del programa: " salida         # Se piden las salidas del programa.
    cat << EOF > $nombre.c
/*
Autor:          $USER
Compilador:     $(gcc --version | head -n 1)
Compilado:      gcc -o $nombre.out $nombre.c
Fecha:          $(date +%D)
Librerias:      stdio
Resumen:        $resumen
Entradas:       $entrada
Salidas:        $salida
*/

//Librerias
#include <stdio.h>
EOF
# Introducimos la información, los comandos necesarios y las variables al archivo: $nombre.c