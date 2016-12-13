/**********************************/
/* graph.h                        */
/**********************************/
#ifndef _grpah
#define _graph

#include "globals.h"

typedef int vertex ;
typedef enum { directed, undirected } graph_type ;
typedef enum { DEPTH_FIRST, BREADTH_FIRST } searchorder ;
typedef struct { int weight; vertex vertex_number ; } edge ;
typedef struct { graph_type type; int number_of_verticies; edge **matrix; } graph_header, *graph;

#define UNUSED_WEIGHT (32767)
#define WEIGHT(p_e) ((p_e)->weight)
#define VERTEX(p_e) ((p_e)->vertex_number)


status init_graph( graph *p_G, int vertex_cnt, graph_type type );
void destroy_graph(graph *p_G) ;
status add_edge( graph G, vertex vertex1, vertex vertex2, int weight ) ;
status deleted_edge( graph G, vertex vertex1, vertex vertex2 ) ;
bool isadjacent( graph G , vertex vertex1, vertex vertex2 );
void graph_size( graph G, int *p_vertex_cnt , int p_edge_cnt );
edge *edge_iterator(graph G, vertex vertex_number, edge *p_last_return );
status traverse_graph(graph G, searchorder order, status (*p_func_f)());
status depth_first_search(graph G , vertex vertex_number, bool visited[], status (*p_func_f)());
int get_closest(int distance[], bool path_found[], int vertex_cnt) ;      
void adjust_distance( graph G, int distance[], bool path_found[], int base_vertex ) ;
status breadth_first_search(graph G , vertex vertex_number, bool visited[], status (*p_func_f)());
status single_source_shortest_path(graph G, int source_vertex, int distance[]) ;






#endif
