#Gnuplot script for ploting the tent function

set terminal x11 size 700,500 enhanced persist

set xrange [1:2]
set grid

set title 'Tent Function'

plot 'tent.txt' u 1:3 w d notitle