// Exercise 16.64: Write a specialized version of the template
// from the previous exercise to handle vector<const char*> and
// a program that uses this specialization.

#include <vector>
#include <string>
#include <iostream>

template <typename T, typename C>
unsigned occurrences(T &&t, const C &container)
{
	unsigned count  = 0;
	for(auto i : container)
		if(t == i)
			++count;
	return count;
}

template <>
unsigned occurrences(const char *(&ptc), const std::vector<const char*> &ccvec)
{
	unsigned count = 0;
	for(auto i : ccvec)
		if(*ptc == *i)
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

	// ex16.64
	const char c('i');
	const char *cpc = &c;
	const char *cpc2 = &c;
	vector<const char*> cvec;
	cvec.push_back(cpc);
	cvec.push_back(cpc);
	cout << occurrences(cpc2,cvec) << endl;	
	
	return 0;
}
