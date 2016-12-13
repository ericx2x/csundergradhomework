  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Simple tester for integer wrappers

/* Wrapper is tested here for the Integer Class.

Idiom basically states that.. Singleton ensures a class has only one instance, and provide a global point of access to it. Application needs one, and only one, instance of an object.
Additionally, lazy initialization and global access are necessary. Make the class of the single instance object responsible for creation, initialization, access, and enforcement.
Declare the instance as a private static data member. Provide a public static member function that encapsulates all initialization code, and provides access to the instance. 
Singleton needs to have the following criteria saisfied. 
    - Ownership of the single instance cannot be reasonably assigned
    - Lazy initialization is desirable
    - Global access is not otherwise provided for
	*/


#include "e4.3-integer.h"
#include <iostream>
using namespace std;

int main () {
  Integer i = Integer::make(5);
  Integer j = i.clone(); 
  cout << "i and j should be both 5" << endl;
  cout << "i = " << i.get() << "; j = " << i.get() << endl;
  i = i.set(2);   
  j.plus(3);
  cout << "now, i should be 2, and j should be 8" << endl;
  cout << "i = " << i.get() << "; j = " << j.get() << endl;
  cout << "now i is 18 j is 8" << endl;
  i = i.plus(j).plus(j);  // chaining: (i.add(j)).add(j)
  cout << "i = " << i.get() << "; j = " << j.get() << endl;
  Integer k = i.plus(3);
  Integer m = i.plus(k);
  cout << "now i is i+3+i+3, j is the same as before, k is old value of i+3, m is i" << endl;
  cout << "i = " << i.get() << "; j = " << j.get() << endl;
  cout << "k = " << k.get() << "; m = " << m.get() << endl;
  cout << "more math: i = j-3, k = j*3, m = j/3" << endl;
  i = j.minus(3);
  k = j.times(3);
  m = j.divide(3);
  cout << "i = " << i.get() << "; j = " << j.get() << endl;
  cout << "k = " << k.get() << "; m = " << m.get() << endl;   
  cout << "try to divide by 0" << endl;
  try {
   Integer m = Integer::make(0);
   i = k.divide(m);
  } catch( domain_error& e) {
   cout << e.what() << endl;
  } 
 }
