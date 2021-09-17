#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <stdio.h>
#include <stdlib.h>
#include "calcSDL.h"
#include "calculator.h"

int init_SDL(liste_2pointeurs liste, int taille, double a, double b, OP op){
	gdata_t        g;
	int running  = 1;
	int graphics = 1;


	SDL_Event      event;

	g.window     = 0;
	g.renderer   = 0;
	g.font       = 0;
	g.width      = 1200;
	g.height     = 900;
	g.X 		 = 0;
	g.Y 		 = 0;

	if (SDL_Init(SDL_INIT_VIDEO) == -1) {
		fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
		graphics = 0;
	}
	else {
		g.window = SDL_CreateWindow("Courbe Fonction", SDL_WINDOWPOS_CENTERED, 30, 
						g.width, g.height, SDL_WINDOW_SHOWN |  SDL_WINDOW_RESIZABLE); 

		if (g.window == 0) {
			fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); 
			graphics = 0;
		}
		else {
			g.renderer = SDL_CreateRenderer(g.window, -1, SDL_RENDERER_ACCELERATED ); /* | SDL_RENDERER_PRESENTVSYNC */
			if (g.renderer == 0) {
				fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); 
				graphics = 0;
			}
			else {
				if (TTF_Init() != 0){
					fprintf(stderr, "Erreur d'initialisation TTF : %s\n", TTF_GetError()); 
					graphics = 0;
				}
				else {
					g.font = TTF_OpenFont("Arial.ttf", 20);

					if (!g.font) {
						graphics = 0; 
						fprintf(stderr, "La police ARIAL n'est pas chargee\n"); 
					}
				}
			}
		}
	}

	if (graphics==0){
		if (g.font     != 0) TTF_CloseFont(g.font);
		if (g.renderer != 0) SDL_DestroyRenderer(g.renderer);
		if (g.window   != 0) SDL_DestroyWindow(g.window);
		TTF_Quit();
		SDL_Quit();
		return 0;
	} 


	displayGraph(g, liste, taille, a, b, op);

	while (running) {
		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_WINDOWEVENT:
					//printf("window event\n");
					switch (event.window.event)  {
						case SDL_WINDOWEVENT_CLOSE:  
							printf("appui sur la croix\n");
							break;
						case SDL_WINDOWEVENT_SIZE_CHANGED:
							// g.width  = event.window.data1;
							// g.height = event.window.data2;
							// printf("Size : %d%d\n", g.width, g.height);
							break;
						case SDL_WINDOWEVENT_MOVED:
							SDL_RenderPresent(g.renderer);
							break;
						default:
							SDL_RenderPresent(g.renderer);
							break;
					}   
					break;
				case SDL_MOUSEBUTTONDOWN:
					g.X=event.button.x;
					g.Y=event.button.y;
					printf("Appui :%d %d\n", event.button.x, event.button.y);
					break;
				case SDL_QUIT :
					printf("on quitte\n");    
					running = 0;
			}
		}
		SDL_Delay(1);
	}
	TTF_CloseFont(g.font);
	SDL_DestroyRenderer(g.renderer);
	SDL_DestroyWindow(g.window);
	TTF_Quit();
	SDL_Quit();
	return 0;
}

void displayString(gdata_t g, char * chaine_Aff, int taille_Police, int x, int y, CO coul) {

	int iW, iH;
	SDL_Color     couleurBlanc    = {255, 255, 255, 255};
	SDL_Color     couleurNoir     = {0 , 0, 0, 255};
	SDL_Color     couleurRouge    = {255, 0, 0, 255};
	SDL_Color     couleurVert     = {0, 255, 0, 255};
	SDL_Color     couleurBleu     = {0, 0, 255, 255};
	SDL_Color couleur;
	switch (coul){
		case blanc:
			couleur=couleurBlanc;
			break;
		case noir:
			couleur=couleurNoir;
			break;
		case rouge:
			couleur=couleurRouge;
			break;
		case vert:
			couleur=couleurVert;
			break;
		case bleu:
			couleur=couleurBleu;
			break;
	}

	g.font = TTF_OpenFont("Arial.ttf", taille_Police);

	SDL_Surface * surf     = TTF_RenderText_Shaded(g.font, chaine_Aff, couleur, couleurBlanc);
	SDL_Texture * text     = SDL_CreateTextureFromSurface(g.renderer, surf);
	SDL_Rect rect;


	SDL_QueryTexture(text, NULL, NULL, &iW, &iH);

	rect.x = x;
	rect.y = y;
	rect.w = iW;
	rect.h = iH;

	SDL_RenderCopy(g.renderer, text, NULL, &rect);
}


