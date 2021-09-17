#ifndef LC2
#define LC2

typedef struct cellule{
	char * ligne;
	struct cellule * suiv;
}cellule;

typedef struct liste{
	cellule * tete;
	cellule * fin;
}liste_2pointeurs;

/*Declarations_Fonctions*/

// creer_liste()
// In : Void
// Out: creer une liste avec pointeur de tete et pointeur de fin
liste_2pointeurs creer_liste();

// ecrire_dans_la_liste()
// In : liste_2pointeurs *
// Out: l'utilisateur ecrit dans la liste
void ecrire_dans_la_liste(liste_2pointeurs *);

// fichier_dans_la_liste()
// In : liste_2pointeurs *, char *
// Out: le fichier ecrit dans la liste
void fichier_dans_la_liste(liste_2pointeurs *, char *);

// inserer_char_dans_liste()
// In : char *, liste_2pointeurs *
// Out: une chaine de charactere est ecrite dans un nouvel element (dernier) de la liste
void inserer_char_dans_liste(char *, liste_2pointeurs *);

// afficher_listeTF()
// In : liste_2pointeurs
// Out: Affiche la liste
void afficher_listeTF(liste_2pointeurs);

// liberer_liste()
// In : liste_2pointeurs *
// Out: Libere la memoire
void liberer_liste(liste_2pointeurs *);

/*Fin_Declarations_Fonctions*/

#endif


/*
//revision chaines de characteres

int blablou(){
	char s[5]="azert";
	char *s2=(char *)malloc(7*sizeof(char));
	if (s2!=NULL){
		//s2="bonjour";
		strcpy(s2,"aurevoi");
		//s2="aurevoi";
		//s2="aurevoir";
		*s2='A';
		*(s2+2)='G';
//		strcpy(s2,"A");
		printf("%s\n",s);
		printf("%s\n",s2);
	}
	return 0;
}

int main(){
	int * i = (int *)malloc(3*sizeof(int));
	i[0]=12312;i[1]=67;
	char * s =i;
	printf("%c\t%c\n",s[0],*(s+1));
	return 0;
}

*/