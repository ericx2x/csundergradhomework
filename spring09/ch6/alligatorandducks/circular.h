/***************************/
/* circular.h              */
/***************************/

#ifndef _circular
#define _circular

#include "globals.h"

typedef struct node node, *list;
struct node {generic_ptr datapointer; list next; } ;

status allocate_node(list *p_L, generic_ptr data);
void free_node(list *p_L);

status init_circ_list (list *p_L);
bool empty_circ_list (list L);
status circ_insert (list *p_L, generic_ptr data);
status circ_append (list *p_L, generic_ptr data);
status circ_delete (list *p_L, generic_ptr *p_data);
status circ_delete_node (list *p_L, list node);
status circ_traverse (list L, status (*p_func_f)());

#endif
