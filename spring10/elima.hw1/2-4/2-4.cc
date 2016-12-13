/*******************************/
/* Eric Lima                   */
/*                             */
/* Exercise 2-4                */
/*                             */
/* Feb 12, 2010                */
/*******************************/


#include <iostream>
#include <fstream>
#include <string>

using namespace std ;

int main( int argc, char *argv[] ) {

  int linecount ;
  char c1, c2 ;
  string s1, s2 ;
  ifstream file1, file2 ;

  // Compare character by character

  if ( argc == 3 ) {

    file1.open( argv[1] ) ;
    file2.open( argv[2] ) ;   

    c1 = file1.get() ;
    c2 = file2.get() ;

    while ( c1 != EOF && c2 != EOF ) {

      if ( c1 != c2 ) {

	cout << "Files are not equal.\n" << endl ;
	break ;
      }

    c1 = file1.get() ;
    c2 = file2.get() ;

    if ( c1 == EOF && c2 != EOF || c1 != EOF && c2 == EOF )
      cout << "Are not equal.\n" << endl ;

    }
    
    if ( c1 == EOF && c2 == EOF ) 
      cout << "Are equal.\n" << endl ;
  }

  // Printing out line numbers that are different

  else if ( argc == 4 ) {

    linecount = 1 ;

    file1.open( argv[2] ) ;
    file2.open( argv[3] ) ;   

    getline( file1, s1 ) ;
    getline( file2, s2 ) ;

    while ( !file1.eof() || !file2.eof() ) {          

      if ( s1 != s2 ) 
	cout << "Are not equal on line number " << linecount << endl ;    

      getline( file1, s1 ) ;
      getline( file2, s2 ) ;

      linecount++ ;
    
    }
  }  

  //else wrong arguments were entered at command line

  else 
    cout << "Wrong arguments.\n" << endl ;

    file1.close() ;
    file2.close() ;

  return 0 ;
}			     