#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hall_of_fame.h"

donnee_t * creerListe(void){
	donnee_t * tr;
	tr=NULL;
	return tr;
}

void ajouterFin(donnee_t ** tr, int score, char * jeu, char alias[]){//char * jeu = char jeu [] (cf aussi le .h)
	donnee_t * element = (donnee_t *)malloc(sizeof(donnee_t));
	element->score=score;
	strcpy(element->jeu,jeu);
	strcpy(element->alias,alias);
	element->suiv=NULL;

	if ((*tr)==NULL){
		(*tr)=element;
	}
	else{
		donnee_t * cour = *tr;
		while (cour->suiv!=NULL){
			cour=cour->suiv;
		}
		cour->suiv=element;
	}
}

void ajouterDebut(donnee_t ** tr, int score, char jeu [], char alias []){
	donnee_t * element = (donnee_t *)malloc(sizeof(donnee_t));
	element->score=score;
	strcpy(element->jeu,jeu);
	strcpy(element->alias,alias);
	element->suiv=*tr;
	*tr=element;
}

void afficherListe(donnee_t * cour){
	if (cour==NULL){
		printf("Liste Vide\n");
	}
	else{
		int i=1;
		while (cour!=NULL){
			printf("-%d-  \033[32mJEU:\033[00m %s \033[32mALIAS:\033[00m %s \033[32mSCORE:\033[00m %d\n",i,cour->jeu,cour->alias,cour->score);
			cour=cour->suiv;
			i++;
		}
	}
}

void libererListe(donnee_t ** tr){
	donnee_t * cour = *tr;
	while ((*tr)!=NULL){
		cour=(*tr)->suiv;
		free(*tr);
		(*tr)=cour;
	}
}

/*
int main(){
	donnee_t * tr=creerListe();
	ajouterFin(&tr,5,"Lol","Faker");
	ajouterFin(&tr,12,"MARTINE A LA FERME LE JEU","XX martine51 XX");
	ajouterFin(&tr,-5,"tetris","Gerard");
	ajouterFin(&tr,54,"bonjour","bertrand");

	ajouterDebut(&tr,3012,"premierElem","joueur1");
	ajouterDebut(&tr,10,"leVraiPremier","joueur0");
	afficherListe(tr);

	libererListe(&tr);
	return 0;
}
*/