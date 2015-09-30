#include <iostream>
#include <sstream>
#include <string>

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
	ret << "pointers: " << p;
	if(p)
		ret << " " << debug_rep(*p);
	else
		ret << " null pointer";
	return ret.str();
}

template <typename T>
ostream &print(ostream &os, const T &t)
{
	return os << t;
}

template <typename T, typename ... Args>
ostream &print(ostream &os, const T &t, const Args&... rest)
{
	os << t << ", ";
	return print(os,rest...);
}

template <typename ... Args>
ostream &errorMsg(ostream &os, const Args& ... rest)
{
	return print(os, debug_rep(rest)...);
}

int main()
{
	string s1 ("demo1");
	int i1 = 1;
	errorMsg(cout,&s1,&i1);
	return 0;
}
