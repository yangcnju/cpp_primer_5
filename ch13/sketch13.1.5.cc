#include <string>
#include <iostream>

class Sales_data {
public:
	Sales_data() = default;
	Sales_data(const Sales_data&) = default;
	Sales_data& operator=(const Sales_data&);
	~Sales_data() = default;
};	// class Sales_data

Sales_data& Sales_data::operator=(const Sales_data&) = default;

struct NoCopy{
	NoCopy() = default;
	NoCopy(const NoCopy&) = delete;
	NoCopy &operator=(const NoCopy&) = delete;
	~NoCopy() = default;
};

struct NoDtor{
	NoDtor() = default;
	~NoDtor()  = delete;
};

NoDtor nd;
NoDtor *p = new NoDtor();
delete p;

class PrivateCopy{
	PrivateCopy(const PrivateCopy&);
	PrivateCopy& operator=(const PrivateCopy&);
public:
	PrivateCopy() = default;
	~PrivateCopy();
}
