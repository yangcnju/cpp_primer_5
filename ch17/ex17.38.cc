// Exercise 17.38: Extend your program from the previous exercise to print
// each word you read onto its own line.

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	char sink[80];
	ifstream is("ex17.9.cc");
	while(is.getline(sink, 60, ' '))
		cout << sink << endl;

	is.close();
  
	return 0;
}
