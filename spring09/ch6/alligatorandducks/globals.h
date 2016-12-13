/*************************************/
/* globals.h                         */
/*************************************/

#ifndef _globals
#define _globals

#define DATA(L) ((L) -> datapointer)
#define NEXT(L) ((L) -> next)

typedef enum { OK, ERROR } status;
typedef enum { FALSE=0, TRUE=1 } bool;
typedef void *generic_ptr;

#endif
