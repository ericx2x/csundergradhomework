/*************************************************/
/*  Eric Lima                                    */
/*                                               */
/*  Homework 5-12                                */
/*                                               */
/*  March 11, 2010                               */
/*************************************************/

//The array approach is here.

class IntStackA {

 public:

  IntStackA( int size ) ;
  IntStackA( const IntStackA& s ) ;
  IntStackA& operator=( const IntStackA& s ) ;
  ~IntStackA() ;
  void push( int i ) ;
  int pop() ;

 private: 

  int top_ ;
  int* stack_ ;
  int size_ ;

} ;

