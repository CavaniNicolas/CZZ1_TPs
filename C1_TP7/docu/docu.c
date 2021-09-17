#include <stdio.h>
#include <string.h>
#include "../src/listechainée2.h"
#include "docu.h"

int main(int argc, char * argv[]){
	liste_2pointeurs liste;
	liste=creer_liste();
	if (argc==1){
		printf("Mettre le nom du fichier .h a documenter en paramètre\n");
	}
	else{
		FILE * file_h = NULL;
		file_h = fopen(argv[1],"r");
		if (file_h==NULL){
			printf("can't open your file\n");
		}

		else{

			printf("Creation de la documentation à partir de %s\n",argv[1]);
			char ligne[255];
			while (fgets(ligne,255,file_h)!=NULL){
				inserer_char_dans_liste(ligne,&liste);
			}

			remplir_docu(liste);
			liberer_liste(&liste);

			fclose(file_h);
		}
	}
	return 0;
}

void remplir_docu(liste_2pointeurs liste){
	FILE * file_docu = NULL;
	file_docu = fopen("bin/documentation.txt","w+");
	
	if (file_docu!=NULL){
		cellule * cour = liste.tete;

		fprintf(file_docu,"\tC1_TP7, listechainée2\n\tdocumentation by N. Cavani\n\tDecembre 2019\n\n");
		while(cour!=NULL){
			if (cour->ligne[0]=='#'){
				fprintf(file_docu,"%s",cour->ligne);
			}
			//printf("%s",cour->ligne);
			if (0==strcmp(cour->ligne,"/*Declarations_Fonctions*/\r\n") ){
				while (cour!=NULL && 0!=strcmp(cour->ligne,"/*Fin_Declarations_Fonctions*/\r\n") ){
					//printf("%s",cour->ligne);
					fprintf(file_docu,"%s",cour->ligne);
					cour=cour->suiv;
				}
				fprintf(file_docu,"%s",cour->ligne);
			}
			if (cour!=NULL){
				// printf("on est la\n");
				cour=cour->suiv;
			}
		}
		fclose(file_docu);
		printf("Creation de la doc terminée dans: bin/documentation.txt\n");
	}

}