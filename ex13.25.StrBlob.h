#ifndef _ex13_25_StrBlob_h
#define _ex13_25_StrBlob_h

#include <string>
#include <vector>
#include <initializer_list>
#include <memory>

class StrBlob;

class StrBlobPtr{
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0);

	std::string& deref() const;
	StrBlobPtr& incr();

	//operators
	std::string& operator*() const;
	StrBlobPtr& operator++();
	bool operator==(const StrBlobPtr&) const;
	bool operator!=(const StrBlobPtr&) const;

private:
	std::shared_ptr<std::vector<std::string>>
		check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};	// class StrBlobPtr


class StrBlob{
public:
	friend class StrBlobPtr;

	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const { return data->size(); }
	
	// value like behavior
	StrBlob(const StrBlob &sb):
		data(std::make_shared<std::vector<std::string>>(*sb.data)) {}
	StrBlob& operator=(const StrBlob &sb)
	{ 
		data = std::make_shared<std::vector<std::string>>(*sb.data);
 		return *this;	
	}

	// add and remove elements
	void push_back(const std::string &s) {data->push_back(s);}
	void pop_back();

	std::string& front();
	std::string& back();

	std::string& front() const;
	std::string& back() const;

	StrBlobPtr begin();
	StrBlobPtr end();
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg) const;
};

#endif
