#ifndef flooditH
#define flooditH

#define COULEURS 6
#define TAILLE 12
#define TENTATIVES 24
#define PALETTE 4
//palettes: 1  2  3  4  51  52  53  6
//palettes ptrs: 0  1  2  3  4  5  6  7

enum couleurs{
	beige,
	bleuC,
	rouge,
	vert,
	jauneorange,
	violetC
};

typedef struct gdata_s {
    SDL_Window   * window;
    SDL_Renderer * renderer;
    TTF_Font     * font;
    int            width;
    int            height;
    int			   X;
    int 		   Y;
} gdata_t;


void choisir_palette();
void init_plateau(int [TAILLE][TAILLE]);
void afficher_plateau(SDL_Renderer *, int[TAILLE][TAILLE]);
void afficher_compteur(gdata_t, int);
int fin(int [TAILLE][TAILLE]);
int choisir_couleur(int, int, int [TAILLE][TAILLE]);
int remplir_plateau(int *, int, int, int [TAILLE][TAILLE], int, int);
void remplir(int, int, int [TAILLE][TAILLE], int, int);
int verifier_compteur(int);
void message_fin(int, gdata_t);

void displayString(gdata_t, char *, int, int);
void displayStringFINALE(gdata_t, char *, int, int, int);

#endif