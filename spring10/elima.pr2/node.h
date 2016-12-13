/***************************************/
/* Eric Lima                           */
/*                                     */
/* Project 2                           */
/*                                     */
/* March 25, 2010                      */
/***************************************/

#ifndef _NODE
#define _NODE

#include <string>

using namespace std;

class Node {

 public:
  Node( string );
  Node();
  ~Node();

  Node& next( ) ;
  Node& getleftchild() ;
  Node& insertLeft( string s );
  Node& insertRight( string s );

  void dfs ( );

  Node *leftchild; 
  Node *rightchild; 
  string label;
};

#endif
