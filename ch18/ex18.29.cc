// Exercise 18.29: Given the following class hierarchy:
// ...
// (a) In what order are constructors and destructors run on a Final object?
// (b) A Final object has how many Base parts? How many Class parts ?
// (c) Which of the follwing assignments is a compile-time error ?

#include <iostream>
#include <string>

using namespace std;

class Class {
public:
	Class() { cout << "Class()" << endl; }
};	// class Class

class Base : virtual public Class {
public:
	Base() : Class() { cout << "Base()" << endl; }
};	// class Base

class D1 : virtual public Base {
public:
	D1() : Base() { cout << "D1()" << endl; }
};	// class D1

class D2 : virtual public Base {
public:
	D2() : Base() { cout << "D2()" << endl; }
};	// class D2

class MI : public D1, public D2 {
public:
	MI() : Base(),D1(),D2() { cout << "MI()" << endl; }
}; 	// class MI

class Final : public MI, public Class {
public:
 Final() : MI() { cout << "Final()" << endl; }
};	// class Final

int main(int argc, char **argv)
{
	Final f;
	// (c)
	Base *pb;
	Class *pc;
	MI *pmi;
	D2 *pd2;

	//pb = new Class;	// sliced down?
	//pc = new Final; // ambiguous
	//pmi = pb;	// base to derived conversion. should not work 
	pd2 = pmi; // derived to base, ok.
	return 0;
}
