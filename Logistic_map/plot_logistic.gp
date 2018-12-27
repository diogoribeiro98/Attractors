#Gnuplot script for ploting the logistic function

set terminal x11 size 700,500 enhanced persist

set xrange [-2:4]
set grid

set title 'Logistic Function'

plot 'logistic.txt' u 1:3 w d notitle