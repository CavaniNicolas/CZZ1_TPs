#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "teZZt.h"
#include "calculator.h"


BEGIN_TEST_GROUP(tableau_structure)

TEST(identification_avec_enum) {
   CHECK(   ID == identification("x"));
   CHECK( NONE == identification("x\n"));
   CHECK(  SIN == identification("sin(x)"));
   CHECK(  COS == identification("cos(x)"));
   CHECK(  LOG == identification("log(x)"));
   CHECK(  EXP == identification("exp(x)"));
   CHECK( NONE == identification("t"));
}

TEST(control_eval_f) {
   CHECK( EQ(0.0, evalf( 0.0, ID)));
   CHECK( EQ(0.0, evalf( 0.0, SIN)));
   CHECK( EQ(1.0, evalf( 0.0, COS)));
   CHECK( EQ(0.0, evalf( 0.0, ID)));

   CHECK( EQ(      M_PI , evalf( M_PI, ID)));
   CHECK( EQ(       0.0 , evalf( M_PI, SIN)));
   CHECK( EQ(      -1.0 , evalf( M_PI, COS)));
   CHECK( EQ( exp(M_PI) , evalf( M_PI, EXP)));

   CHECK( EQ( 0.0 , evalf( M_PI/2.0, COS)));
}

END_TEST_GROUP(tableau_structure)


/*int main(void) {
	RUN_TEST_GROUP(tableau_structure); 
   return 0;
}
*/