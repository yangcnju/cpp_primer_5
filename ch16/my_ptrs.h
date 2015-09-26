#ifndef _my_ptrs_h
#define _my_ptrs_h

#include <stdexcept>
#include <iostream>
#include <string>

namespace my_ptrs {

template <typename> class shared_ptr;

template <typename T>
shared_ptr<T> make_shared(T *t)
{
	shared_ptr<T> ptr(std::move(t));
	return ptr;
}

template <typename T>
shared_ptr<T> make_shared(typename T::iterator b, typename T::iterator e)
{
	T *t= new T(b,e);
	shared_ptr<T> ptr(std::move(t));
	return ptr;
}

// own version of shared_ptr
template <typename T>
class shared_ptr {
public:
	shared_ptr() : p(new T), count(1) {}
	shared_ptr(T *pt): p(std::move(pt)), count(1){}	// pt not useful after
	                                                // been used for shared_ptr
	shared_ptr(shared_ptr<T> &sptr):
		p(sptr.p), count(++sptr.count) {}
	shared_ptr(shared_ptr<T> &&sptr) noexcept:
		p(std::move(sptr.p)), count(sptr.count) {}
	shared_ptr& operator=(shared_ptr<T> &sptr)
	{ p = sptr.p; count = ++sptr.count; return *this;}
	shared_ptr& operator=(shared_ptr<T> &&sptr) noexcept
	{ p = std::move(sptr.p); count = sptr.count; return *this;}

	~shared_ptr()
	{ 
		if((--count) == 0) {
			std::cout << "shared_ptr deleter." << std::endl;
			delete p; 
		}
	}

	// interface
	T operator*() { return *p; }
	T const operator*() const { return *p; }
	T* operator->() { return p; }
	T const * operator->() const { return p; }
	unsigned usage() const { return count; }
private:
	T *p;
	unsigned count;
};	// template class shared_ptr

// own version of unique_ptr
template <typename T>
class unique_ptr {
public:
	unique_ptr(): p(new T) {}
	unique_ptr(T *t): p(std::move(t)) {}	// t not useful after been
	                                      // used by unique_ptr
	unique_ptr(unique_ptr<T> &uptr) : p(new T(*(uptr.p))) {}
	unique_ptr(unique_ptr<T> &&uptr) noexcept : 
		p(std::move(*(uptr.p))) {}
	unique_ptr& operator=(unique_ptr<T> &uptr)
	{ if(*p!=*(uptr.p)) p = new T(*(uptr.p)); return *this; }
	unique_ptr& operator=(unique_ptr<T> &&uptr) noexcept
	{ if(*p!=*(uptr.p)) p = std::move(*(uptr.p)); return *this; }
	~unique_ptr()	{ std::cout << "unique_ptr deleter." << std::endl; delete p; }

	// interface
	T operator*() { return *p; }
	T const operator*() const { return *p; }
	T* operator->() { return p; }
	T const * operator->() const { return p; }
private:
	T *p;
};	// template class unique_ptr

}

#endif
