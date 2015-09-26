#include "StrVec.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	StrVec sv1;
	sv1.push_back("s1");
	sv1.push_back("s2");
	sv1.push_back("s3");
	cout << sv1.size() << endl;
	cout << "capacity: " << sv1.capacity() << endl;
	return 0;
}
