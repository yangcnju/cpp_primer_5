// Exercise 19.12: Define a pointer to member that can point to the cursor
// member of class Screen. Fetch the value of Screen::cursor through that
// pointer.

#include <iostream>
#include <string>
#include "Screen.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
	Screen myScreen(5,5,"543112");
	const string Screen::*pdata = Screen::data();
	auto d = myScreen.*pdata;
	cout << d << endl;

	const std::string::size_type Screen::*pcursor = myScreen.current();
	auto c = myScreen.*pcursor;
	cout << c << endl;
	return 0;
}
