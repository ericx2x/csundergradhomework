/*************************************************/
/*  Eric Lima                                    */
/*                                               */
/*  Project1                                     */
/*                                               */
/*  February 29, 2010                            */
/*************************************************/


#include "Sphere.h"
#include <iostream> 

using namespace std ;
using namespace PointNS ;
using namespace SphereNS ;

int main( int argc, char *argv[] ) {

Point p1(1,1,1), p2(2,2,2), p3(3,3,3) ;
Sphere s1(p1,1), s2(p2,2), s3(p3,3) ;
  int v, w, x, y;

  info(s1) ;
  info(s2) ;
  info(s3)  ;

  cout << "\nSpheres 1 and 3 are being swapped" << endl;

  Sphere * temp = new Sphere( p1, 1 );

  s1 = s3;
  s3 = *temp;

  info(s1);
  info(s2);
  info(s3);

  cout << "\nPlease, enter in the new radius which will be cloned into the new sphere. " << endl;
  cin >> v;

  s1.clone(v);

  cout << "\nPlease, enter in the new radius which will be cloned into the new sphere. " << endl;
  cin >> v;

  s3.clone(v);

  if ( s1.equal(s2) )

    cout << "\nThe spheres 1 and 2 are equal." << endl;

  else 
	  cout << "\nThe spheres 1 and 2 are not equal" << endl;


  cout << "\nPlease, enter the point that will check it in the first sphere. " << endl;

  cin >> w >> x >> y;


  Point z( w, x, y );

  if (s1.within(z))
    cout << "Point has been confirmed to be in the sphere." << endl;

  else 
	  cout << "Point has NOT been confirmed to be in the sphere." << endl ;

 

  return 0 ;
}			     
