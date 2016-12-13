/***************************************/
/* Eric Lima                           */
/*                                     */
/* Exercise 6-2                        */
/*                                     */
/* Computing 4                         */
/***************************************/

#include "intstack.h"
#include <iostream>

using namespace std;

int main ( int argc, char *argv[] ) {

  IntStack i( 3 );
  IS s(i);
  int x;

  cout << "A size 3 int stack had been made. " << endl;

  s.empty();

  for ( x = 0; x < 3; x++ ) 
    i.push(x);

  s.full();

  IntStack b( 3 );
  b = i;

  return 0;
}
