#ifndef _BlobPtr_h
#define _BlobPtr_h

// template class Blob

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include "Blob.h"

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

// implementations for template class BlobPtr
#include "BlobPtr.tpp"

#endif
