#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
ostream &print(ostream &os, const T &t)
{
	return os << t;
}

template <typename T, typename ... Args>
ostream &print(ostream&os, const T &t, const Args ... rest)
{
	os << t << ", ";
	return print(os,rest...);
}

// ex16.54
class noStream {
public:
	noStream(const int &d): data(d) {}
	noStream& operator=(const noStream &d) = default;
	noStream(const noStream &rhs) = default;
	~noStream() {}
private:
	int data;
};	// class noStream

// ex16.55
// If nonvariadic version of print was defined after the def
// of the variadic version:
// would be infinite recursion.

int main()
{
	vector<int> ivec {0,1,2,3,4,5};
	print(cout, ivec[0],ivec[1],ivec[2],ivec[3],ivec[4]);

	// if no '<<' defined, would not compile.
	// noStream ns(1);
	// print(cout,ns);
	return 0;
}
