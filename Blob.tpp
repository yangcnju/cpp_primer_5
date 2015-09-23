#ifndef _Blob_tpp
#define _Blob_tpp

//typedef typename std::vector<T>::size_type size_type;

// friend class definition for operator== of Blob<T>
template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs)
{
	return *(lhs.data) == *(rhs.data);
}

// Implementation of template class Blob
template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

template<typename T>
T& Blob<T>::front()
{
	check(0,"front on empty Blob");
	return data->front();
}

template<typename T>
T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
T& Blob<T>::operator[](size_type i)
{
	check(i, "subscription out of range");
	return (*data)[i];
}

template<typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

//Constructors
template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il):
	data(std::make_shared<std::vector<T>>(il)) {}

template <typename T>
Blob<T>::Blob(typename std::vector<T>::iterator b, 
              typename std::vector<T>::iterator e):
	data(std::make_shared<std::vector<T>>(b,e))
{}

#endif
