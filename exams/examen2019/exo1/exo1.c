/*
 * REMPLACER LES NOMS DES FONCTIONS PAR LES VOTRES
 * DANS LES FICHIERS VOTRECODE.H et VOTRECODE.C
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "code.h"

#include "../teZZt.h"


// DEBUT DES FONCTIONS DE TESTS
BEGIN_TEST_GROUP(exo1)


TEST(INIT, "initialisation") {
	char tab[50];
   
	init(tab, 0, '0');
	CHECK( !strcmp(tab, ""));
	init(tab, 8, '0');
	CHECK( !strcmp(tab, "00000000"));
	init(tab, 0, '1');
	CHECK( !strcmp(tab, ""));
	init(tab, 1, '1');
	CHECK( !strcmp(tab, "1"));
}


TEST(INVERSION, "inversion") {
    char tab[50];

    strcpy(tab, "00000001");
	inverser(tab);
	CHECK( !strcmp(tab, "10000000"));
	
	tab[3] = 0;
	inverser(tab);
	CHECK( !strcmp(tab, "001"));

	tab[1] = 0;
	inverser(tab);
	CHECK( !strcmp(tab, "0"));

	tab[0] = 0;
	inverser(tab);
	CHECK( ! strcmp(tab, ""));
}

TEST(CONVERSION1, "binaire to decimal") {
    CHECK (   0 == conversionb2d("0"));
    CHECK (   1 == conversionb2d("1"));
    CHECK (   2 == conversionb2d("10"));
    CHECK (   3 == conversionb2d("11"));
    CHECK (   4 == conversionb2d("100"));
    CHECK (   5 == conversionb2d("101"));
    CHECK (   6 == conversionb2d("110"));
    CHECK (   7 == conversionb2d("111"));
    CHECK ( 128 == conversionb2d("10000000"));
    CHECK ( 129 == conversionb2d("010000001"));
    CHECK (   0 == conversionb2d(""));
}

TEST(CONVERSION2, "decimal to binaire") {
    char tab[50];
    
    conversiond2b(0, tab);
    CHECK( !strcmp("0", tab));
    conversiond2b(1, tab);
    CHECK( !strcmp("1", tab));
    conversiond2b(2, tab);
    CHECK( !strcmp("10", tab));
    conversiond2b(13, tab);
    CHECK( !strcmp("1101", tab));
    conversiond2b(35, tab);
    CHECK( !strcmp("100011", tab));
    conversiond2b(256, tab);
    CHECK( !strcmp("100000000", tab));
}

TEST(ADDITION, "addition de binaires") {    
    char r[50];

    addition(r, "0", "0");
    CHECK( !strcmp("0", r));
    addition(r, "1", "0");
    CHECK( !strcmp("1", r));
    addition(r, "0", "1");
    CHECK( !strcmp("1", r));
    addition(r, "1", "1");
    CHECK( !strcmp("10", r));
    addition(r, "10", "1");
    CHECK( !strcmp("11", r));
    addition(r, "11", "1");
    CHECK( !strcmp("100", r));
    addition(r, "1110", "1");
    CHECK( !strcmp("1111", r));
    addition(r, "111111", "101");
    CHECK( !strcmp("1000100", r));
    addition(r, "1111111111111111111111111111111", "1");
    CHECK( !strcmp("10000000000000000000000000000000", r));
} 


END_TEST_GROUP(exo1)


int main() {
    RUN_TEST_GROUP(exo1); 
    return 0;
}
