#include <iostream>
#include <vector>
#include "Vec.h"
#include <string>
#include <iterator>

using namespace std;

int main()
{
	vector<int> ivec0;
	ivec0.emplace_back(10);
	ostream_iterator<int> out_iter(cout, " ");
	copy(ivec0.begin(),ivec0.end(),out_iter);
	cout << endl;	

	Vec<int> ivec;
	ivec.emplace_back(10);
	//ostream_iterator<int> out_iter(cout, " ");
	copy(ivec.begin(),ivec.end(),out_iter);
	cout << endl;	
	return 0;
}
