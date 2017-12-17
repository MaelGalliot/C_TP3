CFLAGS = -g -Wall

all : main.o graphe.o automate.o langage.o fichier.o
	gcc $^ -o tp3 $(CFLAGS)

main.o : main.c 
	gcc -c main.c -o main.o $(CFLAGS)

graphe.o : graphe.c graphe.h
	gcc -c graphe.c -o graphe.o $(CFLAGS)

automate.o : automate.c automate.h
	gcc -c automate.c -o automate.o $(CFLAGS)

langage.o : langage.c langage.h
	gcc -c langage.c -o langage.o $(CFLAGS)
	
fichier.o : fichier.c fichier.h
	gcc -c fichier.c -o fichier.o $(CFLAGS)
	
clean : 
	rm -f *.o
