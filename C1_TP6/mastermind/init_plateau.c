#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "SDLh.h"

int coul_fond_reponse[]={132,86,83};

int coord_colonne[]={60,220,380,550};
int coord_ligne[]={80,160,240,320,400,480,560,640,720,800};

int tab_couleurs[8][3]  =  {{255,177,177}, //beige
							{175,15 ,15 }, //rouge
							{251,211,37 }, //jaune
							{33 ,195,15 }, //vert
							{50 ,59 ,209}, //bleu
							{170,15 ,196}, //violet
							{235,76 ,15 }, //orange
							{200,200,255}};//resetViolet



int tab_coord_malp[NB_LIGNES][NB_COLONNES][2] = {
						{ {753,83}   ,{833.4,83}   ,{753,118.8},{833.4,118.8} },
						{ {753,162}  ,{833.4,162}  ,{753,197.8},{833.4,197.8} },
						{ {753,241.1},{833.4,241.1},{753,276.9},{833.4,276.9} },
						{ {753,320.1},{833.4,320.1},{753,355.9},{833.4,355.9} },
						{ {753,399.2},{833.4,399.2},{753,434.9},{833.4,434.9} },
						{ {753,478.2},{833.4,478.2},{753,514}  ,{833.4,514}   },
						{ {753,557.3},{833.4,557.3},{753,593}  ,{833.4,593}   },
						{ {753,636.3},{833.4,636.3},{753,672.1},{833.4,672.1} },
						{ {753,715.4},{833.4,715.4},{753,751.1},{833.4,751.1} },
						{ {753,794.4},{833.4,794.4},{753,830.2},{833.4,830.2} } };



