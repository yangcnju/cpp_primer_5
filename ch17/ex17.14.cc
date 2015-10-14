// Exercise 17.14: Write several regular expressions designed to trigger
// various errors. Run your program to see what output your compiler
// generates for each error.

#include <regex>
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
	try{
	regex r1("[[:alnum:]]+\\.(cpp|cxx|cc)$",regex::icase);
	smatch results;
	string test_str("myfile.cc");
	if(regex_search(test_str,results,r1))
		cout << results.str() << endl;
	}catch(regex_error &e) {
		cout << e.what() << endl;
		cout << "code: " << e.code() << endl;
	}
	return 0;
}
