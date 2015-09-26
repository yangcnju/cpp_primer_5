// Exercise 16.26: Assuming NoDefault is a class that does not have
// a default constructor, can we explicitly instantiate vector<NoDefault>?
// If not, why not?
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class NoDefault {
public:
	NoDefault() = delete;
	NoDefault(int i) : data(i) {}
	~NoDefault() = default;
	
	int show() const { return data; }
private:
	int data;
};	// class NoDefault

// Explicit instantiation
// template class vector<NoDefault>;
// no.
// 1. instantiation already done by stl.
// 2. need default constructor.

int main(int argc, char **argv)
{
	// Implicit instantiation
	vector<NoDefault> ndvec {1,2,3};
	for(auto i : ndvec)
		cout << i.show() << endl;

	return 0;
}
