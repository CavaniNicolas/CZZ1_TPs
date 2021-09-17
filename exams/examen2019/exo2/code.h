#ifndef CODE_EXO2
#define CODE_EXO2

#define MAX 100

typedef struct  {
	char lettre;
	int nb;
	int nbd;
	char mots[MAX][50];
} info ;

void stats1(char *, int *, int * , int*) ;
void stats2(char *, info *, int *, int * , int*) ;

char * lecture(char *);
long taille_fichier(char*);

void initialiser(info *);
void inserer(info * , char * );

int total_mots(info *);
int total_mots_distincts(info *);


#endif