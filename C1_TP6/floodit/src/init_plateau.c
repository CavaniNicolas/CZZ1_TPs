#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "floodit.h"

SDL_Rect rect;

int tab_couleurs[COULEURS][3];

int palette1[COULEURS][3]={ {255,183,138}, //beige
							{0,176,226}, //bleuC
							{226,43,32}, //rouge
							{33,172,15}, //vert
							{255,185,47}, //jauneorange
							{225,128,255} }; //violetC

int palette2[COULEURS][3]={ {0,0,0}, //noir
							{255,255,255}, //blanc
							{255,0,0}, //rouge
							{0,0,255}, //bleu
							{0,255,0}, //vert
							{255,255,0} }; //jaune

int palette3[COULEURS][3]={ {167,0,0}, //jaune
							{122,167,0}, //bleuC
							{103,136,150}, //gris
							{33,172,15}, //vert
							{122,143,0}, //vertF
							{165,94,0} }; //marron

int palette4[COULEURS][3]={ {255,126,0}, //orange
							{255,155,237}, //rose
							{116,115,115}, //gris
							{0,181,255}, //bleu
							{118,0,95}, //violet
							{255,211,36} }; //jaune

int palette5_1[COULEURS][3]={ {255,183,138}, //beige
							  {255,255,0}, //jauneC
							  {255,211,36}, //jaune
							  {255,126,0}, //orange
							  {255,74,47}, //rouge
							  {167,0,0} }; //rougeF

int palette5_2[COULEURS][3]={ {138,210,255}, //gris
							  {47,228,255}, //bleuC1
							  {0,129,255}, //bleuC2
							  {36,80,255}, //bleuC3
							  {0,0,255}, //bleuF
							  {0,167,167} }; //vert

int palette5_3[COULEURS][3]={ {125,162,255}, //bleuC
							  {255,138,244}, //roseC
							  {222,47,255}, //roseF
							  {182,0,255}, //violetC
							  {146,0,255}, //violet
							  {119,0,167} }; //violetF

int palette6[COULEURS][3]={ {255,0,0}, //rouge
							{165,94,0}, //marron
							{116,115,115}, //gris
							{20,0,137}, //bleu
							{118,0,95}, //violet
							{226,123,32} }; //orange

/*
int ** tab_couleurs;

void choisir_palette(){
	printf("%ld\n",sizeof(int[COULEURS][3]));
	//int ** tab_couleurs_ptrs[8]={palette1, palette2, palette3, palette4, palette5_1, palette5_2, palette5_3, palette6};
	int *** palettetmp=(int ***)malloc(sizeof(int[COULEURS][3]));
	for (int i=0;i<COULEURS;i++){
		for (int j=0;j<3;j++){
			*palettetmp[i][j]=palette6[i][j];
		}
	}
	tab_couleurs = *palettetmp;
}
*/

void choisir_palette(){
	switch (PALETTE) {
		case 1:
			for (int i=0;i<COULEURS;i++){
				for (int j=0;j<3;j++){
					tab_couleurs[i][j]=palette1[i][j];
				}
			}
			break;
		case 2:
			for (int i=0;i<COULEURS;i++){
				for (int j=0;j<3;j++){
					tab_couleurs[i][j]=palette2[i][j];
				}
			}
			break;
		case 3:
			for (int i=0;i<COULEURS;i++){
				for (int j=0;j<3;j++){
					tab_couleurs[i][j]=palette3[i][j];
				}
			}
			break;
		case 4:
			for (int i=0;i<COULEURS;i++){
				for (int j=0;j<3;j++){
					tab_couleurs[i][j]=palette4[i][j];
				}
			}
			break;
		case 51:
			for (int i=0;i<COULEURS;i++){
				for (int j=0;j<3;j++){
					tab_couleurs[i][j]=palette5_1[i][j];
				}
			}
			break;
		case 52:
			for (int i=0;i<COULEURS;i++){
				for (int j=0;j<3;j++){
					tab_couleurs[i][j]=palette5_2[i][j];
				}
			}
			break;
		case 53:
			for (int i=0;i<COULEURS;i++){
				for (int j=0;j<3;j++){
					tab_couleurs[i][j]=palette5_3[i][j];
				}
			}
			break;
		case 6:
			for (int i=0;i<COULEURS;i++){
				for (int j=0;j<3;j++){
					tab_couleurs[i][j]=palette6[i][j];
				}
			}
			break;
	}
}


