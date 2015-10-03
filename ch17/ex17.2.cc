// Exercise 17.2: Define a tuple that holds a string, a vector<string>,
// and a pair<string, int>.

#include <tuple>
#include <utility> // pair
#include <vector>
#include <string>
#include <iostream> // cout, endl

using namespace std;

int main()
{
	tuple<string,vector<string>,pair<string,int>> st 
	{"string tuple", {"aa","bbb","cccc"},{"stringpair",9}};
	cout << get<0>(st) << endl;

	vector<string> svec {"aaa","bb","c"};
	auto sipair = make_pair(string("pair string"), 9);
	auto st2 = make_tuple(string("string t"), svec, sipair);
	cout << get<0>(st2) << endl;
	return 0;
}
