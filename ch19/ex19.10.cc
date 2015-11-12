// Exercise 19.10: Given the follwing class hierarchy, which type name do the
// following statements print?

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class A {
public:
	A() {}
	virtual ~A() {}

	virtual void show() const { cout << "this is A." << endl; }
};

class B : public A {
public:
  B() : A(),b(0) {}
	virtual ~B() {}

	virtual void show() const { cout << "this is B." << endl; }
private:
	int b;
};

class C : public B {
public:
	C(): B() {}
	virtual ~C() {}

	virtual void show() const { cout << "this is C." << endl; }
};

int main(int argc, char **argv)
{
	A *pa = new C;
	cout << typeid(pa).name() << endl;

	C cobj;
	A& ra = cobj;
	cout << typeid(&ra).name() << endl;

	B *px = new B;
	A& ra2 = *px;
	cout << typeid(ra2).name() << endl;

	return 0;
}
