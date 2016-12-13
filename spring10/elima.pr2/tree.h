/***************************************/
/* Eric Lima                           */
/*                                     */
/* Project 2                           */
/*                                     */
/* March 25, 2010                      */
/***************************************/

#ifndef _TREE
#define _TREE

#include "node.h"

class Tree : public Node {
 public:
  Tree( string );
  Tree();
  ~Tree();

  Node& getRoot();

  Node *root; 

};

#endif
