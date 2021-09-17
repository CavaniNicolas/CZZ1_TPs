#include <stdio.h>

/*1. Passage par valeur ou par adresse:
void echangeParValeur(int a,int b){
//    printf("a=%d b=%d\n",a,b);
    int c=a;
    a=b;
    b=c;
//    printf("a=%d b=%d\n",a,b);
}

void echangeParAdresse(int * a,int * b){
//    printf("a=%p b=%p\n",&a,&b);
    int c=*a;
    *a=*b;
    *b=c;
//    printf("a=%p b=%p\n",&a,&b);
}

int main(){
    int i=2;
    int j=5;
    printf("i=%d j=%d\n",i,j);
    echangeParValeur(i,j);
    printf("i=%d j=%d\n\n",i,j);

    printf("i=%d j=%d\n",i,j);
    echangeParAdresse(&i,&j);
    printf("i=%d j=%d\n",i,j);

    return 0;
}
*/


/*2. Operation sur les pointeurs
void swap(char *val1, char *val2){
    char tmp=*val1;
    *val1=*val2;
    *val2=tmp;
}
int main(){
    int i=2;
    int *ptri=&i;
    char c1='m';
    char *ptrc1=&c1;

    printf("ptri(u)  = %u      ptrc1(u) = %u \n",ptri, ptrc1);
    printf("ptri(x)  = %x        ptrc1(x) = %x \n",ptri, ptrc1);
    printf("ptri(p)  = %p  ptrc1(p) = %p \n",ptri, ptrc1);
    printf("*ptri(d) = %d    *ptrc1(d) = %d     *ptrc1(c) = %c\n", *ptri, *ptrc1, *ptrc1);
    ptri++;
    //ptrc1++;
    printf("ptri(u)  = %u      ptrc1(d) = %d \n\n",ptri, ptrc1);

    double d=51;
    double *ptrd=&d;
    printf("ptrd(u)   = %u\n",ptrd);
    printf("ptrd(x)   = %x\n",ptrd);
    printf("ptrd(p)   = %p\n",ptrd);
    printf("*ptrd(ld) = %ld\n",*ptrd);
    printf("*ptrd(f)  = %f\n\n",*ptrd);
    *ptrd++;
    *ptrd++;
    printf("ptrd(u)   = %u\n",ptrd);
    printf("ptrd(x)   = %x\n",ptrd);
    printf("ptrd(p)   = %p\n",ptrd);
    printf("*ptrd(ld) = %ld\n",*ptrd);
    printf("*ptrd(f)  = %f\n\n",*ptrd);

    double *ptrd2=&d;
    printf("ptrd2(u)   = %u\n",ptrd2);
    printf("ptrd2(x)   = %x\n",ptrd2);
    printf("ptrd2(p)   = %p\n",ptrd2);
    printf("*ptrd2(ld) = %ld\n",*ptrd2);
    printf("*ptrd2(f)  = %f\n\n",*ptrd2);

    char c2='w';
    char *ptrc2=&c2;
    printf("ptrc2(u)   = %u\n",ptrc2);
    printf("ptrc2(x)   = %x\n",ptrc2);
    printf("ptrc2(p)   = %p\n",ptrc2);
    printf("*ptrc2(ld) = %ld\n",*ptrc2);
    printf("*ptrc2(f)  = %f\n",*ptrc2);
    printf("*ptrc2(c)  = %c\n\n",*ptrc2);

    swap(ptrc1,ptrc2);
    printf("*ptrc1(c)  = %c\n",*ptrc1);
    printf("*ptrc2(c)  = %c\n",*ptrc2);
    return 0;
}
*/


/*3. Tableaux, pointeurs et chaines de caracteres

int main(){
    int tab[]={0,1,7,3,4,5};

    printf("%lu %lu %lu\n",sizeof(char), sizeof(int), sizeof(double));

    int * p1;

    p1 = tab;
    printf("%d",*p1);
    ++p1;
  
    printf("%d\n",*p1);
    
    ++p1;
    printf("%d",*p1);
    ++p1;
    printf("%d",*p1);
    ++p1;
    printf("%d",*p1);
    ++p1;
    printf("%d\n\n",*p1);
    

    char *p2;

    p2 = (char *) p1;
    p2 += sizeof(int);

    printf("%p\n", p2);

    printf("%d\n", *((int*)p2));
    printf("%d\n", *(p1+6));


    //p1 = NULL;
    //printf("%d", *p1);

    return 0;
}

int compter1(char * chaine){
    int i=0;
    while (*(chaine+i) != '\0')
        //debut+0, debut+1, debut
        ++i;
    return i;
//return la longeur de la chaine de caracteres
}

int compter2(char * chaine){
    char * s = chaine;
    while (*chaine != '\0')
        ++chaine;
    return chaine - s;
//return la longueur de la chaine de caracteres
}

int compter3(char * chaine){
    char * s = chaine;
    while (*chaine++);
    return chaine - s;
//return la longueur de la chaine de caracteres +1
}

int main(){
    char chainec[]="bon";
    int a=compter3(chainec);
    printf("%d\n",a);
    return 0;
}
*/

/*4. Revision de la manipulation des outils*/
#include <string.h>
#include <stdlib.h>
/*
void saisir(char * s){
    printf("Saisir un chaine\n");
    scanf("%s",s);
}

int main(){
    char *s = malloc(sizeof(char)*10);
    printf("Entrer votre prenom.\n");
    saisir(s);
    printf("Bonjour %s!\n",s);

    if (!strcmp(s,"ddd"))
        printf("bizzare \n");
    free(s);
    return 0;
}
*/

/*5. Allocation dynamique*/

void init(double * tab, int L){
    int i;
    for (i=0;i<L;i++){
        tab[i]=(float)(i*i);
    }
}

void afficher(double * tab, int L){
    int i;
    for (i=0;i<L;i++){
        printf("%f\n",tab[i]);
    }
}

int main(){
    int taille;
    printf("taille : \n");
    scanf("%d",&taille);
    double * tab= malloc(sizeof(double)*taille);
    init(tab,taille);
    //afficher(tab,taille);
    free(tab);
    return 0;
}


/* structure Jean

typedef struct chaine_t
{
    int i;
    struct chaine_t *suiv;
}MaillonC, * Chaine;
MaillonC c;
Chaine ch;
ch = &c;


int *k;
&k := k;
k := cm(k);
*k := cm²(k);

int i, *k;
k=&i;
*/