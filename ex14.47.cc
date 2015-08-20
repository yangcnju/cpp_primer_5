#include <iostream>
#include <string>

using namespace std;

struct Integral {
	Integral(int i = 0) : data(i) {}
	Integral(const Integral&) = default;
	Integral& operator=(const Integral&) = default;
	~Integral() = default;
	operator int() const { std::cout << "int() const "; return data; }
	operator const int() { std::cout << "const int() "; return data; }
private:
	int data;
};	// struct Integral

int main()
{
	Integral i = 9;
	cout << i << endl;
	cout << static_cast<int>(i) << endl;
	cout << i + 5 << endl;
	const Integral *pi = &i;
	cout << *pi + 5 << endl;
}
