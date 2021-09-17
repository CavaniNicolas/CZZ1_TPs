#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fic2LC.h"

liste_2pointeurs creer_liste(){
	liste_2pointeurs liste;
	liste.tete=NULL;
	liste.fin=NULL;
	return liste;
}

int fichier_dans_la_liste(liste_2pointeurs * liste, char * filename){
	FILE * file = NULL;
	file = fopen(filename,"r");
	if (file==NULL){
		printf("fichier inexistant\n");
		return -1;
	}
	else{
		int taille=0;
		//printf("on lit dans le fichier\n");
		char ligne[255];
		while (fgets(ligne,255,file)!=NULL){
			inserer_char_dans_liste(ligne,liste);
			taille++;
		}
		fclose(file);
		return taille;
	}
}

void inserer_char_dans_liste(char * ligne, liste_2pointeurs *liste){
	cellule * element=(cellule *)malloc(sizeof(cellule));
	if (element!=NULL){
		element->ligne = (char *)malloc((1+strlen(ligne))*sizeof(char));

		if (element->ligne!=NULL){
			if (liste->tete!=NULL){
				liste->fin->suiv=element;
			}
			else{
				liste->tete=element;
			}
		}
		strcpy(element->ligne,ligne);
		element->suiv=NULL;
		liste->fin=element;
	}
}

void afficher_listeTF(liste_2pointeurs liste){
	if (liste.tete!=NULL){
		printf("\n\n\tdébut :\n");
		cellule * cour = liste.tete;

		while (cour!=NULL){
			printf("%s",cour->ligne);
			cour=cour->suiv;
		}

		printf("\tfin.\n");
	}
	else{
		printf("liste vide\n");
	}
}

void liberer_liste(liste_2pointeurs *liste){
	cellule * cour = liste->tete;
	while (cour!=NULL){
		free(cour->ligne);
		cour=cour->suiv;
		free(liste->tete);
		liste->tete=cour;
	}
	liste->tete=NULL;
	liste->fin=NULL;
}
