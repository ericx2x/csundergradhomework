/*****************/
/* token.c       */
/*****************/

#include <stdio.h>
#include "token.h"
#include "globals.h"

tokendata *gettoken(){

   static bool eof = FALSE;
   static char buffer[BUFSIZ], *bufptr = NULL;
   static tokendata token;
   char *operators = "+-*/(";

   if (eof == TRUE) {
      token.tokentype = EOF_T;
      return &token;
   }

   if(bufptr == NULL){

      printf("? ");
      if ((bufptr = gets(buffer)) == NULL || *bufptr == '\0'){
         eof = TRUE;
         token.tokentype = EOF_T;
         return &token;
      }
   }

   while(isspace(*bufptr))
      bufptr++;

   if (*bufptr == '\0')
      token.tokentype = EOL_T;
   else if (*bufptr == ')')
      token.tokentype = RIGHTPAREN_T;
   else if (strchr(operators, *bufptr) != NULL)
      token.tokentype = OPERATOR_T;
   else
      token.tokentype = VARIABLE_T;

   token.tokenvalue = *bufptr;

   if (token.tokentype == EOL_T)
      bufptr = NULL;
   else
      bufptr++;

   return &token;
}










   
