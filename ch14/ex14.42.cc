// functional header
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	// (a) Count the number of values that are greater than 1024
	vector<int> vals {1,2,10,20,100,200,1000,2000,10000,20000};
	greater<int> igreaterObj;
	auto larger_than_1024 = count_if(vals.cbegin(),vals.cend(),
																	 bind(igreaterObj,placeholders::_1,1024));
	cout << "number of values larger than 1024: " << larger_than_1024 << endl;

	// (b) Find the first string that is not equal to 'pooh'
	string str_match {"pooh"};
	vector<string> svec {"poo","hooh","pooh","haha"};
	not_equal_to<string> not_str;
	auto iter = find_if(svec.cbegin(),svec.cend(),
										  [not_str, str_match](const string &s) 
												{ return not_str(s, str_match); } ); 
	cout << "first string not equal to " + str_match + " is: "
			 << *iter << endl;

	// (c) Multiply all values by 2
	multiplies<int> mul_Obj;	
	vector<int> ivec {1,2,3,4,5,6,7,8,9,10};
	ostream_iterator<int> o_iter(cout, " ");
	copy(ivec.cbegin(),ivec.cend(),o_iter);
	cout << endl;
	
	transform(ivec.begin(),ivec.end(),ivec.begin(),
						bind(mul_Obj,placeholders::_1,2));	
	cout << "after multiplication: " << endl;
	copy(ivec.cbegin(),ivec.cend(),o_iter);
	cout << endl;

	return 0;
}
