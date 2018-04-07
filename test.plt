#set terminal png size 400,300 enhanced font "Helvetica,20"
#set output 'output.png'
#set terminal svg size 350,262 enhanced font 'Verdana,12'
#set terminal svg size 700,500
set terminal svg
set output 'output.svg'

set title "The Title"
set xlabel "X-Label"
set ylabel "Y-Label"
set xrange [0:5]
set yrange [0:3]
plot "-" with linespoints title "The Line", "-" with linespoints title "The Line 2"
#  X     Y1 
1.0   1.2   
2.0   1.8   
3.0   1.6   
4.0   1.2   
end
#  X  Y2
1.0   0.2
2.0   0.3
3.0   0.2
4.0   0.2
end