/*********************************/
/* listinterface.c               */
/*********************************/

#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"
#include "listinterface.h"

extern status term_insert(list *p_L, int coef, int deg){
   
   term *p_term = (term *) malloc(sizeof(term));

   if(p_term == NULL)
      return ERROR;

   p_term->coefficient = coef;
   p_term->degree = deg;

   if (insert(p_L, (generic_ptr) p_term) == ERROR) {
      free(p_term);
      return ERROR;
   }

   return OK;
}


extern status term_delete(list *p_L, int *p_coef, int *p_deg){

   term *p_term;

   if(delete(p_L, (generic_ptr *) &p_term) == ERROR)
      return ERROR;

   *p_coef = p_term->coefficient;
   *p_deg = p_term->degree;

   free(p_term);
   return OK;
}

                        
