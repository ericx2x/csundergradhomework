/***************************************/
/* Eric Lima                           */
/*                                     */
/* Project1                            */
/*                                     */
/* November 19, 2009                   */
/***************************************/

#include <iostream>
#include <string>
#include "Point.h"
#include "ArrayHolder.h"
#include "Rectangle.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main (int argc, char **argv) {

   string op;
   ArrayHolder ah;
   
   while (op != "Q") {
      
      cout << " -- OPTIONS -- " << endl;
      cout << "PP: Plot a set of points" << endl;
      cout << "PR: Plot a rectangle" << endl;
      cout << "Q: Quit" << endl << endl;
      cout << "Enter an option: ";

      cin >> op;

      if (op == "PP")
         ah.getPoints();

      else if (op == "PR")
         ah.getRect();
      
      else if (op == "Q")
         break;

      else
         cout << "\"" << op << "\" is not a valid option." << endl;
      
   }

   return 0;
}
