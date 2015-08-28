#include <iostream>

class Base {
public:
	virtual int fcn() { return 0; }
};

class D1 : public Base {
public:
	int fcn() override { return 1; }
};

using namespace std;

int main()
{
	Base bobj; 
	D1 d1obj;

	Base *bp1 = &bobj, *bp2 = &d1obj;
	cout << bp1->fcn() << endl;
	cout << bp2->fcn() << endl;	
	return 0;
}
