/*
 * concat.cc
 *    reads a series of strings into a vector.
 *    outputs all the strings concatenated by hyphens.
 *
 * Eric Lima
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main () {

   string word;
   vector<string> text;
   
   cout << "Enter a series of strings. ^D to end." << endl;

   while (cin >> word)
      text.push_back(word);

   for (vector<string>::iterator i = text.begin(); i != text.end(); i++)
      cout << *i << "-";

   cout << endl;
   
   return 0;
}
