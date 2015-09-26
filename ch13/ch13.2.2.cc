#include <string>
#include <iostream>

class HasPtr{
public:
	HasPtr(const std::string &s = std::string()):
		ps(new std::string(s)), i(0), use(new std::size(1)) {}
	HasPtr(const HasPtr &p):
		ps(p.ps), i(p.i), use(p.use) { ++*use;}
	HasPtr& operator=(const HasPtr&);
	~HasPtr();
private:
	int i;
	std::string *ps;
	std::size_t *use;
} ; // class HasPtr which is pointer like

HasPtr::~HasPtr()
{
	if(--*use == 0){
		delete ps;
		delete use;
	}
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	++*rhs.use;
	if(--*use == 0){
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	use = rhs.use;
	i = rhs.i;
	return *this;
}
