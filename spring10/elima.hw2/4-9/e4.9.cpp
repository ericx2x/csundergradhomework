  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 4-9
  // Simple tester for the Student stack class

#include "e4.9-student.h"
#include "e4.9-student-stack.h"
#include <iostream>

/* Here you can see Canonical Construction happening.
The way this works is it has a class manage its resources.
Resources can be constructors, destructor, and assignment operators.
Memory leaks are avoided when it allocates the memory.*/

using namespace std;
using namespace e4_9; // This line extends the scope.
  void showTop(const StudentStack& s) {
    if(s.empty()) {
      cout << "Empty stack" << endl;
      return;
    }
     cout << "Top of the stack " << s.top().getName() << " "<<  s.top().getId() << endl;
  }
  
// The main tests some functions once the solution is implemented

int main() {

  StudentStack s(2), t = s;
  showTop(s);
  Student n1("Mary");
  t.push(n1);
  
  if(t.getError() == StudentStack::STACK_FULL) {
    cout << "can't happen\n";
    t.clearError();
  }
  showTop(t);
  t.push(Student("John"));

  if(t.getError() == StudentStack::STACK_FULL) {
    cout << "full\n";
    t.clearError();
  }
  showTop(t);
  t.push(Student("abc"));

  if(t.getError() == StudentStack::STACK_FULL) {
    cout << "full\n";
    t.clearError();
  }

  t.pop();
  if(t.getError() != StudentStack::STACK_OK) {
    cout << "can't happen\n";
    t.clearError();
  }
  showTop(t);
}

