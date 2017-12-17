#include "graphe.h"
#include "automate.h"
#include "langage.h"
#include "fichier.h"

int main(void)
{
    int taille = 15;
    char * nomfichier = calloc(taille,sizeof(char));
    FILE * fichier = NULL;
    printf("Fichier a lire : ");
    lecture(nomfichier,taille);
    printf("Lecture du fichier %s",nomfichier);
    fichier = fopen(nomfichier, "r+"); // ouverture du fichier en mode lecture
    if(fichier !=NULL)
    {
        struct automate * pautomate = lire_automate(fichier);
        // Renvoie 1 si le mot est reconnu par l'automate
        // Renvoie 0 si le mot n'est pas reconnu par l'automate
        char * alpha = calloc(taille,sizeof(char));
        printf("Votre mot :");
        lecture(alpha,taille);
        if(accepte(pautomate,alpha))
            printf("Mot accepte");

        int rep;
        printf("\nVoulez-vous modifiez l'automate (1 = yes) :");
        scanf("%d",&rep);
        if(rep==1)
           pautomate=ecrire_automate(fichier,pautomate);
        if(rep==2)
        {
            char * nomfichier2 = calloc(taille,sizeof(char));
            printf("Sauvegarde de l'automate\nNom de fichier :");
            lecture(nomfichier2,taille); // Permet de lire la chaine de caractère rentrée par l'utilisateur et d'enlevere le \n à la fin
            sauvegarde_automate(pautomate,nomfichier2);
        }

        fclose(fichier);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier");
    }

	return 0;
}
