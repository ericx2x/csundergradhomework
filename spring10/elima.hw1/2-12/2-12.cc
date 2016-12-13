/*******************************/
/* Eric Lima                   */
/*                             */
/* Exercise 2-12               */
/*                             */
/* Feb 12, 2010                */
/*******************************/

#include <iostream>

int &max ( int A[], int size );
int *large ( int A[], int size );

using namespace std;

int main ( int argc, char *argv[] ) { 

  int A[5];

  int x, i;

  cout << "Enter 5 integers, please." << endl;
  
  for ( i = 0; i < 5; i++ ) {
    cin >> x;
    A[i] = x;
  }
  
  cout << "The largest int with references is " << max( A, 5 ) << endl;
  cout << "The largest int with pointers is " << *large( A, 5 ) << endl;

  return 0;
}

int &max ( int A[], int size ) {

  int i, &val = A[0];
  
  for ( i = 1; i < size; i++ )
    if ( A[i] > val )
      val = A[i];

  return val;

}

int *large ( int A[], int size ) {

  int *val, i;

  for ( i = 1; i < size; i++ )
    if ( &A[i] > val )
      val = &A[i];

  return val;

}
