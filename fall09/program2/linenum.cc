/***************************************/
/* Eric Lima                           */
/*                                     */
/* Program Linenum                     */
/*                                     */
/* October 13, 2009                    */
/***************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main( int argc, char *argv[] ) {

  ifstream infile( argv[1] ) ;
  int n = 1 ;
  string s1 ;

  while ( getline( infile, s1 ) )                        //simple get line function
    cout << n++ << setw( s1.size() + 8 ) << s1 << endl ; //making space of 8
    

  infile.close();

  return 0 ;

}
