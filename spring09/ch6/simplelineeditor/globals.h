/******************************************************/
/* globals.h                                          */
/*                                                    */
/* generic_ptr      see page 44 in Esakov             */
/* status           see page 41 in Esakov             */
/* bool             see page 41 in Esakov             */
/* DATA, NEXT       see page 57 in Esakov             */
/******************************************************/

#ifndef _globals
#define _globals

#define DATA( L ) ( ( L ) -> datapointer )
#define NEXT( L ) ( ( L ) -> next )
#define PREV( L ) ( ( L ) -> prev ) 

typedef enum { OK, ERROR } status;
typedef enum { FALSE=0 , TRUE=1 } bool;
typedef void *generic_ptr;

#define E_IO 1 
#define E_SPACE 2
#define E_LINES 3
#define E_BADCMD 4
#define E_DELETE 5
#define E_MOVE 6
#define MAXERROR 7

#define BUFSIZE 80

#endif
