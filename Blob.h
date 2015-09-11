#ifndef _Blob_h
#define _Blob_h

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

template <typename> class BlobPtr;
template <typename> class Blob;
template <typename>
  bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T>
class Blob {
	friend class BlobPtr<T>;
	friend bool operator==(const Blob<T>&, const Blob<T>&);
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	// constructors
	Blob();
	Blob(std::initializer_list<T> il);
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
};	// class Blob

// Implementation
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


//-------------------------------
// Definition of template class BlobPtr
template <typename T> class BlobPtr {
public:
	BlobPtr(): curr(0) {}
	BlobPtr(Blob<T> &a, size_t sz = 0):
		wptr(a.data), curr(sz) {}
	T& operator*() const
	{ auto p = check(curr, "dereference past end");
		return (*p)[curr];
	BlobPtr& operator++();	// prefix
	BlobPtr& operator--();
	BlobPtr& begin() { return BlobPtr<T>(*this); }
	BlobPtr& end() { return BlobPtr<T>(*this, data->size()); }
private:
	std::shared_ptr<std::vector<T>>
		check(std::size_t, const std::string &) const;
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;
};	// class BlobPtr

// Implemenation of BlobPtr
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++() const
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--() const
{
	check(curr, "increment past end of StrBlobPtr");
	--curr;
	return *this;
}

#endif
