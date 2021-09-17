#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//TP : http://fc.isima.fr/~loic/unixc/tpc-04-comp.php

//tete fictive : une cellule dont le seul champ qui nous intéresse est le champ suiv
//donnee_t tf;
//tete reelle : un simple pointeur sur la première cellule
//donnee_t * tr;

struct donnee{
    int score;
    struct donnee * suiv;    
};
typedef struct donnee donnee_t;

/////////////////////////////////////////////////////////////////////////////////////////////
/*
// Liste avec Une tete fictive
void creation_liste_TF(donnee_t * tf){
	donnee_t * element1;
	element1 = (donnee_t *)malloc(sizeof(donnee_t));
	element1->score = 11;
	element1->suiv = NULL;
	(*tf).suiv=element1;
	//premier terme

	element1 = (donnee_t *)malloc(sizeof(donnee_t));
	element1->score = 22;
	element1->suiv = NULL;
	(*tf).suiv->suiv = element1;
	//insere a la fin (2eme)

	element1 = (donnee_t *)malloc(sizeof(donnee_t));
	element1->score = 33;
	element1->suiv = NULL;
	(*tf).suiv->suiv->suiv = element1;
	//insere a la fin (3eme)

	element1 = (donnee_t *)malloc(sizeof(donnee_t));
	element1->score = 44;
	element1->suiv = NULL;
	(*tf).suiv->suiv->suiv->suiv = element1;
	//insere a la fin (4eme)

	element1 = (donnee_t *)malloc(sizeof(donnee_t));
	element1->score = 15;
	element1->suiv=(*tf).suiv;
	(*tf).suiv=element1;
	//insere 1ere position

	element1 = (donnee_t *)malloc(sizeof(donnee_t));
	element1->score = 3;
	element1->suiv = (*tf).suiv->suiv->suiv;
	(*tf).suiv->suiv->suiv=element1;
	//insere 3eme position

	//free(element1);
	//free(element1);
	//free(element1);
	//free(element1);
	//free(element1);
	//free(element1);
}

void afficherListe1(donnee_t tete){
   while (tete.suiv!=NULL)
   {
      printf("%d ", tete.suiv->score);
      tete.suiv = tete.suiv->suiv;
   }
}

void afficherListe2(donnee_t tete){
  donnee_t * cour = tete.suiv;
   while (cour!=NULL)
   {
      printf("%d ", cour->score);
      cour = cour->suiv;
   }
}

void afficherListe3(donnee_t * cour){
   while (cour!=NULL)
   {
      printf("%d ", cour->score);
      cour = cour->suiv;
   }
}

void inserer_1erTerme_Liste(donnee_t * ptete, donnee_t * elem)
{
    elem->suiv = ptete->suiv;
    ptete->suiv    = elem;
}

int main(){
	donnee_t tf;
	tf.suiv=NULL;
	//liste vide

	creation_liste_TF(&tf);

	donnee_t terme1;
	terme1.score=1111;
	inserer_1erTerme_Liste(&tf,&terme1);
	//inserer le 1er element

	afficherListe1(tf); printf("\n");
	afficherListe2(tf); printf("\n");
	afficherListe3(tf.suiv); printf("\n");
}
*/


/////////////////////////////////////////////////////////////////////////////////////////////


void creation_liste_TR(donnee_t ** tete){
	donnee_t * element = (donnee_t *)malloc(sizeof(donnee_t));
	element->score = 2;
	element->suiv = NULL;
	(*tete) = element;

	element = (donnee_t *)malloc(sizeof(donnee_t));
	element->score = 3;
	element->suiv=NULL;
	(*tete)->suiv=element;

	element = (donnee_t *)malloc(sizeof(donnee_t));
	element->score = 1;
	element->suiv = (*tete);
	(*tete) = element;
}
// en passant par adresse avec un pointeur OU en retournant le pointeur de structure :
donnee_t * creation_liste_PTR(donnee_t * tete){
	donnee_t * element = (donnee_t *)malloc(sizeof(donnee_t));
	element->score = 2;
	element->suiv = NULL;
	tete = element;

	element = (donnee_t *)malloc(sizeof(donnee_t));
	element->score = 3;
	element->suiv=NULL;
	tete->suiv=element;

	element = (donnee_t *)malloc(sizeof(donnee_t));
	element->score = 1;
	element->suiv = tete;
	tete = element;
	return(tete);
}

void afficher(donnee_t * cour){
	while (cour != NULL){
		printf("%d",cour->score);
		cour=cour->suiv;
	}
	printf("\n");
}

void inserer_1er_listeTR(donnee_t ** tr){
	donnee_t * element = (donnee_t *)malloc(sizeof(donnee_t));
	element->score=11;
	element->suiv=*tr;
	*tr=element;
}

int main(){
	donnee_t * tr;
	tr = NULL;

	//creation_liste_TR(&tr);
	tr=creation_liste_PTR(tr);
	inserer_1er_listeTR(&tr);
	afficher(tr);
    return 0;
}

