// Pointer like behavior
// Ch13.2
#ifndef _HasPtr_h
#define _HasPtr_h

#include <string>
#include <memory>

class HasPtr{
	friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr():
		ps(new std::string()), i(0), use(new std::size_t(1)) {}
	HasPtr(const HasPtr&);
	HasPtr& operator=(const HasPtr&);
	~HasPtr();

	const std::string operator*() const;
	const std::size_t count() const;
private:
	std::string *ps;
	int i;
	std::size_t *use;
};	// class HasPtr

inline void swap(HasPtr&, HasPtr&);

#endif
