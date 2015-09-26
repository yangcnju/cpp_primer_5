#include <string>
#include <iostream>

class HasPtr{
public:
	HasPtr();
	HasPtr(const std::string&);
	HasPtr(const HasPtr&);
	HasPtr& operator=(const HasPtr&);
	~HasPtr();
private:
	int i;
	std::string *ps;
} ; // class HasPtr

HasPtr::HasPtr():
	i(0), ps(new std::string()) {}

HasPtr::HasPtr(const std::string &s):
	i(0), ps(new std::string(s)) {}

HasPtr::HasPtr(const HasPtr &rhs):
	i(rhs.i), ps(new std::string(*rhs.ps)) {}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	i = rhs.i;
	auto newp = new string(*rhs.ps);
	delete ps;
	ps = newp;
	return *this;
}

HasPtr::~HasPtr()
{
	delete ps;
}
