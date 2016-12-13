/********************************************************************************************************/
/* Main function to be used with Dijkstra's shortest path problem.                                      */
/********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

status write_vertex ( int a ) {

  printf(" %d  ", a ) ;
  return OK ;

}

int main ( int argc, char *argv[] ){

  FILE *fileptr ;
  int weight    ;
  int from      ;
  int i         ;
  int to        ;
  int numberofvertices;
  int source_vertex ;
  int *distance ;
  graph G ;

  fileptr = fopen( argv[1], "r");
  fscanf( fileptr, "%d",  &numberofvertices );

  init_graph( &G, numberofvertices, directed );

  while ( fscanf( fileptr, "%d %d %d", &from, &to, &weight ) != EOF ) add_edge( G, from, to, weight );

  printf("\n Depth First Traversal:   ");

  traverse_graph( G, DEPTH_FIRST, write_vertex ) ;

  distance = (int *) malloc( numberofvertices * sizeof( int ) ) ;

  source_vertex = 0 ;

  single_source_shortest_path( G, source_vertex, distance );

  printf("\n\n");

  for ( i = 0 ; i < numberofvertices ; i++ ) { 
   
    printf("The minimum distance from vertex %d to vertex %d is %d.\n", source_vertex, i, distance[i] ) ;

  }
  printf("\n");

  fclose ( fileptr );

  return 0 ;
}
