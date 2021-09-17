#ifndef calcSDL_H
#define calcSDL_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "fic2LC.h"
#include "calculator.h"


typedef enum coul{
	blanc=0, noir, rouge, vert, bleu
} CO;

typedef struct gdata_s {
    SDL_Window   * window;
    SDL_Renderer * renderer;
    TTF_Font     * font;
    int            width;
    int            height;
    int			   X;
    int 		   Y;
} gdata_t;

/*Declarations_Fonctions*/

int init_SDL(liste_2pointeurs, int, double, double, OP);

void displayGraph(gdata_t, liste_2pointeurs, int, double, double, OP);

void displayString(gdata_t, char *, int, int, int, CO);

void liste_min_max(liste_2pointeurs, double *, double *);

/*Fin_Declarations8Fonctions*/

#endif