void init_plateau(int tab[TAILLE][TAILLE]){
	int i, j;
	srand(time(NULL));
	for (i=0;i<TAILLE;i++){
		for (j=0;j<TAILLE;j++){
			tab[i][j]=rand()%COULEURS;
		}
	}
}

void afficher_plateau(SDL_Renderer * renderer, int tab[TAILLE][TAILLE]){
	int i; int j;
	int pas=800/TAILLE;
	int coul;
	for (i=0;i<TAILLE;i++){
		for (j=0;j<TAILLE;j++){
			coul=tab[i][j];
			SDL_SetRenderDrawColor(renderer, tab_couleurs[coul][0], tab_couleurs[coul][1], tab_couleurs[coul][2], 0);
			rect.x = 50+i*pas; rect.y = 100+j*pas;
			rect.w = pas; rect.h = pas;
			SDL_RenderFillRect(renderer, &rect);
		}
	}
}

void afficher_compteur(gdata_t g, int compteur){
	char texte[15];
	sprintf(texte,"Coups : %d",compteur);
	displayString(g, texte, 50, 50);
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

int choisir_couleur(int X, int Y, int tab[TAILLE][TAILLE]){
	if (50<X && X<50+TAILLE*(800/TAILLE) && 100<Y && Y<100+TAILLE*(800/TAILLE)){
		int choix;
		choix = tab[(X-50)/(800/TAILLE)][(Y-100)/(800/TAILLE)];
		return choix;
	}
	else{
		return tab[0][0];
	}
}

int remplir_plateau(int * compteur, int coul_00, int choix, int tab[TAILLE][TAILLE], int x, int y){
	remplir(coul_00, choix, tab, x, y);
	if (coul_00 != tab[0][0]){
		*compteur+=1;
		return 1;
	}
	else{
		return 0;
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

int verifier_compteur(int compteur){
	if (compteur>=TENTATIVES){
		//perdu
		return 1;
	}
	else{
		//ca continue
		return 0;
	}
}

void message_fin(int compteur, gdata_t g){
	if (compteur>TENTATIVES){
		displayStringFINALE(g,"PERDU",270,400,0);
		printf("perdu\n");
	}
	else{
		displayStringFINALE(g,"GAGNE",270,400,1);
		printf("gagne\n");
	}
	SDL_RenderPresent(g.renderer);
}

void displayString(gdata_t g, char * chaine, int x, int y) {

    int iW, iH;
    SDL_Color     couleurNoire    = {0, 0, 0, 255};
    SDL_Color     couleurBlanche  = {255, 255, 255, 255};
    SDL_Surface * surf     = TTF_RenderText_Shaded(g.font, chaine, couleurBlanche, couleurNoire);
    SDL_Texture * text     = SDL_CreateTextureFromSurface(g.renderer, surf);
    SDL_Rect rect;
   

    SDL_QueryTexture(text, NULL, NULL, &iW, &iH);

    rect.x = x;
    rect.y = y;
    rect.w = iW;
    rect.h = iH;

    SDL_RenderCopy(g.renderer, text, NULL, &rect);
}

void displayStringFINALE(gdata_t g, char * chaine, int x, int y, int RV) {

    int iW, iH;
	SDL_Color     couleurBlanche  = {255, 255, 255, 255};
    SDL_Color     couleurRouge    = {255, 0, 0, 255};
    SDL_Color     couleurVert  = {0, 255, 0, 255};
    SDL_Color couleur;
	if (RV==1){
		couleur = couleurVert;
	}
	else{
		couleur = couleurRouge;
	}

	g.font = TTF_OpenFont("Arial.ttf", 100);

    SDL_Surface * surf     = TTF_RenderText_Shaded(g.font, chaine, couleur, couleurBlanche);
    SDL_Texture * text     = SDL_CreateTextureFromSurface(g.renderer, surf);
    SDL_Rect rect;
   

    SDL_QueryTexture(text, NULL, NULL, &iW, &iH);

    rect.x = x;
    rect.y = y;
    rect.w = iW;
    rect.h = iH;

    SDL_RenderCopy(g.renderer, text, NULL, &rect);
}

