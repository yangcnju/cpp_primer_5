#ifndef _my_find_h
#define _my_find_h

template <typename InputIterator, typename T>
InputIterator my_find(InputIterator first, InputIterator last, const T &val)
{
	while(first!=last){
		if(*first==val) return first;
		++first;
	}
	return last;
}

#endif
