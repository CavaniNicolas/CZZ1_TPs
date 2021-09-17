#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "floodit.h"
#include "time.h"

int main(){
	int choix, compteur = 0;

	int plateau[TAILLE][TAILLE];
	init_plateau(plateau);
	afficher_plateau(plateau,compteur);

	while (!fin(plateau) && compteur<=TENTATIVES) {
	//	printf("fin dans while = %d\n",fin(plateau));
		choisir_couleur(&choix);
		remplir(plateau[0][0],choix,plateau,0,0);
		afficher_plateau(plateau,compteur);
	//printf("fin fin= %d\n",fin(plateau));
		compteur++;
	}
	resultat(compteur);
	return 0;
}

void init_plateau(int tab[TAILLE][TAILLE]){
	int i, j;
	srand(time(NULL));
	for (i=0;i<TAILLE;i++){
		for (j=0;j<TAILLE;j++){
			tab[i][j]=rand()%COULEURS+1;
		}
	}
}

void afficher_plateau(int tab[TAILLE][TAILLE], int compteur){
	int i, j;
	system("clear");
	printf("\ncoups max : %d\n",TENTATIVES);
	printf("coups : %d\n",compteur);
	printf("---------------------------\n");
	for (i=0;i<TAILLE;i++){
		printf("\033[00m| ");
		for (j=0;j<TAILLE;j++){
			printf("\033[3%dm%d ",tab[i][j],tab[i][j]);
		}
		printf("\033[00m|\n");
	}
	printf("---------------------------\n");
}

int fin(int tab[TAILLE][TAILLE]){
	int win=1;
	int i = 0, j = 0;
	int coul_00 = tab[0][0];

	while (win==1 && i<TAILLE){
		j=0;
		while (win==1 && j<TAILLE){
			if (coul_00 != tab[i][j]){
				win=0;
			}
			j++;
		}
		i++;
	}
	return win;
}

void choisir_couleur(int * choix){
	*choix = 0;
	while (*choix<1 || *choix>COULEURS){
		printf("choix : ");
		*choix=lireInt();
	}
}

void remplir(int coul_00, int choix, int tab[TAILLE][TAILLE], int x, int y){
	if (coul_00 != choix){
		if (0<=x && x<TAILLE && 0<=y && y<TAILLE){
			if (tab[x][y]==coul_00){
				tab[x][y]=choix;
				remplir(coul_00, choix, tab, x+1, y);
				remplir(coul_00, choix, tab, x-1, y);
				remplir(coul_00, choix, tab, x,   y+1);
				remplir(coul_00, choix, tab, x,   y-1);
			}
		}
	}
}

void resultat(int compteur){
	if (compteur<TENTATIVES){
		printf("VICTOIRE\n");
	}
	else{
		printf("DEFAITE\n");
	}
}




void viderBuffer(){
	int c=0;
	while (c != '\n' && c != EOF){
		c = getchar();
	}
}

int lire(char * chaine, int longueur){
	char * positionEntree = NULL;
	if (fgets(chaine,longueur,stdin) != NULL){
		positionEntree = strchr(chaine, '\n');
		if (positionEntree != NULL){
			*positionEntree = '\n';
		}
		else{
			viderBuffer();
		}
		return 1;
	}
	else{
		viderBuffer();
		return 0;
	}
}

long lireInt(){
	char nombretexte[100]; // 100 cases devraient suffire
	if (lire(nombretexte,100)){
		// Si lecture du texte ok, convertir le nombre en long et le retourner
		return ( strtol(nombretexte, NULL, 10) );
	}
	else{
		// Si problème de lecture, renvoyer 0
		return 0;
	}
}