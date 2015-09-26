#ifndef _my_print_h
#define _my_print_h

#include <iostream>

template <typename InputIterator>
void print(InputIterator beg, InputIterator end)
{
	while(beg!=end)
		std::cout << *beg++ << " ";
	std::cout << std::endl;
}

template <typename T>
void print(const T *v, std::size_t sz)
{
	for(std::size_t i = 0; i!=sz; ++i){
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

#endif
