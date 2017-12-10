all : main.o graphe.o
	gcc $^ -o tp3 -g -Wall

main.o : main.c 
	gcc -c $<.c -o $<.o -g -Wall

fonction.o : graphe.c graphe.h
	gcc -c $<.c -o $<.o -g -Wall
	
clean : 
	rm -f *.o

mrproper : clean
	rm -f tp3
