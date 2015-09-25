#ifndef _BlobPtr_tpp
#define _BlobPtr_tpp

/*
*********************************
*/
// Implemenation of BlobPtr
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
	check(curr, "increment past end of StrBlobPtr");
	--curr;
	return *this;
}

#endif
