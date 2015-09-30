#include <iostream>
#include <sstream>

using namespace std;

template <typename T> string debug_rep(const T &t)
{
	ostringstream ret;
	ret << t;
	return ret.str();
}

template <typename T> string debug_rep(T *p)
{
	ostringstream ret;
	ret << "pointer: " << p;
	if (p)
		ret << " " << debug_rep(*p);
	else
		ret << " null pointer";
	return ret.str();
}

int main()
{
	string s("hi");
	cout << debug_rep(&s) << endl;
	return 0;
}
