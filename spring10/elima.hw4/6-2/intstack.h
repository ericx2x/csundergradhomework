/***************************************/
/* Eric Lima                           */
/*                                     */
/* Exercise 6-2                        */
/*                                     */
/* Computing 4                         */
/***************************************/

#ifndef _intstack
#define _intstack

#include <stdexcept>

class IntStack {
 public:
  IntStack( int = 100 );
  IntStack( const IntStack& );
  ~IntStack();
  IntStack& operator=( const IntStack& );
  void push(int);
  int pop();
  

 private:
  int top_;
  int* stack_;
  int size_;

  friend class IS;

};

class IS : public IntStack {
 public:
  IS( Intstack );
  void empty( );
  void full ( );
  int getnodc( );

 private:


  friend class IntStack;

};



#endif
