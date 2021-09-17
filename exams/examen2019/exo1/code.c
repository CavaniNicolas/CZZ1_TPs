#include "code.h"
#include <string.h>
#include <stdio.h>

void init(char * tab, int taille, char value) {
	int i=0;
	for (i=0;i<taille;i++){
		tab[i]=value;
	}
	tab[i]='\0';
}

void inverser(char * tab){
	int taille=0;
	while (tab[taille]!='\0'){
		taille++;
	}
	int i=0;
	char tmp;
	while (i<taille-i-1){
		tmp = tab[i];
		tab[i]=tab[taille-i-1];
		tab[taille-i-1]=tmp;
		i++;
	}
}

int conversionb2d(const char * tab){
	int dec=0;
	if (tab[0]!='\0'){
		int i=1;
		int bit;
		if (tab[0]=='0'){bit=0;}else{bit=1;}
		dec = bit;
		while (tab[i]!='\0'){
			if (tab[i]=='0'){bit=0;}else{bit=1;}
			dec=dec*2+bit;
			i++;
		}
	}

	return dec;
}

void conversiond2b(int nb, char * tab){
	if (nb!=0){
		int i=0;
		char bit;
		while (nb!=0){
			if (nb%2==0){bit='0';}else{bit='1';}
			tab[i]=bit;
			i++;
			nb=nb/2;
		}
		tab[i]='\0';
	}
	else{
		tab[0]='0';
		tab[1]='\0';
	}
	inverser(tab);
}


char * addition(char *r, char *a, char * b) {
	int add=conversionb2d(a)+conversionb2d(b);
	conversiond2b(add,r);
	
	/*int i=0;
	int bita=0;
	int bitb=0;
	int retenue=0;

	int taillea=0;
	int tailleb=0;
	while (a[taillea]!='\0'){taillea++;}
	
	while (b[tailleb]!='\0'){tailleb++;}
	

	i=0;
	while (taillea-i-1!=0 && tailleb-i-1!=0){
		if (a[taillea-i-1]=='0'){bita=0;}else{bita=1;}
		if (b[tailleb-i-1]=='0'){bitb=0;}else{bitb=1;}

		if ((bita+bitb+retenue)%2==0){
			r[i]='0';
			if (bita+bitb+retenue==0){
				retenue=0;
			}
			else{retenue=1;}
		}
		else{
			r[i]='1';
			if (bita+bitb+retenue==1){
				retenue=0;
			}
			else{retenue=1;}
		}
		i++;
	}

	if (taillea-i-1<=0){
		while (tailleb-i-1>0){
			if (b[tailleb-i-1]=='0'){bitb=0;}else{bitb=1;}
			if ((bitb+retenue)%2==0){
				r[i]='0';
				if (bitb+retenue==0){retenue=0;}
				else{retenue=1;}
			}
			else{r[i]='1';}
				retenue=0;
			i++;
		}
	}
	else{
		while (taillea-i-1>0){
			if (a[taillea-i-1]=='0'){bita=0;}else{bita=1;}
			if ((bita+retenue)%2==0){
				r[i]='0';
				if (bita+retenue==0){retenue=0;}
				else{retenue=1;}
			}
			else{r[i]='1';}
				retenue=0;
			i++;
		}
	}

	r[i]='\0';
	inverser(r);*/

    return r;
}	

