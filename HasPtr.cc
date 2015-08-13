#include "HasPtr.h"

HasPtr::HasPtr(const HasPtr &rhs):
	ps(rhs.ps), i(rhs.i), use(rhs.use) { ++*use; }

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	--*use;
	if(*use == 0){
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	++*use;
	return *this;
}

HasPtr::~HasPtr()
{
	--*use;
	if(*use == 0){
		delete use;
		delete ps;
	}
}

const std::string HasPtr::operator*() const
{
	return *ps;
}

const std::size_t HasPtr::count() const
{
	return *use;
}

void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps,rhs.ps);
	swap(lhs.i,rhs.i);
}
