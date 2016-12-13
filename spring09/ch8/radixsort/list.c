/*********************************************/
/*                                           */
/* list.c //Simple linked list               */
/*                                           */
/* Eric Lima                                 */
/* 21 JAN 2009                               */
/*                                           */
/*********************************************/
#include <stdlib.h>
#include "globals.h"
#include "list.h"

extern status allocate_node(list *p_L, generic_ptr data)
{
    list L = (list) malloc(sizeof(node));
    
    if (L == NULL) { return ERROR; }

    *p_L = L;
    DATA(L) = data;
    NEXT(L) = NULL;
    return OK;
} 

extern void free_node(list *p_L)
{
    free(*p_L);
    *p_L = NULL;
}

extern status init_list(list *p_L)
{
    /*
     * Initialize *p_L by setting the list pointer to NULL.
     * Always return OK (a different implementation
     * may allow errors to occur).
     */

    *p_L = NULL;
    return OK;
}

extern bool empty_list(list L) 
{
    /*
     * Return TRUE if L is an ampty list, FALSE otherwise.
     */
    return (L == NULL) ? TRUE : FALSE;
}

extern status insert(list *p_L, generic_ptr data) 
{
    list L;

    /*
     * Insert a new node containing data as the first item in *p_L.
     */

     if (allocate_node(&L, data) == ERROR) { return ERROR; }
     NEXT(L) = *p_L;
     *p_L = L;
     return OK;
}

extern status append(list *p_L, generic_ptr data)
{    
    /*
     * Append a new node containing data as the last item in *p_L.
     */

    list L, tmplist;

    if (allocate_node(&L, data) == ERROR) { return ERROR; }

    if (empty_list(*p_L) == TRUE) { *p_L = L; }
    else {
        for (tmplist = *p_L; NEXT(tmplist)!=NULL; tmplist=NEXT(tmplist)) {
            NEXT(tmplist) = L;
        }
    }
    return OK;
}

extern status delete(list *p_L, generic_ptr *p_data)
{
    /* 
     * Delete the firs node in *p_L and return the DATA in p_data.
     */

    if(empty_list(*p_L)) { return ERROR; }

    *p_data = DATA(*p_L);
    return delete_node(p_L, *p_L);
}

extern status delete_node(list *p_L, list node)
{
    /*
     * Delete node from *p_L.
     */

    if (empty_list(*p_L) == TRUE) { return ERROR; }
    
    if (*p_L == node) { *p_L = NEXT(*p_L); }
    else {
        list L;
        for (L = *p_L; L != NULL && NEXT(L) != node; L = NEXT(L));

        if (L == NULL) { return ERROR; }
        else { NEXT(L) = NEXT(node); }
    }
    free_node(&node);
    return OK;
}

extern status traverse(list L, status (*p_func_f) ())
{
    /*
     * Call p_func_f with the data field of each node in L.
     * If p_func_f() ever returns ERROR, the function returns ERROR
     */
    
    if (empty_list(L)) { return OK; }

    if ((*p_func_f)(DATA(L)) == ERROR ) { return ERROR; }
    else { return traverse(NEXT(L), p_func_f); }
}

extern status find_key(list L, generic_ptr key, int (*p_cmp_f) (), list *p_keynode) 
{
    /*
     * Find the node in L that has a data-matching key.
     * If the node is found, it is passed back in *p_keynode.
     * OK is returned. p_cmp_f() is a comparison funciton
     * that returns 0 when there is a match.
     */

    list curr = NULL;

    while ((curr = list_iterator(L, curr)) != NULL) {
        if ((*p_cmp_f) (key, DATA(curr)) == 0) {
            *p_keynode = curr; 
            return OK;
        }
    }
    return ERROR;
}

extern list list_iterator(list L, list lastreturn)
{
    /*
     * Return each item of L in turn. Return NULL
     * after the last item has been returned.
     * lastreturn is the value that was returned last.
     * If lastreturn is NULL, start at the beginning of L.
     */
     return (lastreturn == NULL) ? L : NEXT(lastreturn);
}

extern void destroy(list *p_L, void (*p_func_f) ())
{
    /* 
     * Delete every node in *p_L.
     * If p_func_p) is nonnull, call it with the data stored
     * in each node.
     */

    if (empty_list(*p_L) == FALSE) {
        destroy(&NEXT(*p_L), p_func_f);
        if (p_func_f != NULL) { (*p_func_f) (DATA(*p_L)); }
        free_node(p_L);
    }
}     

extern bool equal(list L1, list L2, bool (*p_cmp_f)()) {
    
    if (empty_list(L1) == FALSE && empty_list(L2) == FALSE) {
        if (p_cmp_f != NULL) {
            if ((*p_cmp_f)(DATA(L1),DATA(L2))) {
                return (equal(NEXT(L1),NEXT(L2),p_cmp_f));
            }
            else { 
                return FALSE;
            }
        }
    }
    /* 
     * We should only be at this point if equal has been 
     * passed a NULL pointer for one of the lists. IF
     * this is the case, we check to makre sure BOTH
     * lists terminate at the same time (they both will be
     * NULL)
     */
    return (L1 == NULL && L2 == NULL); 
}
