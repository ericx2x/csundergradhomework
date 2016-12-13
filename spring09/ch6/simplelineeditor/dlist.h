typedef struct double_node double_node, *double_list;

struct double_node{
  generic_ptr datapointer;
  double_list next ;
  double_list prev ;
} ;

#define DATA(L) ((L)->datapointer)
#define NEXT(L) ((L)->next)
#define PREV(L) ((L)->prev)
} double_node ;

typedef double_node *double_list ;

extern status allocate_double_node ( double_list *p_L, generic_ptr data ) ;
extern void free_double_node ( double_list *p_L ) ;
extern status init_double_list ( double_list *p_L ) ;
extern bool empty_double_list ( double_list L ) ;
extern bool empty_double_list( double_list L ) ;
extern status double_insert( double_list *p_L, generic_ptr data ) ;
extern status double_delete ( double_list *p_L, generic_ptr data ) ;
extern status double_delete_node ( double_list *p_L, generic_ptr*p_data ) ;
extern status double_delete_node ( double_list *p_L, double_list node ) ;
extern void cut_list ( double_list *p_L, double_list *p_start, double_list *p_end ) ;
extern void paste_list ( double_list *p_target, double_list *p_source ) ;

extern status double_append( double_list *p_L, generic_ptr data ) ;
extern int double_length( double_list L ) ;
extern status double_traverse( double_list L, status (*p_func_f ) () ) ;
extern void destroy_double_list( double_list *p_L, void (*p_func_f)());
extern int double_node_number( double_list L );
extern double_list nth_double_node ( double_list L, int n ) ;
extern double_list nth_relative_double_node( double_list L, int n ) ;

#endif
