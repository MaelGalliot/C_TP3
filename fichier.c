#include "langage.h"
#include "fichier.h"
#include "automate.h"
#include "graphe.h"
#include <stdio.h>
#include <stdlib.h>
// Paramètres : descripteur de fichier
// Retourne un graphe alloué en mémoire dans la fonction
struct automate * lire_automate(FILE * pfichier)
{
    fseek(pfichier,0,SEEK_SET);
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


    if ((e1 < pautomate->graphe_trans->nbsommets) && (e2 < pautomate->graphe_trans->nbsommets)&& (etiquette_existe(pautomate, v)==1)) // Si un arc avec ces paramètres n'existe pas encore
	{
	    if(arc_existe(pautomate->graphe_trans, e1, e2, v) == 0)
            fprintf(pfichier," %d %d %c",e1,e2,v);
	}
	else
        printf("Impossible de créer l'arc");
    /*Mise à jour*/
    liberer_automate(pautomate);
    pautomate=lire_automate(pfichier);
    return pautomate;
}

// Paramètres : automate + nom de fichier
// Sauve l'automate dans le fichier
void sauvegarde_automate(struct automate * pautomate, char * nomfichier)
{
    int i;
    FILE * pfichier = NULL;
    pfichier=fopen(nomfichier,"w+");
    if(pfichier !=NULL)
    {
        int taille_alpha = strlen(pautomate->alphabet)-1; // -1 car il y a le caractère de fin de chaine
        fprintf(pfichier,"%d %d",pautomate->graphe_trans->nbsommets,taille_alpha);
        for(i=0;i<=taille_alpha;++i)//On créer l'alphabet
            fprintf(pfichier,"%c",pautomate->alphabet[i]);

        int taille_etatfinaux = strlen(pautomate->etats_finaux)+1; // On a décalé le pointeur à l'initialisation
        fprintf(pfichier,"\n%d %d\n",pautomate->etat_init,taille_etatfinaux);
        for(i=0;i<taille_etatfinaux;++i)
            fprintf(pfichier,"%d\n",pautomate->etats_finaux[i+7]); // ??? Pourquoi l'état final se retrouve en 8 eme position du tableau ????


        for (i=0; i < pautomate->graphe_trans->nbsommets; ++i)
        {
            struct larc * piteration = pautomate->graphe_trans->adjs[i];
            while (piteration != NULL)
            {
                fprintf(pfichier,"%d %c\n", piteration->voisin, piteration->etiquette);
                piteration = piteration->arc_suiv;
            }
        }
    }
    else
        printf("Impossible d'ouvrir le fichier %s",nomfichier);
    fclose(pfichier);
}

void lecture(char * pnomfichier, int taille)
{
    static int init=0;
    int len_nomfichier;
    if(init>=2)
        while (getchar() != '\n');
    fgets(pnomfichier,taille,stdin);
    len_nomfichier = strlen(pnomfichier);
    pnomfichier[(len_nomfichier-1)]='\0';
    init++;
}
