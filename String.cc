#include "String.h"

#include <iostream>

// static member
std::allocator<char> String::alloc;

String::String(const String &rhs)
{
	auto newdata = alloc_n_copy(rhs.begin(),rhs.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
	std::cout << "copy constructor utilized." << std::endl;
}

String& String::operator=(const String &rhs)
{
	auto newdata = alloc_n_copy(rhs.begin(),rhs.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	std::cout << "copy-assignment utilized." << std::endl;
	return *this;
}

String::String(const std::initializer_list<char> &il)
{
	auto newdata = alloc_n_copy(il.begin(),il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
	std::cout << "initializer_list constructed." << std::endl;
}

String::~String()
{
	free();
}

void String::reallocate()
{
	size_t new_capacity = size()*2;
	auto newdata = alloc.allocate(new_capacity);
	auto dest = newdata;
	auto elem = elements;
	for(size_t i = 0; i!=size(); ++i)
		alloc.construct(dest++,std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + new_capacity;
}

std::pair<char*, char*> String::alloc_n_copy(const char *b, const char *e)
{
	auto p = alloc.allocate(e-b);
	return {p, std::uninitialized_copy(b,e,p)};
}

void String::free()
{
	if(elements){
		for(auto p = first_free; p!=elements;
				alloc.destroy(--p));
		alloc.deallocate(elements,cap-elements);
	}
}
