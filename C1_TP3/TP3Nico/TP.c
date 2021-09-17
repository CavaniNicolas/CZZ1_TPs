#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "teZZt.h"
#include "vecteur.h"


typedef float * VecteurType;

void vecteurToFile(FILE * flux, VecteurType vecteur, int ordre);
//vecteurToFile(stdout, vecteur, ordre);

void vecteurToFile(FILE * flux, VecteurType vecteur, int ordre){
    int i=0;
    for (i=0;i<ordre;i++){
       fprintf(flux,"%.3f ", *(vecteur+i));
    }
}




VecteurType vecteurFromFileByName(const char * nom_fic, int * p_ordre){
    FILE * fichier = NULL;
    fichier = fopen(nom_fic, "r");

    int ordre; float temp;
    VecteurType vecteur=NULL;

    if (fichier != NULL){ // if (fichier){}
        printf("fichier ouvert\n");
        fscanf(fichier, "%d", &ordre);
        printf("%d",ordre);
        * p_ordre=ordre;
        
        vecteur=(float *)malloc(ordre*sizeof(float));
        /*
        int i=0;
        for (i=0;i<ordre;i++){
            fscanf(fichier,"%f",&temp);
            vecteur[i]=temp;
        }*/

        int i=0;
        while (!feof(fichier)){
            fscanf(fichier,"%f",&temp);
            vecteur[i]=temp;
            i++;
        }

    }
/*
        char * contenue = malloc(sizeof(char)*1000);
        fscanf(fichier, "%c" ,contenue);
        printf("%c\n")
*/

    else{
        printf("fichier NULL");
        
    }
    fclose(fichier);
    return vecteur;
}


/*
{
    int temp;

    FILE * fichier = fopen("chat.txt", "r");
        while (!feof(fichier))
        {
            fscanf(fichier, "%d", &temp);
            printf("%d", temp);
        }
}
*/

