#include <stdio.h>
#include "token.h"
#include "stack.h"
#include "char_interface.h"

#define PUSH(s, c) if (push_char(s, c) == ERROR) { printf("Fatal error in pushing symbol on stack.\n"); exit(1); }
#define POP(s, c) if (pop_char(s, c) == ERROR) { printf("Fatal error in popping symbol off stack.\n"); exit(1); }
#define TOP(s, c) if (top_char(s, c) == ERROR) { printf("Fatal error in top operation.\n"); exit(1); }

int stackprec(stack *p_S);
int inputprec(char c);
void skiptoeol();
void clearstack(stack *p_S);

int main(int arc, char *argv[]){

   stack S;
   tokendata *p_token;
   char stacksymbol;
   bool eofreached = FALSE;

   init_stack(&S);
   PUSH(&S, BOTTOMMARKER);

   do {
      p_token = gettoken();

      switch (p_token->tokentype){

         case EOF_T:
            eofreached = TRUE;
            break;

         case VARIABLE_T:
            printf("%c ", p_token->tokenvalue);
            break;

         case OPERATOR_T:
            while (stackprec(&S) >= inputprec(p_token->tokenvalue)) {
               POP(&S, &stacksymbol);
               printf("%c ", stacksymbol);
            }
            PUSH(&S, p_token->tokenvalue);
            break;

         case RIGHTPAREN_T:
            do {
               POP(&S, &stacksymbol);

               if(stacksymbol == BOTTOMMARKER) {
                  printf("Error in expression.\n");
                  skiptoeol();
                  clearstack(&S);
                  break;
               }

               if (stacksymbol != '(')
                  printf("%c ", stacksymbol);
            } while (stacksymbol != '(');
            break;

         case EOL_T:
            TOP(&S, &stacksymbol);
            
            while (stacksymbol != BOTTOMMARKER) {
               POP(&S, &stacksymbol);
               if (stacksymbol == '(') {
                  printf("Error in expresion.\n");
                  clearstack(&S);
               }
               else printf("%c ", stacksymbol);
               
               TOP(&S, &stacksymbol);
            }

            putchar('\n');
            break;
      }
   } while(eofreached == FALSE);

   return 0;
}

                     
int stackprec(stack *p_S){

   char topsymbol;

   TOP(p_S, &topsymbol);

   switch (topsymbol) {
      case '(':
         return 0;
      case '*':
      case '/':
         return 2;
      case '+':
      case '-':
         return 1;
      case '$':
         return -1;
      default:
         printf("Unknown symbol on stack: %c\n", topsymbol);
         return -1;
   }
   
   /* Cannot get here */
   return -1;
}


int inputprec(char c){

   switch(c){
      case '(':
         return 3;
      case '*':
      case '/':
         return 2;
      case '+':
      case '-':
         return 1;
      default:
         printf("Unknown operator in input: %c\n", c);
         return -1;
   }

   /* Cannot get here */
   return -1;
}


void skiptoeol(){

   tokendata *p_token;

   do {
      p_token = gettoken();
   } while(p_token->tokentype != EOL_T && p_token->tokentype != EOF_T);
   putchar('\n');
}


void clearstack(stack *p_S){

   char c;

   while (empty_stack(p_S) == FALSE)
      POP(p_S, &c);
   
   PUSH(p_S, BOTTOMMARKER);
}
