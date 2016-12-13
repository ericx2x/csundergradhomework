/*********************************/
/* symboltable.h                 */
/*********************************/

#ifndef _symbol
#define _symbol

typedef struct symbol_table { int A ; int B ; int C ; } symbol_table ;

void set_symbol( symbol_table *p_symtab, char sym, int value ) ;

int get_symbol ( symbol_table symtab, char sym ) ;

#endif
