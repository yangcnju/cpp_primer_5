#include <iostream>

template <typename T>
void g(T&& val)
{
	return;
}

using namespace std;

int main()
{
	int i = 0;
	const int ci = i;

	// (a)
	g(i);	// T is 'int&'

	// (b)
	g(ci);	// T is 'const int&'

	// (c)
	g(i*ci);	// T is int&&

	// ex16.43
	g(i=ci);	// same as i? (int&)

	return 0;
}
