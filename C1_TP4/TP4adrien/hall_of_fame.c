#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hall_of_fame.h"




void creationdonnee (){
   donnee_t donnee1;
   donnee1.score = 100;
   strcpy(donnee1.alias,"qsd");
   strcpy( donnee1.jeu,"fq");
   afficherDonnee(NULL, donnee1);
}

// un petit commentaire ?
void afficherDonnee(FILE * file, donnee_t d) {
   fprintf(file, "%s : %s avec %d\n", d.jeu, d.alias, d.score);

}

// un petit commentaire ?
void saisirDonnee(FILE *file, donnee_t * d){
   fgets((*d).jeu, 100, file);
   fgets((*d).alias, 40, file);
   char * nb [10];
   (*d).score = atoi(fgets(nb, 10, file));

   RemoveEnter((*d).jeu);
   RemoveEnter((*d).alias);
   
}

int tableauFromFilename(char * nomFichier, donnee_t tab []){
   FILE * file = NULL;
   file = fopen(nomFichier, "r");
   if (file != NULL){
      printf("Fichier \"%s\" ouvert\n", nomFichier);

      int cpt = 0;
      while (cpt<TAILLE_MAX || feof(file) == 0)
      {
         fscanf(file, "%s", tab[cpt].jeu);
         fscanf(file, "%s", tab[cpt].alias);
         fscanf(file, "%d", &tab[cpt].score);
         printf("%d",cpt); //nico
         cpt++;
      }
      return cpt;
   }
   else{
      printf("Impossible d'ouvrir le fichier \"%s\"\n", nomFichier);
      return 0;
   }
}


void RemoveEnter (char * chaine){
   while (*chaine != '\0')
   {
      if (*chaine == '\n')
         DecalageG(chaine+1);
      chaine++;
   }
   
}

// Pointeur du premier element a décaler vers la gauche (ATTENTION, ecrasement de l'émément juste avant)
void DecalageG (char * chaine){
   while (*chaine != '\0')
   {
      *(chaine-1) = *(chaine);
      chaine++;
   }
   *(chaine-1) = '\0';
   
}

void AffichageChaine(char * chaine){
   while (*chaine != '\0')
   {
      printf("%c", *chaine);
      chaine++;
   }
   printf("\n");
}