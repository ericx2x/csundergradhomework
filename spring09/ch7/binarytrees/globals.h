/*************************************/
/* globals.h                         */
/*************************************/

#ifndef _globals
#define _globals

#define DATA(L) ((L) -> datapointer)
#define NEXT(L) ((L) -> next)
#define RIGHT(T) ((T) -> right)
#define LEFT(T) ((T) -> left)

typedef enum { OK, ERROR } status;
typedef enum { FALSE=0, TRUE=1 } bool;
typedef void *generic_ptr;

#endif
