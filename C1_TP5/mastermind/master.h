#ifndef master_h
#define master_h

/* DECLARATION DES CONSTANTES SYMBOLIQUES */

#define NB_LIGNES 10
#define NB_COLONNES 4
#define NB_COULEURS 6

/* DECLARATION DES TYPES PERSONNELS */
// et de leur typedef si besoin
#define STRUCTURE
typedef struct {
    int bienp;
    int malp;
} combinaison;

/* DECLARATIONS DES METHODES */

void initialiser_solution(int [NB_COLONNES]);
void initialiser_plateau (int [NB_LIGNES][NB_COLONNES+2]);
combinaison compiler_proposition(int [NB_COLONNES], int [NB_COLONNES]);
void debugnico(int [NB_COLONNES], int [NB_COLONNES]);

void afficher_plateau(int [NB_LIGNES][NB_COLONNES+2]);
void user_proposition(int [NB_COLONNES]);
int remplir_plateau(int [NB_LIGNES][NB_COLONNES+2], int [NB_COLONNES],combinaison,int);

void afficher_sol_prop(int [NB_COLONNES]);

int mastermind();
void viderBuffer();
#endif