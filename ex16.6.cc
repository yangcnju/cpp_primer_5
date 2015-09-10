#include "my_beg_n_end.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	char ca[10] = {'a','b','c','d'};
	cout << sizeof(ca)/sizeof(char) << endl;

	for(auto p = my_t::begin(ca); p!= my_t::end(ca); ++p){
		cout << *p << " ";
	}
	cout << endl;
	return 0;
}
