cat /etc/passwd | sed '/^[[:blank:]]*#/d'| sed -n 'p;n' | tr -d "_" | sed 's/\:\*\:.*//g'| sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | tr "\n" ", "
