/*************************************/
/* globals.h                         */
/*************************************/

#ifndef _globals
#define _globals

#define DATA( L ) ( ( L ) -> datapointer )
#define NEXT( L ) ( ( L ) -> next )
#define PREV( L ) ( ( L ) -> prev )

typedef enum { OK, ERROR } status ;
typedef enum { FALSE = 0, TRUE = 1 } bool ;

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
