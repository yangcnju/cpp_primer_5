#include "String.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	String *s1= new String({'d','e','m','o'});
	String *s2=nullptr;
	String *s3(new String(*s1));
	String *s4 = s3;
	vector<String*> vs {s1,s2,s3,s4};

	return 0;
}
