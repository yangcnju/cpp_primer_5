#include "ex13.25.StrBlob.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	StrBlob sb {"string1","string2","string3"};
	sb.push_back("extra_s");
	cout << "ex13.25: " << endl;
	cout << "size of the StrBlob sb: " << sb.size() << endl;
	StrBlob sb2(sb);
	sb2.pop_back();
	cout << sb.size() << " " << sb2.size() << endl;
	StrBlob sb3 = sb;
	sb3.push_back("s5");
	sb3.push_back("s6");
	cout << sb.size() << " " << sb3.size() << endl;
	cout << endl;
	return 0;
}
