examen:examen.o code.o  teZZt.o
	gcc -o examen examen.o code.o teZZt.o -lm 
	@echo "Lancer le programme avec  ./examen" 
teZZt.o:teZZt.h teZZt.c
	gcc -c teZZt.c -g -Wall -Wextra
examen.o:examen.c code.h 
	gcc -c examen.c -g -Wall -Wextra
code.o:code.h code.c
	gcc -c code.c -g -Wall -Wextra 
clean:
	rm -rf examen code.o examen.o
