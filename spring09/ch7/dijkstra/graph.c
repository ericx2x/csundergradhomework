/**********************************/
/* graph.c                        */
/**********************************/


#include <stdio.h>
#include <stdlib.h>
#include "globals.h"
#include "graph.h"

status init_graph( graph *p_G, int vertex_cnt, graph_type type ) 
{
  graph G ;
  int i, j ;
  G = (graph) malloc ( sizeof(graph_header) ) ;
  if ( G == NULL ) 
    return ERROR ;
  G->number_of_verticies = vertex_cnt ;
  G->type = type ;

  G->matrix = (edge**) malloc ( vertex_cnt *sizeof(edge*));
  if(G->matrix[0]== NULL ) {
    free(G) ;
    return ERROR ;
  }
  G->matrix[0] = (edge *) malloc( vertex_cnt*vertex_cnt*sizeof(edge));
  if (G->matrix[0] == NULL ) {
    free(G->matrix) ;
    free(G) ;
    return ERROR ;
  }
  
  for( i = 1 ; i < vertex_cnt ; i++ ) {
    for( j = 0 ; j < vertex_cnt ; j++ ) {
      G->matrix[i][j].weight = UNUSED_WEIGHT ;
      G->matrix[i][j].vertex_number = j ;
    }
  }
  
  *p_G = G ;
  return OK ;
}

void destroy_graph(graph *p_G) 
{
  free((*p_G) -> matrix[0]);
  free((*p_G) -> matrix ) ;
  free(*p_G);
  *p_G = NULL ;
}

status add_edge( graph G, vertex vertex1, vertex vertex2, int weight ) 
{
  if ( vertex1 < 0 || vertex1 >= G->number_of_verticies) 
    return ERROR ;
  if ( vertex2 < 0 || vertex2 >= G->number_of_verticies)
    return ERROR ;
  if ( weight <= 0 || weight >= UNUSED_WEIGHT )
    return ERROR ;

  G->matrix[vertex1][vertex2].weight = weight ;
  if (G->type == undirected)
    G->matrix[vertex2][vertex1].weight = weight ;

  return OK ;

}

status deleted_edge( graph G, vertex vertex1, vertex vertex2 )
{

  if ( vertex1 < 0 || vertex1 >= G->number_of_verticies)
    return ERROR ;
  if ( vertex2 < 0 || vertex2 >= G->number_of_verticies)
    return ERROR ;

  G->matrix[vertex1][vertex2].weight = UNUSED_WEIGHT ;
  if ( G->type == undirected ) 
    G-> matrix[vertex2][vertex1].weight = UNUSED_WEIGHT ;
  return OK ;
}

bool isadjacent( graph G , vertex vertex1, vertex vertex2 ) 
{

  if ( vertex1 < 0 || vertex1 >= G->number_of_verticies) 
    return FALSE ;
  if ( vertex2< 0 || vertex2 >= G->number_of_verticies)
    return FALSE ;

  return (G->matrix[vertex1][vertex2].weight == UNUSED_WEIGHT)?FALSE:TRUE ;
}

void graph_size( graph G , int *p_vertex_cnt , int p_edge_cnt )
{

  int i , j, edges ;

  *p_vertex_cnt = G->number_of_verticies ;
  edges = 0 ;
  for ( i = 0 ; i < G->number_of_verticies ; i++ )
    for ( j = 0 ; j < G -> number_of_verticies; j++) 
      if ( G -> matrix [i][j].weight != UNUSED_WEIGHT ) 
	edges++ ;
  if ( G -> type == undirected ) 
    edges /= 2;
  p_edge_cnt = edges ;
}

edge *edge_iterator(graph G, vertex vertex_number, edge *p_last_return ) {

  vertex other_vertex ;

  if (vertex_number < 0 || vertex_number >= G -> number_of_verticies)
    return NULL ;

  if( p_last_return == NULL ) 
    other_vertex = 0 ;
  else 
    other_vertex = VERTEX(p_last_return ) + 1 ;
  for (; other_vertex < G->number_of_verticies ; other_vertex++)
    if(G->matrix[vertex_number][other_vertex].weight!=UNUSED_WEIGHT)
      return &G ->matrix[vertex_number][other_vertex];
  return NULL;
}  

