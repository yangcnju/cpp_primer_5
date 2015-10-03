// Exercise 17.1: Define a tuple that holds three int values and initialize
// the members to 10, 20, and 30.

#include <tuple>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	tuple<int,int,int> its {10,20,30};
	cout << get<0>(its) << " "
		   << get<1>(its) << " "
			 << get<2>(its) << endl;
	return 0;
}
