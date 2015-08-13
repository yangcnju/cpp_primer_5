#ifndef _StrBlob_h
#define _StrBlob_h

#include "ex13.25.StrBlobPtr.h"
#include <string>
#include <vector>
#include <initializer_list>
#include <memory>

class StrBlobPtr;

class StrBlob{
public:
	friend class StrBlobPtr;

	StrBlobPtr begin();
	StrBlobPtr end();

	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const { return data->size(); }
	
	// add and remove elements
	void push_back(const std::string &s) {data->push_back(s);}
	void pop_back();

	std::string& front();
	std::string& back();

	std::string& front() const;
	std::string& back() const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg) const;
};

#endif
