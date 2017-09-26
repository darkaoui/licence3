set terminal png size 1024,768
set termoption enhanced
set encoding utf8

# Pour changer le titre
set title "Mon super graphique"

set style data lines

# Les legendes des axes
set xlabel "Taille Buffer"
set ylabel "Temps CPU"

set xrange [0:40]

# Pour changer le nom du fichier produit
set output 'graphique.png'

# La commande pour tracer. Le \ est obligatoire avant un passage à la ligne
plot 'tp7.txt' u 1:2 title "fwrite() 1" lw 2 linecolor rgb "red", \
     '' u 1:3 title "fputc() 2" lw 2 linecolor rgb "blue"
