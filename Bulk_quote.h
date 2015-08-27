#ifndef _Bulk_quote_h
#define _Bulk_quote_h

#include "Quote.h"
#include <string>
#include <vector>

class Bulk_quote : public Quote {
public:
	Bulk_quote() : Quote() {}
	Bulk_quote(const std::string &book, double sales_price,
						 std::size_t q=0, double d=0.0):
		Quote(book, sales_price), min_qty(q), discount(d) {}
	double net_price(std::size_t n) const override; 

	virtual std::vector<std::string> debug() const override;
private:
	static size_t max_qty;
	std::size_t min_qty = 0;	// minimum purchase quantity for the discount
	double discount = 0.0;	// fractional discount to apply
};

#endif
