#! /bin/bash

: << 'Header'
Autor:              Alessandro Lavagnino
Carnet:             201907400
Fecha:              01/03/2022
Tipo de archivo:    Script de bash
Ejecución:          ./clima2.sh
Resumen:            Obtenemos la información del clima e imprimimos las primeras 7 líneas de esta directamente a la terminal. Saltandonos la creación
                    del archivo temporal.
Header

curl -s wttr.in/Guatemala |  head -n 7