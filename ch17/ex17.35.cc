// Exercise 17.35: Write a version of the program from page 758, that
// printed the square root of 2 but this time print hexadecimal digits
// in uppercase.

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	cout << setprecision(12);
	cout << right;
	cout << hexfloat << uppercase << setw(30) << sqrt(2.0) << endl;
	cout << hexfloat << uppercase << setw(30) << sqrt(3.0) << endl;
	cout << defaultfloat << nouppercase;
	return 0;
}
