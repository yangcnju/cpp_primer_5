#ifndef _Quote_h
#define _Quote_h

#include <string>
#include <vector>
#include <iostream>		// for exercise 15.26

class Quote {
public:
	Quote(): bookNo(std::string()) { std::cout << "Quote()" << std::endl; }
	Quote(const std::string &book, double sales_price):
				bookNo(book), price(sales_price) 
		{ std::cout << "Quote(book,price)" << std::endl; }
	Quote(const Quote&);
	Quote(Quote&&);
	Quote& operator=(const Quote&);
	Quote& operator=(Quote&&);

	std::string isbn() const { return bookNo; }

	virtual double net_price(std::size_t n) const
	{ return n * price; }
	virtual ~Quote() { std::cout << "virtual ~Quote()" << std::endl; }

	// ex15.11
	virtual std::vector<std::string> debug() const;
private:
	std::string bookNo;
protected:
	double price = 0.0;
};	// Quote

#endif
