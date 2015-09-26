#include <iostream>

template <typename T>
T my_max(const T &lhs, const T &rhs)
{
	return (lhs < rhs ? rhs : lhs);
}

using namespace std;

int main()
{
	int i {1};
	double d {2.1};
	cout << my_max<double>(i,d) << endl;
	return 0;
}
