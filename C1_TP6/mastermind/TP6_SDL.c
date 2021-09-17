#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "SDLh.h"

//compiler avec : gcc TP6_SDL.c -o progSDL -lSDL2 -lSDL2_gfx -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_net
//gcc TP6_SDL.c init_plateau.c -o progSDL -lSDL2 -lSDL2_image -lSDL2_ttf


int main(){

  if (SDL_Init(SDL_INIT_EVERYTHING)==-1){
      fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n",SDL_GetError());
      return EXIT_FAILURE;
  }
  SDL_Window * window;
  window = SDL_CreateWindow("MASTERMIND", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
              WIDTH, HEIGHT,
              SDL_WINDOW_RESIZABLE);
  if (window == NULL){
      fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
      //on peut aussi utiliser SLD_Log()
  }
  SDL_Renderer * renderer;
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED ); /*  SDL_RENDERER_SOFTWARE */
  if (renderer == NULL) {
   fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); 
   /* faire ce qu'il faut pour quitter proprement */
  }


  initialiser_plateau(renderer);

  //SDL_RenderClear(renderer);

  /* afficher à l'ecran */
  SDL_RenderPresent(renderer);

  //SDL_Delay(2000);


  int running =1;
  SDL_Event event;
  int width; int height;

  int X; int Y; int choix=0; int ligne=0; int colonne=0;
  int finit=0;

  int solution[NB_COLONNES];
  initialiser_solution(solution);   for(int i=0;i<NB_COLONNES;i++){printf("%d ",solution[i]);}
  int proposition[NB_COLONNES];
  combinaison combi;

  while (running){
    while (SDL_PollEvent(&event)){
      switch(event.type){
        case SDL_WINDOWEVENT:
          printf("window event\n");
          switch (event.window.event){
            case SDL_WINDOWEVENT_CLOSE:  
              printf("appui sur la croix\n"); 
              break;
            case SDL_WINDOWEVENT_SIZE_CHANGED:
              width = event.window.data1;
              height = event.window.data2;
              printf("Size : %d%d\n", width, height);
              SDL_RenderPresent(renderer); //afficherEcran();
              break;
            //default: //fait completement lagger
            //  SDL_RenderPresent(renderer); //afficherEcran();
          }
          break;
        case SDL_MOUSEBUTTONDOWN:
          if (finit==0){
            X=event.button.x;
            Y=event.button.y;
            printf("Appui :%d %d\n", event.button.x, event.button.y);
            // afficherEcran() ?
            choix=selection_bouton(X,Y);          printf("%d\n",choix);
            inserer_choix(&ligne,&colonne,choix,renderer,proposition);
            verifier_proposition(choix,&ligne,&colonne,proposition,solution, &combi, renderer);
            if (combi.bienp==4){
              printf("Cest gagné\n");
              win_screen(renderer);
              finit=1;
            }
            else{
              if (ligne==10){
                printf("Cest perdu\n");
                loose_screen(renderer, solution);
                finit=1;
              }
            }
          }
          break;
        case SDL_QUIT : 
          printf("on quitte\n");    
          running = 0;
      }
    }
  SDL_Delay(1); //delai minimal
  }

  IMG_Quit();
  SDL_Quit();
  return 0;
}

void aff_bienp_malp(SDL_Renderer * renderer, int ligne, combinaison combi){
  int quatre;
  for (quatre=0;quatre<combi.malp;quatre++){
    SDL_SetRenderDrawColor(renderer, 255,255,255,0);
    rect.x = tab_coord_malp[ligne][quatre][x_coord]; rect.y = tab_coord_malp[ligne][quatre][y_coord];
    rect.w = 44.6; rect.h = 26.8;
    SDL_RenderFillRect(renderer, &rect);
  }

  for (quatre=0;quatre<combi.bienp;quatre++){
    SDL_SetRenderDrawColor(renderer, 117,255,88,0);
    rect.x = tab_coord_malp[ligne][quatre][x_coord] + 180; rect.y = tab_coord_malp[ligne][quatre][y_coord];
    rect.w = 44.6; rect.h = 26.8;
    SDL_RenderFillRect(renderer, &rect);
  }

  SDL_RenderPresent(renderer);
}

