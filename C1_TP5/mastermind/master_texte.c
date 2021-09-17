#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "master.h"

int main(){
    int rejouer=1;
    while (rejouer!=0){
        mastermind();
        printf("Rejouer ? \033[32mOui:1\033[00m ; \033[31mNon:0\033[00m\n? ");
        scanf("%d",&rejouer);
        //viderBuffer();
    }
    printf("\nDommage... A Bientôt :)\n\n");
    return 0;
}

int mastermind(){
    int ligne=0;
    int solution[NB_COLONNES];
    initialiser_solution(solution);
    //afficher_sol_prop(solution);

    int plateau[NB_LIGNES][NB_COLONNES+2];
    initialiser_plateau(plateau);
    printf("\n    \033[31mMASTERMIND\033[00m\n");
    //printf(" \033[31m1  \033[32m2  \033[33m3  \033[34m4  \033[35m5  \033[36m6\033[00m\n");
    afficher_plateau(plateau);
    printf("\nC'est parti !\n");

    combinaison combi;
    combi.bienp=0; combi.malp=0;
    int proposition[NB_COLONNES];

    while (ligne<10 && combi.bienp!=4){
        user_proposition(proposition);
        combi=compiler_proposition(proposition,solution);
        ligne=remplir_plateau(plateau,proposition,combi,ligne);
        afficher_plateau(plateau);

        if (combi.bienp==4){
            printf("Bravo, c'est gagné, en %d tentatives\n\n",ligne);
        }
        else{
            if (ligne==10){
                printf("Tu as perdu.\nLa solution était [ \033[3%dm%d\033[00m \033[3%dm%d\033[00m \033[3%dm%d\033[00m \033[3%dm%d\033[00m ]\n\n",solution[0],solution[0],solution[1],solution[1],solution[2],solution[2],solution[3],solution[3]);
            }
            else{
                printf("Il te reste %d tentatives\n",10-ligne);
            }
        }
    }
    return 0;    
}

void afficher_plateau(int plateau[NB_COLONNES][NB_COLONNES+2]){
    int j;
    printf(" \033[31m1  \033[32m2  \033[33m3  \033[34m4  \033[35m5  \033[36m6\033[00m\n");
    printf("=============b=m==\n");
    for (int i=0;i<NB_LIGNES;i++){
        printf("| ");
        j=0;
        for (j=0;j<NB_COLONNES;j++){
            printf("\033[3%dm%d\033[00m ",plateau[i][j],plateau[i][j]);
        }
        printf("|| %d %d |\n",plateau[i][j], plateau[i][j+1]);
    }
    printf("==================\n");
}

//int couleur(int chiffre){
//printf("\033[3%dmtest\033[00m",2);
//rouge     \033[31m
//vert      \033[32m
//jaune     \033[33m
//bleu      \033[34m
//violet    \033[35m
//turquoise \033[36m
//    return;
//}

void viderBuffer(){
    int c;
    do {
        c = getchar();
    } while (c != EOF && c != '\n');
}

void user_proposition(int proposition[NB_COLONNES]){
    printf("\nInserez votre proposition, chaque chiffres séparés d'un espace, et faites entrée\n");
    printf("? ");
    scanf("%d",&proposition[0]);
    scanf("%d",&proposition[1]);
    scanf("%d",&proposition[2]);
    scanf("%d",&proposition[3]);
    printf("\n");
    viderBuffer();
}

int remplir_plateau(int plateau[NB_LIGNES][NB_COLONNES+2], int proposition[NB_COLONNES], combinaison combi, int ligne){
    int j;
    for (j=0;j<NB_COLONNES;j++){
        plateau[ligne][j]=proposition[j];
    }
    plateau[ligne][j]=combi.bienp;
    plateau[ligne][j+1]=combi.malp;
    ligne+=1;
    return ligne;
}

void afficher_sol_prop(int tab[NB_COLONNES]){
    printf("[ ");
    for (int i=0;i<NB_COLONNES;i++){
        printf("%d ",tab[i]);
    }
    printf("]");
}