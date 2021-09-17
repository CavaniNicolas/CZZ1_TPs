#include "code.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void stats1(char *texte, int *nb_chars, int * nb_lignes, int * nb_mots){
	(*nb_chars)=0;
	(*nb_mots)=0;
	(*nb_lignes)=1;
	int bool_mot=0;

	if (texte[*nb_chars]!='\0'){

		while (texte[*nb_chars]!='\0'){

			bool_mot=0;
			while (texte[*nb_chars]!='\0' && texte[*nb_chars]>=65 && texte[*nb_chars]<=90){	//A=65 Z=90
				(*nb_chars)++;
				bool_mot=1;
			}

			if (bool_mot==1){
				(*nb_mots)++;
				bool_mot=0;
			}

			if (texte[*nb_chars]=='\n'){
				(*nb_lignes)++;
			}

			if (texte[*nb_chars]!='\0'){
				(*nb_chars)++;
			}

		}
	}
}
 


long taille_fichier(char * nom) {
	FILE * f  = fopen(nom, "rb");
	long r = 0;
	if (f) {
		fseek(f, 0, SEEK_END);
		r = ftell(f);
		fclose(f);
	}
	return r;
}

char * lecture(char * nom) {
	long taille = taille_fichier(nom);
	char * chaine = (char *)malloc(taille*sizeof(char)+1);
	if (chaine!=NULL){
		FILE * file = NULL;
		file = fopen(nom,"r");

		if (file!=NULL){
			int i=0;
			for (i=0;i<taille;i++){
				chaine[i]=fgetc(file);
			}
			chaine[i]='\0';
			fclose(file);
		}
		else{
			chaine=NULL;
		}
	}

	return chaine;
} 


void initialiser(info * infos) {
	int i=0;
	int j=0;
	for (i=0;i<26;i++){
		infos[i].lettre=65+i;
		infos[i].nb=0;
		infos[i].nbd=0;
		for (j=0;j<MAX;j++){
			strcpy(infos[i].mots[j],"");
		}
	}
}


void inserer(info * infos, char * mot){
	int i=0; int j=0; unsigned k=0;
	int bool_distinct=0;
	int bool_bienplace=0;
	int lettre1=mot[0]-65;
	
	infos[lettre1].nb++;

	//modif nbd (nombre de mots distincts)
	while ( i<MAX && strcmp("",infos[lettre1].mots[i]) ){
		if ( !strcmp(infos[lettre1].mots[i],mot) ){
			bool_distinct=1;
		}
		i++;
	}
	if (bool_distinct==0){
		infos[lettre1].nbd++;
	}


	//ranger le mot par ordre lexicographique si il n'est pas dans la liste
	if ( !strcmp("",infos[lettre1].mots[MAX-1]) ){
		if (bool_distinct==0){
			i=0; k=1;

			while (bool_bienplace==0){

				while ( i<MAX && k<strlen(infos[lettre1].mots[i]) && k<strlen(mot) &&  mot[k]>infos[lettre1].mots[i][k] ) {
					i++;
				}
				if (mot[k]<infos[lettre1].mots[i][k]){
					bool_bienplace=1; //cette valeur de i est le bon emplacement du mot
				}
				else{
					k++;
				}
			}

			//decalage des mots apres celui qu'on insere
			j=MAX-2;
			while (j>=i){
				strcpy( infos[lettre1].mots[j+1] , infos[lettre1].mots[j] );
				j--;
			}

			//copie du mot au bon emplacement
			strcpy(infos[lettre1].mots[i],mot);
		}
	}
	else{
		printf("Capacité max de mots distincts atteintes pour ceux commencant par la lettre %c\n",mot[0]);
	}


}


void stats2(char *texte, info * infos, int *nb_chars, int * nb_lignes, int * nb_mots){
	initialiser(infos);
	int i=0; int k=0;
	char chaine[50];
	while (texte[i]!='\0'){
		k=0;
		while (texte[i]>=65 && texte[i]<=90){
			chaine[k]=texte[i];
			k++;
			i++;
		}
		if (k!=0){
			inserer(infos,chaine);
		}

		i++;
	}
	stats1(texte, nb_chars, nb_lignes, nb_mots);
	printf("AAAAAAAAAAAAAAAA : %d \n",total_mots_distincts(infos));
}


int total_mots(info * infos ) {
	int i=0;
	int nb=0;
	for (i=0;i<26;i++){
		nb+=infos[i].nb;
	}
	return nb;
}

int total_mots_distincts(info * infos) {
	int i=0;
	int nbd=0;
	for (i=0;i<26;i++){
		nbd+=infos[i].nbd;
	}
	return nbd;
}