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
BEGIN_TEST_GROUP(exo2)


TEST(STATS1, "") {
	char tab[300];
    int cars, lignes, mots;
   
    strcpy(tab, "UN");
    stats1(tab, &cars, &lignes, &mots);

    CHECK( 2 == cars);
    CHECK( 1 == lignes);
    CHECK( 1 == mots);

    strcpy(tab, "");
    stats1(tab, &cars, &lignes, &mots);

    CHECK( 0 == cars);
    CHECK( 1 == lignes);
    CHECK( 0 == mots);

    strcpy(tab, "UN\nDEUX");
    stats1(tab, &cars, &lignes, &mots);

    CHECK( 7 == cars);
    CHECK( 2 == lignes);
    CHECK( 2 == mots);

    strcpy(tab, "UN  PETIT, ESSAI\nNON PLUTOT DEUX!\n");
    stats1(tab, &cars, &lignes, &mots);

    CHECK( 34 == cars);
    CHECK( 3  == lignes);
    CHECK( 6  == mots);

}

TEST(LECTURE1, "") {
    char * texte;

    texte = lecture("pastrouve.txt");
    REQUIRE( NULL == texte);

    texte = lecture("essai.txt");

    REQUIRE( NULL != texte);
    CHECK( (unsigned)taille_fichier("essai.txt") == strlen(texte));     
    free(texte);
}


/*TEST(INITIALISER, "") {
    info infos[26];
    int j;
    initialiser(infos);

    CHECK( 'A' == infos[0].lettre );
    CHECK(   0 == infos[0].nb     );
    CHECK(   0 == infos[0].nbd    );
    for(j = 0; j < MAX; ++j)
        CHECK( !strcmp("", infos[0].mots[j]));

    //  je testerai pour tous les indices

    CHECK( 'Z' == infos[25].lettre );
    CHECK(   0 == infos[25].nb     );
    CHECK(   0 == infos[25].nbd    );
    for(j = 0; j < MAX; ++j)
        CHECK( !strcmp("", infos[25].mots[j]));
}*/

TEST(INSERER, "") {
    info infos[26];
    initialiser(infos);

    inserer(infos, "EXAMEN");

    CHECK( 'E' == infos[4].lettre );
    CHECK(   1 == infos[4].nb     );
    CHECK(   1 == infos[4].nbd    );
    CHECK(   1 == infos[4].nbd    );
    CHECK( !strcmp("EXAMEN", infos[4].mots[0]));
    CHECK( !strcmp("", infos[4].mots[1]));
    
    inserer(infos, "EXAMEN");

    CHECK( 'E' == infos[4].lettre );
    CHECK(   2 == infos[4].nb     );
    CHECK(   1 == infos[4].nbd    );
    CHECK( !strcmp("EXAMEN", infos[4].mots[0]));
    CHECK( !strcmp(""      , infos[4].mots[1]));

    inserer(infos, "EXERCICE");
    CHECK(   3 == infos[4].nb     );
    CHECK(   2 == infos[4].nbd    );
    CHECK( !strcmp("EXAMEN"  , infos[4].mots[0]));
    CHECK( !strcmp("EXERCICE", infos[4].mots[1]));
    CHECK( !strcmp(""        , infos[4].mots[2]));

    inserer(infos, "EXERCICE");
    CHECK(   4 == infos[4].nb     );
    CHECK(   2 == infos[4].nbd    );
    CHECK( !strcmp("EXAMEN"  , infos[4].mots[0]));
    CHECK( !strcmp("EXERCICE", infos[4].mots[1]));
    CHECK( !strcmp(""        , infos[4].mots[2]));

    inserer(infos, "ECLAIRCISSEMENT");
    CHECK(   5 == infos[4].nb     );
    CHECK(   3 == infos[4].nbd    );
    CHECK( !strcmp("ECLAIRCISSEMENT" , infos[4].mots[0]));
    CHECK( !strcmp("EXAMEN"          , infos[4].mots[1]));
    CHECK( !strcmp("EXERCICE"        , infos[4].mots[2]));
    CHECK( !strcmp(""                , infos[4].mots[3]));


    CHECK(   5 == total_mots          (infos) );
    CHECK(   3 == total_mots_distincts(infos) );


    //tests supplementaires persos

/*    inserer(infos, "EXO");
    CHECK(   6 == infos[4].nb     );
    CHECK(   4 == infos[4].nbd    );
    CHECK( !strcmp("ECLAIRCISSEMENT" , infos[4].mots[0]));
    CHECK( !strcmp("EXAMEN"          , infos[4].mots[1]));
    CHECK( !strcmp("EXERCICE"        , infos[4].mots[2]));
    CHECK( !strcmp("EXO"             , infos[4].mots[3]));
    CHECK( !strcmp(""                , infos[4].mots[4]));

    inserer(infos, "AVION");
    CHECK(   1 == infos[0].nb     );
    CHECK(   1 == infos[0].nbd    );
    CHECK( !strcmp("AVION" , infos[0].mots[0]));
    CHECK( !strcmp(""    , infos[0].mots[1]));

    inserer(infos, "AVION");
    CHECK(   2 == infos[0].nb     );
    CHECK(   1 == infos[0].nbd    );
    CHECK( !strcmp("AVION" , infos[0].mots[0]));
    CHECK( !strcmp("" , infos[0].mots[1]));

    CHECK(   8 == total_mots          (infos) );
    CHECK(   5 == total_mots_distincts(infos) );
*/
}


TEST(STATS2, "") {
    info infos[26];
    int cars, lignes, mots;

    char texte[] = "VOUS AVEZ CODE UNE COMMANDE UNIX QUI EXISTE DEJA, POUR LES INFORMATIONS DE BASE : "
                   "NOMBRE DE LETTRES, DE MOTS ET DE LIGNES.\n"
                   "IL FAUT MAINTENANT FAIRE LA LISTE DES MOTS DISTINCTS ET COMPTER TOUTES LES OCCURENCES\n"
                   "QUEL EST LE RESULTAT ?";

    stats2(texte, infos, &cars, &lignes, &mots);

    CHECK( 231 == cars   );
    CHECK(   3 == lignes );
    CHECK(  40 == mots   );

    CHECK(   40 == total_mots          (infos) );
    CHECK(   34 == total_mots_distincts(infos) );

    CHECK(   1 == infos[1].nb     );
    CHECK( !strcmp("AVEZ", infos[0].mots[0]));
    //CHECK( !strcmp("BASE", infos[1].mots[0]));

    CHECK( !strcmp("LA"     , infos[11].mots[0]));    
    CHECK( !strcmp("LE"     , infos[11].mots[1]));    
    CHECK( !strcmp("LES"    , infos[11].mots[2]));    
    CHECK( !strcmp("LETTRES", infos[11].mots[3]));
    CHECK( !strcmp("LIGNES" , infos[11].mots[4]));
    CHECK( !strcmp("LISTE"  , infos[11].mots[5]));
    CHECK( !strcmp(""       , infos[11].mots[6]));

}

TEST(LECTURE2, "") {
    char * texte;
    info infos[26];
    int cars, lignes, mots;

    texte = lecture("essai.txt");

    REQUIRE( NULL != texte);
    stats2(texte, infos, &cars, &lignes, &mots);
    
    CHECK( 179 == cars   );
    CHECK(   6 == lignes );
    CHECK(  29 == mots   );

    CHECK(   29 == total_mots          (infos) );
    CHECK(   29 == total_mots_distincts(infos) );

    free(texte);
}

END_TEST_GROUP(exo2)


int main() {
    RUN_TEST_GROUP(exo2); 
    return 0;
}
