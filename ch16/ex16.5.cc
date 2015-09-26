#include "my_print.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	vector<int> ivec {1,2,3,4,5};
	char c_array[] = {'a','b','c','d'};
	print(ivec.cbegin(),ivec.cend());
	print(c_array,4);
	return 0;
}
