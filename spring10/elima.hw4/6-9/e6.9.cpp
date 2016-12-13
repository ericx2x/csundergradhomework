/***************************************/
/* Eric Lima                           */
/*                                     */
/* Exercise 6-9                        */
/*                                     */
/* Computing 4                         */
/***************************************/
  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 6-9
  // Example 6.9
  // File: e6.9.cpp 
  // Simple test program
#include "e6.9-mystring.h"
 #include <iostream>
using namespace std;
#include <string>
void show(const MyString::string& m) {
  for(int i = 0; i < m.strlen(); ++i) {
    try {
     cout << m.at(i);
    } catch(domain_error& e) {
      cout << e.what() << " should not have happened" << endl;
    }
 }
 cout << endl;
}
void test(const MyString::string& m) {
  char c;
  cout << "testing string:";
  show(m);
  cout << "enter a char ";
  cin >> c;
  int i = m.strpos(c);
  if(i == -1) cout << "not found";
  else cout << "found at position " << i;
  cout << endl;
}
  
   // to test the command line, two strings are placed here.
  
int main(int argc, char* argv[]) {
  if(argc != 3) {
    cerr << "usage: " << argv[0] << " string1 string2 " << endl;
    return 1;
  }
  string s(argv[1]);
  typedef MyString::string Mystring;
  Mystring m1(argv[2]);
  Mystring m2(s);
  const Mystring m3(m2);
  show(m1);
  show(m2);
  show(m3);
  test(m1);
  
  // muldner tests insert and remove here
  
using namespace MyString;
  try {
    cout << endl<< endl<<"testing insert into:" << endl;
    show(m3);
    cout << "string being inserted" << endl;
    show(m1);
    int p;
    cout << "enter a position to insert to: ";
    cin >> p;
    Mystring m4 = insert(m3, p, m1);
    cout << "new string" << endl;
    show(m4);  
    cout << "first string" << endl;
    show(m3);
    cout << "second string" << endl;
    show(m1);  

    cout << "now, modifying the first string" << endl;
    insert(m1,p,m2);
    cout << "modified string" << endl;
    show(m1);

    cout << endl<< endl<<"testing remove from:" << endl;
    show(m3);
    int l;
    cout << "enter a position to remove from: ";
    cin >> p;
    cout << "enter the number of characters to remove: ";
    cin >> l;
    Mystring m5 = remove(m3, p, l);
    cout << "new string" << endl;
    show(m5);
    cout << "first string" << endl;
    show(m3);
    cout << "second string" << endl;
    show(m1);
 
  } catch(std::domain_error& e) {
    cout << e.what() << endl;
  }
}
