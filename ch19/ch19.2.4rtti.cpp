#include <typeinfo>
#include <iostream>
#include <string>

using std::cout;
using std::endl;

class Base {
	friend bool operator==(const Base&, const Base&);
public:
	Base() : b(0) {}
	Base(int i) : b(i) {}
	int data() const { return b; }
protected:
	virtual bool equal(const Base &rb) const { return b == rb.b; }
private:
	int b;
};

class Derived : public Base {
public:
	Derived() : Base(), d(0) {}
	Derived(int i) : Base(), d(i) {}
	Derived(int i1, int i2): Base(i1), d(i2) {}
protected:
	bool equal(const Base &b) const { return d == b.data(); } 
private:
	int d;
};

bool operator==(const Base &lhs, const Base &rhs)
{
	return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}

int main()
{
	int arr[10];
  Derived d;
	Base *p = &d;
	cout << typeid(42).name() << endl;
	cout << typeid(arr).name() << endl;
	cout << typeid(std::string).name() << endl;
	cout << typeid(p).name() << endl;
	cout << typeid(*p).name() << endl;
	return 0;
}