void displayGraph(gdata_t g, liste_2pointeurs liste, int taille_liste, double a, double b, OP op) {                          
	char chaine[255];
	double  maxx = 1000;
	double  maxy = 700;
	int  i = 0;
	double ecartx = (b-a);
	double Vmin; double Vmax;
	liste_min_max(liste, &Vmin, &Vmax);
	double ecarty = (Vmax-Vmin);
	//printf("ecartx %f ecarty%f vmax%f vmin%f\n", ecartx,ecarty,Vmax,Vmin);

	cellule * cour = liste.tete;
	double val;
	double ratioP;

	SDL_Rect r;
	SDL_SetRenderDrawColor(g.renderer, 255, 255, 255, 255);
	SDL_RenderClear(g.renderer);
	SDL_SetRenderDrawColor(g.renderer, 150, 0, 0, 255);

	printf("Calcul en cour\n");
	while(cour!=NULL){
		val = strtod(cour->ligne,NULL);
		ratioP = (100*(val-Vmin))/ecarty;
		//printf("val = %f   % P = %f\n",val,ratioP);

		r.x = 120+(maxx/taille_liste*i);
		r.y = 800-(ratioP)*(maxy/100);
		r.w = 3;
		r.h = 3;
		SDL_RenderFillRect(g.renderer, &r);

		// sprintf(chaine, "%2d", i);
		// displayString(g, chaine, 60, (int)(maxx/22.0*(i+1)-4), 420, noir);

		// if (h[i]>0) {
		// 	sprintf(chaine, "%d", h[i]);
		// 	displayString(g, chaine, 60, (int)(maxx/22.0*(i+1)-4), 75, noir);
		// }
		cour=cour->suiv;
		i++;
	}

	SDL_SetRenderDrawColor(g.renderer, 0, 0, 0, 255);

	//CALCULS FAUX
	for (i=0;i<21;i++){
		sprintf(chaine, "%.1f", (float)(a+(i*ecartx/20)));
		displayString(g,chaine,20,120+(i*maxx/20),830,bleu); // valeurs abscisses

		r.x = 120+(i*maxx/20); r.y = 820;
		r.w = 2; r.h = 8;
		SDL_RenderFillRect(g.renderer, &r);  // graduations abscisses
		r.x = 120+(i*maxx/20); r.y = 100;
		r.w = 1; r.h = 720;
		SDL_RenderFillRect(g.renderer, &r); // lignes verticales
	}
	for (i=0;i<21;i++){
		sprintf(chaine, "%.2f", (float)(Vmin+(i*ecarty/20)));
		displayString(g,chaine,20,40,800-(i*maxy/20),bleu); // valeurs ordonnées

		r.x = 92; r.y = 800-(i*maxy/20);
		r.w = 8; r.h = 2;
		SDL_RenderFillRect(g.renderer, &r);  // graduations ordonnées
		r.x = 100; r.y = 800-(i*maxy/20);
		r.w = 1020; r.h = 1;
		SDL_RenderFillRect(g.renderer, &r); // lignes horizontales
	}

	displayString(g,"x",30,1160,790,rouge);
	r.x = 100; r.y = 810;
	r.w = 1040; r.h = 3;
	SDL_RenderFillRect(g.renderer, &r); // axe abscisses

	strcpy(chaine,OPER_NAMES[op]);
	displayString(g,chaine,30,90,45,rouge);
	r.x = 100; r.y = 80;
	r.w = 3; r.h = 730;
	SDL_RenderFillRect(g.renderer, &r); // axe ordonnées

	SDL_RenderPresent(g.renderer);
}

void liste_min_max(liste_2pointeurs liste, double * Vmin, double * Vmax){
	cellule * cour = liste.tete;
	double val = atof(cour->ligne);
	*Vmin = *Vmax = val;

	while (cour!=NULL){
		val = atof(cour->ligne);
		if (val<*Vmin){
			*Vmin=val;
		}
		if (val>*Vmax){
			*Vmax=val;
		}
		cour=cour->suiv;
	}
}