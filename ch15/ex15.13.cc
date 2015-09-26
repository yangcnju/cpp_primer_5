// Given the following classes, explain each print function:

#include <iostream>
#include <string>

using namespace std;

class base {
public:
	base() : basename("base") {}
	base(const string &s): basename(s) {}
	string name() { return basename; }
	virtual void print(ostream &os) const { os << basename; }
private:
	string basename;
};	// class base

class derived: public base {
public:
	derived() : base("derived"),i(0) {}
	derived(int num): base("derived init by int"), i(num) {}
	// below is modified to explicitly call base version of print
	// otherwise infinite loop!
	void print(ostream &os) const { base::print(os); os << " " << i; }
private:
	int i;
};	// class derived

void call_print(const base &b)
{
	b.print(cout);
	cout << endl;
}

int main()
{
	base b;
	derived d;
	call_print(b);
	call_print(d);
	base *b_ptr = &d;
	call_print(*b_ptr);
	return 0;
}
