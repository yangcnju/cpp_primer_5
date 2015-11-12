// Exercise 19.4: Using the classes defined in the first exercise, rewrite the 
// following code to convert the expression *pa to the type C&:

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
	if(C *pc = dynamic_cast<C*>(pa))
		pc->show();
	else{
		pa->show();
		cout << "cast failed." << endl;
	}

	return 0;
}
