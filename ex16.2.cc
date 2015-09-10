#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
int compare(const T &v1, const T &v2)
{
	if(less<T>()(v1,v2)) return -1;
	if(less<T>()(v2,v1)) return 1;
	return 0;
}

template <unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
	return strcmp(p1,p2);
}

int main(int argc, char **argv)
{
	cout << compare(1,0) << endl;

	vector<int> vec1{1,2,3}, vec2{4,5,6};
	cout << compare(vec1,vec2) << endl;	// T is vector<int>

	cout << compare("hi","mom") << endl;
	return 0;
}
