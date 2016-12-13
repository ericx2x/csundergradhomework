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
  // File: e6.9-mystring.h
  // Interface of MyString::StringIfc using a class adapter
  // There are four helpers, to insert and remove strings
#include <stdexcept>
#include <string>
#include "e6.9-mystring-ifc.h"
namespace MyString {
  class string : public StringIfc, private std::string {
    // helpers
    friend string insert(const string& s1, int loc, const string& s2) throw(std::domain_error);
         // return s2 inserted to s1
    friend string& insert(string& s1, int loc, const string& s2) throw(std::domain_error);
        // return and modifies s1
    friend string remove(const string& s, int pos, int length) throw(std::domain_error);
           // return s with length characters removed, starting from pos
    friend string& remove(string& s, int pos, int length) throw(std::domain_error);
           // return and modify s with length characters removed, starting from pos   
  public:
    string(const char*);
    string(const std::string&);
    string(const string&);
    virtual ~string();

    string& operator=(const string&);
  //  typedef std::string::size_type size;      
    virtual int strpos(char) const;
    virtual int strlen() const;
    virtual char at(int) const throw(std::domain_error); 
  private:
   std::string rep_;
  };
}