void initialiser_plateau(SDL_Renderer * renderer){
	//test pour initialiser les images
	int flags=IMG_INIT_JPG|IMG_INIT_PNG;
	int initted= 0;
	initted = IMG_Init(flags);
	if((initted&flags) != flags){
		printf("IMG_Init: Impossible d'initialiser le support des formats JPG et PNG requis!\n");
		printf("IMG_Init: %s\n", IMG_GetError());
	}


	//fond
	SDL_SetRenderDrawColor(renderer, 50, 0, 40, 0);
	rect.x = rect.y = 0;
	rect.w = 1400; rect.h = 900;
	SDL_RenderFillRect(renderer, &rect);

	//titre
	SDL_Texture  *avatar;
	SDL_Surface *image = NULL;
	image=IMG_Load("images/titre.png");
	//image=SDL_LoadBMP("loic.bmp"); fonction standard de la SDL2
	if(!image){
		printf("IMG_Load: %s\n", IMG_GetError());
	}
	avatar = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);
	rect.x = 505; rect.y = 16;
	rect.w = 390; rect.h = 44;
	SDL_RenderCopy(renderer, avatar, NULL, &rect);
	//L'image a ete copiee dans le renderer qui sera plus tard affiche a l'ecran


	//initialiser boutons

	//retour
	SDL_SetRenderDrawColor(renderer, tab_couleurs[beige][0], tab_couleurs[beige][1], tab_couleurs[beige][2], 0);
	rect.x = 1150; rect.y = 37;
	rect.w = 200; rect.h = 90;
	SDL_RenderFillRect(renderer, &rect);

	image=IMG_Load("images/retour.png");
	if(!image){
		printf("IMG_Load: %s\n", IMG_GetError());}
	avatar = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);
	rect.x = 1178; rect.y = 48;
	rect.w = 139; rect.h = 67;
	SDL_RenderCopy(renderer, avatar, NULL, &rect);



	//valider
	SDL_SetRenderDrawColor(renderer, tab_couleurs[beige][0], tab_couleurs[beige][1], tab_couleurs[beige][2], 0);
	rect.x = 1150; rect.y = 140;
	rect.w = 200; rect.h = 90;
	SDL_RenderFillRect(renderer, &rect);

	image=IMG_Load("images/valider.png");
	if(!image){
		printf("IMG_Load: %s\n", IMG_GetError());}
	avatar = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);
	rect.x = 1191; rect.y = 143;
	rect.w = 119; rect.h = 84;
	SDL_RenderCopy(renderer, avatar, NULL, &rect);




	//rouge
	SDL_SetRenderDrawColor(renderer, tab_couleurs[rouge][0], tab_couleurs[rouge][1], tab_couleurs[rouge][2], 0);
	rect.x = 1150; rect.y = 270;
	rect.w = 200; rect.h = 90;
	SDL_RenderFillRect(renderer, &rect);

	//jaune
	SDL_SetRenderDrawColor(renderer, 251, 211, 37, 0);
	rect.x = 1150; rect.y = 372;
	rect.w = 200; rect.h = 90;
	SDL_RenderFillRect(renderer, &rect);

	//vert
	SDL_SetRenderDrawColor(renderer, 33, 195, 15, 0);
	rect.x = 1150; rect.y = 474;
	rect.w = 200; rect.h = 90;
	SDL_RenderFillRect(renderer, &rect);

	//bleu
	SDL_SetRenderDrawColor(renderer, 50, 59, 209, 0);
	rect.x = 1150; rect.y = 576;
	rect.w = 200; rect.h = 90;
	SDL_RenderFillRect(renderer, &rect);

	//violet
	SDL_SetRenderDrawColor(renderer, 170, 15, 196, 0);
	rect.x = 1150; rect.y = 678;
	rect.w = 200; rect.h = 90;
	SDL_RenderFillRect(renderer, &rect);

	//orange
	SDL_SetRenderDrawColor(renderer, 235, 76, 15, 0);
	rect.x = 1150; rect.y = 780;
	rect.w = 200; rect.h = 90;
	SDL_RenderFillRect(renderer, &rect);


	//initialiser plateau
	//fond
	SDL_SetRenderDrawColor(renderer, 255, 218, 179, 0);
	rect.x = 30; rect.y = 70;
	rect.w = 650; rect.h = 800;
	SDL_RenderFillRect(renderer, &rect);


	//colonne 1
	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 60; rect.y = 80;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 60; rect.y = 160;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 60; rect.y = 240;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 60; rect.y = 320;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 60; rect.y = 400;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 60; rect.y = 480;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 60; rect.y = 560;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 60; rect.y = 640;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 60; rect.y = 720;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 60; rect.y = 800;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);



	//colonne 2
	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 220; rect.y = 80;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 220; rect.y = 160;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 220; rect.y = 240;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 220; rect.y = 320;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 220; rect.y = 400;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 220; rect.y = 480;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 220; rect.y = 560;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 220; rect.y = 640;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 220; rect.y = 720;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 220; rect.y = 800;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);



	//colonne 3
	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 380; rect.y = 80;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 380; rect.y = 160;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 380; rect.y = 240;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 380; rect.y = 320;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 380; rect.y = 400;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 380; rect.y = 480;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 380; rect.y = 560;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 380; rect.y = 640;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 380; rect.y = 720;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 380; rect.y = 800;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);



	//colonne 4
	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 550; rect.y = 80;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 550; rect.y = 160;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 550; rect.y = 240;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 550; rect.y = 320;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 550; rect.y = 400;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 550; rect.y = 480;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 550; rect.y = 560;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 550; rect.y = 640;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 550; rect.y = 720;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);

	SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
	rect.x = 550; rect.y = 800;
	rect.w = 100; rect.h = 60;
	SDL_RenderFillRect(renderer, &rect);









	//reponses

	//fond
	SDL_SetRenderDrawColor(renderer, coul_fond_reponse[0], coul_fond_reponse[1], coul_fond_reponse[2], 0);
	rect.x = 726; rect.y = 70;
	rect.w = 360; rect.h = 800;
	SDL_RenderFillRect(renderer, &rect);

	//barre
	SDL_SetRenderDrawColor(renderer, 0,0,0,0);
	rect.x = 903.9; rect.y = 70;
	rect.w = 4.2; rect.h = 800;
	SDL_RenderFillRect(renderer, &rect);




	int ligne, quatre;
	//mal placés
	for (ligne=0;ligne<10;ligne++){
		for (quatre=0;quatre<4;quatre++){
				SDL_SetRenderDrawColor(renderer, 78,0,29,0);
				rect.x = tab_coord_malp[ligne][quatre][x_coord]; rect.y = tab_coord_malp[ligne][quatre][y_coord];
				rect.w = 44.6; rect.h = 26.8;
				SDL_RenderFillRect(renderer, &rect);
		}
	}


	//bien placés
	for (ligne=0;ligne<10;ligne++){
		for (quatre=0;quatre<4;quatre++){
				SDL_SetRenderDrawColor(renderer, 78,0,29,0);
				rect.x = tab_coord_malp[ligne][quatre][x_coord] + 180; rect.y = tab_coord_malp[ligne][quatre][y_coord];
				rect.w = 44.6; rect.h = 26.8;
				SDL_RenderFillRect(renderer, &rect);
		}
	}



}