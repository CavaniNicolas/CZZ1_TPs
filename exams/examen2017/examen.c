/*
 * REMPLACER LES NOMS DES FONCTIONS PAR LES VOTRES
 * DANS LES FICHIERS VOTRECODE.H et VOTRECODE.C
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "code.h"

#include "teZZt.h"



/* variables statiques pour les tests */

double tab_stat1 []         = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 } ;
int    taille_stat1         = sizeof(tab_stat1)/sizeof(double);

double tab_stat2 []         = {0., 1., 2., 3., 4., 5., 6., 7., 8., 9., 10.};
int    taille_stat2         = sizeof(tab_stat2)/sizeof(double);

int    etoiles_zz_res    [] = { 25, 22, 37, 28, 17, 18, 17, 27, 30, 1, 27, 32, 40};
int    etoiles_iphone_res[] = { 1, 1, 3, 6, 12, 21, 25, 29, 40, 36 };


donnee_t * dat_iphone       = NULL;
double   * tab_iphone       = NULL;
int        taille_iphone    = -1;

donnee_t * dat_zz           = NULL;
double   * tab_zz           = NULL;
int        taille_zz        = -1;

int      * etoiles_zz       = NULL;
int      * etoiles2_zz      = NULL;
int      * etoiles_iphone   = NULL;


// DEBUT DES FONCTIONS DE TESTS
BEGIN_TEST_GROUP(examen)


TEST(SOMME, "verification somme") {
   CHECK( EQ(  6.0 , somme(tab_stat1,   taille_stat1)   ));
   CHECK( EQ( 55.0 , somme(tab_stat2,   taille_stat2)   ));
   CHECK( EQ( 55.0 , somme(tab_stat2+1, taille_stat2-1) ));
}


TEST(MOYENNE, "verification moyenne") {
   CHECK( EQ( 1.0  , moyenne(tab_stat1, taille_stat1)     ));
   CHECK( EQ( 5.0  , moyenne(tab_stat2, taille_stat2)     ));
   CHECK( EQ( 5.5  , moyenne(tab_stat2+1, taille_stat2-1) ));
}

TEST(MINIMUM, "verification min") {
   CHECK( 1    ==  minimum(tab_stat1,   taille_stat1)    );
   CHECK( EQ( 0. , minimum(tab_stat2,   taille_stat2)   ));
   CHECK( EQ( 1. , minimum(tab_stat2+1, taille_stat2-1) ));
}

TEST(MAXIMUM, "verification max") {
   CHECK( 1     ==  maximum(tab_stat1,   taille_stat1)    );
   CHECK( EQ( 10. , maximum(tab_stat2,   taille_stat2)   ));
   CHECK( EQ(  9. , maximum(tab_stat2+1, taille_stat2-2) ));
}



TEST(FICHIER_INEXISTANT) {
    taille_zz = lecture("inexistant.txt", &dat_zz);
    CHECK( 0 ==  taille_zz);
}

TEST(FICHIER_IPHONE) {
    taille_iphone = lecture("iphone.txt", &dat_iphone);
    CHECK( 10 == taille_iphone);
    conversion_to_double(dat_iphone , &tab_iphone, taille_iphone);
    CHECK ( EQ( 1033.66 , somme  (tab_iphone, taille_iphone)));
    CHECK ( EQ( 103.366 , moyenne(tab_iphone, taille_iphone)));
    CHECK ( EQ(   1.39  , minimum(tab_iphone, taille_iphone)));
    CHECK ( EQ( 231.22  , maximum(tab_iphone, taille_iphone)));
}


TEST(FICHIER_ZZ) {
    // effectif des promos depuis quelques années
    taille_zz = lecture("zz.txt", &dat_zz);
    CHECK( 13 == taille_zz);
    conversion_to_double(dat_zz , &tab_zz, taille_zz);
    CHECK ( EQ( 1417   , somme  (tab_zz, taille_zz)));
    CHECK ( EQ(  109.0 , moyenne(tab_zz, taille_zz)));
    CHECK ( EQ(   74   , minimum(tab_zz, taille_zz)));
    CHECK ( EQ(  130   , maximum(tab_zz, taille_zz)));
}  

TEST(AFFICHAGE_ZZ) {
    int i;
    etoiles_zz = affichage(dat_zz, taille_zz);

    for(i = 0; i < taille_zz; ++i) 
    {
       CHECK( etoiles_zz_res[i] == etoiles_zz[i]);
    }
}

TEST(MODIFICATION_ZZ) {
    dat_zz[9].valeur = 0;
    conversion_to_double(dat_zz , &tab_zz, taille_zz);
    CHECK( EQ(1343.0, somme(tab_zz, taille_zz)));

    etoiles2_zz = affichage(dat_zz, taille_zz);
    CHECK( 0 == etoiles2_zz[9] );
}



TEST(AFFICHAGE_IPHONE) {
    int i;
    etoiles_iphone = affichage(dat_iphone, taille_iphone);

    for(i = 0; i < taille_iphone; ++i) 
    {
       CHECK( etoiles_iphone_res[i] == etoiles_iphone[i]);
    }
}


END_TEST_GROUP(examen)


int main() {
    RUN_TEST_GROUP(examen);
    return 0;
}
