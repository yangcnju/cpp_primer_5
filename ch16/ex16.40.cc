#include <vector>
#include <string>
#include <iostream>

template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
	return *beg;
}

using namespace std;

int main()
{
	vector<string> svec {"aa","bbb","cc"};	// would be illegal on svec
	vector<int> ivec {1,2,3,4,5};
	cout << fcn3(ivec.begin(),ivec.end()) << endl;
	return 0;
}
