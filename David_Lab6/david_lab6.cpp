#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <functional>

using namespace std;


/***
This function takes an input filestream, output filestream, and maximum line width as input.
It runs through the text file and puts the text in an optimal number of lines given the line 
character width.
***/
void optimizeText(istream& in, ostream& out, size_t width) 
{
   string tmp;
   char cur = '\0';
   char last = '\0';
   size_t i = 0;

   while (in.get(cur)) 
   {
      if (++i == width+1) 
      {
      
		 out << '\n' << tmp;      
         i = tmp.length();
         tmp.clear();
      } 
      else if (isspace(cur) && !isspace(last)) 
      { 
         out << tmp;
         tmp.clear();
      }
      tmp += cur;
      last = cur;
   }
}

int main()
{
	string input_file;
	string output_file;
	size_t max_line_length;

	cout << " Please enter an input text file > " ;
	cin >> input_file;

	cout << " Please enter an output file name > " ;
	cin >> output_file;

	cout << " Please enter the max line length desired > " ;
	cin >> max_line_length;

	fstream in_file;
   	in_file.open(input_file, ios::in);

   	fstream out_file;
    out_file.open(output_file, ios::out);

    optimizeText(in_file, out_file, max_line_length);

    in_file.close();
    out_file.close();

    cout << " _____________________________________________________" << endl;
   cout << " Your file has been generated as " << output_file << endl;
   cout << " _____________________________________________________" << endl;

   return 0;
}