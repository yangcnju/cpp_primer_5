// Exercises in 19.4.2

#include <iostream>
#include <string>
#include "Screen.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
	Screen myScreen(5,5,"543112");
	auto pmf = &Screen::get_cursor;
	pmf = &Screen::get;
	cout << pmf << endl;

	using ptrget = char (Screen::*)(Screen::pos, Screen::pos) const;
	using ptrget_default = char (Screen::*)() const;

	ptrget pget = &Screen::get;
	ptrget_default pdget = &Screen::get;

	cout << (myScreen.*pget)(0,1) << endl;
	cout << (myScreen.*pdget)() << endl;

	return 0;
}
