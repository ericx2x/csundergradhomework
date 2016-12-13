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
#include <stdio.h>


using namespace std;

int main() {

int i, j, k;

//This is where I make the menu. The user has 3 options: Play, Instructions, or quit.


 cout<<"   $$$             $$$" <<endl<< "   $$$ Evil Snakes $$$" <<endl<<"   $$$             $$$"<< endl << "Type 1 to play the game" << endl << "Type 2 to view instuctions" << endl << "Type 3 to quit"<< endl ;

  cin>> i ;

 if (i ==2){
   cout<< "==Instructions==" <<endl<< "You have 3 lives. If you touch a snake ($) you die once. Once the time hits 0 you progress to the next level which will have more enemies!" << endl<<"--Controls--" <<endl << "Press W to move up."<<endl<<"Press S to move down."<<endl<<"Press A to move left."<< endl << "Press D to move right."<<endl<<"Press Spacebar to shoot fireballs."<<endl<<"To start type 1, or type 3 to exit." <<endl;
    cin >> i ;
    if(i==1){  Game gameInstance(80,30) ;

    gameInstance.run(i,j, k) ;
    }

}
 else if(i==1){
 // Create a game on an 80x30 map
  Game gameInstance(80,30) ;

  gameInstance.run(i, j, k ) ;
  }
  
    else if(i == 3){
    return 0 ;
  }
}

