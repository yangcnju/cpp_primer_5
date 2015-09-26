#include "my_size_array.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int ia[10] = {1,2,3,4,5};
	cout << my_t::m_sizeof(ia) << endl;
	return 0;
}
