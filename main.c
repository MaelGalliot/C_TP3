#include "graphe.h"
#include "automate.h"
#include "langage.h"

int main(void)
{
    FILE * fichier = NULL;
    fichier = fopen("graphe.txt", "r+"); // ouverture du fichier en mode lecture
    if(fichier !=NULL)
    {
        struct automate * pautomate = lire_automate(fichier);
        // Renvoie 1 si le mot est reconnu par l'automate
        // Renvoie 0 si le mot n'est pas reconnu par l'automate
        accepte(pautomate, "baaaaaaaabbabb");

        int rep;
        printf("Voulez-vous modifiez l'automate (1 = yes) :");
        scanf("%d",&rep);
        if(rep)
           pautomate=ecrire_automate(fichier,pautomate);

        fclose(fichier);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier");
    }

	return 0;
}
