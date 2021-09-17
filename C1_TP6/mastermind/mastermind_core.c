#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <stdlib.h>
#include <stdio.h>
#include "time.h"
#include "SDLh.h"

void initialiser_solution(int solution[NB_COLONNES]) {
   srand(time(NULL));
   for (int i=0;i<NB_COLONNES;i++){
      solution[i]=rand()%NB_COULEURS+1;
   }
}

void verifier_proposition(int choix, int * ligne, int * colonne, int proposition[NB_COLONNES], int solution[NB_COLONNES], combinaison * combi, SDL_Renderer * renderer){
  printf("on passe par la\n");
  printf("colonne %d\n",*colonne);
  printf("ligne %d\n",*ligne);

  if (choix==11 && *colonne==4){
    *combi=compiler_proposition(proposition, solution);
    printf("on verifie la proposition\n");
    
    aff_bienp_malp(renderer,*ligne,*combi);

    printf("mal p =%d\n",combi->malp);
    printf("bien p =%d\n",combi->bienp);
    *colonne=0;
    *ligne+=1;
  }
}

combinaison compiler_proposition(int proposition [NB_COLONNES], int solution [NB_COLONNES]){
	combinaison c;
	c.bienp=c.malp=0;
	int copySol[NB_COLONNES];
	int copyProp[NB_COLONNES];
	for (int copy=0;copy<NB_COLONNES;copy++){
		copySol[copy]=solution[copy];
		copyProp[copy]=proposition[copy];
	}

	for (int i=0;i<NB_COLONNES;i++){
		if (copyProp[i]==copySol[i]){
			c.bienp++;
			copySol[i]=0;
			copyProp[i]=0;
		}
	}

	for (int i=0;i<NB_COLONNES;i++){
		for (int j=0;j<NB_COLONNES;j++){
			if (copyProp[i]!=0 && copyProp[i]==copySol[j]){
				c.malp++;
				copySol[j]=0;
				copyProp[i]=0;
				//debugnico(copyProp,copySol);
			}
		}
	}
	return c;
}