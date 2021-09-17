#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listechainée2.h"

int main(int argc, char * argv[]){
	liste_2pointeurs liste;
	liste=creer_liste();
	if (argc==1){
		ecrire_dans_la_liste(&liste);
	}
	else{
		printf("%s\n",argv[1]);
		fichier_dans_la_liste(&liste, argv[1]);
	}
	afficher_listeTF(liste);
	liberer_liste(&liste);
	afficher_listeTF(liste);
	return 0;
}
