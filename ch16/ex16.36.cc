#include <iostream>

using namespace std;

template <typename T> int f1(T t1, T t2)
{
	return 0;
}

template <typename T1, typename T2> int f2(T1 t1, T2 t2)
{
	return 1;
}

int main()
{
	int i = 0, j = 42, *p1 = &i, *p2 = &j;
	const int *cp1 = &i, *cp2 = &j;
	cout << f1(p1, p2) << endl;	// (a)
	cout << f2(p1, p2) << endl;	// (b)
	cout << f1(cp1, cp2) << endl;	// (c)
	cout << f2(cp1,cp2) << endl;	// (d)
	//cout << f1(p1, cp1) << endl;	// (e) type deduction error
	cout << f2(p1, cp1) << endl;	// (f)
	return 0;
}
