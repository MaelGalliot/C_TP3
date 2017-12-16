#include "langage.h"
#include <stdio.h>
#include <stdlib.h>
// Paramètres : descripteur de fichier
// Retourne un graphe alloué en mémoire dans la fonction
struct automate * lire_automate(FILE * pfichier)
{
    int nbetats,nbalphabet,i;
    fscanf(pfichier,"%d %d",&nbetats,&nbalphabet); //On récupère le nombre d'état et le nombre de lettre dans l'alphabet
    char alphabet[nbalphabet];
    for(i=0;i<=nbalphabet;++i)//On créer l'alphabet
        fscanf(pfichier,"%c",&alphabet[i]);

    int etat_init,nbetatsfinaux;
    fscanf(pfichier,"%d %d",&etat_init,&nbetatsfinaux); // On récupère l'état initiale et le nombre d'état final
    int etats_finaux_parametres[nbetatsfinaux];
    for(i=0;i<nbetatsfinaux;++i)// On créer un trableau avec le nombre d'état final
        fscanf(pfichier,"%d",&etats_finaux_parametres[i]);

    struct automate * pautomate = creer_automate(nbetats, alphabet, etat_init, etats_finaux_parametres, nbetatsfinaux);

    int lecture[2];
    char symbole;
    while(fscanf(pfichier,"%d %d %c", &lecture[0],&lecture[1],&symbole)==3) // La fonction fscanf() renvoie 3 si tt se passe bien 0 si la donnée ne correspond pas au format et -1 à la fin du fichier
    {
         ajouter_transition(pautomate, lecture[0], lecture[1], symbole);
    }
    afficher(pautomate->graphe_trans);
    return pautomate;
}

/* bug : rajoute dans le fichier graphe.txt des données en plus*/
// Paramètres : descripteur de fichier + graphe
struct automate * ecrire_automate(FILE * pfichier, struct automate * pautomate)
{
    int e1,e2;
    char v;
    /* Création d'une transition */
    fseek(pfichier,0,SEEK_END); // On met le curseur à la fin
    printf("Etat depart :");
    scanf("%d",&e1);
    printf("Etat arrive :");
    scanf("%d",&e2);
    printf("Symbole :");
    while (getchar() != '\n');
    v = getchar();
    fprintf(pfichier," %d %d %c",e1,e2,v);

    /*Mise à jour*/
    liberer_automate(pautomate);
    pautomate=lire_automate(pfichier);
    return pautomate;
}

/*
// Paramètres : nom de fichier
// Retourne un AFD alloué en mémoire dans la fonction à partir des données
struct automate * lire_automate(char * nomfichier)
{
//	return pautomate;
}

// Paramètres : automate + nom de fichier
// Sauve l'automate dans le fichier
void sauvegarde_automate(strucut automate * pautomate, char * nomfichier)
{

}*/

