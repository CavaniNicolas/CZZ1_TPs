#ifndef calculatorH
#define calculatorH
#include <stdlib.h>


typedef enum ope{
	NONE, ID, SIN, COS, LOG, EXP
} OP;

extern char const * OPER_NAMES[];

/*Declarations_Fonctions*/

// identificaition ()
OP identification(char *);

// evalf()
double evalf(double, OP);

// calcul()
// In : Deux entiers : Interval [a,b]
//      Entier Delta
//      OP opération, fonction à calculer pour les valeurs de l'interval
//      char * : nom du fichier dans lequel ecrire les valeurs
// Out: Calcul les valeurs et les ecrit dans le fichier
void calcul(double, double, double, OP, char *);

// saisie d'un chiffre en chaine de charactere et le transforme en double
void saisir_chiffre(double *);

// saisie de l'operation en chaine de charactere et enlève le \n indésirable
void saisir_operation(char *);

// saisie de l'interval et de delta (utilise saisir_chiffre())
void saisir_interval(double *, double *, double *);




double evalp(double, OP);

double identite(double);

double erreur (double);


/*Fin_Declarations_Fonctions*/

#endif