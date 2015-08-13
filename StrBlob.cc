#include "StrBlob.h"
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

////////////////////////////////
// constructor
StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}

StrBlob::StrBlob(initializer_list<string> il):
	data(std::make_shared<vector<string>>(il)) {}

// copy control
StrBlob::StrBlob(const StrBlob &rhs):
	data(std::make_shared<vector<string>>(rhs.data)) {}

StrBlob::StrBlob(StrBlob &&rhs) noexcept :
	data(std::move(rhs.data)) {}

StrBlob& StrBlob::operator=(const StrBlob &rhs)
{
	data = rhs.data;
	return *this;
}

StrBlob& StrBlob::operator=(StrBlob &&rhs) noexcept
{
	data = std::move(rhs.data);
	return *this;
}

void StrBlob::check(size_type i, const string &msg) const
{
	if(i>=data->size())
		throw out_of_range(msg);
}

string& StrBlob::front()
{
	// if the vector is empty, check will throw
	check(0, "front on empty StrBlob");
	return data->front();
}

string& StrBlob::back()
{
	check(0,"back on empty StrBlob");
	return data->back();
}

string & StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0,"pop_back on empty StrBlob.");
	data->pop_back();
}


StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }
