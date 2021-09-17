#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hall_of_fame.h"


int main(){
	donnee_t * tr=creerListe(); // donnee_t * tr = NULL;
	//ajouterFin(&tr,5,"Lol","Faker");
	//ajouterFin(&tr,12,"MARTINE A LA FERME LE JEU","XX martine51 XX");
	//listeChainee_fromFileByName("save.txt",&tr);
	//char * num="14\n";
	//printf("%d\n",atoi(num));
	menu(&tr);
	//test_strcpy();

	return 0;
}


void menu(donnee_t ** tr){
	int choix=0;

	printf("\n\t BIENVENUE DANS LA LISTE CHAINEE !!\n\t     Que désirer vous faire ?\n");

	while(choix!=7){
		printf("\n\t\033[36m--------------\033[33mMENU\033[00m\033[36m----------------\n");
		printf("\t|\033[00m  Afficher la liste chainee : 1 \033[36m|\n");
		printf("\t|\033[00m  Insérer un nouvel élément : 2 \033[36m|\n");
		printf("\t|\033[00m       Editer un element    : 3 \033[36m|\n");
		printf("\t|\033[00m     Supprimer un element   : 4 \033[36m|\n");
		printf("\t|\033[00m   Récupérer la sauvegarde  : 5 \033[36m|\n");
		printf("\t|\033[00m    Ecraser la sauvegarde   : 6 \033[36m|\n");
		printf("\t|\033[00m           Quitter          : 7 \033[36m|\n");
		printf("\t----------------------------------\033[00m\n?  ");
		scanf("%d",&choix);
		viderBuffer();
		printf("\n");
		//int modif;
		switch(choix){
			case 1:
				afficherListe(*tr);
				break;
			case 2:
				printf("Pour inserer en debut     : 1\n");
				printf("Pour inserer en fin       : 2\n");
				printf("Pour inserer à un endroit : 3\n?  ");
				scanf("%d",&choix);
				viderBuffer();
				donnee_t element;
				switch(choix){
					case 1:
						user_input(&element);
						ajouterDebut(tr,element.score,element.jeu,element.alias);
						break;
					case 2:
						user_input(&element);
						ajouterFin(tr,element.score,element.jeu,element.alias);
						break;
					case 3:
						//int pos=0;
						printf("feature a faire\n");
						//printf("A quelle position voulez vous insérer un élément ?\n?  ");
						//scanf("%d",&pos);
						//vider_buffer();
						//user_input(&element);
						//ajouterElement(tr,element.score,element.jeu,element.alias);
						break;
				}
				break;
			case 3:
				printf("Quel élément souhaitez vous modifier ?\n?  ");
				int modif;
				scanf("%d",&modif);
				viderBuffer();
				donnee_t * cour = afficherUnSeul_renvoyerAdresse((*tr),modif);
				if (cour!=NULL){
					user_input(cour);//modifie l'élément
				}
				break;
			case 4:
				printf("feature a faire\n");
				//supprimer un element
				break;
			case 5:
				printf("Etes vous sur ? Vous allez perdre la liste actuelle\n");
				printf("\033[32mOui : 1\033[00m ; \033[31mNon : 0\033[00m\n");
				scanf("%d",&modif);
				viderBuffer();
				switch(modif){
					case 1:
						supprimer_liste(tr);
						listeChainee_fromFileByName("save.txt",tr);
						break;
					case 0:
						break;
				}
				break;
			case 6:
				printf("Etes vous sur ? Vous allez perdre la sauvegarde actuelle\n");
				printf("\033[32mOui : 1\033[00m ; \033[31mNon : 0\033[00m\n");
				scanf("%d",&modif);
				viderBuffer();
				switch(modif){
					case 1:
						ecraser_sauvegarde("save.txt",*tr);
						break;
					case 0:
						break;
				}
				break;
			case 7:
				printf("Aurevoir :)\n\n");
				supprimer_liste(tr);
				break;
		}
	}
}

