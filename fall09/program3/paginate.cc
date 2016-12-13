/****************************************************/
/* Paginate.cc										*/
/*													*/		
/* Eric Lima										*/
/*													*/
/* October 20th, 2009								*/
/*													*/
/* This program includes these optional functions   */
/*    -multi-file processing						*/
/*    -line truncation								*/
/****************************************************/

#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>

using std::endl;
using std::cout;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::fstream;

void print_file (const string & filename, const int line, const int columns, int & page_count);
void print_line (const string & line, int & line_counter, const int max_column);
void print_header (const string & filename, const int & page_number);

int main ( int argc, char *argv[] ) {

   int line = 24 ;
   int tabstop = 8 ;
   int columns = 80 ;

   // Command line parsing

   if (argc < 2) {
      cout << "Please enter a file on the command line." << endl;
      cout << "Use: ./paginate [--line-per-page] [--columns-per-page] file1 [file2] [..]" << endl;
      return 0;
   }
   
   int i;
   for (i = 1; argv[i][0] == '-'; i += 2) {

      string option = argv[i];
      int val = atoi (argv[i+1]);
      
      if (option == "--line-per-page")
         line = val;
      if (option == "--columns-per-page")
         columns = val;
   }

   vector<string> filenames;
   for ( ; i < argc; i++) filenames.push_back(argv[i]);
   
   // Use the Paginate function

   int page_count = 0;
   for (vector<string>::iterator filename_itr = filenames.begin(); filename_itr != filenames.end(); ++filename_itr) {

      print_file (*filename_itr, line, columns, page_count); 
   }
   
   return 0;
}



void print_file (const string & filename, const int max_line, const int max_column, int & page_count) {
   
   // Get the lines of the file
   
   fstream file(filename.c_str());
   vector<string> body;
   
   while (!file.eof()) {
      string line;
      getline (file, line);
      body.push_back (line);
   }
   file.close();
   
   // Output pages
   
   int line_counter = 0;

   for (vector<string>::iterator line_itr = body.begin(); line_itr != body.end() - 1; ++line_itr) {

      if (line_counter % max_line == 0) {
         print_header (filename, page_count);
         page_count++;
      }
      
      print_line (*line_itr, line_counter, max_column);

   }

   while (line_counter % max_line != 0)
      print_line ("", line_counter, max_column);

   return;
}



void print_line (const string & line, int & line_counter, const int max_column){
   
   string line_out;
   
   if (line.length() > max_column)
      line_out = line.substr (0, max_column - 3) + "...";
   else
      line_out = line;

   cout << setw(8) << left << line_counter + 1 << line_out << endl;
   line_counter++;
   
   return;
}



void print_header (const string & filename, const int & page_number) {

   cout <<  endl << "-- Page: " << page_number + 1 << " | File: " << filename << " --" << endl;
   return;
}
