#ifndef _my_beg_n_end_h
#define _my_beg_n_end_h

#include <utility>
namespace my_t {
	template <typename T>
	T *begin(T *a)
	{
		return a;
	}

	template <typename T>
	T *end(T *a)
	{
		std::size_t sz = sizeof(a)/sizeof(T);
		return a+sz;
	}
}

#endif
