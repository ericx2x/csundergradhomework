
#include <stdlib.h>
#include "treeprimitives.h"
#include "globals.h"
#include "queue.h"

typedef enum { OPERATOR, CONSTANT, VARIABLE } NodeType ;
typedef enum { PLUS, MINUS, TIMES, DIVIDE } Operator ;
typedef struct exprnode {
  NodeType nodetype ;
  union {
    Operator optype ;
    char symbolname ;
    int constvalue ;
  } nodevalue ;
}exprnode ;

#define TYPE(n) ((n)->nodetype)
#define OP_VALUE(n)((n)->nodevalue.optype)
#define SYM_VALUE(n) ((n)->nodevalue.symbolname)
#define CON_VALUE(n) ((n)->nodevalue.constvalue)

exprnode *allocate_constexpr(int value) {
  exprnode *p_expr = (exprnode *)malloc(sizeof(exprnode));
  if (p_expr != NULL ) {
    TYPE(p_expr) = CONSTANT ;
    CON_VALUE(p_expr)=value ;
  }
  return p_expr ;
}

exprnode *allocate_symbolexpr( Operator value ){
  
  exprnode *p_expr = (exprnode *) malloc(sizeof(exprnode));
  
  if(p_expr != NULL ) {
    TYPE(p_expr)=OPERATOR ;
    OP_VALUE(p_expr) = value ;
  }
  return p_expr ;
}
