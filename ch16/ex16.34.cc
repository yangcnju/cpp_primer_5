#include <iostream>
#include <string>

using namespace std;

template <class T>
int compare(const T &lhs, const T &rhs)
{
	return 0;
}


int main()
{
	// (a)
	cout << compare<string>("hi", "world") << endl;
	// will be deduced as char[3] and char[6] if not specified as string
	
	// (b)
	cout << compare("bye", "dad") << endl;

	return 0;
}
