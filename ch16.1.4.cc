#include "DebugDelete.h"
#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	double *p = new double;
	DebugDelete d;
	d(p);
	int* ip = new int;
	DebugDelete()(ip);

	unique_ptr<int, DebugDelete> up(new int, DebugDelete());
	unique_ptr<string, DebugDelete> usp(new string, DebugDelete());

	return 0;
}
