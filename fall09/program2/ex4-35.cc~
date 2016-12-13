/***************************************/
/* Eric Lima                           */
/*                                     */
/* Exercise 4.35                       */
/*                                     */
/* October 13, 2009                    */
/***************************************/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main( int argc, char *argv[] ) {

  string strings ;
  vector<string> s ;

  cout << "Enter in strings and press Ctrl+D to end the process." << endl ;
  
  while ( cin >> strings )
    s.push_back(strings) ;

  cout << endl ;

  char **c = new char*[s.size()] ;
  
  for ( vector<string>::size_type i = 0; i < s.size(); i++ ) {
      
    char *a = new char[ s[i].size() ] ;
    const char *b = s[i].c_str() ;
    strcpy( a, b ) ;
    cout << a << endl ;
    c[i] = a ;
    
  }   
  
  
  for ( vector<string>::size_type i = 0; i < s.size(); i++ )
    cout << s[i] << endl ;
  
  return 0 ;

}
