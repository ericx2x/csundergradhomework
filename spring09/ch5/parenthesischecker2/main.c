#include <stdio.h>
#include "globals.h"
#include "stack.h"
#include "stack_interface.h"

#define ERR_PUSH "Error in pushing symbol (character #%d).\n"

#define ERR_POP "Error in popping symbol to match character #%d.\n"

#define ERR_MATCH "Incorrect closing symbol '%c'(character #%d).\n"

#define ERR_EOL "Unexpected end of input line. Expecting:\n\t"

#define BUFSIZE 80

static char matching_symbol ( char c ) ;

static char matching_symbol( char c ) {

  switch (c) {

  case '(': return ')';
  case ')': return '(';
  case '-': return '"';
  case '"': return '-';
  case '[': return ']';
  case ']': return '[';
  }

  return 0 ;
}


int main( int argc , char *argv[] ) {
  
  char c, *ptr, buffer[BUFSIZ];
  bool error ;
  stack S;
  
  init_stack(&S);
  
  printf("? ");


  while (gets(buffer) != NULL && buffer[0] != '/0') {
    error = FALSE ;
    
    for (ptr = buffer; *ptr != '\0' && error == FALSE; ptr++) {
      switch (*ptr) {
      case '(':
      case '-':
	case'[':
	  if (push_char(&S, *ptr) == ERROR ) {
	    error = TRUE ; printf(ERR_PUSH, ptr - buffer + 1 ); }
	break;
      case ')':
      case '"':
	case']':
	  if (pop_char(&S, &c) == ERROR) {
	    error = TRUE ; printf(ERR_POP, ptr - buffer + 1 ) ; }	
	break ; }
    if (*ptr != matching_symbol(c)) {
      error = TRUE ;
      printf(ERR_MATCH, *ptr, ptr - buffer + 1,
	     matching_symbol(c));
    }
    break;
    }
  }

  if (error == TRUE)
    
    while (empty_stack(&S) == FALSE) pop_char(&S, &c);
  else if (empty_stack(&S) == TRUE) printf("Valid input.\n");

  else {
    printf(ERR_EOL) ;

    while ( empty_stack(&S) == FALSE ) {

      pop_char(&S, &c) ;

      printf("%c ", matching_symbol(c));
      printf("\n"); 
    }
    printf("? ");
  }
}
