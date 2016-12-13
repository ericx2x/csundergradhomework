/***************************************/
/* Eric Lima                           */
/*                                     */
/* Project 2                           */
/*                                     */
/* March 25, 2010                      */
/***************************************/

#include <iostream>
#include <string>
#include "tree.h"

using namespace std;

int main ( int argc, char *argv[] ) {

  Node *tmp = new Node( );
  string s;

  cout << "\nPlease, enter a label for a tree. ";
  cin >> s;

  Tree t(s);

  cout << "\nThe root of the new tree is ";
  *tmp = t.getRoot();

  if ( tmp != NULL )
    cout << tmp->label << endl;

  else cout << "This tree is empty." << endl;

  cout << "\nNow please enter a label for the child node. ";
  cin >> s;

  t.root->insertLeft( s );


  cout << "\n Please, enter a label for a sibling of node. " << s << ": ";
  cin >> s;

  t.root->leftchild->insertRight( s );


  cout << "\nNow inserting node 'g' as a child of the root." << endl;
  
  cout << "Now inserting node 'd' as a child of " << s << "." << endl;
  
  cout << "Now inserting node 'e' as a child of " << s << "." << endl;
  
  cout << "Now inserting node 'f' as a child of e." << endl;


  t.root->getleftchild().insertRight( "g" ).insertLeft( "d" ).insertRight( "e" ).insertLeft( "f" );


  cout << "\nNow performing a depth first search on the tree" <<endl;
  
  cout << "Printing each label of the node as it reaches it" << endl;
  
  t.root->dfs();

  cout << "\nComplete." << endl;


  return 0 ;
}
