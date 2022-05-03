unset label
clear
# Formato de la imagen
set terminal jpeg
set output "Valor_Cardamomo2.jpg"
# Títulos
set title "Valor del cultivo del cardamomo en el período 2013-2020"
# Ejes y rangos
set xlabel "Año"
set ylabel "Valor del cultivo"
set xrange [2013:2020]
set yrange [600:900]
# Estilo
set grid
set style data linespoints
set key at 2016.5,875
# Gráfica
plot "DatosP1" using 1:2 title 'Precio cardamomo', 28.214*x + -56164.367 title 'Regresión lineal'