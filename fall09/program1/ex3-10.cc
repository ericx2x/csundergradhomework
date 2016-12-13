/*
 * Ex 3.10
 *    Remove punctuation from a string.
 *
 * Eric Lima
 *
 */

#include <iostream>
#include <string>

using namespace std;

int main () {

   string s;

   cout << "Enter strings. ^D when done." << endl;
   
   while (cin >> s) {

      for (string::size_type i = 0; i < s.length(); i++) {

         if (ispunct (s[i])) s[i] = NULL;
      }

      cout << s << endl;
   }

   return 0;
}
