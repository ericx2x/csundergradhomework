
#include <stdlib.h>

bool Equal(list L1, list L2 ) int (*p_cmp_f)()){
if Empty list(L1) && Emptylist(L2) return TRUE ;
if Empty (L1) && Empty L2 return false ;
if !Empty L1 && Empty L2 return false ; 
return ( ( *p_cmp_f)(Data(L1), Data(L2) ) == 0 ) && equal ( Next ( L1 ), Next( ( L2 ), p_cmp_f ) ;
