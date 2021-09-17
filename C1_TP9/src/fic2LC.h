#ifndef fic2LC_H
#define fic2LC_H

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

// fichier_dans_la_liste()
// In : liste_2pointeurs *, char *
// Out: la taille de la liste chainée, -1 si erreur / (la liste a evidemment été remplie)
int fichier_dans_la_liste(liste_2pointeurs *, char *);

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