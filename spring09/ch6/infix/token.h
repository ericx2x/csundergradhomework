/****************************/
/* token.h                  */
/****************************/

#ifndef _token
#define _token

#include <stdio.h>

#define BOTTOMMARKER '$'
typedef enum { EOF_T, EOL_T, OPERATOR_T, VARIABLE_T, RIGHTPAREN_T } inputtype;

typedef struct {
   inputtype tokentype;
   char tokenvalue;
} tokendata;

tokendata *gettoken();

#endif
