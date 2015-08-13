#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class obj{
public:
	obj(): i(0) { cout << "default constructor." << endl; }
	obj(int j) : i(j) { cout << "int construct" << endl; }
	obj(const obj &o): i(o.i) { cout << "copy construct." << value() << endl; }
	obj(obj &&mo) noexcept: i(std::move(mo.i)) 
	{ cout << "move construct." << value() << endl; }

	obj& operator=(const obj &rhs) 
	{ i = rhs.i; cout << "assignment." << endl; return *this; }
	obj& operator=(obj &&rhs) noexcept
	{ i = std::move(rhs.i); cout << "move assignment." << endl; return *this; }
	int value() const { return i; }
private:
	int i;
}; // class obj

int main()
{
	obj o1;
	obj o2(1), o3(2);
	obj o4(3);
	cout << "-------------" << endl;
	vector<obj> objVec;
	objVec.push_back(o1);	
	objVec.push_back(o2);
	objVec.push_back(o3);
	objVec.push_back(o4);
	return 0;
}
