// Exercise 16.63: Define a function template to count the number of
// occurrences of a given value in a vector. Test your program by passing
// it a vector of doubles, a vecotor of ints, and a vector of strings.

#include <vector>
#include <string>
#include <iostream>

template <typename T, typename C>
unsigned occurrences(const T &t, const C &container)
{
	unsigned count  = 0;
	for(auto i : container)
		if(t == i)
			++count;
	return count;
}

using namespace std;

int main(int argc, char **argv)
{
	vector<double> dvec {0.1,0.2,0.3,0.4,0.5};
	vector<int> ivec {1,1,3,4,5,6,7};
	vector<string> svec {"aaa","bb","ccccc","bb","e","bb"};

	cout << occurrences(0.1,dvec) << endl;
	cout << occurrences(1,ivec) << endl;
	cout << occurrences("bb",svec) << endl;

	return 0;
}
