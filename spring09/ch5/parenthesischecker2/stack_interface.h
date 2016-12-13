/*************************/
/* stack_interface.h     */
/*************************/

#include "globals.h"

extern status push_char(stack *p_S, char c);
extern status pop_char(stack *p_S, char *p_c);
extern status top_char(stack *p_S, char *p_c);
