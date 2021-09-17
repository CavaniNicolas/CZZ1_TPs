#ifndef flooditH
#define flooditH

#define COULEURS 6
#define TAILLE 12
#define TENTATIVES 24

void init_plateau(int[TAILLE][TAILLE]);
void afficher_plateau(int[TAILLE][TAILLE],int);
int fin(int[TAILLE][TAILLE]);

void choisir_couleur(int *);
void remplir(int,int,int[TAILLE][TAILLE],int,int);
void resultat(int);


void viderBuffer();
int lire(char *, int);
long lireInt();

#endif