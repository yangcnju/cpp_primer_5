#ifndef _Quote_h
#define _Quote_h

#include <string>
#include <vector>

class Quote {
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price):
				bookNo(book), price(sales_price) {}
	std::string isbn() const { return bookNo; }

	virtual double net_price(std::size_t n) const
	{ return n * price; }
	virtual ~Quote() = default;

	// ex15.11
	virtual std::vector<std::string> debug() const;
private:
	std::string bookNo;
protected:
	double price = 0.0;
};	// Quote

#endif
