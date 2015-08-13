#include <iostream>
#include <string>
#include <vector>

struct X{
	X() {std::cout << "X()" << std::endl;}
	X(const X&) {std::cout << "X(const X&)" << std::endl;}
	~X() {std::cout << "~X()" << std::endl;}
	X& operator=(const X&) {
		std::cout << "X& operator=(const X&)" << std::endl;
		return *this;
	}
};

int main()
{
	X x1;
	X x2;
//	x2 = x1;
	std::vector<X> v1;
	v1.push_back(x1);
//	v1.push_back(x2);
	return 0;
}
