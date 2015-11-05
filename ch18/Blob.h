#ifndef _Blob_h
#define _Blob_h

// template class Blob

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <iostream>

template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T>
class Blob {
	friend class BlobPtr<T>;
//	friend bool operator==(const Blob<T>&, const Blob<T>&);
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	// constructors
	Blob();
	Blob(std::initializer_list<T> il);
	Blob(typename std::vector<T>::iterator, typename std::vector<T>::iterator);
	// number of elements in the Blob
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	// add and remove elements
	void push_back(const T &t) { data->push_back(t); }
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();
	// element access
	T& front();
	T& back();
	T& operator[](size_type i);
private:
	std::shared_ptr<std::vector<T>> data;
	void check(size_type i, const std::string &msg) const;
};	// template class Blob

// all implementations for template class Blob
#include "Blob.tpp"

#endif
