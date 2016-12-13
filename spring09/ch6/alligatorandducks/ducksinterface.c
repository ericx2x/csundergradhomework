/**********************/
/* ducksinterface.c   */
/**********************/

#include <stdio.h>
#include "globals.h"
#include "circular.h"
#include "ducksinterface.h"
#include "duck.h"

duck getnextduck(list *p_L, int m){

   int i;
   duck *p_duck;
   
   for (i = 1; i < m; i++) 
      *p_L = NEXT(*p_L);
   
   circ_delete (p_L, (generic_ptr *) &p_duck);

   return *p_duck;
}


status circ_append_duck(list *p_L, duck *p_duck){

   return circ_append(p_L, (generic_ptr) p_duck);
}

