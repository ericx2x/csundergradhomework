#include "stack.h"
#include "array.cpp"
#include <iostream>

using namespace std;

template<typename T>

void reverse(ARRAY_NAMESPACE::Array<T> &in) {
  Stack<T,100> temp = Stack<T,100>();

  for(int i = 0; i < in.size(); i++) {
    temp.push(in[i]);
  }

  for(int i = 0; i < in.size(); i++) {
    in[i] = temp.pop();
  }
}

int main(int argc, char *argv) {

  int i;

  ARRAY_NAMESPACE::Array<int> A = Array();
  
  for(i = 0; i < 100; i++) A[i] = i;

  cout << "Beginning \n";

  for(i = 0; i < 100; i++) cout << A[i];

  reverse<int>(A);

  cout << "\nFinish\n";

  for(i = 0; i < 100; i++) cout << A[i];

  cout << "\n";

}
