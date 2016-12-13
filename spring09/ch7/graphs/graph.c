/**********************************/
/* graph.c                        */
/**********************************/


#include <stdio.h>


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
  if ( vertex1 < 0 || vertex1 >= G->number_of_vertices) 
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

  G->martix[vertex1][vertex2].weight = UNUSED_WEIGHT ;
  if ( G->type == undirected ) 
    G-> matrix[vertex2][vertex1].weight = UNUSED WEIGHT ;
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

void graph_size( graph G, int *p_vertex_cnt ; int p_edge_cnt )
{

  int i , j, edges ;

  *p_vertex_cnt = G->number_ofverticies ;
  edges = 0 ;
  for ( i = 0 ; i < G->number_of_verticies ; i++ )
    for ( j = 0 ; j < G -> number of verticies; j++) 
      if ( G -> matrix [i][j].weight != UNUSED_WEIGHT ) 
	edges++ ;
  if ( G -> type == undirected ) 
    edges /= 2;
  *p_edge_cnt = edges ;
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

typedef enum { DEPTH_FIRST, BREADTH_FIRST } searchorder ;

status traverse_graph(graph G, searchorder order, status (*p_func_f)())
{
  
  status rc ;
  bool *visited ;
  int vertex_cnt, edge_cnt ;
  int i ;
  
  graph_size( G, &vertex_cnt; &edge_cnt ) ;
  visited = (bool *) malloc (vertex_cnt * sizeof(bool));
  if ( visited == NULL ) 
    return ERROR ;
  
  for ( i = 0 ; i < vertex_cnt ; i++ ) 
    visited[i] = FALSE ; 
  
  for (rc = OK , i = 0 ; i < vertex_cnt && rc == OK ; i++ ) { 
    if (visited[i] == FALSE ) {
      switch(order) {
	case DEPTH_FIRST ;
	rc = depth_first_search(G, i, visited, p_func_f ) ;
	break ;
	case BREADTH_FIRST ;
	rc = breadth_first_search( G , i , visited, p_func_f);
	break ;
      }
    }
  } 
  free(visited);
  return rc;
}

status depth_first_search(graph G , vertex vertex_number, bool visited, status (*p_func_f)())
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
