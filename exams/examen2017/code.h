#ifndef __CORRECTION_EXAM_ZZ1__
#define __CORRECTION_EXAM_ZZ1__

/*
 * DEFINITIONS IMPORTANTES POUR L'EXAMEN 
 */

#define LARGEUR 40

typedef struct donnee {
   int    annee;
   double valeur;
} donnee_t;


double maximum   (double * , int );
double minimum   (double * , int );
double moyenne   (double * , int );
double somme     (double * , int );

int    lecture             (char *   , donnee_t **); 
void   conversion_to_double(donnee_t * , double **, int);

int *  affichage(donnee_t *, int);



#endif