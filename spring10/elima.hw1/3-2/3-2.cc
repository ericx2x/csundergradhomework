/*******************************/
/* Eric Lima                   */
/*                             */
/* Exercise 3-2                */
/*                             */
/* Feb 12, 2010                */
/*******************************/

#include <iostream>

using namespace std;

int gcd ( int n, int d ) {

  if ( n%d == 0 ) return d;

  return ( gcd( d, n%d ) );
}

class Fraction {
private:
  Fraction Add ( Fraction a, Fraction b );
  Fraction Subtract ( Fraction a, Fraction b );
  Fraction Multiply ( Fraction a, Fraction b );
  Fraction Divide ( Fraction a, Fraction b );
  
public:
  Fraction( int, int );
  int num;
  int den;

};

Fraction::Fraction( int x, int y ) {

  this -> num = x;
  this -> den = y;

}

Fraction Fraction::Add ( Fraction a, Fraction b ) {
  
  int x;

  if ( a.den != this->den ) {
    b.num = a.num;
    b.den = a.den;

    a.num = a.num * b.den;
    a.den = a.den * b.den;
    
    b.num = b.num * b.den;
    b.den = b.den * b.den;
  }

  tmp.num = a.num + b.num;
  tmp.den = a.den;

  x = gcd( tmp.num, tmp.den );

  if ( x != 1 ) {
    tmp.num /= x;
    tmp.den /= x;
  }

  return b;

}

Fraction Fraction::Subtract ( Fraction a, Fraction b ) {

  int tmp;
  int d;

  if ( a.den != this->den ) {

    tmp = a.den;
    a.den = a.den * this->den;
    a.num = a.num * this->den;
    
    b.den = this->den * tmp;
    b.num = this->den * tmp;

  }

  b.num = a.num - b.num;

  d = gcd( b.num, b.den );

  if ( d != 1 ) {
    b.num /= d;
    b.den /= d;
  }

  return b;
}

Fraction Fraction::Multiply ( Fraction a, Fraction b ) {

  int c;

  a.num = a.num * b.num;
  a.den = a.den * b.den;

  c = gcd( a.num, a.den );
  
  if ( c != 1 ) {
    a.num /= c;
    a.den /= c;
  }

  return a;
}

Fraction Fraction::Divide ( Fraction a, Fraction b ) {

  int tmp = b.num;
  b.num = b.den;
  b.den = tmp;

   a.num = a.num * b.num;
  a.den = a.den * b.den;

  c = gcd( a.num, a.den );
  
  if ( c != 1 ) {
    a.num /= c;
    a.den /= c;
  }

  return a;
}
  


int main ( int argc, char *argv[] ) {

  int x, y;

  cout << "Please enter the numerator and denominator for fraction 1: " << endl;
  cin >> x >> y;
  Fraction a ( x, y );
  
  cout << "Please enter the numerator and denominator for fraction 2: " << endl;
  cin >> x >> y;
  Fraction b ( x, y );

  Fraction tmp = tmp.Add(a,b);

  cout << a.num << "//" << a.den << " + " << b.num << "//" << b.den << " = " <<
       << tmp.num << "//" << tmp.den << endl;

  tmp = tmp.Subtract(a,b);

  cout << a.num << "//" << a.den << " - " << b.num << "//" << b.den << " = " <<
       << tmp.num << "//" << tmp.den << endl;

  tmp = tmp.Multiply(a,b);

  cout << a.num << "//" << a.den << " * " << b.num << "//" << b.den << " = " <<
       << tmp.num << "//" << tmp.den << endl;

  tmp = tmp.Divide(a,b);

  cout << a.num << "//" << a.den << " / " << b.num << "//" << b.den << " = " <<
       << tmp.num << "//" << tmp.den << endl;  


  return 0;
}
