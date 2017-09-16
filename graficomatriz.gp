set terminal png enhanced


set output "graficomatriz.png"

f(x)=a*x**3+b*x**2+c*x+d
set xlabel "numero da matriz nxn"
set ylabel "numero de operações"
set title "Gráfico de operaçoes em relaçao ao numero da matriz"
set grid
set xrange [0:11]
set yrange [0:1000]
set  xtics 1
fit f(x) "dadosgraficomatriz.dat" via a,b,c,d
plot f(x) t "f(x) de 3 grau ajustada","dadosgraficomatriz.dat" pt 7 ps 1 lc 4 t "dados"



set output


