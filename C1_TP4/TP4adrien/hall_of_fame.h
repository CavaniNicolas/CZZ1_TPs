#ifndef hall_of_fame_h
#define hall_of_fame_h

#define TAILLE_MAX 50

/* DECLARATION DES TYPES PERSONNELS */
// et de leur typedef si besoin

struct donnee
{
    int score;
    char jeu [100];
    char alias [40];
};

typedef struct donnee donnee_t;

/* DECLARATIONS DES METHODES */
void afficherDonnee(FILE *, donnee_t);
void saisirDonnee (FILE * , donnee_t *);
void creationdonnee ();
void RemoveEnter (char * chaine);
void AffichageChaine(char * chaine);
// mettre ici les autres declarations

#endif