void ecraser_sauvegarde(char * filename, donnee_t * cour){
	//donnee_t * cour = tr;
	FILE * file = NULL;
	file=fopen(filename,"w+");
	if (file!=NULL){
		while (cour->suiv!=NULL){
			fprintf(file,"%s\n",cour->jeu);
			fprintf(file,"%s\n",cour->alias);
			fprintf(file,"%d\n",cour->score);
			cour=cour->suiv;
		}
		fprintf(file,"%s\n",cour->jeu);
		fprintf(file,"%s\n",cour->alias);
		fprintf(file,"%d",cour->score);
	}
	fclose(file);
}

void supprimer_liste(donnee_t ** tr){
	if (*tr!=NULL){
		donnee_t * cour = *tr;
		donnee_t * suivant = cour->suiv;
		*tr=NULL;
		while(suivant!=NULL){
			free(cour);
			cour=suivant;
			suivant=suivant->suiv;
		}
	}
}

void listeChainee_fromFileByName(char * filename, donnee_t ** tr){
	FILE * file=NULL;
	file=fopen(filename,"r");
	if (file!=NULL){
 
		donnee_t * cour = *tr;
		//int i=1;
		while (feof(file)==0){//feof(FILE * stream) renvoie une valeur nulle si on est pas encore au bout
			//printf("while numero : %d\n",i);i++;
			donnee_t * element = (donnee_t *)malloc(sizeof(donnee_t));

			fgets(element->jeu,sizeof(cour->jeu),file);
			removeEnter(element->jeu);
			fgets(element->alias,sizeof(cour->alias),file);
			removeEnter(element->alias);
			char temp[15];
			
			element->score=atoi(fgets(temp,15,file));
			element->suiv=NULL;

			if (cour==NULL){
				*tr=element;
				cour=element;
			}
			else{
				cour->suiv=element;
				cour=element;
			}
		}
	}
	fclose(file);
}

void saisirDonnee(FILE *file, donnee_t * p){
   fgets((*p).jeu,sizeof((*p).jeu),file);
   fgets((*p).alias,sizeof((*p).alias),file);
   char nb [10];
   (*p).score=atoi(fgets(nb,10,file));

   removeEnter((*p).jeu);
   removeEnter((*p).alias);
}

void removeEnter(char * chaine){
   int l = strlen(chaine);
   chaine[l-1]='\0';
}


void user_input(donnee_t * element){
	char jeu[70];
	char alias[30];
	int score;

	printf("Saisissez le jeu    : ");
	scanf("%s",jeu);
	viderBuffer();
	printf("Saisissez le pseudo : ");
	scanf("%s",alias);
	viderBuffer();
	printf("Saisissez le score  : ");
	scanf("%d",&score);
	viderBuffer();

	strcpy(element->jeu,jeu);
	strcpy(element->alias,alias);
	element->score=score;
}

donnee_t * afficherUnSeul_renvoyerAdresse(donnee_t * cour,int modif){
	int i=1;
	while (cour->suiv!=NULL && i<modif){
		cour=cour->suiv;
	i++;
	}
	if (i==modif){
		printf(  "-%d-  \033[32mJEU:\033[00m %s \033[32mALIAS:\033[00m %s \033[32mSCORE:\033[00m %d\n",i,cour->jeu,cour->alias,cour->score);
	}
	else{
		printf("Valeur hors de la liste\n");
		cour=NULL;
	}
	return cour;
}

void test_strcpy(){
	char jeu[4];
	scanf("%s",jeu);
	printf("%s\n",jeu);

	donnee_t * ell=(donnee_t *)malloc(sizeof(donnee_t));
	//malloc important pour creer de l'emplacement memoire pour la structure
	//et pas uniquement la memoire necessaire pour le pointeur de structure.
	if(ell==NULL){
		printf("erreur\n");
	}
	//Test important dans le cas où il n'y a plus d'emplacement mémoire disponible.
	else{
		ell->suiv=NULL;
		strcpy(ell->alias,"hoho");
		ell->score=5;
		strcpy(ell->jeu,"bonbb");
		strcpy(ell->jeu,jeu);
		printf("%s\n",ell->jeu);
	}
//
}

void viderBuffer(){
    int c;
    do {
        c = getchar();
    } while (c != EOF && c != '\n');
}