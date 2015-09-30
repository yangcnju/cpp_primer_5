#include <string>
#include <iostream>

using namespace std;

template <typename ... Args> void g(Args ... args)
{
	cout << "Args: " << sizeof...(Args) << endl;
	cout << "args: " << sizeof...(args) << endl;
}

template <typename T, typename... Args>
void f(const T &t, const Args&... rest)
{
	cout << "Args: " << sizeof...(Args) << endl;
	cout << "args: " << sizeof...(rest) << endl;
}

int main()
{
	int i = 0; double d = 3.14; string s = "how now brown cow";
	g(i,s,42,d);
	g(s,42,"hi");
	g(d,s);
	g("hi");

	f(i,s,42,d);
	f(s,42,"hi");
	f(d,s);
	f("hi");
	return 0;
}
