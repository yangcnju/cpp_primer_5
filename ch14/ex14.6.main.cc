#include "ex14.6.Sales_data.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	Sales_data s1("apple",5.0,1);
	Sales_data s2;
	Sales_data s3(std::move(s1));
	cout << s3 << s2;
	return 0;
}
