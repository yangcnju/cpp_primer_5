#ifndef _Vec_tpp
#define _Vec_tpp

#include "Vec.h"

template <typename T>
std::allocator<T> Vec<T>::alloc;

// copy control
template <typename T>
Vec<T>::Vec(const Vec<T> &t)
{
	auto newdata = alloc_n_copy(t.begin(),t.end());
	elements = newdata.first;
	first_free = newdata.second;
}

template <typename T>
Vec<T> &Vec<T>::operator=(const Vec<T> &t)
{
	auto data = alloc_n_copy(t.begin(), t.end());
	free();
	elements = data.first;
	first_free = data.second;
	return *this;
}

template <typename T>
Vec<T>::~Vec() { free(); }

template <typename T>
void Vec<T>::push_back(const T &t)
{
	chk_n_alloc();
	alloc.construct(first_free++, t);
}

template <typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
	auto data = alloc.allocate(e-b);
	return {data, std::uninitialized_copy(b,e,data)};
}

template <typename T>
void Vec<T>::free()
{
	if (elements) {
		for(auto p = first_free; p!=elements;
				alloc.destroy(--p));
		alloc.deallocate(elements, cap - elements);
	}
}

template <typename T>
void Vec<T>::reallocate()
{
	auto newcapacity = size() ? 2*size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for(size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

#endif
