#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "graphe.h"

// Initialise une structure graphe contenant un nombre de sommets passé en paramètre et aucun arc
// Renvoie l'adresse mémoire ddu graphe allouée
struct graphe * creer_graphe(int nbsommets)
{
	struct graphe * pgraphe;
	pgraphe = malloc(sizeof(struct graphe)); 
	pgraphe->nbsommets = nbsommets;
	pgraphe->adjs = malloc(sizeof(struct larc *)*nbsommets); // Alloue la mémoire pour le tableau de listes d'adjacence

	int i = 0;
	for(i=0; i<nbsommets;++i)
	{
		pgraphe->adjs[i]=NULL;
	}

	return pgraphe; // Adresse mémoire du graphe créé
}

// Paramètres : 2 sommets et une étiquette associée
// Renvoie 1 si cet arc existe déjà
// Renvoie 0 si l'arc n'existe pas
int arc_existe(struct graphe * pgraphe, int s1, int s2, char symbole)
{
	int existence = 0;

	struct larc * piteration = pgraphe->adjs[s1]; // On recupère le pointeur du sommet s1 sur la liste chainée
	if(pgraphe->adjs[s1] != NULL)
	{

        while (piteration != NULL) // Tant que l'on est pas au bout de la chaine
        {
        	if ((piteration->voisin == s2) && (piteration->etiquette == symbole))
            {
                existence = 1;
                piteration=NULL;//On termine la boucle l'arc existe déjà
            }
            else //L'arc actuel ne relie pas le s1 avec le s2 on passe à celui d'après
            {
                piteration = piteration->arc_suiv;
            }
            
        }
	}
	return existence; // 0 ou 1 en fonction de l'existence de l'arc
}

// Ajoute un arc entre deux sommets passés en paramètre
// Assigne un symbole aussi passé en paramètre
void ajouter_arc(struct graphe * pgraphe, int s1, int s2, char symbole)
{	
	if (arc_existe(pgraphe, s1, s2, symbole) == 0) // Si un arc avec ces paramètres n'existe pas encore
	{
		struct larc * parc;
		parc = malloc(sizeof(struct larc));
		parc->voisin = s2;
		parc->etiquette = symbole;

		parc->arc_suiv = pgraphe->adjs[s1];
		pgraphe->adjs[s1] = parc;
	}

	else // Si un arc avec ces paramètres existe déjà
	{
		printf("L'arc existe déjà.\n");
	}
}

// Paramètres : 2 sommets et une étiquette associée
// Supprime l'arc associé à ces paramètres si celui-ci existe
void retirer_arc(struct graphe * pgraphe, int s1, int s2, char symbole)
{
	if(arc_existe(pgraphe,s1,s2,symbole) == 1)
	{
		if ((pgraphe->adjs[s1]->etiquette == symbole) && (pgraphe->adjs[s1]->voisin == s2)) // Si le premier arc de la chaîne match
		{
			struct larc * pmemoire = pgraphe->adjs[s1]; // Garde en mémoire l'adresse de l'arc à supprimer (1er), pour free plus tard
			pgraphe->adjs[s1] = pgraphe->adjs[s1]->arc_suiv; // pgraphe->adjs[s1]pointe maintenant directement sur l'arc suivant (2e devenu 1er)
			free(pmemoire); // Libère la mémoire de l'arc supprimé
		}

		else
		{
			struct larc * pprecedent = pgraphe->adjs[s1];  // Pointeur sur arc-1
			struct larc * pactuel = pgraphe->adjs[s1]->arc_suiv;;  // Pointeur sur arc

			while(pactuel != NULL) 
			{
				if (pactuel->voisin == s2 && pactuel->etiquette == symbole)
				{
					pprecedent->arc_suiv = pactuel->arc_suiv; // arc-1 pointe sur arc +1
					printf("On a supprimé l'arc de %d à %d d'étiquette %c.\n", s1, s2, symbole);
					free(pactuel); // free arc (qui a match)
				}
				else // Itération suivante
				{
					pprecedent = pactuel; 
					pactuel = pactuel->arc_suiv; 
				}
			}
		}
	}
}

