  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // Exercise 5.6
  // Application of three classes
  // File: e5.6.cpp
#include <string>
#include "e5.6-address.h"
#include "e5.6-address-extended.h"
#include "e5.6-address-post.h"

using namespace e56;
using namespace std;

int main(int argc, char** argv) {
  if(argc != 5) {
    cerr << "usage " << argv[0] << " name address zipcode and postbox" << endl;
    return 1;
  }
  string name(argv[1]);
  string address(argv[2]);
  string zip(argv[3]);
  string post(argv[4]);
/*
  cout << "Enter name, address, zip code, and postbox number" << endl;
  cin >> name;
  cin >> address;
  cin >> zip;
  cin >> post;
*/
  Address a(name, address);
  
  ExtendedAddress e(name, address, zip);

  PostAddress p(name, address, zip, post);

  cout << "testing address: " << a.name() << " " << a.address() << endl;

  cout << "testing extended address: " << e.name() << " " << e.address() << 
      " " << e.zip() << endl;
  cout << "testing post address: " << p.name() << " " << p.address() <<
      " " << p.zip() << " " << p.postbox() << endl;
  cout << "---------------- copy constructor ------ " << endl;
  Address a1 = a;
  cout << "testing address: " << a1.name() << " " << a1.address() << endl; 
  ExtendedAddress e1 = e;
 cout << "testing extended address: " << e1.name() << " " << e1.address() <<
      " " << e1.zip() << endl;
  PostAddress p1 = p;
  cout << "testing post address: " << p1.name() << " " << p1.address() <<
      " " << p1.zip() << " " << p1.postbox() << endl;
  cout << "---------------- assignments ------ " << endl;
  p = p1;
   cout << "testing post address: " << p.name() << " " << p.address() <<
      " " << p.zip() << " " << p.postbox() << endl;   
  cout << "testing post address: " << p1.name() << " " << p1.address() <<
      " " << p1.zip() << " " << p1.postbox() << endl; 
  cout << "---------------- pointers  ------ " << endl;
  Address* ap = new Address(name, address);
  ExtendedAddress* ep = new ExtendedAddress(name, address, zip);
  PostAddress* pp = new PostAddress(name, address, zip, post);
  cout << "testing address: " << ap->name() << " " << ap->address() << endl;
  delete ap;
 
  cout << "testing extended address: " << ep->name() << " " << ep->address() <<
      " " << ep->zip() << endl;
  delete ep;

  cout << "testing post address: " << pp->name() << " " << pp->address() <<
      " " << pp->zip() << " " << pp->postbox() << endl;   
  delete pp; 

}

 
