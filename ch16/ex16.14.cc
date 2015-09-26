#include "Screen.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	Screen<3,4> s1;
	cout << s1;
	
	Screen<3,4> s2("demo2");
	cout << s2;
	s2 = s1;
	cout << s2;

	// ex16.15
	Screen<16,16> s3("ex16.15");
	cout << "Input string for s3: " << endl;
	cin >> s3;
	cout << s3;

	return 0;
}
