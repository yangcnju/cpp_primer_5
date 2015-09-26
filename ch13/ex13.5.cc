#include <iostream>
#include <string>

class HasPtr{
public:
	HasPtr(const std::string &s = std::string()):
		ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr &orig);
	HasPtr& operator=(const HasPtr &orig);
	~HasPtr();
private:
	std::string *ps;
	int i;
};	// class HasPtr

HasPtr::HasPtr(const HasPtr &orig):
	ps(new std::string(*(orig.ps))),i(orig.i) {}

HasPtr& HasPtr::operator=(const HasPtr &orig)
{
	ps = new std::string(*(orig.ps));
	i = orig.i;
	return *this;
}

HasPtr::~HasPtr()
{
	delete ps;
}

int main()
{
	HasPtr hp1,hp2;
	return 0;
}
