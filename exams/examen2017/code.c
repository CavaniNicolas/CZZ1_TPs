#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "code.h"

double minimum(double * tab, int taille) {
	int i=1; double min=tab[0];
	for (i=1;i<taille;i++){
		if (tab[i]<=min){
			min=tab[i];
		}
	}
	return min;
}

double maximum(double * tab, int taille) {
	int i=1; double max=tab[0];
    for (i=1;i<taille;i++){
		if (tab[i]>=max){
			max=tab[i];
		}
	}
    return max;
}

double moyenne(double * tab, int taille) {
    double S=somme(tab,taille);
    return S/taille;
}



double somme(double * tab, int taille ) {
	int i=0; double S=0;
	for (i=0;i<taille;i++){
		S+=tab[i];
	}
	return S;
}

int lecture(char * nom, donnee_t ** ptab) {
	FILE * file = NULL;
	file = fopen(nom,"r");
	char ligne[255];

	int i=0;
	int taille=0;

	if (file!=NULL){

		fgets(ligne,255,file);
		taille=atoi(ligne);

		donnee_t * tab_ligne = (donnee_t *)malloc(taille*sizeof(donnee_t));

		if (tab_ligne!=NULL){
			for (i=0;i<taille;i++){
				fscanf(file,"%d",&tab_ligne[i].annee);
				fscanf(file,"%lf",&tab_ligne[i].valeur);

				//printf("%d\n",tab_ligne[i*sizeof(donnee_t)].annee);
				//printf("%lf\n",tab_ligne[i*sizeof(donnee_t)].valeur);

			}
		}

	*ptab=tab_ligne;
	fclose(file);
	}

	return taille;
}


void conversion_to_double(donnee_t * tabs, double **tabd, int taille) {
	double * tab_val = (double *)malloc(taille*sizeof(double));
	if (tab_val!=NULL){
		int i=0;
		for (i=0;i<taille;i++){
			tab_val[i]=tabs[i].valeur;
		}
		*tabd=tab_val;
	}
}

int * affichage(donnee_t * tab, int taille) {
	double * tab_val = NULL;
	conversion_to_double(tab, &tab_val, taille);
	double min=minimum(tab_val,taille);
	double max=maximum(tab_val,taille);

	int * etoiles = (int *)malloc(taille*sizeof(int));
	if (etoiles!=NULL){

		int i=0;
		for (i=0;i<taille;i++){
			if (40*(tab_val[i]-min)/(max-min)==0 && tab_val[i]!=0){
				etoiles[i]=1;
			}
			else{
				etoiles[i]=40*(tab_val[i]-min)/(max-min);
			}
			printf("%f\n",40*(tab_val[i]-min)/(max-min));
		}
	}

return etoiles;
}
