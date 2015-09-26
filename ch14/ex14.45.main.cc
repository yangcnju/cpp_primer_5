#include "ex14.45.Sales_data.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	Sales_data s1("apple",5.0,1);
	Sales_data s2;
	Sales_data s3(std::move(s1));
	cout << s3 << s2;
	cout << static_cast<string>(s3) << " " << static_cast<double>(s3) << endl;
//	cout << double(s2) << endl;
//	cout << string(s2) << endl;
	return 0;
}
