/***************************************/
/* Eric Lima                           */
/*                                     */
/* Exercise 6-2                        */
/*                                     */
/* Computing 4                         */
/***************************************/

#include <iostream>
#include "intstack.h"

using namespace std;

//Constructor that will run by default. This sets size of the array.

IntStack::IntStack( int size ) {
  top_ = -1;
  size_ = size;
  stack_ = new int[size];
}

//This constructor copies every element in the array and gives it to IntStack.

IntStack::IntStack(const IntStack& s ) {
  top_ = s.top_;
  size_ = s.size_;
  stack_ = new int[size_];
  for ( int i = 0; i <= top_; ++i )
  stack_[i] = s.stack_[i];


}

IntStack& IntStack::operator=( const IntStack& s ) {
  if ( this == &s )
    return *this;

  if ( size_ != s.size_ ) {
    delete [] stack_;
    stack_ = new int[s.size_];
  }

  top_ = s.top_;
  size_ = s.size_;
  for ( int i =0; i <= top_; ++i )
    stack_[i] = s.stack_[i];
  return *this;
}

IntStack::~IntStack() {
  delete [] stack_;
}

//If the stack isn't full a new int gets pushed into the stack here.

void IntStack::push( int i) {
  if ( top_ == size_ -1 )
    cout << "Stack Full " <<endl;

  stack_[++top_] = i;
}

//If the stack isn't empty a int gets removed from the array.

int IntStack::pop()  {
  if( top_ == -1 )
    cout << "Stack Empty " << endl;

  return stack_[top_--];
}

void IS::empty( ) {

  if ( this->top_ == -1 )
    cout << "This stack is empty." << endl;

}

void IS::full( ) {

  if ( this->top_ == this->size_ )
    cout << "Stack full." << endl;

}

int IS::getnodc ( ) {
  return 1;
}

IS::IS(IntStack i) { IntStack( i ) }
