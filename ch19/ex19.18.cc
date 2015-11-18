// Exercise 19.18: Write a function that uses count_if to count how many
// empty strings are in a given vector.

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;
using std::string;

class mystr : public string {
public:
	using string::string;	// inherit constructor
	
	bool empty() const { return string::empty(); }
	bool myfcn() const { return true; }
};

int main()
{
	vector<string> svec ={"","demo1","demo2","","demo3"};

	cout << count_if(svec.cbegin(),svec.cend(),
			             [](const string &s){return s.empty();}) 
	     << endl;

  function<bool (const std::string&)> fcn = &string::empty;
	cout << count_if(svec.begin(),svec.end(), fcn) << endl;
	mystr ms1 = "my string";
	function<bool (const mystr&)> myfcn = &mystr::myfcn;
	vector<mystr> myvec = {"","haha","hahaha","","haha3"};
	cout << count_if(myvec.begin(),myvec.end(), myfcn) << endl;
  	
	return 0;
}
