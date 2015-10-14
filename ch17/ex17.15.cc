// Exercise 17.15: Write a program using the pattern that finds words that
// violate the "i before e except after c" rule. Have your program prompt
// the user to supply a word and indicate whether the word is okay or not.
// Test your program with words that do and do not violate the rule.

#include <regex>
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
	try{
	regex r1("[[:alpha:]]*[^c]ei[[:alpha:]]*");
	smatch results;
	string test_str;

	cout << "Input a word to test (q to quit): " << endl;
	  while(cin >> test_str && test_str != "q"){
	    if(regex_search(test_str,results,r1))
	  		cout << "OK" << endl;
	  	else
	  		cout << "Not" << endl;

	    cout << "Input a word to test (q to quit): " << endl;
	  }
	}catch(regex_error &e) {
		cout << e.what() << endl;
		cout << "code: " << e.code() << endl;
	}
	return 0;
}
