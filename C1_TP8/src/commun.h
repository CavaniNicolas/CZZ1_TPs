#ifndef communH
#define communH

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

/*
 * strucure cle (nom), valeur (note)
 */

extern int ERROR;

#define ERROR_OK          0
#define ERROR_LIST_ALLOC  1
#define ERROR_FILE        1

typedef struct cell_s {
    char key[30];
    int  value;
    struct cell_s * nk, *nv;
} cell_t;

typedef struct list_s {
    cell_t * key;
    cell_t * value;
} list_t;


typedef struct gdata_s {
    SDL_Window   * window;
    SDL_Renderer * renderer;
    TTF_Font     * font;       
    int            width;
    int            height;
} gdata_t;

#define HISTOSIZE 21

/* #define DEBUG */

#ifdef DEBUG
    #define LOG(A) printf A
#else
    #define LOG(A)
#endif

typedef int histogram_t[HISTOSIZE];

#endif