#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hall_of_fame.h"

/*
int main(){
   donnee_t tab[TAILLE_MAX];
   int n=tableauFromFilename("jeu1.txt",tab);
   printf("%d\n",n);
}
*/

// fct pas tres utile...
donnee_t editerStruct(donnee_t essai){
   essai.score = 102;
   strcpy(essai.jeu,"Cookie");
   strcpy(essai.alias,"J1_Pgm");

   //Ca cest faux:
   //essai.jeu = "Cookie";
   //essai.alias = "J1pgm";

   return essai;
}

void afficherDonnee(FILE * file, donnee_t d) {
   fprintf(file,"%s : %s avec %d\n",d.jeu,d.alias,d.score);
}

/*
void saisirDonnee(FILE *file, donnee_t * p){
   fgets((*p).jeu,sizeof((*p).jeu),file);
   fgets((*p).alias,sizeof((*p).alias),file);
   char * nb [10];
   (*p).score=atoi(fgets(nb,10,file));

   removeEnter((*p).jeu);
   removeEnter((*p).alias);
}
*/

/*
void removeEnter(char * chaine){
   int l = strlen(chaine);
   chaine[l-1]='\0';
}
*/

int tableauFromFilename(char * filename, donnee_t tableau[]){
   int i=0;

   FILE * file = NULL;
   file = fopen(filename, "r");

   while(i<TAILLE_MAX && !feof(file)){ //feof(FILE * stream) renvoie une valeur nulle si on est pas encore au bout
      fgets(tableau[i].jeu,70,file);
      fgets(tableau[i].alias,30,file);
      char nb[10];
      tableau[i].score=atoi(fgets(nb,10,file));
      removeEnter(tableau[i].jeu);
      removeEnter(tableau[i].alias);
      printf("%d\n",i);
      i++;
   }
   for (int k=0;k<i;k++){
      printf("%s\n",tableau[k].jeu);
      printf("%s\n",tableau[k].alias);
      printf("%d\n",tableau[k].score);
   }
   printf("%d\n",i);
   return i;
}
