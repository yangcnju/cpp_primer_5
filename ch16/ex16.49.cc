// Exercise 16.49: Explain what happens in each of the following calls:
#include <iostream>

using namespace std;

// Exercise 16.50 included.
template <typename T> void f(T) { cout << "f(T)" << endl; }
template <typename T> void f(const T*) { cout << "f(const T*)" << endl; }
template <typename T> void g(T) { cout << "g(T)" << endl; }
template <typename T> void g(T*) { cout << "g(T*)" << endl; }

int main()
{
	int i = 42, *p = &i;
	const int ci = 0, *p2 = &ci;

	g(42); // g(int&)
	g(p); // g(int*)
	g(ci);	// g(const int&)
	g(p2);	// g(const int*)
	f(42);	// f(const int&)
	f(p);	// f(int*)??
	f(ci);	// f(const int&)
	f(p2);	// f(const int*)

	return 0;
}
