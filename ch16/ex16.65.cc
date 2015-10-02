// Exercise 16.65:
// In ch16.3 (p. 698) we defined overloaded two versions of debug_rep
// one had a const char* and the other a char* parameter. Rewrite these
// functions as specializations.

#include <string>
#include <iostream>
#include <sstream>

template <typename T> std::string debug_rep(const T &t)
{
	std::ostringstream ret;
	ret << t;
	return ret.str();
}

template <typename T> std::string debug_rep(T *p)
{
	std::ostringstream ret;
	ret << "pointer: " << p;
	if(p)
		ret << " " << debug_rep(*p);
	else
		ret << " null pointer";
	return ret.str();
}

/* overloaded version.
std::string debug_rep(const std::string &);	// see page 699
std::string debug_rep(char *p)
{
	return debug_rep(std::string(p));
}

std::string debug_rep(const char *p)
{
	return debug_rep(std::string(p));
}
*/

template <>
std::string debug_rep(char *p)
{
	std::cout << "debug_rep(char *p) ";
	return debug_rep(std::string(p));
}

template <>
std::string debug_rep(const char *p)
{
	std::cout << "debug_rep(const char *p) ";
	return debug_rep(std::string(p));
}

using namespace std;

int main(int argc, char **argv)
{
	string s("hi");
	cout << debug_rep(&s) << endl;
	char a[10] = "hahaha";
	cout << debug_rep(&a) << endl;
	cout << debug_rep("3rd") << endl;
	return 0;
}
