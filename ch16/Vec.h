// for exercise 16.16: Rewrite the StrVec class on p. 526 as a template
#ifndef _Vec_h
#define _Vec_h

#include <memory>
#include <utility>	// pair, forward
#include <string>

template <typename T>
class Vec {
public:
	Vec():
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
	Vec(const Vec<T>&);
	Vec &operator=(const Vec<T>&);
	~Vec();

	void push_back(const T&);
	template <typename ... Args> void emplace_back(Args&&...);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	T *begin() const { return elements; }
	T *end() const { return first_free; }
private:
	static std::allocator<T> alloc;

	void chk_n_alloc()
	{ if(size() == capacity()) reallocate(); }

	std::pair<T*, T*> alloc_n_copy(const T*, const T*);
	void free();
	void reallocate();
	T *elements;
	T *first_free;
	T *cap;
};	// template class Vec<T>

// Implementation of template class Vec<T>
#include "Vec.tpp"

#endif
