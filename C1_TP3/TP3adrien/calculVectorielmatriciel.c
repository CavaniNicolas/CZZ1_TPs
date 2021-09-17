#include<stdio.h>
#include<stdlib.h>

typedef float * VecteurType;

void vecteurToFile (FILE * flux, VecteurType V, int n){
    int i;
    fprintf(flux, "[ ");
    for (i=0; i<n; i++){
        fprintf(flux, "%.3f ", *(V+i));
    }
    fprintf(flux, "]");
}


float * vecteurFromFileByName (char * nomFichier, int * n){
    FILE * fichier = NULL;
    fichier = fopen(nomFichier, "r");

    if (fichier != NULL ){
        printf("Fichier \"%s\" ouvert\n", nomFichier);


        fscanf(fichier, "%d", n);

        float * contenue = malloc(sizeof(float)*(*n));
        int i = 0;
        while (feof(fichier) == 0){

            fscanf(fichier, "%f", (contenue+i));
            printf("%f\n", *(contenue+i));
            
            i++;
        }

        fclose(fichier);
        // Quand je rends la memoire, toutes les valeures de la memoir
        // de la mémoir reserver se met a 0.
        // Garbage coloctor ?
        // Comment faire pour rendre la memoire ET en pouvoir recuperer
        // dans les tests unitaires ?
        //free(contenue);
        return contenue;
    }
    else{
        printf("Impossible d'ouvrir le fichier \"%s\"\n", nomFichier);
        return NULL;
    }

}


int produitScalaire (float * v1, float *v2, int ordre){
    float ps = 0;
    int i=0;
    for (i=0; i<ordre; i++){
        printf("%f\n", *(v2+i));
        ps += *(v1+i) * *(v2+i);
    }
    printf("%f\n\n", ps);
    return (int) ps;
}
