#include <iostream>

using namespace std;

template <typename T> T calc(T t, int i)
{
	return  t+i;
}

template <typename T> T fcn(T t1, T t2)
{
	return t1+t2;
}

double d {2.12};
float f {2.01};
char c {'a'};

int main()
{
	cout << calc(c, 'c') << endl;		// (a)	
	cout << calc(d,f) << endl;	// (b)
	cout << fcn(c, 'c') << endl;	// (c)
	cout << fcn(d,double(f)) << endl;	// (d) not legal, double and float are different
	                          // types.
	return 0;
}
