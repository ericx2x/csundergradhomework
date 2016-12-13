  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 4-9
  // File: e4.9-student-stack.h
  // Bounded stack of Students
  // There are four stack operations available:
  //   push() to push a student
  //   pop() to pop and return the top of the stack
  //   top() to return a reference to the top of the stack without popping it.
  //   empty() to test whether or not the stack is empty
  // If any operation fails then it sets the appropriate error
  //   code, which can be obtained with getError() 
  //   and cleared using clearError().
  //   that checks whether the stack is empty

// This namespace segment is declared to include the StudentStack class

  #ifndef E3_9_STUDENT_STACK_H
  #define E3_9_STUDENT_STACK_H
namespace e4_9 {
  class Student;
  class StudentStack {
  public:
    // canonical construction
    explicit StudentStack(int = 100);  // default size
    StudentStack(const StudentStack&);
    ~StudentStack();
    StudentStack& operator=(const StudentStack&);

    // stack operations
    void push(const Student&);
    void pop();
    const Student& top() const;  // read-only access to the top
    bool empty() const;
    bool full() const;

    enum ErrorState {STACK_OK, STACK_FULL, STACK_EMPTY};
    void clearError();
    ErrorState getError() const;
  private:
    int top_;
    Student* stack_;
    int size_;
    mutable ErrorState errorState_;
  };
}
  #endif

