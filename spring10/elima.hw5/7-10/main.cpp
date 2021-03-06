#include "Queue.h"
#include "Segment.h"
#include "Point.h"
#include "Queue.cpp"
#include <iostream>

using namespace std;

int main(int argc, char *argv) {

  Point a = Point(1,1);
  Point b = Point(1,2);
  Point c = Point(1,3);
  Point d = Point(1,4);
  Point e = Point(1,5);
  Point temp;

  Queue<Point,5> q1 = Queue<Point,5>();

  cout << "Checking if the queue is empty... ";

  if( q1.empty() ) cout << "Empty\n";
  else cout << "Not empty\n";

  cout << "Checking if the queue is full.. ";

  if( q1.full() ) cout << "Full\n";
  else cout << "Not Full\n";

  cout << "\nThe queue recieves points in this order. \n";

  cout << "a: ";
  a.print();
  cout << "b: ";
  b.print();
  cout << "c: ";
  c.print();
  cout << "d: ";
  d.print();
  cout << "e: ";
  e.print();

  cout << "The points will now be inserted\n";

  q1.insert(a);
  q1.insert(b);
  q1.insert(c);
  q1.insert(d);
  q1.insert(e);

  cout << "Checking if the queue is empty... ";

  if( q1.empty() ) cout << "Empty\n";
  else cout << "Not empty\n";

  cout << "Checking if he queue is full... ";

  if( q1.full() ) cout << "Full\n";
  else cout << "Not full\n";

  cout << "The first point is "; 
  q1.front().print();
  q1.remove();

  cout << "The second point is "; 
  q1.front().print();
  q1.remove();

  cout << "The third point is "; 
  q1.front().print();
  q1.remove();

  cout << "\nQueue is being nulled.\n";
  q1.makenull();

  cout << "Checking if the queue is empty... ";
    
  if( q1.empty() ) cout << "Empty\n";
  else cout << "Not empty\n";

  Point *f = new Point(1,1);
  Point *g = new Point(1,2);
  Point *h = new Point(1,3);
  Point *i = new Point(1,4);
  Point *j = new Point(1,5);
  Point *k = new Point(2,1);
  Point *l = new Point(2,2);
  Point *m = new Point(2,3);
  Point *n = new Point(2,4);
  Point *o = new Point(2,5);
  
  Segment A = Segment(f,g);
  Segment B = Segment(h,i);
  Segment C = Segment(j,k);
  Segment D = Segment(l,m);
  Segment E = Segment(n,o);

  Queue<Segment,5> q2 = Queue<Segment,5>();

  cout << "Checking if the queue is empty. ";

  if( q2.empty() ) cout << "Empty\n";
  else cout << "Not\n";

  cout << "Check if queue is full: ";

  if( q2.full() ) cout << "Full\n";
  else cout << "Not full\n";

  cout << "\nThe segments are being inserted into the queue in this order.. \n";

  cout << "A: \n";
  A.print();
  cout << "\nB: \n";
  B.print();
  cout << "\nC: \n";
  C.print();
  cout << "\nD: \n";
  D.print();
  cout << "\nE: \n";
  E.print();

  cout << "\nSegments are now being inserted.\n\n";

  q2.insert(A);
  q2.insert(B);
  q2.insert(C);
  q2.insert(D);
  q2.insert(E);

  cout << "Checking if the queue is empty. ";

  if( q2.empty() ) cout << "Empty\n";
  else cout << "Not empty\n";

  cout << "Checking if the queue is full... ";

  if( q2.full() ) cout << "Full\n";
  else cout << "Not full\n";

  cout << "The first segment is \n"; 
  q2.front().print();
  q2.remove();

  cout << "The second segment is \n"; 
  q2.front().print();
  q2.remove();

  cout << "The third segment is \n"; 
  q2.front().print();
  q2.remove();

  cout << "\nQueue is being nulled.\n";
  q2.makenull();

  cout << "Checking if the queue is empty... ";
    
  if( q2.empty() ) cout << "Empty\n";
  else cout << "Not empty\n";

  

}
