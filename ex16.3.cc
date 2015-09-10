#include "Sales_data.h"
#include "compare.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	Sales_data s("demo",12.0,1);
	Sales_data s2("demo2",24.0,1);

	cout << s << endl;
	cout << s2 << endl;
	
	//cout << compare<Sales_data>(s,s2) << endl;
	cout << compare<string>("s1","s2") << endl;
	return 0;
}
