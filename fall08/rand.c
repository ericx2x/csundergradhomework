/* --------------------------------------------------------- */
/* sample data gathering routine                             */
/* data can come from anywhere, generally a DB or data file  */
/* here it's randomly generated                              */
/* --------------------------------------------------------- */
#include <stdlib.h>     /* for rand() */
#include <time.h>       /* for seed   */
get_data( int   num_sets,
	  int   num_points,
	  float data[num_sets][num_points] )
{
  int i, j;
  srand( (unsigned int)time((time_t)NULL) );
  for( i=0; i<num_sets; ++i )
    for( j=0; j<num_points; ++j )
      /* random number between 0 & 500 */
      data[i][j] = 1.0+(500.0 * rand()/(RAND_MAX+1.0));
}

/* -------- also random colors ----------------------------- */
get_individual_colors( int           num_sets,
                       int           num_points,
                       unsigned long extclr[num_sets][num_points] )
{
  int i, j;
  for( i=0; i<num_sets; ++i )
    for( j=0; j<num_points; ++j )
      extclr[i][j] = (unsigned long)rand();
}
