FT_LINE1=7
FT_LINE2=15

cat /etc/passwd | grep -v '^#' | sed -n "$FT_LINE1,${FT_LINE2}p" | cut -d ':' -f1 | rev | sort -r | tr '\n' ', ' | sed 's/, $/./' | tr -d '\n'
