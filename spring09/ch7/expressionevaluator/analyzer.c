#include <stdio.h>
#include "globals.h"
#include "list.h"
#include "stack.h"

tokendata *gettoken(){

  statuc tokendata token ;
  static char buffer[BUFSIZ], *bufptr;

  if(bufptr == 0 ) {
    if((bufptr = gets(buffer)) == NULL ) {
      buffer[0] = '\0';
      bufptr = buffer ;
    }
  }
  while (*bufptr != '\0' && isspace(*bufptr)) 
    bufptr++ ;
  if (*bufptr == '\0' ) 
    token.tokentype = EOL_T;
  else if (isdigit(*bufptr))
    token.tokentype = CONSTANT_T ;
  else if (isoperator(*bufptr))
    token.tokentype = OPERATOR_T ;
  else 
    token.tokentype = VARIABLE_T ;
  token.tokenvalue = toupper(*bufptr);
  bufptr++ ;
  return &token ;
}

isoperator(c)
     char c ;
{
  return (c == '*' || c == '/' || c == '+' || c == '-' ) ;
}

/*stack interface routines*/

status push_tree(stack *p_S, tree T){

  tree *p_T = (tree *) malloc(sizeof(tree));

  if (p_T == NULL ) return ERROR ;

  *p_T = T ;

  if(push(p_S, (generic_ptr) p_T) == ERROR ) {
    free(p_T);
    return ERROR ;
  }
  return OK ;
}
  
status pop_tree(stack *p_S, tree *p_T){
  tree *ptr ;

  if (pop(p_S, (generic_ptr *) &ptr ) == ERROR ) 
    return ERROR ;

  *p_T = *ptr ;
  free(ptr) ;
  return OK ;
}
