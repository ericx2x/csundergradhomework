/*******************************************************/
/* main.c                                              */
/*******************************************************/

#include "tree.c"
#include "symboltable.h"
#include "expressions.c"

main() {

  int result ;
  tree T ;
  symbol_table symtab ;
  char yn ;

  printf("Enter the expression (postfix notation): ");
  if (read_expr(&T) == ERROR ) {
    fprintf(stderr, "Error reading expression.\n");
    exit(-1);
  }

  printf("Expression is: ");
  print_expr(T);

  do {
    read_symbols(&symtab);
    eval_expr(T, symtab, &result);
    printf("Expression value is %d\n", result ) ;
    printf("Are there more values (y or n)? ") ;
    scanf(" %c", &yn);
  } while (yn == 'y' || yn == 'Y' ) ;
  printf("End of program.\n");
}

void read_symbols ( symbol_table *symtab ) {

  int A, B, C ;

  printf("Enter values of A, B, C: " ) ;
  scanf("%d %d %d", &A, &B, &C ) ;

  set_symbol( symtab , 'A', A ) ;
  set_symbol( symtab , 'B', B ) ;
  set_symbol( symtab , 'C', C ) ;
}

