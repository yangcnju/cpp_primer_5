#include "Quote.h"
#include <iostream>

Quote::Quote(const Quote &q):
	bookNo(q.bookNo), price(q.price) 
	{ std::cout << "Quote(const Quote&)" << std::endl; }

Quote::Quote(Quote &&q):
	bookNo(std::move(q.bookNo)), price(std::move(q.price))
	{ std::cout << "Quote(Quote&&)" << std::endl; }

Quote& Quote::operator=(const Quote &q)
{
	bookNo = q.bookNo;
	price = q.price;
	std::cout << "Quote& operator=(const Quote&)" << std::endl;
	return *this;
}

Quote& Quote::operator=(Quote &&q)
{
	bookNo = std::move(q.bookNo);
	price = std::move(q.price);
	std::cout << "Quote& operator=(Quote &&q)" << std::endl;
	return *this;
}

std::vector<std::string> Quote::debug() const
{
	std::vector<std::string> dats;
	dats.push_back("price");
	return dats;
}
