/*************************************************/
/*  Eric Lima                                    */
/*                                               */
/*  Homework 5-1                                */
/*                                               */
/*  March 11, 2010                               */
/*************************************************/


#include <string>
#include <iostream>

using namespace std ;

class X {  //X is declared here.

public: 

  virtual void show( string = "" ) const ;
  X(int) ;
  virtual ~X() ;

private:

  int i_ ;

} ;

void X::show( string s ) const {

  if ( s != "" )
    cout << s << i_ ;
}

X::X( int j ) : i_(j) {

  show() ;
}  

X::~X() {

  cout << "X" << endl ;
}

class Y : public X {   //Y is declared here and it is inherited from X

public:

  virtual void show( string s = "" ) const ;
  Y( int, double ) ;
  ~Y() ;

private:

  double d_ ;

} ;

void Y::show( string s ) const {

  cout << d_ << ' ' << s << endl ;
}

Y::Y( int j, double s ) : X(j), d_(s) {

  show() ;
}

Y::~Y() {

  cout << "Y" << endl ;
}

class Z : public Y { //Z is declared here and it is inherited from Y

public:

  void show( string = "" ) const ;
  Z( string, int, double ) ;
  ~Z() ;

private:

  string c_ ;

} ;

void Z::show( string s ) const {

  cout << c_ << endl ;
}

Z::Z( string s, int j, double d ) : Y(j, d), c_(s) {

  show(s) ;
}

Z::~Z() {

  cout << "Z" << endl ;
}

//The functinality of the classes is tested here in main.

int main( int argc, char *argv[] ) {

  X* m = new Y( 3, 3.5 ) ; //The Y object gets made here. The show function will get called from the constructor.

  m->show("2") ; //Lazy binding causes the show function to get called.

  delete m ;  //The descrutctor associated to Y is called despite m being a pointer to X.
  
  m = new Z( "Z", 4, 4.5 ) ;//The constructor goes through X, Y, and Z in that order.

  m->show("3") ;  //Show is from Z class.

  delete m ;   //Z's destructor is called here.

  return 0 ;
}			     
