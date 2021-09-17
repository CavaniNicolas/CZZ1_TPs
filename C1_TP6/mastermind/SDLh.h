#ifndef SDLh
#define SDLh

#define WIDTH 1400
#define HEIGHT 900

#define NB_LIGNES 10
#define NB_COLONNES 4
#define NB_COULEURS 6

typedef struct combinaison{
    int bienp;
    int malp;
} combinaison;

void initialiser_solution(int [NB_COLONNES]);
combinaison compiler_proposition(int [NB_COLONNES], int [NB_COLONNES]);


SDL_Rect rect;
//structure pour faire des rectangles


extern int coord_ligne[];
extern int coord_colonne[];

extern int coul_carre_plateau[];
extern int coul_fond_reponse[];

extern int tab_couleurs[8][3];
//matrice couleurs des boutons

extern int tab_coord_malp[10][4][2];
//matrice coord malp
//matrice coord bienp = matrice coord malp + 180 sur tous les x
enum xy{
	x_coord,y_coord
};


void initialiser_plateau(SDL_Renderer *);
int selection_bouton(int, int);
void inserer_choix(int *, int *, int, SDL_Renderer *, int[]);
void verifier_proposition(int, int *, int *, int[], int[], combinaison *, SDL_Renderer *);

void win_screen(SDL_Renderer *);
void loose_screen(SDL_Renderer *, int [NB_COLONNES]);

void aff_bienp_malp(SDL_Renderer *,int,combinaison);

enum couleur_boutons{
	beige,
	rouge,
	jaune,
	vert,
	bleu,
	violet,
	orange,
	resetViolet,
	retour=10,
	valider
};

#endif