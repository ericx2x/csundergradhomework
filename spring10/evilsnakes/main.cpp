/*********************************************************/
/* Programmer: Michael Staub                             */
/*                                                       */
/* File Name: main.cpp                                   */
/*                                                       */
/* Date: 2/28/2010                                       */
/*********************************************************/

#include <iostream>
#include <ncurses.h>
#include "game.h"

using namespace std;

int main() {

  Game gameInstance(80,40) ; 

  gameInstance.menu() ;
  gameInstance.run() ;

  return 0 ;

}

