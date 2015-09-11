#ifndef _my_size_array_h
#define _my_size_array_h

namespace my_t {
	template <typename T, unsigned size>
	constexpr unsigned m_sizeof(const T (&a)[size])
	{
		return size;
	}
}

#endif
