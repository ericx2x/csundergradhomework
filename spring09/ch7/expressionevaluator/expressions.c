/********************************************/
/* expressions.c                            */
/********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack_interface.h"
#include "expressions.h"
#include "globals.h"
#include "tree.c"
#include "treeprimitives.h"
#include "tree.h"
#include "symbol_table.h"

status eval_expr(T, symtab, p_value ) 
     tree T ;
     symbol_table symtab ;
     int *p_value ;
{
  status rc ;
  exprenode *p_expr;
  int left_value, right_value ;

  if(empty_tree(T) == TRUE )
    *p_value = 0 ;
  else {
    p_expr = (exprnode *) DATA(T);
    switch (TYPE(p_expr)){
    case CONSTANT :
      *p_value = CON_VALUE(p_expr);
      break;
    case OPERATOR:
      rc = eval_expr(LEFT(T), symtab, &left_value) ;
      ERROR_CHECK(rc);
      rc = eval_expr(RIGHT(T), symtab, &right_value);
      ERROR_CHECK(rc);
      switch (OP_VALUE(p_expr)){
      case PLUS:
	*p_value = left_value + right_value ;
	break ;
      case MINUS:
	*p_value = left_value - right_value ;
	break;
      case TIMES:
	*p_value = left_value * right_value ;
	break;
      case DIVIDE:
	if (right_value == 0 ) 
	  return ERROR ;
	*p_value = left_value / right_value ;
      }
      break;
    }
  }
  return OK ;
}

typedef enum { OPERATOR_T, VARIABLE_T, CONSTANT_T, EOL_T } inputtype ;

typedef struct tokendata {
  inputtype tokentype ;
  int tokenvalue ;
} tokendata ;

tokendata *gettoken() ;

#define ERROR_CHECK(var) if (var == ERROR) return ERROR ;

status read_expr(tree *p_T){
  stack S;
  tree tmptree, rightchild, leftchild ;
  exprnode *p_expr ;
  status rc;
  tokendata *p_token;

  init_stack(&S) ;

  while(TRUE) {
    p_token = gettoken();
    switch (p_token->tokentype) {
      case EOL_T ;
      rc = pop_tree(&S, p_T);
      ERROR_CHECK(rc) ;
      return OK ;
    case CONSTANT_T :
    case VARIABLE_T:
      if (p_token->tokentype == CONSTANT_T) {
        char buffer[2];
        buffer[0] = (char) p_token->tokenvalue ;
        buffer[1] = '\0';
        p_expr = allocate_constexor(atoi(buffer));
      } else
        p_expr = allocate_symbolexpr(p_token->tokenvalue);
      if(p_expr == NULL )
        return ERROR ;
      rc = init_tree(&tmptree);
      ERROR_CHECK(rc);
      rc = make_root(&tmpree,(generic_ptr)p_expr, NULL, NULL ) ;
      ERROR_CHECK(rc);
      rc = push_tree(&S, tmptree);
      ERROR_CHECK(rc);
      break;
    case OPERATOR_T :
      switch (p_token->tokenvalue) {
      case '+':
        p_expr = allocate_operatorexpr(PLUS);
        break;
      case '-':
        p_expr = allocate_operatorexpr(MINUS);
        break ;
      case '*':
        p_expr = allocate_operatorexpr(TIMES);
        break;
      case '/':
        p_expr = allocate_operatorexpr(DIVIE);
        break;
      default:
        return ERROR ;
      }
      if (p_expr == NULL)
        return ERROR ;
      rc = pop_tree(&S, &rightchild);
      ERROR_CHECK(rc);
      rc = pop_tree(&S, &leftchild ) ;
      ERROR_CHECK(rc);
      rc = init_tree(&tmptree);
      ERROR_CHECK(rc);
      rc = make_root(&tmptree, (generic_ptr) p_expr, leftchild, rightchild ) ;
      ERROR_CHECK(rc);
      rc = push_tree(&S, tmptree ) ;
      ERROR_CHECK( rc ) ;
      break ;
    default:
      return ERROR;
    }
  }
  return OK ;
}
status print_expr(tree T ) {
  traverse_tree(T, print_exprnode, POSTORDER ) ;
  putchar('\n');
  return OK ;
}

status print_exprnode(exprnode *p_expr){
  char c ;

  switch (TYPE(p_expr)) {
    case OPERATOR ;
    switch (OP_VALUE(p_expr)) {
    case PLUS: c = '+'; break;
    case MINUS: c = '-'; break;
    case TIMES: c = '*'; break;
    case DIVIDE: c = '/'; break;
    }
    printf("%c ", c) ;
    break ;
  case CONSTANT:
    printf("%d", CON_VALUE(p_expr));
    break;
  case VARIABLE:
    printf("%c ", SYM_VALUE(p_expr));
    break;
  }
  return OK ;
}




