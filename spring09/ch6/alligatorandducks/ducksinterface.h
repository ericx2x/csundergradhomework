/**********************/
/* ducksinterface.h   */
/**********************/

#ifndef _ducksinterface
#define _ducksinterface

#include <stdio.h>
#include "globals.h"
#include "duck.h"

duck getnextduck(list *p_L, int m);
status circ_append_duck(list *p_L, duck *p_duck);

#endif
