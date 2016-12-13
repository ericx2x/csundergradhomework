/**********************************/
/* graph.h                        */
/**********************************/


#include "globals.h"

typedef int vertex ;
typedef struct {
  int weight ;
  vertex vertex_number ;
} edge ;
#define UNUSED_WEIGHT (32767)
#define WEIGHT(p_e) ((p_e)->weight)
#define VERTEX(p_e) ((p_e)->vertex_number)

typedef enum { directed, undirected } graph_type ;

typedef struct {
  graph_type type ;
  int number_of_verticies ;
  edge **matrix;
} graph_header, *graph ;




status init_graph( graph *p_G, int vertex_cnt, graph_type type );
void destroy_graph(graph *p_G) ;
status add_edge( graph G, vertex vertex1, vertex vertex2, int weight ) ;
status deleted_edge( graph G, vertex vertex1, vertex vertex2 ) ;
bool isadjacent( graph G , vertex vertex1, vertex vertex2 );
void graph_size( graph G, int *p_vertex_cnt ; int p_edge_cnt );
edge *edge_iterator(graph G, vertex vertex_number, edge *p_last_return );
status traverse_graph(graph G, searchorder order, status (*p_func_f)());
status depth_first_search(graph G , vertex vertex_number, bool visited, status \(*p_func_f)());



