#include "my_find.h"
#include <vector>
#include <list>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	vector<int> ivec {1,2,3,4,5,6,7,8};
	list<string> slst {"s1","s2","s3","slast"};
	auto pos = my_find(ivec.cbegin(),ivec.cend(),8);
	auto pos2 = my_find(slst.cbegin(),slst.cend(),"slast");
	cout << *pos << endl;
	cout << *pos2 << endl;
	return 0;
}
