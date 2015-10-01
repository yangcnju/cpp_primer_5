#include <string>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

int main()
{
	vector<string> svec {"aaa","bb"};
	cout << "svec originally is: ";
	ostream_iterator<string> o_iter(cout, " ");
	copy(svec.cbegin(),svec.cend(),o_iter);
	cout << endl;

	string s ("extra");
	svec.emplace_back(s);
	cout << "svec after change: ";
	copy(svec.cbegin(),svec.cend(),o_iter);
	cout << endl;
	return 0;
}
