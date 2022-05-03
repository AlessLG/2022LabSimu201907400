unset label
clear
# Formato de la imagen
set terminal jpeg
set output "Grafica_aumentada_exp(x)+x.jpg"
# Títulos
set title "exp(x)+x"
# Ejes y rangos
set xlabel "Eje x"
set ylabel "Eje y"
set xrange [-1:1]
set yrange [-1:1]
# Estilo
set grid
set style data linespoints
set key at 4.1,-4
# Gráfica
plot exp(x)+x linewidth 2