// Paramètres : état de départ et étiquette
// Renvoie l'état d'arrivée 
// Renvoie -1 si la transition n'existe pas
int transiter(struct graphe * pgraphe, int etat, char symbole)
{
	int etat_atteint = -1;
    if(etat<=pgraphe->nbsommets)
    {
        struct larc * piteration = pgraphe->adjs[etat];
        while (piteration != NULL) // Tant que l'étiquette n'est pas la bonne
        {
            if(piteration->etiquette != symbole)
            {
                piteration = piteration->arc_suiv;
            }
            else
                break;
        }
        if(piteration != NULL)
        {
           if(piteration->etiquette == symbole)
            {
                etat_atteint=piteration->voisin;
            }
        }
    }
	return etat_atteint; // Etat d'arrivée ou -1 si celui-ci n'existe pas
}

// Affiche le graphe en listant pour chaque sommet les sommets accessibles et les étiquettes associéees
void afficher(struct graphe * pgraphe)
{
	printf("\n");
	int i = 0;
	for (i=0; i < pgraphe->nbsommets; ++i)
	{
		printf("Sommet %d : \n", i);

		struct larc * piteration = pgraphe->adjs[i];
		while (piteration != NULL)
		{
			printf("(%d,%c)\n", piteration->voisin, piteration->etiquette);
			piteration = piteration->arc_suiv;
		}
	}
}

// Libère l'espace mémoire occupé par le graphe
void liberer_graphe(struct graphe * pgraphe)
{
	int i;
	struct larc * pactuel = NULL; // Pointeur sur arc
	struct larc * pprecedent = NULL;  // Pointeur sur arc-1

	//Libere la mémoire des arcs
	for (i = 0; i < pgraphe->nbsommets; i++) // Pour le nombre de sommet
	{
		pactuel = pgraphe->adjs[i];
		while (pactuel != NULL)
		{
			pprecedent = pactuel; // On garde en mémoire le pointeur actuel
			pactuel = pactuel->arc_suiv; // On passe au pointeur suivant
			free(pprecedent); // On free l'ancien arc
		}
	}
	free(pgraphe); // Libère la structure graphe
	printf("Graphe détruit\n");
}

/*
void Menu(struct graphe * pgraphe)
{
	int choixMenu=-1,sommet1,sommet2,tailleGraphe,i=0,etat_depart;
	char symbole, alphabet[9]={'a','b','c','d','e','f','g','h'};
	while(choixMenu != 6)
	{
	    choixMenu=-1;
		while(choixMenu>6 || choixMenu<1)
		{
			printf("\n\n1.Creer un arc\n2.Retirer un arc\n3.Affiche le graphe\n4.Transition\n5.Liberer la memoire et recreer un graphe\n6.Stop\nChoix : ");
			scanf("%d",&choixMenu);
		}

		switch(choixMenu)
		{
			case 1 :

				do{
					printf("Sommet de depart :");
					scanf("%d",&sommet1);
					printf("Sommet d'arrivee :");
					scanf("%d",&sommet2);
					if(i<9){
                        symbole=alphabet[i];
                        i++;
					}
					else
                        i=0;
				}while(Verification(pgraphe,sommet1,sommet2));
				ajouter_arc(pgraphe, sommet1, sommet2, symbole);
				break;

			case 2 :
				do{
					printf("Sommet de depart :");
					scanf("%d",&sommet1);
					printf("Sommet d'arrivee :");
					scanf("%d",&sommet2);
				}while(Verification(pgraphe,sommet1,sommet2));
				retirer_arc(pgraphe, sommet1, sommet2);
				break;

			case 3 : afficher(pgraphe);
			break;

            case 4:
                symbole = 'a'; // Il faut recuperer le symbole
                printf("Etat de depart : ");
                scanf("%d",&etat_depart);
                if(transiter(pgraphe,etat_depart,symbole) != -1)
                    printf("En partant de l'etat %d, on arrive a l'etat %d en passant par la branche de symbole : %c",etat_depart,transiter(pgraphe,etat_depart,symbole),symbole);
                else
                    printf("Transition impossible auncun arc du sommet %d n'a le symbole %c",etat_depart,symbole);
                break;
			case 5 :
				liberer_graphe(pgraphe);
				printf("\nVeuillez rentrer la taille de votre graphe :");
				scanf("%d",&tailleGraphe);
				struct graphe * pgraphe = creer_graphe(tailleGraphe);
			break;

			case 6 : liberer_graphe(pgraphe);
			break;
		}
	}
}

int Verification (struct graphe * pgraphe, int s1, int s2)
{
	int ok =0;
	if( (s1 > (pgraphe->nbsommets) ) || (s2 > (pgraphe->nbsommets)) )
	{
		printf("Erreur : la valeur du sommet est trop grande\n");
		ok = 1;
	}
	return ok;
}
*/