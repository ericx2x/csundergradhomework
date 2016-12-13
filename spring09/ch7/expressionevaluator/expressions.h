/********************************************/
/* expressions.h                            */
/********************************************/

#ifndef _expressions
#define _expressions

#include "treeprimitives.h"
#include "globals.h"
#include "symboltable.h"


typedef enum { OPERATOR, CONSTANT, VARIABLE } NodeType ;
typedef enum { PLUS, MINUS, TIMES, DIVIDE } Operator ;

typedef struct exprnode {

  NodeType nodetype ;
  union { Operator optype; char symbolname ; int constvalue ; } nodevalue ;

} exprnode ;

#define TYPE(n) ((n) -> nodetype )

#define OP_VALUE(n) ((n)->nodevalue.optype)

#define SYM_VALUE(n) ((n)->nodevalue.symbolname)

#define CON_VALUE(n) ((n)-> nodevalue.constvalue)

extern exprnode *allocate_constexpr (int value) ;
extern exprnode *allocate_symbolexpr (char value ) ;
extern exprnode *allocate_operatorexpr (Operator value ) ;
extern status read_expr( tree *p_T ) ;
extern status print_expr( tree T ) ;
extern status eval_expr ( tree T, symbol_table symtab, int *p_value ) ;

#endif
