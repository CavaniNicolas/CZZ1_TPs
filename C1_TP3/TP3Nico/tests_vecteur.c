#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teZZt.h"
#include "vecteur.h"


BEGIN_TEST_GROUP(vecteur)
/*
TEST(Exemple) {
	int b = 3;
	
	CHECK (3 == b);
	CHECK (0 == b);
} 
*/
/*
TEST(AffichageA) {
   // vecteur statique a afficher
   float v1 [] = {1.0, 2.0, 3.0 };
   // creation du flux de texte => buffer
   char buffer[1024];
   FILE * file = fmemopen(buffer, 1024, "w");
   // REQUIRE ( NULL != file);

   vecteurToFile(file, v1, 3);

   fclose(file);

   // verification de ce qui est envoye sur le flux
   // chaque composante est affichee avec trois chiffre apres la virgule
   // %.3f
   CHECK( 0==strcmp(buffer, "1.000 2.000 3.000 ") );
}


TEST(AffichageB) {
   // vecteur dynamique a afficher
   float * v1 = NULL;
   // creation du flux de texte => buffer
   char buffer[1024];


   v1 = (float *) malloc(3 * sizeof(float));
   REQUIRE ( NULL != v1 ) ; // allocation impossible ?

   v1[0] = 3.0;
   v1[1] = 2.0;
   v1[2] = 1.0;

   FILE * file = fmemopen(buffer, 1024, "w");
   REQUIRE ( NULL != file); // ouverture du flux impossible ?

   vecteurToFile(file, v1, 3);

   fclose(file);

   // verification de ce qui est envoye sur le flux
   // chaque composante est affichee avec trois chiffre apres la virgule
   // %.3f
   CHECK( 0==strcmp(buffer, "3.000 2.000 1.000 ") );
}
*/

typedef float * VecteurType;
VecteurType vecteurFromFileByName(const char * nom_fic, int * p_ordre);

TEST(LectureA, "verification des ordres des vecteurs") {
   int     ordre;
   float * vec = NULL;

   vecteurFromFileByName("v1.txt", &ordre);
   CHECK( 3 == ordre );

   vecteurFromFileByName("v2.txt", &ordre);
   CHECK( 6 == ordre );

//   vecteurFromFileByName("v3.txt", &ordre);
//   CHECK( 3 == ordre );

   // fichier non existant

   vec = vecteurFromFileByName("v0.txt", &ordre);
   CHECK( NULL == vec);

}

/*
TEST(LectureB, "verification de v1.txt") {
   int     ordre;
   float * vec;

   vec = vecteurFromFileByName("v1.txt", &ordre);
   CHECK  ( 3    == ordre );
   REQUIRE( NULL != vec); // si vec est null, on ne veut pas continuer le test

   CHECK( EQ(vec[0], 5.0) );
   CHECK( EQ(vec[1], 6.3) );   // :-))
   CHECK( EQ(vec[2], 7.0) ); 
} */

/*
TEST(LectureC, "verification de v2.txt") {
   int     ordre;
   float * vec;

   vec = vecteurFromFileByName("v2.txt", &ordre);
   CHECK  ( 6    == ordre );
   REQUIRE( NULL != vec); // si vec est null, on ne veut pas continuer le test

   CHECK( EQ(vec[0], 6.1) );
   CHECK( EQ(vec[1], 5.2) );
   CHECK( EQ(vec[2], 4.3) );
   CHECK( EQ(vec[3], 3.4) );
   CHECK( EQ(vec[4], 2.5) );
   CHECK( EQ(vec[5], 1.6) );
} */

/*
TEST(LectureD, "verification de v3.txt") {
   int     ordre;
   float * vec;

   vec = vecteurFromFileByName("v3.txt", &ordre);
   CHECK  ( 3    == ordre );
   REQUIRE( NULL == vec); // v3 est incomplet, on veut que ce soit nul
} */


/*
TEST(PVA) {
	float * v1  = NULL;
	float v2[3] = { 1.0, 2.0, 3.0};
	int   ordre = 0;

	v1 = vecteurFromFileByName("v1.txt", &ordre);
	CHECK   ( 3    == ordre);
	REQUIRE ( NULL != v1);

	CHECK( EQ( 38, produitScalaire(v1, v2, ordre)));
}
*/
END_TEST_GROUP(vecteur)


int main(void) {
	RUN_TEST_GROUP(vecteur); 
 	return 0;
}
