// Exercise 17.34: Write a program that illustrates the use of each
// manipulator in Table 17.17 (p. 757) and 17.18.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	cout << boolalpha << "bool value: " << true << endl;
	cout << noboolalpha;

	cout << showbase << "showbase: " << oct << 0x100 << endl;
	cout << noshowbase << "noshowbase: " << oct << 0x100 << endl;
	cout << dec;

	cout << showpoint << "showpoint: " << 0.01 << endl;
	cout << noshowpoint << "noshowpoint: " << 0.01 << endl;

	cout << showpos << "showpos: " << 0.01 << endl;
	cout << noshowpos;

	cout << uppercase << scientific 
	     << "uppercase & scientific: " << 0.0001 << endl;
	cout << nouppercase;

	cout << left << setw(15) << "left: " << 0.01 << endl;
	cout << right << setw(15) << "right: " << 0.01 << endl;
	return 0;
}