void win_screen(SDL_Renderer * renderer){
  SDL_Texture  *avatar;
  SDL_Surface *image = NULL;
  image=IMG_Load("images/gagne.png");
  //image=SDL_LoadBMP("loic.bmp"); fonction standard de la SDL2
  if(!image){
    printf("IMG_Load: %s\n", IMG_GetError());
  }
  avatar = SDL_CreateTextureFromSurface(renderer, image);
  SDL_FreeSurface(image);
  rect.x = 208.7; rect.y = 66.4;
  rect.w = 982.5; rect.h = 509.6;
  SDL_RenderCopy(renderer, avatar, NULL, &rect);
  //L'image a ete copiee dans le renderer qui sera plus tard affiche a l'ecran
  SDL_RenderPresent(renderer);
}

void loose_screen(SDL_Renderer * renderer, int solution[NB_COLONNES]){
  SDL_Texture  *avatar;
  SDL_Surface *image = NULL;
  image=IMG_Load("images/perdu.png");
  //image=SDL_LoadBMP("loic.bmp"); fonction standard de la SDL2
  if(!image){
    printf("IMG_Load: %s\n", IMG_GetError());
  }
  avatar = SDL_CreateTextureFromSurface(renderer, image);
  SDL_FreeSurface(image);
  rect.x = 208.7; rect.y = 66.4;
  rect.w = 982.5; rect.h = 509.6;
  SDL_RenderCopy(renderer, avatar, NULL, &rect);
  //L'image a ete copiee dans le renderer qui sera plus tard affiche a l'ecran

  //fond
  SDL_SetRenderDrawColor(renderer, 255, 186, 114, 0);
  rect.x = 323.2; rect.y = 474.2;
  rect.w = 674.4; rect.h = 203.6;
  SDL_RenderFillRect(renderer, &rect);

  int tab_position_solution[NB_COLONNES][2]={{357.2,519.8},
                                             {514  ,519.8},
                                             {670.9,519.8},
                                             {827.8,519.8}};

  //solution
  int k;
  for (k=0;k<=3;k++){
    SDL_SetRenderDrawColor(renderer, tab_couleurs[solution[k]][0],tab_couleurs[solution[k]][1], tab_couleurs[solution[k]][2], 0);
    rect.x = tab_position_solution[k][0]; rect.y = tab_position_solution[k][1];
    rect.w = 135.9; rect.h = 112.4;
    SDL_RenderFillRect(renderer, &rect);
  }

  SDL_RenderPresent(renderer);

}

int selection_bouton(int X, int Y){
  int choix=0;
  if (X>=1150 && X<=1350){
    if (Y>=270 && Y<=360 ){
      choix=rouge;
    }
    if (Y>=372 && Y<=462 ){
      choix=jaune;
    }
    if (Y>=474 && Y<=564 ){
      choix=vert;
    }
    if (Y>=576 && Y<=666 ){
      choix=bleu;
    }
    if (Y>=678 && Y<=768 ){
      choix=violet;
    }
    if (Y>=780 && Y<=870 ){
      choix=orange;
    }
    if (Y>=37 && Y<=127 ){
      choix=retour;
    }
    if (Y>=140 && Y<=230 ){
      choix=valider;
    }
  }
  return choix;
}


void inserer_choix(int * ligne, int * colonne, int choix, SDL_Renderer * renderer, int proposition[NB_COLONNES]){
  if (1<=choix && choix<=6 && *ligne<=10){
    if (*colonne<=3){
      SDL_SetRenderDrawColor(renderer, tab_couleurs[choix][0], tab_couleurs[choix][1], tab_couleurs[choix][2], 0);
      rect.x = coord_colonne[*colonne]; rect.y = coord_ligne[*ligne];
      rect.w = 100; rect.h = 60;
      SDL_RenderFillRect(renderer, &rect);
      proposition[*colonne]=choix;
      *colonne+=1;
    }
  }
  if (choix==10 && 0<*colonne && *ligne<=10){
    printf("retour\n");
    *colonne-=1;
    SDL_SetRenderDrawColor(renderer, tab_couleurs[resetViolet][0], tab_couleurs[resetViolet][1], tab_couleurs[resetViolet][2], 0);
    rect.x = coord_colonne[*colonne]; rect.y = coord_ligne[*ligne];
    rect.w = 100; rect.h = 60;
    SDL_RenderFillRect(renderer, &rect);
    //proposition[*colonne]=0;
  }
  SDL_RenderPresent(renderer);
}


/*
typedef struct couleurs{
  int r;
  int g;
  int b;
} couleur;

couleur rouge = {255,0,0};
couleur vert = {0,255,0};
couleur bleu = {0,0,255};
couleur jaune = {255,255,0};
couleur violet = {255,0,255};
couleur orange = {255,59,0};
*/