// Exercise 17.37: Use the unformatted version of getline to read a file
// a line at a time. Test your program by giving it a file that contains
// empty lines as well as lines that are longer than the character array
// that you pass to getline.

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	char sink[80];
	ifstream is("ex17.9.cc");
	while(is.getline(sink, 60, '\n'))
		cout << sink << endl;

	is.close();
  
	return 0;
}
