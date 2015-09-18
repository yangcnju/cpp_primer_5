#include <iostream>
#include <string>

#include "Vec.h"

using namespace std;

int main(int argc, char **argv)
{
	Vec<string> strVec;
	strVec.push_back("1st");
	strVec.push_back("2nd");
	strVec.push_back("3rd");
	cout << "strVec has size: " << strVec.size() << endl;

	return 0;
}
