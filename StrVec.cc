#include "StrVec.h"

std::allocator<std::string> StrVec::alloc;

StrVec& StrVec::operator=(StrVec &&s) noexcept
{
	if(this != &s){
		free();
		elements = s.elements;
		first_free = s.first_free;
		cap = s.cap;
		s.elements = s.first_free = s.cap = nullptr;
	}
	return *this;
}

StrVec::StrVec(const std::initializer_list<std::string> &il)
{
	for(auto beg = il.begin(); beg!=il.end(); ++beg)
		push_back(*beg);
}

void StrVec::push_back(const std::string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy
	(const std::string *b, const std::string *e)
{
	auto data = alloc.allocate(e-b);
	return {data, std::uninitialized_copy(b,e,data)};
}

void StrVec::free()
{
	if(elements){
		auto p = elements;
		std::for_each(p,first_free,[](std::string &s) {alloc.destroy(&s);});
		//for(auto p = first_free; p!=elements; alloc.destroy(--p));
		alloc.deallocate(elements, cap-elements);
	}
}

StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(),s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec &&s) noexcept
	: elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2*size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for(size_t i = 0; i!=size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void StrVec::reserve(size_t n)
{
	if(n>capacity()){
		auto newdata = alloc.allocate(n);
		auto dest = newdata;
		auto elem = elements;
		for(size_t i = 0; i!=size(); ++i)
			alloc.construct(dest++, std::move(*elem++));
		free();
		elements = newdata;
		first_free = dest;
		cap = elements + n;
	}
}

StrVec::~StrVec()
{
	free();
}
