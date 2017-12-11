all : main.o graphe.o automate.o
	gcc $^ -o tp3 -g -Wall

main.o : main.c 
	gcc -c main.c -o main.o -g -Wall

graphe.o : graphe.c graphe.h
	gcc -c graphe.c -o graphe.o -g -Wall

automate.o : automate.c automate.h
	gcc -c automate.c -o automate.o -g -Wall
	
clean : 
	rm -f *.o

mrproper : clean
	rm -f tp3
