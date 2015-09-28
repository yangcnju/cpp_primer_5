// Given the following template, explain what happens if we call g
// on a literal value such as 42. What if we call g on a variable
// of type int?
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
void g(T&& val)
{ vector<T> v; }

int main()
{
	g(42);	// T is const int&
	return 0;
}
