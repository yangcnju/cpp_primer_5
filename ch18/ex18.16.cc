// Exercise 18.17: test using at different positions

#include <iostream>

using namespace std;

namespace Exercise {
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}

int ivar = 0;
// position 1
//  using Exercise::ivar; // conflict with global ivar
//  using Exercise::dvar;	
//  using Exercise::limit;

void manip() {
	// position 2
  using Exercise::ivar;
  using Exercise::dvar;	// cause conflict
  using Exercise::limit;
	double dvar = 3.1416;
	int iobj = limit + 1;
	++ivar;
	++::ivar;
	cout << "global ivar: " << ::ivar << endl;
	cout << "dvar: " << dvar << endl;
}

int main(int argc, char **argv)
{
	manip();
	return 0;
}
