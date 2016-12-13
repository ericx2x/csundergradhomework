/*****************************************************************************/
/* Polynomial Addition Program - listinterface.h                             */
/* Eric J Lima                                                               */
/* Last Modified January 30, 2009                                            */
/*****************************************************************************/
#ifndef INC_LISTINTERFACE_H
#define INC_LISTINTERFACE_H

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "globals.h"
#include "polynomial.h"

extern status term_insert(list *p_L, int coef, int deg);
extern status term_delete(list *p_L, int *p_coef, int *p_deg); 

#endif /* INC_LISTINTERFACE_H */
