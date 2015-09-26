#include "ex14.45.Sales_data.h"

#include <iostream>

// Impletation of Sales_data

Sales_data::Sales_data(const std::string &s, double p_input, std::size_t num):
	item_name(std::make_shared<std::string>(s)), 
	q(std::make_shared<std::size_t>(num)),
	p(p_input) {}

Sales_data::Sales_data(const Sales_data &rhs):
	item_name(rhs.item_name), q(rhs.q), p(rhs.p) { ++*q; }

Sales_data::Sales_data(Sales_data &&rhs) noexcept:
	item_name(std::move(rhs.item_name)), q(std::move(rhs.q)), p(rhs.p) {}

Sales_data& Sales_data::operator=(const Sales_data &rhs)
{
	item_name = rhs.item_name;
	q = rhs.q;
	++*q;
	p = rhs.p;
	return *this;
}

Sales_data& Sales_data::operator=(Sales_data &&rhs) noexcept
{
	if(this!=&rhs){
		item_name = std::move(rhs.item_name);
		q = std::move(rhs.q);
		p = rhs.p;
	}
	return *this;
}

std::ostream& operator<<(std::ostream &os, const Sales_data &s)
{
	os << *(s.item_name) << " : " << s.p << " " << *(s.q) << std::endl;
	return os;
}

std::istream& operator>>(std::istream &is, Sales_data &s)
{
	std::string name;
	double price;
	std::size_t n;
	is >> name >> price >> n;
	if(is){
		*(s.item_name) = name;
		s.p = price;
		*(s.q) = n;
	}
	else
		s = Sales_data();
	return is;
}
