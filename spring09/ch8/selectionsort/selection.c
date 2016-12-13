/*******************************************************************/
/* Programmer: Eric J Lima                                         */
/*                                                                 */
/* Polymorphic Selection Sort Function                             */
/*******************************************************************/

#include "globals.h"

void selection_sort( generic_ptr data[], int n , int (*p_cmp_f)()){

  generic_ptr *p_minimum, *p_i, *p_j, tmp ;
  generic_ptr *p_lastelement = data + n - 1 ;

  for ( p_i = data ; p_i < p_lastelement ; p_i++ ) {

    p_minimum = p_i ; 

  for ( p_i = p_i + 1 ; p_j <= p_lastelement ; p_j++ ) 

    if ( (*p_cmp_f)(*p_minimum, *p_j) > 0 ) p_minimum = p_j ;

    tmp = *p_i ;
    *p_i = *p_minimum ;
    *p_minimum = tmp ;
  }
}
