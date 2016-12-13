/***************************************/
/* Eric Lima                           */
/*                                     */
/* Exercise 6-4                        */
/*                                     */
/* Computing 4                         */
/***************************************/

#include "classes.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main ( int argc, char *argv[] ) {

  int flag = 1, i;
  string s;
  string filename;
  
  cout << "Please enter input filename: ";
  cin >> filename;

  ifstream inFile( filename.c_str() );

  //determine if it is double slash or minus
  s = getline( inFile );

  for ( i = 0; i < s.length; i++ ) {
    if ( s[i] == '/' ) 
      if ( s[++i] == '/' ) {
	flag++;
	break;
      }
    if ( s[i] == '-' )
      if ( s[++i] == '-' ) {
	flag--;
	break;
      }
  }

  if ( flag == 1 ) {
    cout << "This file is neither type." << endl;
    return 0;
  }
  //now we have what we want, time to use the factory

  if ( flag == 2 ) {
    FileFactory *factory = new FileSlashFactory;
    File *dafile;

    dafile = factory->createFileSlash;

    dafile.display();
    close inFile;
  }

  else {
    FileFactory *factory = new FileDashFactory;
    File *dafile;

    dafile = factory->createFileDash;

    dafile.display();
    close inFile;
  }
 
  return 0;
}
