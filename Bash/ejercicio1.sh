#! /bin/bash

: << 'Header'
Autor:              Alessandro Lavagnino
Carnet:             201907400
Tipo de archivo:    Script de bash
Ejecución:          ./ejercicio1.sh
Resumen:            Este script obtiene datos del clima desde internet y muestra las primeras 7 líneas
                    de la información obtenida.
Header

curl -s wttr.in/Guatemala > temporal    # Introducimos la información obtenida del comando curl dentro del 
                                        # archivo temporal. El cual al mismo tiempo creamos. La bandera -s
                                        # elimina la información de la conexión de red que el comando curl
                                        # automáticamente proporciona, para hacer el resultado final más
                                        # limpio.
head temporal --lines=7                 # Imprimimos las primeras siete líneas del archivo temporal.
rm temporal                             # Eliminamos el archivo temporal.








#######  IGNORAR----HISTORIAL DE CÓDIGO  ########

#echo -e ${clima:0:100} '\n''\n'${clima:24:28}

#/.temporal.sh

#echo -e $clima >> temporal
#echo -e {temporal:0:5}

#echo ${clima:0:26} #Imprimimos en la terminal la información de la variable que recién creamos.
#echo ""
#echo ${clima:27:100}