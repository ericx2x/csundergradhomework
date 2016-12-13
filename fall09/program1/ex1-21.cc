/*
 * Ex 1.21
 *    Program based on Sales_item.h
 *
 * Eric Lima
 *
 */

#include <iostream>
#include "Sales_item.h"

int main() {

   Sales_item total, trans;

   while (std::cin >> trans) {
      if (total.same_isbn(trans))
         total += trans;
      else {
         std::cout << total << std::endl;
         total = trans;
      }
   }
   
   return 0;
}

