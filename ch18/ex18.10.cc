// Exercise 18.10: Write a program that uses the Sales_data addition operator
// on objects that have differing ISBNs. Write two versions of the program:
// one that handles the exception and one that does not. Compare the behavior
// of the programs so that you become familiar with what happens when an
// uncaught exception occurs.

#include "Sales_data.h"
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
	Sales_data sd1("item1", 30.0, 1);
	Sales_data sd2("item2", 32.0, 1);
	try{
	cout << sd1+sd2 << endl;
	} catch(logic_error &e){
		cout << e.what() << endl;
	}
	return 0;
}
