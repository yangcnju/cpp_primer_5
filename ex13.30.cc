#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

// value like
class HasPtr{
	friend void swap(HasPtr&, HasPtr&);
	friend bool operator<(const HasPtr &lhs, const HasPtr &rhs);
public:
	HasPtr();
	HasPtr(const std::string&);
	HasPtr(const HasPtr&);
	HasPtr& operator=(const HasPtr&);
	~HasPtr();
	std::string str() const { return *ps; }
	
	//bool operator<(const HasPtr &rhs) const{ return *ps < *rhs.ps; }
private:
	int i;
	std::string *ps;
} ; // class HasPtr

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.i,rhs.i);
	swap(lhs.ps,rhs.ps);
	std::cout << "swap called." << std::endl;
}

inline
bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
	return *lhs.ps < *rhs.ps;
}

HasPtr::HasPtr():
	i(0), ps(new std::string()) {}

HasPtr::HasPtr(const std::string &s):
	i(0), ps(new std::string(s)) {}

HasPtr::HasPtr(const HasPtr &rhs):
	i(rhs.i), ps(new std::string(*rhs.ps)) {}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	i = rhs.i;
	auto newp = new std::string(*rhs.ps);
	delete ps;
	ps = newp;
	return *this;
}

HasPtr::~HasPtr()
{
	delete ps;
}

///////
int main()
{
	HasPtr pt1("apple");
	HasPtr pt2("banana");
	std::cout << pt1.str() << std::endl;
	std::cout << pt2.str() << std::endl;
	std::cout << "--------" << std::endl;
	swap(pt1,pt2);
	std::cout << pt1.str() << std::endl;
	std::cout << pt2.str() << std::endl;

	//ex13.31
	std::cout << "\nexercise 13.31" << std::endl;
	std::vector<HasPtr> ptrs;
	ptrs.push_back(pt1);
	ptrs.push_back(pt2);
	ptrs.push_back(HasPtr("aaa"));
	for(auto i : ptrs){
		std::cout << i.str() << std::endl;
	}

	sort(ptrs.begin(),ptrs.end());
	for(auto i : ptrs){
		std::cout << i.str() << std::endl;
	}
	return 0;
}
