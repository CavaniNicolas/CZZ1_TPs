#ifndef hall_of_fame_h
#define hall_of_fame_h

/* DECLARATION DES TYPES PERSONNELS */
// et de leur typedef si besoin

#define TAILLE_MAX 50

struct donnee{
   int score;
   char jeu[70];
   char alias[30];
   struct donnee * suiv;
};

typedef struct donnee donnee_t;

/* DECLARATIONS DES METHODES */
void afficherDonnee(FILE *, donnee_t);
void saisirDonnee (FILE * , donnee_t *);
void removeEnter(char * chaine);

// mettre ici les autres declarations
donnee_t editerStruct(donnee_t);
int tableauFromFilename(char *, donnee_t []);


//fct de listeChainee.c
donnee_t * creerListe(void);
void ajouterDebut(donnee_t **, int, char [], char []);
void ajouterFin(donnee_t **, int, char *, char []);

void afficherListe(donnee_t *);
void libererListe(donnee_t **);

//fct de listeChainee2.c
void menu(donnee_t **);
void user_input(donnee_t *);
donnee_t * afficherUnSeul_renvoyerAdresse(donnee_t *, int);
void listeChainee_fromFileByName(char *, donnee_t **);
void supprimer_liste(donnee_t **);
void ecraser_sauvegarde(char *, donnee_t *);
//fonctions inutiles a supprimer
void test_strcpy();
void viderBuffer();

#endif