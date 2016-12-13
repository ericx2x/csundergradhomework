/***************************/
/* polynomial.c            */
/***************************/

#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

extern status read_poly(polynomial *p_poly){

   int coef;
   int degree;

   if (init_list(p_poly) == ERROR)
      return ERROR;

   do {
      printf("Enter the coefficient, degree (0,0 when done): ");
      scanf(" %d,%d", &coef, &degree);

      if (coef != 0)
         if(term_insert(p_poly, coef, degree) == ERROR)
            return ERROR;
   } while (coef != 0 || degree != 0);

   return OK;
}


status write_term(term *p_term){

   printf(" + %dx^%d:", p_term->coefficient, p_term->degree);
   return OK;
}

extern void write_poly(polynomial poly){

   traverse(poly, write_term);
}


int cmp_degree(term *p_term1, term *p_term2){

   return p_term1->degree - p_term2->degree;
}

extern status add_poly(polynomial *p_poly1, polynomial *p_poly2){

   list lastreturn = NULL;
   list match_node;
   term *p_term;
   term *p_match_term;
   int coef, degree;

   while ( (lastreturn = list_iterator(*p_poly1, lastreturn)) != NULL){

      p_term = (term *) DATA(lastreturn);
      if (find_key(*p_poly2, (generic_ptr)p_term, cmp_degree, &match_node) == OK){
         p_match_term = (term *)DATA(match_node);
         p_term->coefficient += p_match_term->coefficient;

         delete_node(p_poly2, match_node);
         free(p_match_term);
      }
   }

   while (empty_list(*p_poly2) == FALSE){
      if(term_delete(p_poly2, &coef, &degree) == ERROR)
         return ERROR;
      else if (term_insert(p_poly1, coef, degree) == ERROR)
         return ERROR;
   }

   return OK;
}


extern void destroy_poly(polynomial *p_poly){
   
   destroy(p_poly, free);
}
