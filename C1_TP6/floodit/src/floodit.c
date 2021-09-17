#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <stdio.h>
#include <stdlib.h>
#include "floodit.h"

int main(){
	gdata_t        g;
	int running  = 1;
	int graphics = 1;


	SDL_Event      event;

	g.window     = 0;
	g.renderer   = 0;
	g.font       = 0;
	g.width      = 900;
	g.height     = 950;
	g.X 		 = 0;
	g.Y 		 = 0;

	if (SDL_Init(SDL_INIT_VIDEO) == -1) {
		fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
		graphics = 0;
	}
	else {
		g.window = SDL_CreateWindow("FLOODIT", SDL_WINDOWPOS_CENTERED, 30, 
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

	int compteur=0;
	char texte[15];
	int plateau[TAILLE][TAILLE];
	int choix;
	int finit = 0;

	choisir_palette();

	init_plateau(plateau);
	afficher_plateau(g.renderer, plateau);
	afficher_compteur(g, compteur);

	sprintf(texte,"Coups Max : %d",TENTATIVES);
	displayString(g, texte, 50, 20);
	displayString(g,"FLOOD IT",400,30);

	SDL_RenderPresent(g.renderer);

	while (running) {

		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_WINDOWEVENT:
					printf("window event\n");
					switch (event.window.event)  {
						case SDL_WINDOWEVENT_CLOSE:  
							printf("appui sur la croix\n");
							break;
						case SDL_WINDOWEVENT_SIZE_CHANGED:
							g.width  = event.window.data1;
							g.height = event.window.data2;
							printf("Size : %d%d\n", g.width, g.height);
							break;
						// default:
						// 	printf("evenenent window non pris en compte\n");
					}   
					break;
				case SDL_MOUSEBUTTONDOWN:
					if (!finit){
						g.X=event.button.x;
						g.Y=event.button.y;
						printf("Appui :%d %d\n", event.button.x, event.button.y);
						choix=choisir_couleur(g.X,g.Y,plateau);
						if (remplir_plateau(&compteur, plateau[0][0],choix,plateau,0,0)){
							afficher_plateau(g.renderer,plateau);
							afficher_compteur(g, compteur);
							SDL_RenderPresent(g.renderer);
						}
						finit=verifier_compteur(compteur);
						finit=fin(plateau);
						if (finit){
							message_fin(compteur,g);
						}
					}
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
