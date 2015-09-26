#include <iostream>
#include <string>

using namespace std;

class Base {
public:
	Base()=default;
	Base(const Base&)=default;
	Base& operator=(const Base&)=default;
	~Base()=default;
	Base(int num):i(num) {}

	int val() const { return i; }
private:
	int i;
};

//(b)
class Derived: private Base {
public:
	int dval() const { return val(); }	// still cannot access i in the base
};

int main()
{
	Base b;
	Derived d;
	cout << b.val() << endl;
	cout << d.dval() << endl;
	return 0;
}
