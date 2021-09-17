#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "master.h"
#include "time.h"

// un petit commentaire ?
void initialiser_solution(int solution[NB_COLONNES]) {
   srand(time(NULL));
   for (int i=0;i<NB_COLONNES;i++){
      solution[i]=rand()%NB_COULEURS+1;
   }
}

// un petit commentaire ?
void initialiser_plateau(int plateau [NB_LIGNES][NB_COLONNES+2]){
   for (int i=0; i < NB_LIGNES; ++i){
      for (int j=0; j < NB_COLONNES+2; ++j){
         plateau[i][j]=0;
      }
   }
}

void debugnico(int proposition [NB_COLONNES], int solution [NB_COLONNES]){
   printf("[ ");
   for (int i=0;i<NB_COLONNES;i++){
      printf("%d ",proposition[i]);
   }
   printf("]\n");
   printf("[ ");
   for (int i=0;i<NB_COLONNES;i++){
      printf("%d ",solution[i]);
   }
   printf("]\n");
}

combinaison compiler_proposition(int proposition [NB_COLONNES], int solution [NB_COLONNES]){
	combinaison c;
   c.bienp=c.malp=0;
   int copySol[NB_COLONNES];
   int copyProp[NB_COLONNES];
   for (int copy=0;copy<NB_COLONNES;copy++){
      copySol[copy]=solution[copy];
      copyProp[copy]=proposition[copy];
   }

   for (int i=0;i<NB_COLONNES;i++){
      if (copyProp[i]==copySol[i]){
         c.bienp++;
         copySol[i]=0;
         copyProp[i]=0;
      }
   }

   for (int i=0;i<NB_COLONNES;i++){
      for (int j=0;j<NB_COLONNES;j++){
         if (copyProp[i]!=0 && copyProp[i]==copySol[j]){
            c.malp++;
            copySol[j]=0;
            copyProp[i]=0;
            //debugnico(copyProp,copySol);

         }
      }
   }
   return c;
}