status traverse_graph(graph G, searchorder order, status (*p_func_f)())
{
  
  status rc ;
  bool *visited ;
  int vertex_cnt, edge_cnt ;
  int i ;
  
  graph_size( G, &vertex_cnt, edge_cnt ) ;
  visited = (bool *) malloc (vertex_cnt * sizeof(bool));
  if ( visited == NULL ) 
    return ERROR ;
  
  for ( i = 0 ; i < vertex_cnt ; i++ ) 
    visited[i] = FALSE ; 
  
  for (rc = OK , i = 0 ; i < vertex_cnt && rc == OK ; i++ ) { 
    if (visited[i] == FALSE ) {
      switch(order) {
      case DEPTH_FIRST :
	rc = depth_first_search(G, i, visited, p_func_f ) ;
	break ;
      case BREADTH_FIRST :
	rc = breadth_first_search( G , i , visited, p_func_f);
	break ;
      }
    }
  } 
  free(visited);
  return rc;
}

status depth_first_search(graph G , vertex vertex_number, bool visited[], status (*p_func_f)())
{

  edge *p_edge ;
  status rc ;
  visited[vertex_number] = TRUE ;
  if (( *p_func_f)(vertex_number) == ERROR )
    return ERROR ;

  p_edge = NULL ;
  while ( ( p_edge = edge_iterator( G , vertex_number, p_edge )  ) != NULL )
    if ( visited[VERTEX(p_edge)] == FALSE ) 
      rc = depth_first_search( G, VERTEX(p_edge), visited, p_func_f);
  if(rc == ERROR ) 
    return ERROR ;
  return OK ;
}

status single_source_shortest_path(graph G, int source_vertex, int distance[]){

  bool *path_found ;
  edge *p_edge ;
  int vertex_cnt, edge_cnt ;
  int close_vertex ;
  int i ;

  graph_size(G, &vertex_cnt, edge_cnt ) ;
  path_found = (bool *) malloc(vertex_cnt * sizeof(bool));
  if (path_found == NULL )
    return ERROR ;

  for ( i=0; i<vertex_cnt; i++ ) {
    path_found[i] = FALSE ;
    distance[i] = UNUSED_WEIGHT ;
}

  path_found[source_vertex] = TRUE ;
  distance[source_vertex] = 0 ;

  p_edge = NULL ;

  while ( ( p_edge = edge_iterator(G, source_vertex, p_edge)) != NULL ) 
    distance[VERTEX(p_edge)] = WEIGHT(p_edge) ;

  for( i = 1 ; i < vertex_cnt ; i++ ) {
    close_vertex = get_closest(distance, path_found, vertex_cnt ) ;
    if ( close_vertex == -1 ) 
      return ERROR ;
    path_found[close_vertex] = TRUE ;
    adjust_distance(G, distance, path_found, close_vertex ) ;
  }
  return OK ;
}

int get_closest(int distance[], bool path_found[], int vertex_cnt) {

  int closest_vertex = -1 ;
  int closest_distance = UNUSED_WEIGHT ;
  int i ;

  for (i = 0 ; i < vertex_cnt ; i++ ) {
    if ( path_found[i] == FALSE && distance[i] < closest_distance ) {
      closest_vertex = i ;
      closest_distance = distance[i] ;
    }
  }
  return closest_vertex ;
}

void adjust_distance( graph G, int distance[], bool path_found[], int base_vertex ) {

  int new_distance ;
  edge *p_edge ;

  p_edge = NULL ;
  while ( ( p_edge = edge_iterator(G, base_vertex, p_edge ) ) != NULL ) 
    if (path_found[VERTEX(p_edge)] == FALSE ) {
      new_distance = distance[base_vertex] + WEIGHT(p_edge) ;
      if (new_distance < distance[VERTEX(p_edge)])
	distance[VERTEX(p_edge)] = new_distance ;
    }
}
status breadth_first_search(graph G , vertex vertex_number, bool visited[], status (*p_func_f)())
{
  printf("Implemented") ;
  return OK ;
}
